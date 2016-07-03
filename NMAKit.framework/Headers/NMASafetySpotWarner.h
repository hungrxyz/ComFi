/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMASafetySpotNotification;
@class NMASafetySpotNotificationInfo;
@class NMASafetySpotWarner;

/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 * @{
 */

/**
 * NMASafetySpotWarner delegate providing safety spot warnings relevant to the current navigation
 * session.
 */
@protocol NMASafetySpotWarnerDelegate<NSObject>
@optional

/**
 * Safety spot warning notification for the current navigation session.
 *
 * This method will only be called when NMANavigationManager is navigating a route
 * (mode NMANavigationModeTurnByTurn) using a transport mode of NMATransportModeCar.
 *
 * \param safetySpotWarner NMASafetySpotWarner singleton instance.
 * \param safetySpotNotification NMASafetySpotNotification representing safety spot.
 */
- (void)safetySpotWarner:(NMASafetySpotWarner *)safetySpotWarner didDetectSafetySpot:(NMASafetySpotNotification *)safetySpotNotification;

@end

#pragma mark -


/**
 * Provides safety spot warning information for the current navigation session.
 *
 * \note This class should not be initialized directly. An instance should be obtained via
 * [NMANavigationManager safetySpotWarner].
 */
@interface NMASafetySpotWarner : NSObject

/**
 * Delegate for notification of safety spots relevant to the current navigation session
 */
@property (nonatomic, weak) id<NMASafetySpotWarnerDelegate> delegate;

/**
 * Start the safety spot warner delegate callbacks.
 *
 * Will be started by default if there is an active navigation session ([NMANavigationManager navigationState]
 * is NMANavigationStateRunning)
 */
- (void)start;

/**
 * Stop the safety spot warner delegate callbacks.
 */
- (void)stop;

/**
 * Determines whether or not an NMASafetySpotNotificationInfo is ahead of the current GPS position (as reported
 * by NMAPositioningManager).
 *
 * \return YES if safetySpotNotificationInfo is ahead of the current GPS position.
 */
- (BOOL)isSafetySpotNotificationInfoAhead:(NMASafetySpotNotificationInfo *)safetySpotNotificationInfo;

@end

/** @} */
