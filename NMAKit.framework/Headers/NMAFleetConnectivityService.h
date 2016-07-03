/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAFleetConnectivityEvent;
@class NMAFleetConnectivityError;
@class NMAFleetConnectivityMessage;

/**
 * \addtogroup NMA_FCE NMA Fleet Connectivity Extensions Group
 * @{
 */

/**
 * \brief Represents a delegate to handle NMAFleetConnectivityService incoming messages.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAFleetConnectivityServiceDelegate<NSObject>
@required
/**
 * Called when incoming message arrives.
 *
 * \param message The NMAFleetConnectivityMessage instance.
 *                   See %NMAFleetConnectivityJobMessage and %NMAFleetConnectivityCustomMessage.
 */
- (void)fleetConnectivityMessageReceived:(NMAFleetConnectivityMessage *)message;

/**
 * Called when server acknowledges dispatched event.
 *
 * \param event The NMAFleetConnectivityEvent instance. Note that it won't be the same instance of event
 *                   that was passed to the sendEvent: call.
 *                   See %NMAFleetConnectivityJobStartedEvent, %NMAFleetConnectivityJobFinishedEvent,
 *                   %NMAFleetConnectivityJobRejectedEvent, %NMAFleetConnectivityJobCancelledEvent
 *                   and %NMAFleetConnectivityCustomEvent.
 *
 * \param error The NMAFleetConnectivityError instance in case of network failure or server error.
 *                   See %NMAFleetConnectivityError.
 */
- (void)fleetConnectivityEventAcknowledged:(NMAFleetConnectivityEvent *)event error:(NMAFleetConnectivityError *)error;
@end


/**
 * Main component of Fleet Connectivity Extension responsible for communication.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAFleetConnectivityService : NSObject

/**
 * The %NMAFleetConnectivityServiceDelegate that listens for messages from the
 * %NMAFleetConnectivityService.
 */
@property (nonatomic, weak) id<NMAFleetConnectivityServiceDelegate> delegate;

/**
 * Asset ID that identifies this device. Will be reported in every event dispatched to the server.
 * Server provides new messages based on this ID. Service won't start if it is not specified.
 */
@property (nonatomic) NSString *assetId;

/**
 * Dispatcher ID that identifies the user of this device. Service won't start if it is not specified.
 */
@property (nonatomic) NSString *dispatcherId;

/**
 * Polling interval specified in seconds. Default value is 10 seconds.
 */
@property (nonatomic) NSUInteger pollingInterval;

/**
 * Returns the %NMAFleetConnectivityService singleton instance.
 *
 * \note Use this method to obtain a %NMAFleetConnectivityService instance. Do not call
 * init directly.
 * \note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \return shared %NMAFleetConnectivityService instance
 */
+ (NMAFleetConnectivityService *)sharedFleetConnectivityService;

/**
 * Starts the service if it is not already started.
 * Fails if assetId or dispatcherId is not set.
 *
 * \return NO if assetId or dispatcherId is not set or service is already started.
 */
- (BOOL)start;

/**
 * Stops the service if it is running.
 *
 * \return NO if service is not running.
 */
- (BOOL)stop;

/**
 * Forces poll of new events, if the service is running.
 *
 * \return NO if service is not running.
 */
- (BOOL)forcePoll;

/**
 * Dispatches the provided event.
 *
 * \param event The NMAFleetConnectivityEvent instance.
 *                   See %NMAFleetConnectivityJobStartedEvent, %NMAFleetConnectivityJobFinishedEvent,
 *                   %NMAFleetConnectivityJobRejectedEvent, %NMAFleetConnectivityJobCancelledEvent
 *                   and %NMAFleetConnectivityCustomEvent.
 *
 * \return NO if service is not running or conditions for given event are not met.
 */
- (BOOL)sendEvent:(NMAFleetConnectivityEvent *)event;

/**
 * Retrieves the ID of currently running job. Job is started by sending %NMAFleetConnectivityJobStartedEvent.
 * Job can be stopped by sending %NMAFleetConnectivityJobFinishedEvent or %NMAFleetConnectivityJobCancelledEvent.
 *
 * \return ID of the currently running job. Nil if no job is in progress.
 */
- (NSString *)runningJobId;

@end

/**  @}  */
