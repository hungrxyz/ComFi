/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAVenue3dArea;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \brief Defines a location type in indoor routing.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dBaseLocationType) {
    /**
     * Space location
     */
    NMAVenue3dBaseLocationTypeSpace,

    /**
     * Outdoor location - point on the map
     */
    NMAVenue3dBaseLocationTypeOutdoor,

    /**
     * Level location - point on level inside venue
     */
    NMAVenue3dBaseLocationTypeLevel,

    /**
     * undefined - error
     */
    NMAVenue3dBaseLocationTypeOther
};


/**
 * \class NMAVenue3dBaseLocation "NMAVenue3dBaseLocation.h"
 *
 * \brief Defines a location used in indoor routing.
 *
 * \sa NMAVenue3dSpaceLocation
 * \sa NMAVenue3dOutdoorLocation
 * \sa NMAVenue3dRoutingController
 */
@interface NMAVenue3dBaseLocation : NSObject
    - (void)setParkingLocation:(NMAVenue3dBaseLocation*)location;
    - (BOOL)isValid;
    - (NMAVenue3dArea *)getArea;
    - (NMAGeoCoordinates *)getGeoCoordinate;
    - (NMAVenue3dBaseLocationType)getType;

@end
/** @} */
