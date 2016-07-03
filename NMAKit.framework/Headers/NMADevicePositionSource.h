/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "NMAPositionDataSource.h"

@class CLLocationManager;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 *  Possible methods for determining device position change.
 */
typedef NS_ENUM(NSUInteger, NMADevicePositioningMethod) {
    /** \brief Equivalent to [CLLocationManager startUpdatingLocation] */
    NMADevicePositioningMethodGPS,
    /** \brief Equivalent to [CLLocationManager startMonitoringSignificantLocationChanges] */
    NMADevicePositioningMethodSignificantChanges
};


/**
 * \class NMADevicePositionSource NMADevicePositionSource.h "NMADevicePositionSource.h"
 *
 * \brief A position data source which gets updates from CLLocationManager.
 *
 * NMADevicePositionSource provides basic usage of CLLocationManager to the
 * NMAPositioningManager. The properties of the CLLocationManager instance may be
 * customized as needed, otherwise the default values are used.
 *
 * \note More advanced usage of CLLocationManager may be achieved by subclassing
 * NMADevicePositionSource. Any of the %CLLocationManagerDelegate methods may be
 * freely implemented, except locationManager:didUpdateLocations: and
 * locationManager:didFailWithError:. If either of these methods is implemented,
 * the superclass method should be invoked at some point in the subclass implementation.
 */
@interface NMADevicePositionSource : NSObject<NMAPositionDataSource, CLLocationManagerDelegate>

/**
 * The CLLocationManager instance used to generate position updates.
 */
@property (nonatomic, readonly) CLLocationManager *locationManager;

/**
 * \brief A convenience method to set the frequency of position updates.
 *
 * The device positioning method controls how CLLocationManger generates its updates. Refer to
 * the CLLocationManager API reference for an explanation of the update methods.
 *
 * Defaults to NMADevicePositioningMethodGPS
 *
 * \sa NMADevicePositioningMethod
 */
- (void)setPositioningMethod:(NMADevicePositioningMethod)method;

@end
/** @} */
