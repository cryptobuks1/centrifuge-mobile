package main

// Simple chat using our public demo on Heroku.
// See and communicate over web version at https://jsfiddle.net/FZambia/yG7Uw/

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"os"

	"github.com/centrifugal/centrifuge-mobile"
)

// ChatMessage is chat app specific message struct.
type ChatMessage struct {
	Input string `json:"input"`
}

// // In production you need to receive credentials from application backend.
// func credentials() *centrifuge.Credentials {
// 	// Never show secret to client of your application. Keep it on your application backend only.
// 	// secret := "secret"
// 	// Application user ID - anonymous in this case.
// 	user := ""
// 	// Exp timestamp as string.
// 	exp := centrifuge.Exp(60)
// 	// Empty info.
// 	info := ""
// 	// Generate client sign so Centrifuge server can trust connection parameters received from client.
// 	sign := ""

// 	return &centrifuge.Credentials{
// 		User: user,
// 		Exp:  exp,
// 		Info: info,
// 		Sign: sign,
// 	}
// }

type eventHandler struct {
	out io.Writer
}

func (h *eventHandler) OnConnect(c *centrifuge.Client, e centrifuge.ConnectEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Connected to chat with ID %s", e.ClientID))
	return
}

func (h *eventHandler) OnError(c *centrifuge.Client, e centrifuge.ErrorEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Error: %s", e.Message))
	return
}

func (h *eventHandler) OnDisconnect(c *centrifuge.Client, e centrifuge.DisconnectEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Disconnected from chat: %s", e.Reason))
	return
}

func (h *eventHandler) OnPublication(sub *centrifuge.Sub, e centrifuge.PublicationEvent) {
	var chatMessage *ChatMessage
	err := json.Unmarshal(e.Data, &chatMessage)
	if err != nil {
		return
	}
	rePrefix := "Someone says:"
	fmt.Fprintln(h.out, rePrefix, chatMessage.Input)
}

func (h *eventHandler) OnJoin(sub *centrifuge.Sub, e centrifuge.JoinEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Someone joined: user id %s, client id %s", e.User, e.Client))
}

func (h *eventHandler) OnLeave(sub *centrifuge.Sub, e centrifuge.LeaveEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Someone left: user id %s, client id %s", e.User, e.Client))
}

func (h *eventHandler) OnSubscribeSuccess(sub *centrifuge.Sub, e centrifuge.SubscribeSuccessEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Subscribed on channel %s", sub.Channel()))
}

func (h *eventHandler) OnSubscribeError(sub *centrifuge.Sub, e centrifuge.SubscribeErrorEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Subscribed on channel %s failed, error: %s", sub.Channel(), e.Error))
}

func (h *eventHandler) OnUnsubscribe(sub *centrifuge.Sub, e centrifuge.UnsubscribeEvent) {
	fmt.Fprintln(h.out, fmt.Sprintf("Unsubscribed from channel %s", sub.Channel()))
}

func main() {
	//creds := credentials()
	url := "ws://localhost:8000/connection/websocket?format=protobuf"
	//url := "grpc://localhost:8001"

	handler := &eventHandler{os.Stdout}

	events := centrifuge.NewEventHandler()
	events.OnConnect(handler)
	events.OnError(handler)
	events.OnDisconnect(handler)
	c := centrifuge.New(url, events, centrifuge.DefaultConfig())

	subEvents := centrifuge.NewSubEventHandler()
	subEvents.OnSubscribeSuccess(handler)
	subEvents.OnSubscribeError(handler)
	subEvents.OnPublication(handler)
	subEvents.OnUnsubscribe(handler)
	subEvents.OnJoin(handler)
	subEvents.OnLeave(handler)

	fmt.Fprintf(os.Stdout, "Connect to %s\n", url)
	fmt.Fprintf(os.Stdout, "Print something and press ENTER to send\n")

	sub := c.Subscribe("chat:index", subEvents)

	err := c.Connect()
	if err != nil {
		log.Fatalln(err)
	}

	// Read input from stdin.
	go func(sub *centrifuge.Sub) {
		reader := bufio.NewReader(os.Stdin)
		for {
			text, _ := reader.ReadString('\n')
			msg := &ChatMessage{
				Input: text,
			}
			data, _ := json.Marshal(msg)
			sub.Publish(data)
		}
	}(sub)

	// Run until CTRL+C.
	select {}
}