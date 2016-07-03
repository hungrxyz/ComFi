/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMARoutingMode.h"
#import "NMARoute.h"

@class NMAGeoPosition;
@class NMAManeuver;
@class NMAMapView;
@class NMANavigationManager;
@class NMARoadElement;
@class NMARoute;
@class NMAVoicePackage;
@class NMATrafficWarner;
@class NMATrafficNotification;
@class NMASafetySpotWarner;
@class NMASafetySpotNotification;

/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 *
 * The Navigation group includes classes, protocols, and enumerations
 * related to guidance and turn-by-turn navigation.
 * The key class to this group is {@link NMANavigationManager}.
 *
 * @{
 *
 * @product nlp-hybrid-plus nlp-plus
 */

/**
 * The error domain for Navigation Manager.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const NMANavigationManagerErrorDomain;

/**
 * Unsigned integer, 64 bit wide
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef unsigned long long NMAUint64;

/**
 * Indicates failure of a computation for a 64-bit value.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NMAUint64 const NMANavigationManagerInvalidValue;

/**
 * This notification is sent whenever the NMANavigationManager navigationState
 * property changes.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const NMANavigationManagerStateChangedNotification;

/**
 * This is the key for extracting signpost from realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const NMANavigationManagerSignpostKey;

/**
 * This is the key for extracting junction view from realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const NMANavigationManagerJunctionViewKey;

/**
 * This is the key for extracting 16x9 realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT const id NMARealisticView16x9Key;

/**
 * This is the key for extracting 3x5 realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT const id NMARealisticView3x5Key;

/**
 * This is the key for extracting 5x3 realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT const id NMARealisticView5x3Key;

/**
 * This is the key for extracting 4x3 realistic view
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT const id NMARealisticView4x3Key;

/**
 * The possible states of NMANavigationManager.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMANavigationState) {
    /** \brief No navigation is in progress */
    NMANavigationStateIdle = 0,
    /** \brief Navigation (guidance or tracking) is in progress and active */
    NMANavigationStateRunning,
    /** \brief Navigation is in progress but not currently active */
    NMANavigationStatePaused
};

/**
 * The possible modes of NMANavigationManager.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMANavigationMode) {
    /**
     * \brief Navigation is not running
     */
    NMANavigationModeNone = 0,
    /**
     * \brief Navigation is running in turn-by-turn mode
     * (following a route using GPS data, recalculation
     * will occur if position deviates from route)
     */
    NMANavigationModeTurnByTurn,
    /**
     * \brief Navigation is running in tracking mode
     * (Not following a route, GPS data drives map movement)
     */
    NMANavigationModeTracking
};

/**
 * The methods of setting the orientation used when map tracking is enabled.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAMapTrackingOrientation) {
    /** \brief The map will be oriented with the current heading toward the top of the screen */
    NMAMapTrackingOrientationDynamic,
    /** \brief The map will be oriented with north toward the top of the screen */
    NMAMapTrackingOrientationNorthUp,
};

/**
 * The methods of setting the tilt used when map tracking is enabled.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAMapTrackingTilt) {
    /** \brief The map will be automatically tilted to a 2D perspective */
    NMAMapTrackingTilt2D,
    /** \brief The map will be automatically tilted to a 3D perspective */
    NMAMapTrackingTilt3D,
    /** \brief The map tilt will not be changed */
    NMAMapTrackingTiltCustom
};

/**
 * Distance measurement unit systems
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAMeasurementSystem) {
    /** \brief Meter and kilometer */
    NMAMeasurementSystemMetric = 0,
    /** \brief Miles and yards     */
    NMAMeasurementSystemImperial,
    /** \brief Miles and feet      */
    NMAMeasurementSystemImperialUS
};

/**
 * Realistic view aspect ratio
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSUInteger, NMARealisticViewAspectRatio) {
    NMARealisticView16x9 = 0x1,
    NMARealisticView3x5 = 0x2,
    NMARealisticView5x3 = 0x4,
    NMARealisticView4x3 = 0x8
};

/**
 * Realistic view modes
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMARealisticViewMode) {
    NMARealisticViewOff,
    NMARealisticViewDay,
    NMARealisticViewNight
};

/**
 * Navigation Errors
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMANavigationError) {
    NMANavigationErrorNone,
    /** \brief Guidance is not ready for use */
    NMANavigationErrorGuidanceNotReady,
    /** \brief Guidance Polling must be continued */
    NMANavigationErrorNotReady,
    /** \brief Failed to start Positioning Manager */
    NMANavigationErrorPositioningFailed,
    /** \brief Out of Memory */
    NMANavigationErrorOutOfMemory,
    /** \brief Invalid Parameters */
    NMANavigationErrorInvalidParameters,
    /** \brief Operation not allowed at the time of the call */
    NMANavigationErrorInvalidOperation,
    /** \brief When something was not found (e.g. voice skins) */
    NMANavigationErrorNotFound,
    /** \brief Operation aborted */
    NMANavigationErrorAborted,
    /** \brief The current SDK does not allow the operation */
    NMANavigationErrorOperationNotAllowed,
    /** \brief HERE Developer credentials are invalid or were not provided */
    NMANavigationErrorInvalidCredentials,
    /** \brief The current position data source does not support pedestrian navigation */
    NMANavigationErrorPedestrianNavigationNotAvailable,
    /** \brief Generic error */
    NMANavigationErrorUnknown
};

/**
 * Options for the NMANavigationManager natural guidance feature, set using
 * the \link NMANavigationManager::setNaturalGuidanceMode:\endlink method.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSUInteger, NMANaturalGuidanceOption) {
    NMANaturalGuidanceNone            = 0,
    /** Natural guidance for traffic lights. */
    NMANaturalGuidanceTrafficLight    = 0x01,
    /**  Natural guidance for landmarks */
    NMANaturalGuidanceLandmark       = 0x04,
};

/**
 * Options for the NMANavigationManager traffic avoidance feature, set using
 * the NMANavigationManager::setTrafficAvoidanceMode:(NSUInteger) method.
 *
 * @product nlp-hybrid-plus
 */
typedef NS_ENUM(NSUInteger, NMATrafficAvoidanceMode) {
    /**
     * Route recalculated periodically due to traffic on route.
     * Updates automatically if the new route is better than existing one.
     * \sa \link NMANavigationManager::setRouteRequestInterval:\endlink
     */
    NMATrafficAvoidanceDynamic,
    /**
     * Traffic on route avoidance must be confirmed by the user.
     */
    NMATrafficAvoidanceManual,
    /**
     * Disable use of traffic for rerouting purpose.
     */
    NMATrafficAvoidanceDisabled
};

/**
 * States used to describes the current route re-calculation due to traffic's status.
 *
 * \note It is only applicable with traffic avoidance mode.
 *
 * \sa \link NMANavigationManager::setTrafficAvoidanceMode:\endlink
 * \sa NMATrafficAvoidanceMode
 *
 * @product nlp-hybrid-plus
 */
typedef NS_ENUM(NSUInteger, NMATrafficEnabledRoutingState) {
    /**
     * Route re-calculation due to traffic is disabled, when traffic avoidance mode is set
     * to NMATrafficAvoidanceDisabled.
     */
    NMATrafficEnabledRoutingStateOff,
    /**
     * Route re-calculation due to traffic is enabled and not currently in use.
     */
    NMATrafficEnabledRoutingStateOn,
    /**
     * Route re-calculation is enabled and it currently handling the on-going re-routing.
     */
    NMATrafficEnabledRoutingStateOngoingRequest,
    /**
     * Route re-calculation is enabled but re-routing cannot be processed. For example, the
     * application is currently offline.
     */
    NMATrafficEnabledRoutingStateNotAvailable
};

/**
 * \brief An interface for responding to navigation events sent by the
 * NMANavigationManager.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@protocol NMANavigationManagerDelegate<NSObject>
@optional

/**
 * Called when the destination of turn-by-turn navigation is reached.
 *
 * When the destination is reached, NMANavigationManager -stop is automatically
 * called. When this callback is received, the navigation manager state will be
 * NMANavigationStateIdle.
 *
 */
- (void)navigationManagerDidReachDestination:(NMANavigationManager *)navigationManager;

/*!
 * Called when the current (upcoming) maneuver is updated.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param maneuver The current (upcoming) maneuver to be made.
 * \param nextManeuver The maneuver to be made AFTER THE CURRENT MANEUVER.
 *
 * \note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
       hasCurrentManeuver:(NMAManeuver *)maneuver
             nextManeuver:(NMAManeuver *)nextManeuver;

/*!
 * Called when a change is made to the route being navigated.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param route The route that was set; can be nil.
 *
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
           didUpdateRoute:(NMARoute *)route;

/**
 * Called when lane information should be shown or hidden.
 *
 * No callback if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param laneInfoList An array of \p NMALaneInfo objects containing lane info related
 * to current position.
 * \param visible A boolean value indicating whether the supplied lane info should be shown or hidden.
 *
 * \deprecated This method is deprecated as of NMA SDK 3.2. Please use navigationManager:didUpdateLaneInformation:roadElement: instead.
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
        didUpdateLaneInfo:(NSArray *)laneInfoList
                  visible:(BOOL)visible DEPRECATED_ATTRIBUTE;

/**
 * \brief Used to retrieve information about the lane configuration while navigating.
 *
 * Called when new information about lanes is available. This method is called whenever
 * the current available lane information changes. No available lane information is indicated
 * by a count of zero for the laneInformationList (e.g. lane information should stop being displayed).
 *
 * The lanes are ordered from left (index = 0) to right (index = laneInformationList.count - 1).
 *
 * No callback if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param laneInformationList An array of \p %NMALaneInformation objects. An empty array indicates that
 * no lane information is available and lane information should stop being shown. The lanes are ordered
 * from left (index = 0) to right (index= laneInformationList.count - 1).
 * \param roadElement The \p NMARoadElement that the \p NMALaneInformation is associated with. nil if not
 * available or if laneInformationList is empty.
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
        didUpdateLaneInformation:(NSArray *)laneInformationList
                  roadElement:(NMARoadElement *)roadElement;

/**
 * Called when realistic views for the current (upcoming) maneuver are available.
 *
 * Here is an example of how to get signpost/junction view with aspect ratio 16x9:
 *
 * \code
 * NSDictionary* realisticView = [realisticViews objectForKey:NMARealisticView16x9Key];
 * NMAImage* signpost = [realisticView objectForKey:NMANavigationManagerSignpostKey];
 * NMAImage* junctionView = [realisticView objectForKey:NMANavigationManagerJunctionViewKey];
 * \endcode
 *
 * This callback will not be made if access to this operation is denied. Contact your HERE representative for
 * more information.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param realisticViews A dictionary of realistic view objects containing a junction view and/or a 2D signpost for the
 *        current (upcoming) maneuver using aspect ratio as the key.
 *
 * \note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)                    navigationManager:(NMANavigationManager *)navigationManager
    didUpdateRealisticViewsForCurrentManeuver:(NSDictionary *)realisticViews;

/**
 * Called when realistic views for the next maneuver AFTER THE CURRENT MANEUVER are available.
 *
 * Here is an example of how to get signpost/junction view with aspect ratio 16x9:
 *
 * \code
 * NSDictionary* realisticView = [realisticViews objectForKey:NMARealisticView16x9Key];
 * NMAImage* signpost = [realisticView objectForKey:NMANavigationManagerSignpostKey];
 * NMAImage* junctionView = [realisticView objectForKey:NMANavigationManagerJunctionViewKey];
 * \endcode
 *
 * This may be used as an advance notification. Assuming there are maneuvers A and B and there is a realistic view
 * for maneuver B. When A is the current (upcoming) maneuver, a realistic view for maneuver B will be provided in this
 * navigationManager:didUpdateRealisticViewsForNextManeuver callback. When maneuver B becomes the current (upcoming)
 * maneuver, the realistic view for maneuver B will be provided again in the
 * navigationManager:didUpdateRealisticViewsForCurrentManeuver callback.
 *
 * This callback will not be made if access to this operation is denied. Contact your HERE representative for
 * more information.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param realisticViews A dictionary of realistic view objects containing a junction view and/or a 2D signpost for the
 *        next maneuver AFTER THE CURRENT MANEUVER using aspect ratio as the key.
 *
 * \note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)                 navigationManager:(NMANavigationManager *)navigationManager
    didUpdateRealisticViewsForNextManeuver:(NSDictionary *)realisticViews;

/**
 * Called when all realistic views supplied before this callback are invalidated.
 *
 * If 2 maneuvers are close to each other and both has realistic views, it is not guaranteed that a
 * navigationManagerDidInvalidateRealisticViews callback will be issued between maneuvers. When this
 * callback is received, it is important that application discards all realistic views received.
 *
 * No callback if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note In general, a realistic view for the next maneuver is received before a realistic
 * view for the current (upcoming) maneuver. Take maneuvers A, B, and C. When A is the current (upcoming) maneuver,
 * a realistic view for the next maneuver B is supplied. As the user moves ahead, B becomes the current (upcoming)
 * maneuver. As the user is close to maneuver B, a realistic view for the current (upcoming) maneuver B is supplied again.
 * As the user moves onto maneuver C, navigationManagerDidInvalidateRealisticViews is received so that application can
 * remove all realistic views supplied this far.
 *
 * \param navigationManager The NMANavigationManager singleton.
 *
 * \note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)navigationManagerDidInvalidateRealisticViews:(NMANavigationManager *)navigationManager;

/**
 * Called when a speed limit warning is issued.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param speeding A boolean value indicating the current speeding status; YES if the user is speeding.
 * \param speed The current speed of the user in meters/second.
 * \param speedLimit The speed limit in meters/second or 0 if the information is not
 *        available.
 */
- (void)  navigationManager:(NMANavigationManager *)navigationManager
    didUpdateSpeedingStatus:(BOOL)speeding
            forCurrentSpeed:(float)speed
                 speedLimit:(float)speedLimit;

/**
 * Called when the navigation manager loses its position.
 *
 * When the raw position (e.g. GPS) is lost, navigation may continue for a time
 * if the current position can be successfully estimated. This may occur for example
 * when traveling through a tunnel. This callback will not be sent until the position
 * can no longer be estimated. Thus, it may occur some time after the didLosePosition
 * notification from NMAPositioningManager.
 *
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerDidLosePosition:(NMANavigationManager *)navigationManager;

/**
 * Called when the navigation manager finds its position.
 *
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerDidFindPosition:(NMANavigationManager *)navigationManager;

/**
 * Called when rerouting is triggered.
 *
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerWillReroute:(NMANavigationManager *)navigationManager;

/**
 * Called when rerouting has finished.
 *
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerDidReroute:(NMANavigationManager *)navigationManager;

/**
 * Called when the navigation manager has found an improved route.
 *
 * When the navigation manager traffic avoidance mode is manual, the navigation
 * manager will search for faster routes, but will not automatically switch to
 * them.
 *
 * When a new route is found, it is up to the navigation manager delegate to
 * determine whether or not to use it. To use the new route, call
 * NMANavigationManager::setRoute: with the new route.
 *
 * The new route may be set after returning from this callback, but it is not
 * recommended to wait more than a few seconds before switching the route since
 * a delay might cause the user to receive an invalid instruction from the old
 * route or miss the first instruction from the new route.
 *
 * \note This callback is only sent when NMATrafficAvoidanceManual is in use.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param route The newly calculated NMARoute.
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
    didFindAlternateRoute:(NMARoute *)route;

/**
 * Called when the traffic avoidance routing state changes.
 *
 * \note This callback is only sent when traffic avoidance is enabled or was just
 * disabled.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param state An enum NMATrafficEnabledRoutingState representing the current
 *              traffic enabled routing state.
 *
 * \sa \link NMANavigationManager::setTrafficAvoidanceMode:\endlink
 * \sa NMATrafficEnabledRoutingState
 */
- (void)navigationManager:(NMANavigationManager *)navigationManager
    didChangeRoutingState:(NMATrafficEnabledRoutingState)state;

/**
 * Called when the navigation manager has audio feedback to play.
 *
 * If the delegate returns NO, the pending feedback will not be played. If the delegate
 * returns YES or this method is not implemented, the feedback will be played. This
 * method will be called once for each voice instruction or other non-voice audio feedback
 * (e.g. speed warning beeps).
 *
 * This method can be used to play voice commands using a custom TTS (text to speech)
 * engine. To accomplish this you should write a new NMAAudioOutput class that plays text using
 * the custom engine. When this method is called create an instance of your custom
 * NMAAudioOutput, pass it to [NMAAudioManager playOutput:] and then return NO. This will ensure
 * your custom TTS output is correctly synced with non-voice audio feedback.
 *
 * \param navigationManager The NMANavigationManager singleton.
 * \param text The text to be spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * \return YES to have the voice feedback played by NMANavigationManager. NO to prevent
 * NMANavigationManager playing the voice feedback.
 */
- (BOOL)          navigationManager:(NMANavigationManager *)navigationManager
    shouldPlayVoiceFeedbackWithText:(NSString *)text;

/**
 * Called when navigation manager will play audio feedback.
 *
 * \param text The text to be spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)        navigationManager:(NMANavigationManager *)navigationManager
    willPlayVoiceFeedbackWithText:(NSString *)text;

/**
 * Called when navigation manager has finished playing audio feedback.
 *
 * \param text The text that was spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * \param navigationManager The NMANavigationManager singleton.
 */
- (void)       navigationManager:(NMANavigationManager *)navigationManager
    didPlayVoiceFeedbackWithText:(NSString *)text;

@end


/**
 * \class NMANavigationManager NMANavigationManager.h "NMANavigationManager.h"
 *
 * %NMANavigationManager is a navigation manager class that provides guidance
 * advice and information along a route.
 *
 * <p>
 * Application developers using this API
 * are required to thoroughly test their applications in all expected usage scenarios to ensure safe
 * and correct behaviour. Application developers are responsible for warning their users of the
 * following obligations:
 *  <ol>
 *  <li>
 *  Do not follow instructions which may lead to an unsafe or illegal situation
 *  </li>
 *  <li>
 *  Obey all local laws.
 *  </li>
 *  <li>
 *  Be aware that using a mobile phone or some of its features while driving may be prohibited.
 *  </li>
 *  <li>
 *  Always keep hands free to operate the vehicle while driving.
 *  </li>
 *  <li>
 *  First consideration while driving should be road safety.
 *  </li>
 *  </ol>
 *
 * \note NMANavigationManager requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMANavigationManager : NSObject

/**
 * Returns the NMANavigationManager singleton instance.
 *
 * \note Use this method to obtain a NMANavigationManager instance. Do not call
 * init directly.
 *
 * \return shared NMANavigationManager instance
 */
+ (NMANavigationManager *)sharedNavigationManager;

/**
 * Receives event callbacks containing information about the current
 * navigation session.
 *
 * \sa NMANavigationManagerDelegate
 */
@property (nonatomic, weak) id<NMANavigationManagerDelegate> delegate;

/**
 * Returns the current state of the navigation related to the tracked route.
 *
 * \note When this property changes, NMANavigationManager sends a notification with
 * the name given by NMANavigationManagerStateChangedNotification.
 */
@property (nonatomic, readonly) NMANavigationState navigationState;

/**
 * Returns the current mode of the navigation manager.
 */
@property (nonatomic, readonly) NMANavigationMode navigationMode;

/**
 * Allows the NMANavigationManager to automatically update map position as
 * navigation progresses.
 *
 * \note The default value is YES.
 */
@property (nonatomic) BOOL mapTrackingEnabled;

/**
 * Determines how the map is oriented during navigation map tracking.
 *
 * \note The default value is NMAMapTrackingOrientationDynamic.
 *
 * \sa NMAMapTrackingOrientation
 */
@property (nonatomic) NMAMapTrackingOrientation mapTrackingOrientation;

/**
 * Controls whether the map zoom level is adjusted during navigation map tracking.
 *
 * If map tracking autozoom is enabled, the zoom level of the map will be adjusted based
 * on the user's current movement speed. For example, the map will zoom out to show more
 * area when the user moves faster, and zoom in again when the user slows down. If autozoom
 * is disabled, the zoom level will be left at whatever it was when navigation began (and
 * it can be manually modified during navigation).
 *
 * \note The default value is YES.
 */
@property (nonatomic) BOOL mapTrackingAutoZoomEnabled;

/**
 * Controls how the map is tilted when map tracking is enabled.
 *
 * In 2D and 3D modes, the map will automatically be tilted back appropriately when
 * the tilt value is changed. In Custom mode, the tilt will not be changed. Use custom
 * mode to allow the map to be manually tilted during navigation or to set the tilt to
 * a fixed custom value.
 *
 * \note The default value is NMAMapTrackingTilt3D.
 */
@property (nonatomic) NMAMapTrackingTilt mapTrackingTilt;

/**
 * The voice package used for navigation.
 *
 * The default package is English (US). Setting the voice package to nil
 * restores the default package.
 */
@property (nonatomic) NMAVoicePackage *voicePackage;

/**
 * Determines whether to enable navigation voice. If set to NO,
 * navigation will be running without voice commands, (only speed warnings will be heard
 * during the navigation assuming that the speed warnings are enabled).
 *
 * \note navigation voice is enabled by default.
 * \note if you disabled the voice for the walk navigation you will not hear any beeps or vibrations
 * except when you reach your destination you will hear that once.
 */
@property (nonatomic, getter = isVoiceEnabled) BOOL voiceEnabled;

/**
 * Determines whether to enable device vibration for walk navigation. If set to NO,
 * navigation will be running without vibration.
 *
 * \note vibration is enabled by default.
 * \note voiceEnabled should be YES, in order to this property to take effect.
 */
@property (nonatomic, getter = isVibrationEnabled) BOOL vibrationEnabled;

/**
 * Determines whether to enable beeps for walk navigation. If set to NO,
 * navigation will be running without beeps.
 *
 * \note beeps is enabled by default.
 * \note voiceEnabled should be YES, in order to this property to take effect.
 */
@property (nonatomic, getter = isBeepsEnabled) BOOL beepsEnabled;

/**
 * Determines whether to enable speed warning audio feedback. If set to YES,
 * speed warnings will be heard during the navigation.
 *
 * \note speedWarningAudioFeedbackEnabled is enabled by default.
 *
 */
@property (nonatomic, getter = isSpeedWarningAudioFeedbackEnabled) BOOL speedWarningAudioFeedbackEnabled;

/**
 * The measure unit used for voice guidance.  See \p NMAMeasurementSystem for
 * possible values.  Default is NMAMeasurementSystemMetric.
 *
 * \note Please note that changing this property does not affect all measurements APIs.
 * Only voice guidance will be affected.
 */
@property (nonatomic) NMAMeasurementSystem voicePackageMeasurementSystem;

/**
 * The NMAMapView used for the current navigation.
 *
 * If a map view is specified when navigation is started, that map view will be used
 * to display maneuver arrows (for turn-by-turn navigation) and to track the current
 * position (if mapTrackingEnabled is set to YES).
 *
 * \note Will be nil if no map was specified for the current navigation session.
 *
 * \note Changes made to this property while navigation is active will not be reflected
 * until the next navigation session is started.
 */
@property (nonatomic, weak) NMAMapView *map;

/**
 * Returns the current (upcoming) maneuver on the route, or nil, if this information
 * is not available because the information is not ready yet, or there are no more maneuvers on the
 * route.
 *
 * \note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly) NMAManeuver *currentManeuver;

/**
 * Returns the next maneuver on the route AFTER THE CURRENT MANEUVER , or nil if there is none.
 *
 * \note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly) NMAManeuver *nextManeuver;

/**
 * Returns the distance from current position to the current (upcoming) maneuver in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToCurrentManeuver;

/**
 * Returns the distance from current position to the next maneuver AFTER THE CURRENT MANEUVER
 * in meters, or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToNextManeuver;

/**
 * Returns the distance from current position to the end of route in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToDestination;

/**
 * Returns the distance from route start to the current position in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceFromStart;

/**
 * Returns the average speed of distance travelled in meters/sec or 0 if it
 * cannot be calculated.
 */
@property (nonatomic, readonly) double averageSpeed;

/**
 * Returns the number of seconds that remain to travel to the destination,
 * or -DBL_MAX (see float.h) on error.
 *
 * \note The time interval returned will not include any delays due to traffic
 */
@property (nonatomic, readonly) NSTimeInterval timeToArrival;

/**
 * Returns the number of seconds that remain to travel to the destination
 * taken into account traffic data, or -DBL_MAX (see float.h) on error.
 *
 * This method returns -DBL_MAX if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note IMPORTANT: To ensure the time interval returned considers all traffic
 * remaining on the route see the prerequisites described in [NMARoute ttaWithTraffic]
 *
 * \param mode NMATrafficPenaltyMode used for calculation.
 */
- (NSTimeInterval)timeToArrivalWithTraffic:(NMATrafficPenaltyMode)mode;

/**
 * When set to YES, the current navigation will be paused if any. When set
 * to NO, the current navigation will resume if previously paused. This has no
 * effect if there is no navigation currently in progress.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

/**
 * Controls whether speed warnings are enabled.
 *
 * If set, navigationManager:didUpdateSpeedingStatus:forCurrentSpeed:speedLimit:
 * will be sent to the delegate when speeding is detected or when a correction is made.
 */
@property (nonatomic, getter = isSpeedWarningEnabled) BOOL speedWarningEnabled;

/**
 * The current low speed offset in meters/second.
 *
 * \sa setLowSpeedOffset:highSpeedOffset:speedBoundary:
 */
@property (nonatomic, readonly) float lowSpeedOffset;

/**
 * The current high speed offset in meters/second.
 *
 * \sa setLowSpeedOffset:highSpeedOffset:speedBoundary:
 */
@property (nonatomic, readonly) float highSpeedOffset;

/**
 * The current speed boundary in meters/second.
 *
 * \sa setLowSpeedOffset:highSpeedOffset:speedBoundary:
 */
@property (nonatomic, readonly) float speedBoundary;

/**
 * Controls whether navigation is paused when the application is sent to the
 * background.
 *
 * By default, background navigation is disabled.
 *
 * When background navigation is enabled and [NMAPositioningManager dataSource] is an NMAPositionDataSource
 * provided in the HERE SDK (by default it will be) then navigation will continue to run in the background
 * until completed. If you would like navigation to stop automatically after the device remains stationary
 * in the background for a period of time (15 to 20 minutes) you may need to configure the data source
 * directly. For example, in the case of NMADevicePositionSource:
 *
 * \code
 *      NMADevicePositionSource* posSource = (NMADevicePositionSource*)[NMAPositioningManager sharedPositioningManager].dataSource;
 *      if([posSource isKindOfClass:[NMADevicePositionSource class]]){
 *          posSource.locationManager.pausesLocationUpdatesAutomatically = YES;
 *      }
 * \endcode
 *
 * Note that if navigation is stopped in the background, it will not restart automatically.
 *
 * \note It is recommended to change this property while the app is in the foreground. Changing the
 * property while the app is in the background may have undefined behaviour.
 *
 * \sa NMAPositionDataSource::setBackgroundUpdatesEnabled:
 *
 */
@property (nonatomic) BOOL backgroundNavigationEnabled;

/**
 * Determines the type of realistic views (if any) that are provided during
 * navigation.
 *
 * If realistic views are enabled, when a realistic view for the current (upcoming) or next maneuver
 * becomes available or unavailable the following callbacks may be issued:
 * \p navigationManager:didUpdateRealisticViewsForNextManeuver
 * \p navigationManager:didUpdateRealisticViewsForCurrentManeuver
 * \p navigationManagerDidInvalidateRealisticViews
 *
 * The default value is NMARealisticViewOff. If realistic views are enabled, the
 * desired aspect ratios must also be set using the realisticViewAspectRatios
 * property.
 *
 * The realistic view mode may be changed during active navigation. If it is
 * disabled, a navigationManagerDidInvalidateRealisticViews callback will be sent
 * to inform the delegate to dismiss any realistic views that have previously
 * been displayed.
 *
 * Similarly, if the realistic view type is changed (e.g. from day to night), the
 * delegate will receive a callback to invalidate the old views followed by
 * callbacks with views of the new type.
 *
 * The realistic view mode cannot be changed if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note This feature is only available for turn-by-turn drive navigation.
 *
 * \sa NMANavigationManager::realisticViewAspectRatios
 */
@property (nonatomic) NMARealisticViewMode realisticViewMode;

/**
 * A bit mask defining the desired realistic view aspect ratios.
 *
 * The available aspect ratios are defined by the NMARealisticViewAspectRatio
 * enum. A value of 0 (the default) indicates that no realistic views will be
 * provided.
 *
 * The realistic view aspect ratios cannot be changed if access to this operation
 * is denied. Contact your HERE representative for more information.
 *
 * Changes made to this property during active navigation may not be reflected
 * until the next navigation session, so it is recommended to configure the
 * realistic views before starting navigation.
 *
 * \note Performance may be impacted if all supported aspect ratios are requested.
 */
@property (nonatomic) NSUInteger realisticViewAspectRatios;

/**
 * The current traffic avoidance mode.
 *
 * \sa NMANavigationManager::setTrafficAvoidanceMode:
 */
@property (nonatomic, readonly) NMATrafficAvoidanceMode trafficAvoidanceMode;

/**
 * The time that the navigation manager waits between subsequent checks for a
 * faster route.
 *
 * The route request interval may be set using NMANavigationManager::setRouteRequestInterval.
 *
 * \note This property is only applicable when traffic avoidance is enabled.
 *
 * \sa NMANavigationManager::trafficAvoidanceMode
 */
@property (nonatomic, readonly) NSUInteger routeRequestInterval;

/**
 * Starts a turn-by-turn navigation session using the specified route.
 *
 * Only one navigation session of any type is allowed at a time. Attempts to start
 * another navigation session when the current navigationState is not NMANavigationStateIdle
 * will fail.
 *
 * When navigation is started, the NMANavigationManager will automatically update some
 * positioning settings to provide the best experience. This includes the mapMatchMode of
 * NMAPositioningManager (inferred from the transportMode of the route) and the CLLocationManager
 * settings of the NMADevicePositionSource if applicable. Settings are restored to their previous
 * values when navigation is completed.
 *
 * \note Public transit navigation is not currently supported.
 *
 * \note Navigation may not be started while the application is in the background.
 * \note Navigation requires use of the NMAPositioningManager service; it will be automatically
 *       started if it is not already running.
 *
 * \param route The route to navigate.
 *
 * \return nil if started successfully, otherwise an NSError object with an error code
 * indicating the failure reason. A partial list of the most common reasons is:
 *      NMANavigationErrorInvalidOperation - if a navigation session is currently active, if the
 *                                           provide route includes public transit elements, or
 *                                           the application is currently in the background
 *      NMANavigationErrorInvalidParameters - if the route parameter is nil
 *      NMANavigationErrorOperationNotAllowed - if the SDK does not allow this type of navigation.
 *                                          Access to this operation is denied. Contact your
 *                                          HERE representative for more information.
 */
- (NSError *)startTurnByTurnNavigationWithRoute:(NMARoute *)route;

/**
 * Starts a position tracking navigation session.
 *
 * Tracking mode provides a similar experience to turn-by-turn navigation, but without
 * the guidance arrows and voice commands. The NMAMapView instance will be updated to
 * follow the user's position (if mapTrackingEnabled is YES) and speed warnings will be
 * sent to the navigation delegate.
 *
 * See startTurnByTurnNavigationWithRoute: for more information.
 *
 * \param transportMode The transportation mode to use for tracking. The mode used will
 * affect the settings of the NMAPositioningManager and NMADevicePositionSource when
 * navigation is started.
 *
 * \return nil if successful, otherwise an NSError object with error code indicating
 * the failure reason.
 */
- (NSError *)startTrackingWithTransportMode:(NMATransportMode)transportMode;

/**
 * stop the current navigation started via \p startTurnByTurnNavigationWithRoute or
 * \p startTracking.
 */
- (void)stop;

/**
 * Set the offset values for the speed warning feature.
 *
 * The speeding status of the user is determined by comparing the current speed
 * to the current speed limit with an offset. If the user's speed is greater than
 * the speed limit plus the offset, a speed warning is issued.
 *
 * To allow different offsets and low and high speeds, a speed boundary is used
 * to divide speed limits into two groups. The low speed offset is then used for
 * speed limits less than the speed boundary, and the high speed offset is used
 * for speed limits greater than the speed boundary.
 *
 * For example, suppose the low speed offset is 10km/h and the speed boundary is
 * 80km/h. If the speed limit of the current road is 50km/h, the user will be
 * considered speeding at any speed higher than 60km/h and a warning will be
 * issued.
 *
 * \param lowSpeedOffset Offset at low speeds in meters/second.
 * \param highSpeedOffset Offset at high speeds in meters/second.
 * \param speedBoundary Boundary between low and high speeds in meters/second. The
 * lowSpeedOffset is used below this boundary, and the highSpeedOffset is used above it.
 *
 * \return nil if successful, otherwise an NSError object containing error
 * information.
 *
 * \sa speedWarningEnabled
 */
- (NSError *)setLowSpeedOffset:(float)lowSpeedOffset
               highSpeedOffset:(float)highSpeedOffset
                 speedBoundary:(float)speedBoundary;

/**
 * Plays the most current voice command if possible.
 *
 * \note This method will be ignored if a voice command is currently being played.
 */
- (void)playVoiceCommand;

/**
 * Immediately stops the active voice feedback (if present) and removes any queued feedback.
 */
- (void)cancelVoiceFeedback;

/**
 * Sets the natural guidance mode for use with turn-by-turn navigation.
 *
 * Natural guidance augments the standard turn-by-turn instructions by providing guidance in a simpler,
 * more intuitive way.
 *
 * For example, if the NMANaturalGuidanceTrafficLight option is enabled the user will hear instructions
 * similar to "turn right at the next traffic light".
 *
 * \note Natural guidance is disabled by default.
 *
 * \param mode An OR combination of one or more NMANaturalGuidanceOption values. Pass NMANaturalGuidanceOptionNone
 *             to disable natural guidance.
 *
 * \return NMANavigationErrorNone if the natural guidance mode was set successfully,
 *         NMANavigationErrorInvalidOperation if the mode could not be set.
 *
 * \sa NMANaturalGuidanceOption
 */
- (NMANavigationError)setNaturalGuidanceMode:(NSUInteger)mode;

/**
 * \brief The current natural guidance mode used for turn-by-turn navigation.
 *
 * \return An OR combination of NMANaturalGuidanceOption values which comprise the mode.
 */
- (NSUInteger)naturalGuidanceMode;

/**
 * Sets the navigation traffic avoidance behaviour.
 *
 * If the traffic avoidance mode is dynamic, the navigation manager will
 * automatically update the guidance route to avoid traffic events.
 *
 * If the traffic avoidance mode is manual, the navigation manager delegate will
 * be prompted when a faster route is found and have the option to accept or
 * reject it.
 *
 * Traffic avoidance is disabled by default.
 *
 * The traffic avoidance mode cannot be set if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note: In order to use traffic avoidance mode your device must be online and the traffic data must be
 * downloaded using [NMATrafficManager requestTrafficOnRoute:] or by enabling traffic visualization on
 * NMAMapView using the trafficVisible property.
 *
 * \param mode The desired NMATrafficAvoidanceMode.
 *
 * \return NMANavigationErrorNone if the traffic avoidance mode was set successfully, otherwise one of
 *         the other error codes in NMANavigationError.
 *
 * \sa NMATrafficAvoidanceMode.
 */
- (NMANavigationError)setTrafficAvoidanceMode:(NMATrafficAvoidanceMode)mode;

/**
 * Sets the navigation route request interval.
 *
 * The route request interval controls how frequently the navigation manager
 * will search for a better route to avoid traffic.
 *
 * The default value is 300 seconds (5 minutes).
 *
 * \note This value is only applicable when traffic avoidance is enabled.
 *
 * \param interval The route request interval in seconds.
 *
 * \return NMANavigationErrorNone if operation was successful, otherwise one of
 *         the other error codes in NMANavigationError.
 */
- (NMANavigationError)setRouteRequestInterval:(NSUInteger)interval;

/**
 * Sets the route used for turn-by-turn navigation.
 *
 * Typically, the navigation route should be set once when guidance begins using
 * the startTurnByTurnNavigationWithRoute: method and not changed while guidance
 * is ongoing. However, in some cases a new or better route may be made available
 * during guidance, for example when using the traffic avoidance feature in manual
 * mode. In these cases, this method may be using to update the route during
 * active guidance.
 *
 * \param route The new route navigation manager should use
 *
 * \return NMANavigationErrorNone if operation was successful, otherwise one of
 *         the other error codes in NMANavigationError.
 *         Returns NMANavigationErrorInvalidOperation if turn-by-turn guidance
 *         is not currently active.
 *         Returns NMANavigationErrorInvalidParameters if route is nil or not a
 *         car route.
 */
- (NMANavigationError)setRoute:(NMARoute *)route;

/**
 * NMATrafficWarner instance providing realtime notifications of traffic flows and
 * events during an active navigation session (NMANavigationStateRunning).
 *
 * This method returns a nil object if access to this operation is denied. Contact
 * your HERE representative for more information.
 */
@property (nonatomic, readonly) NMATrafficWarner *trafficWarner;

/**
 * NMASafetySpotWarner instance providing realtime notifications of safety spots
 * during an active navigation session (NMANavigationStateRunning).
 *
 * This method returns a nil object if access to this operation is denied. Contact
 * your HERE representative for more information.
 */
@property (nonatomic, readonly) NMASafetySpotWarner *safetySpotWarner;

#pragma mark - DEPRECATED

/**
 * Returns the number of seconds that remain to travel to the destination
 * taken into account traffic data, or -DBL_MAX (see float.h) on error.
 *
 * This method returns -DBL_MAX if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \deprecated This property is deprecated as of HERE SDK 3.1 and is the equivalent of calling
 * timeToArrivalWithTraffic:NMATrafficPenaltyModeOptimal
 *
 * \note IMPORTANT: To ensure the time interval returned considers all traffic
 * remaining on the route see the prerequisites described in [NMARoute ttaWithTraffic]
 */
@property (nonatomic, readonly) NSTimeInterval timeToArrivalWithTraffic DEPRECATED_ATTRIBUTE;

@end

/** @} */
