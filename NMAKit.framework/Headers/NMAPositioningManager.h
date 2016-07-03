/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoPosition;
@class NMARoadElement;
@protocol NMAPositionDataSource;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/** NMAPositioningManager Notifications */

/**
 * \brief Indicates that the NMAPositioningManager currentPosition has changed.
 *
 * In order to receive this notification, register with NSNotificationCenter using this notification name and the
 * [NMAPositioningManager sharedPositioningManager] instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const NMAPositioningManagerDidUpdatePositionNotification;

/**
 * \brief Indicates that the NMAPositioningManager currentPosition has been lost.
 *
 * In order to receive this notification, register with NSNotificationCenter using this notification name and the
 * [NMAPositioningManager sharedPositioningManager] instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const NMAPositioningManagerDidLosePositionNotification;

/**
 * Positioning methods used with the default position source (NMADevicePositionSource). Not applicable
 * for other types of position source.
 */
typedef NS_ENUM(NSUInteger, NMALocationTrackingMethod) {
    /** \brief Device positioning is not active. */
    NMALocationTrackingMethodNone = 0,
    /** \brief Position provided by CLLocationManager::startUpdatingLocation. */
    NMALocationTrackingMethodGPS,
    /** \brief Position provided by CLLocationManager::startMonitoringSignificantLocationChanges.  */
    NMALocationTrackingMethodSignificantChanges
};

/**
 * The types of position matching that can be performed by the NMAPositioningManager.
 */
typedef NS_ENUM(NSUInteger, NMAMapMatchMode) {
    /** \brief The raw position is matched only to roads which support automobile traffic. */
    NMAMapMatchModeCar,
    /** \brief The raw position is matched only to roads which support pedestrian traffic, e.g. including footpahs and excluding freeways. */
    NMAMapMatchModePedestrian
};


/**
 * \class NMAPositioningManager NMAPositioningManager.h "NMAPositioningManager.h"
 *
 * \brief Manages positioning services for the NMA SDK.
 *
 * <p>
 * This is a singleton class and thus should never be retained, released, or
 * instantiated. The singleton instance is accessed via the
 * sharedPositioningManager method.
 * </p>
 * <p>
 * Use the startPositioning method to begin tracking position, and stopPositioning
 * to stop. By default, position data comes from an instance of NMADevicePositionSource,
 * which uses CLLocationManager to determine position. Any custom source of position
 * data can be used instead by subclassing NMAPositionDataSource and installing an
 * instance of the subclass in the NMAPositioningManager dataSource property.
 * </p>
 * <p>
 * Two types of position are available from the positioning manager: the raw position
 * and the map-matched position. The raw position is simply passed straight through from
 * the positioning manager's data source. The map-matched position is the estimated position
 * on the road network based on the raw position input. When either type of position changes,
 * a NMAPositioningManagerDidUpdatePositionNotification will be sent out. If the raw position
 * is lost, a NMAPositioningManagerDidLosePositionNotification is sent.
 * </p>
 *
 * \note Certain other SDK features may require the use of the positioning manager;
 * if these features are accessed, the positioning manager will be enabled
 * automatically (for example, the NMAPositionIndicator of a NMAMapView).
 *
 * \note NMAPositioningManager requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAPositioningManager : NSObject

/**
 * Returns the NMAPositioningManager singleton instance.
 *
 * \note Use this method to obtain a NMAPositioningManager instance. Do not call
 * init directly.
 *
 * \return shared NMAPositioningManager instance
 */
+ (NMAPositioningManager *)sharedPositioningManager;

/*!
 * \brief The current provider of raw position data for the positioning manager.
 *
 * If positioning is started with a nil dataSource, a default instance of
 * NMADevicePositionSource is created and installed. This instance can then be
 * accessed and configured using the dataSource property. Similarly, if the dataSource
 * is set to nil while positioning is active, a default position source is installed.
 */
@property (nonatomic) id<NMAPositionDataSource> dataSource;

/*!
 * Indicates whether the NMAPositioningManager is currently broadcasting
 * position updates.
 */
@property (nonatomic, readonly, getter = isActive) BOOL active;

/*!
 * The latest unprocessed position received from the current dataSource.
 *
 * \note Will be nil if the latest update from the current dataSource did not
 * return a valid position.
 */
@property (nonatomic, readonly) NMAGeoPosition *rawPosition;

/*!
 * \brief The best esimated position on the road network based on the current rawPosition.
 *
 * When a new raw position is received and map matching is enabled, the position
 * is processed to estimate where on the road network the user is likely to be.
 * If the user is in a car on a known road, this position is likely to be more
 * accurate than the raw position. Map matching can be disabled by setting the
 * mapMatchingEnabled property to NO.
 *
 * \note Will be nil if map matching could not be performed, or if mapMatchingEnabled
 * is set to NO.
 */
@property (nonatomic, readonly) NMAGeoPosition *mapMatchedPosition;

/*!
 * \brief The best estimate for the user's current position.
 *
 * The currentPosition will be equal to either the rawPosition or the
 * mapMatchedPosition, depending on availability, SDK usage, and circumstances.
 *
 * If SDK services such as navigation which require the use of map matching are
 * active, the currentPosition will typically be the map-matched position.
 *
 * \note Will be nil if the positioning manager is not active or does not
 * have a valid position.
 */
@property (nonatomic, readonly) NMAGeoPosition *currentPosition;

/*!
 * Controls whether or not map matching is performed.
 *
 * The Map Matching is not enabled if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note The default value is NO.
 */
@property (nonatomic) BOOL mapMatchingEnabled;

/*!
 * \brief The mode in which raw position data is matched to the road network.
 *
 * If the mode is NMAMapMatchModeCar, the raw position data will only be matched
 * to roads which are accessible by a car. If the mode is NMAMapMatchModePedestrian,
 * the data will only be matched to roads or paths which are accessible on foot.
 *
 * \sa NMAMapMatchMode
 *
 * \note Attempts to set NMAMapMatchModePedestrian will be ignored when the position
 * data source is derived from NMAPositionDataSourceAutomotive as this position source
 * type does not support pedestrian map matching.
 */
@property (nonatomic) NMAMapMatchMode mapMatchMode;

/*!
 * \brief Enables position broadcasting.
 *
 * When positioning is started, the current dataSource will receive a start callback.
 * If no dataSource is set, a default instance of NMADevicePositionSource is created
 * and installed as the source.
 *
 * \return YES if positioning was successfully started, NO if positioning
 * was already in progress or if positioning failed to start.
 *
 * \sa NMAPositionDataSource
 */
- (BOOL)startPositioning;

/*!
 * \brief Disables position broadcasting.
 *
 * When positioning is stopped, the current dataSource will receive a
 * stop callback.
 *
 * \sa NMAPositionDataSource
 */
- (void)stopPositioning;

/*!
 * Get the road element of the current position.
 * Nil if not valid.
 *
 * \return Road element of the current position.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (NMARoadElement *)currentRoadElement;

/*!
 * \brief Used by the dataSource to indicate that a new position update is
 * available.
 *
 * When the current dataSource has a new position update ready, it calls this
 * method passing itself as the parameter. Only one position source may be
 * active at a time, so the parameter should match the current dataSource.
 * Objects other than the current dataSource should not call this method.
 */
- (void)dataSourceDidUpdatePosition:(id<NMAPositionDataSource>)dataSource;

@end
/** @}  */
