// Objective-C API for talking to github.com/centrifugal/centrifuge-mobile Go package.
//   gobind -lang=objc github.com/centrifugal/centrifuge-mobile
//
// File is generated by gobind. Do not edit.

#ifndef __Centrifuge_H__
#define __Centrifuge_H__

@import Foundation;
#include "Universe.objc.h"


@class CentrifugeClient;
@class CentrifugeClientInfo;
@class CentrifugeConfig;
@class CentrifugeConnectContext;
@class CentrifugeCredentials;
@class CentrifugeDisconnectContext;
@class CentrifugeErrorContext;
@class CentrifugeEventHandler;
@class CentrifugeHistoryData;
@class CentrifugeMessage;
@class CentrifugePresenceData;
@class CentrifugePrivateRequest;
@class CentrifugePrivateSign;
@class CentrifugeSub;
@class CentrifugeSubEventHandler;
@class CentrifugeSubscribeErrorContext;
@class CentrifugeSubscribeSuccessContext;
@class CentrifugeUnsubscribeContext;
@protocol CentrifugeConnectHandler;
@class CentrifugeConnectHandler;
@protocol CentrifugeDisconnectHandler;
@class CentrifugeDisconnectHandler;
@protocol CentrifugeErrorHandler;
@class CentrifugeErrorHandler;
@protocol CentrifugeJoinHandler;
@class CentrifugeJoinHandler;
@protocol CentrifugeLeaveHandler;
@class CentrifugeLeaveHandler;
@protocol CentrifugeMessageHandler;
@class CentrifugeMessageHandler;
@protocol CentrifugePrivateSubHandler;
@class CentrifugePrivateSubHandler;
@protocol CentrifugeRefreshHandler;
@class CentrifugeRefreshHandler;
@protocol CentrifugeSubscribeErrorHandler;
@class CentrifugeSubscribeErrorHandler;
@protocol CentrifugeSubscribeSuccessHandler;
@class CentrifugeSubscribeSuccessHandler;
@protocol CentrifugeUnsubscribeHandler;
@class CentrifugeUnsubscribeHandler;

@interface CentrifugeClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (void)close;
- (BOOL)connect:(NSError**)error;
- (BOOL)disconnect:(NSError**)error;
- (CentrifugeSub*)subscribe:(NSString*)channel events:(CentrifugeSubEventHandler*)events error:(NSError**)error;
@end

@interface CentrifugeClientInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSString*)client;
- (void)setClient:(NSString*)v;
- (NSString*)defaultInfo;
- (void)setDefaultInfo:(NSString*)v;
- (NSString*)channelInfo;
- (void)setChannelInfo:(NSString*)v;
@end

@interface CentrifugeConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (long)timeoutMilliseconds;
- (void)setTimeoutMilliseconds:(long)v;
- (NSString*)privateChannelPrefix;
- (void)setPrivateChannelPrefix:(NSString*)v;
- (BOOL)websocketCompression;
- (void)setWebsocketCompression:(BOOL)v;
- (BOOL)ping;
- (void)setPing:(BOOL)v;
- (long)pingMilliseconds;
- (void)setPingMilliseconds:(long)v;
- (long)pongMilliseconds;
- (void)setPongMilliseconds:(long)v;
@end

@interface CentrifugeConnectContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
@end

@interface CentrifugeCredentials : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSString*)timestamp;
- (void)setTimestamp:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
- (NSString*)token;
- (void)setToken:(NSString*)v;
@end

@interface CentrifugeDisconnectContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)reason;
- (void)setReason:(NSString*)v;
- (BOOL)reconnect;
- (void)setReconnect:(BOOL)v;
@end

@interface CentrifugeErrorContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)error;
- (void)setError:(NSString*)v;
@end

@interface CentrifugeEventHandler : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (void)onConnect:(id<CentrifugeConnectHandler>)handler;
- (void)onDisconnect:(id<CentrifugeDisconnectHandler>)handler;
- (void)onError:(id<CentrifugeErrorHandler>)handler;
- (void)onPrivateSub:(id<CentrifugePrivateSubHandler>)handler;
- (void)onRefresh:(id<CentrifugeRefreshHandler>)handler;
@end

@interface CentrifugeHistoryData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (CentrifugeMessage*)messageAt:(long)i;
- (long)numMessages;
@end

@interface CentrifugeMessage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)uid;
- (void)setUID:(NSString*)v;
- (CentrifugeClientInfo*)info;
- (void)setInfo:(CentrifugeClientInfo*)v;
- (NSString*)channel;
- (void)setChannel:(NSString*)v;
- (NSString*)data;
- (void)setData:(NSString*)v;
- (NSString*)client;
- (void)setClient:(NSString*)v;
@end

@interface CentrifugePresenceData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (CentrifugeClientInfo*)clientAt:(long)i;
- (long)numClients;
@end

@interface CentrifugePrivateRequest : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
- (NSString*)channel;
- (void)setChannel:(NSString*)v;
@end

@interface CentrifugePrivateSign : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)sign;
- (void)setSign:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
@end

@interface CentrifugeSub : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)channel;
- (CentrifugeHistoryData*)history:(NSError**)error;
- (CentrifugePresenceData*)presence:(NSError**)error;
- (BOOL)publish:(NSData*)data error:(NSError**)error;
- (BOOL)subscribe:(NSError**)error;
- (BOOL)unsubscribe:(NSError**)error;
@end

@interface CentrifugeSubEventHandler : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (void)onJoin:(id<CentrifugeJoinHandler>)handler;
- (void)onLeave:(id<CentrifugeLeaveHandler>)handler;
- (void)onMessage:(id<CentrifugeMessageHandler>)handler;
- (void)onSubscribeError:(id<CentrifugeSubscribeErrorHandler>)handler;
- (void)onSubscribeSuccess:(id<CentrifugeSubscribeSuccessHandler>)handler;
- (void)onUnsubscribe:(id<CentrifugeUnsubscribeHandler>)handler;
@end

@interface CentrifugeSubscribeErrorContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (NSString*)error;
- (void)setError:(NSString*)v;
@end

@interface CentrifugeSubscribeSuccessContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
- (BOOL)isResubscribe;
- (void)setIsResubscribe:(BOOL)v;
- (BOOL)recovered;
- (void)setRecovered:(BOOL)v;
@end

@interface CentrifugeUnsubscribeContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (id)initWithRef:(id)ref;
@end

@protocol CentrifugeConnectHandler <NSObject>
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectContext*)p1;
@end

@protocol CentrifugeDisconnectHandler <NSObject>
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectContext*)p1;
@end

@protocol CentrifugeErrorHandler <NSObject>
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorContext*)p1;
@end

@protocol CentrifugeJoinHandler <NSObject>
- (void)onJoin:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@protocol CentrifugeLeaveHandler <NSObject>
- (void)onLeave:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@protocol CentrifugeMessageHandler <NSObject>
- (void)onMessage:(CentrifugeSub*)p0 p1:(CentrifugeMessage*)p1;
@end

@protocol CentrifugePrivateSubHandler <NSObject>
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateRequest*)p1 error:(NSError**)error;
@end

@protocol CentrifugeRefreshHandler <NSObject>
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

@protocol CentrifugeSubscribeErrorHandler <NSObject>
- (void)onSubscribeError:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeErrorContext*)p1;
@end

@protocol CentrifugeSubscribeSuccessHandler <NSObject>
- (void)onSubscribeSuccess:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeSuccessContext*)p1;
@end

@protocol CentrifugeUnsubscribeHandler <NSObject>
- (void)onUnsubscribe:(CentrifugeSub*)p0 p1:(CentrifugeUnsubscribeContext*)p1;
@end

FOUNDATION_EXPORT const int64_t CentrifugeCLOSED;
FOUNDATION_EXPORT const int64_t CentrifugeCONNECTED;
FOUNDATION_EXPORT const int64_t CentrifugeCONNECTING;
FOUNDATION_EXPORT const int64_t CentrifugeDISCONNECTED;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultPingMilliseconds;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultPongMilliseconds;
FOUNDATION_EXPORT NSString* const CentrifugeDefaultPrivateChannelPrefix;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultTimeoutMilliseconds;
FOUNDATION_EXPORT const int64_t CentrifugeSUBERROR;
FOUNDATION_EXPORT const int64_t CentrifugeSUBSCRIBED;
FOUNDATION_EXPORT const int64_t CentrifugeSUBSCRIBING;
FOUNDATION_EXPORT const int64_t CentrifugeUNSUBSCRIBED;

@interface Centrifuge : NSObject
+ (NSError*) errBadPublishStatus;
+ (void) setErrBadPublishStatus:(NSError*)v;

+ (NSError*) errBadSubscribeStatus;
+ (void) setErrBadSubscribeStatus:(NSError*)v;

+ (NSError*) errBadUnsubscribeStatus;
+ (void) setErrBadUnsubscribeStatus:(NSError*)v;

+ (NSError*) errClientDisconnected;
+ (void) setErrClientDisconnected:(NSError*)v;

+ (NSError*) errClientExpired;
+ (void) setErrClientExpired:(NSError*)v;

+ (NSError*) errClientStatus;
+ (void) setErrClientStatus:(NSError*)v;

+ (NSError*) errDuplicateWaiter;
+ (void) setErrDuplicateWaiter:(NSError*)v;

+ (NSError*) errInvalidMessage;
+ (void) setErrInvalidMessage:(NSError*)v;

+ (NSError*) errReconnectFailed;
+ (void) setErrReconnectFailed:(NSError*)v;

+ (NSError*) errTimeout;
+ (void) setErrTimeout:(NSError*)v;

+ (NSError*) errWaiterClosed;
+ (void) setErrWaiterClosed:(NSError*)v;

@end

FOUNDATION_EXPORT CentrifugeConfig* CentrifugeDefaultConfig();

FOUNDATION_EXPORT CentrifugeClient* CentrifugeNew(NSString* u, CentrifugeCredentials* creds, CentrifugeEventHandler* events, CentrifugeConfig* config);

FOUNDATION_EXPORT CentrifugeCredentials* CentrifugeNewCredentials(NSString* user, NSString* timestamp, NSString* info, NSString* token);

FOUNDATION_EXPORT CentrifugeEventHandler* CentrifugeNewEventHandler();

FOUNDATION_EXPORT CentrifugeSubEventHandler* CentrifugeNewSubEventHandler();

FOUNDATION_EXPORT NSString* CentrifugeTimestamp();

@class CentrifugeConnectHandler;

@class CentrifugeDisconnectHandler;

@class CentrifugeErrorHandler;

@class CentrifugeJoinHandler;

@class CentrifugeLeaveHandler;

@class CentrifugeMessageHandler;

@class CentrifugePrivateSubHandler;

@class CentrifugeRefreshHandler;

@class CentrifugeSubscribeErrorHandler;

@class CentrifugeSubscribeSuccessHandler;

@class CentrifugeUnsubscribeHandler;

@interface CentrifugeConnectHandler : NSObject <goSeqRefInterface, CentrifugeConnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectContext*)p1;
@end

@interface CentrifugeDisconnectHandler : NSObject <goSeqRefInterface, CentrifugeDisconnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectContext*)p1;
@end

@interface CentrifugeErrorHandler : NSObject <goSeqRefInterface, CentrifugeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorContext*)p1;
@end

@interface CentrifugeJoinHandler : NSObject <goSeqRefInterface, CentrifugeJoinHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onJoin:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@interface CentrifugeLeaveHandler : NSObject <goSeqRefInterface, CentrifugeLeaveHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onLeave:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@interface CentrifugeMessageHandler : NSObject <goSeqRefInterface, CentrifugeMessageHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onMessage:(CentrifugeSub*)p0 p1:(CentrifugeMessage*)p1;
@end

@interface CentrifugePrivateSubHandler : NSObject <goSeqRefInterface, CentrifugePrivateSubHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateRequest*)p1 error:(NSError**)error;
@end

@interface CentrifugeRefreshHandler : NSObject <goSeqRefInterface, CentrifugeRefreshHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

@interface CentrifugeSubscribeErrorHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeError:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeErrorContext*)p1;
@end

@interface CentrifugeSubscribeSuccessHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeSuccessHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeSuccess:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeSuccessContext*)p1;
@end

@interface CentrifugeUnsubscribeHandler : NSObject <goSeqRefInterface, CentrifugeUnsubscribeHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onUnsubscribe:(CentrifugeSub*)p0 p1:(CentrifugeUnsubscribeContext*)p1;
@end

#endif
