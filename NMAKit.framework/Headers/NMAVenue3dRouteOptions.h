/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"
#import "NMAVenue3dRouteSection.h"

@class UIColor;


/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \class NMAVenue3dRouteOptions "NMAVenue3dRouteOptions.h"
 *
 * \brief Defines routing options used in routing.
 *
 * \sa NMAVenue3dRoutingController
 */
@interface NMAVenue3dRouteOptions : NSObject

/**
 * Constructs a NMAVenueRoutingOptions with the specified routing mode parameters.
 *
 * \sa NMARoutingMode
 */
+ (id)optionsWithRoutingMode:(NMARoutingMode *)routingMode;

/**
 * Gets visibility status for a specified route section type.
 *
 * \sa NMAVenue3dRouteSectionType
 */
- (BOOL)isRouteVisibileFor:(NMAVenue3dRouteSectionType)sectionType;

/**
 * Sets visibility status for a specified route section type.
 *
 * \sa NMAVenue3dRouteSectionType
 */
- (void)setRouteVisibilityFor:(NMAVenue3dRouteSectionType)sectionType
                           as:(BOOL)visibility;

/**
 * Sets color for a specified route section type.
 */
- (UIColor *)routeColorFor:(NMAVenue3dRouteSectionType)sectionType;

/**
 * Gets color for a specified route section type.
 */
- (void)setRouteColorForType:(NMAVenue3dRouteSectionType)sectionType
                          as:(UIColor *)color;

/**
 * Visibility status of the flags indicating the start and end locations of the route.
 * Default is YES (flags are shown).
 */
@property (nonatomic, readwrite) BOOL flagsVisible;

/**
 * Visibility status of the icons indicating entrances and access methods (e.g. stairs, elevators along the route.
 * For example if the route leads to different level via stairs, that is incicated with the stairs
 * icon.
 * Default is YES (icons are shown).
 */
@property (nonatomic, readwrite) BOOL iconsVisible;

/**
 * Color of the line indicating an accessor conncetion of the route.
 */
@property (nonatomic, readwrite) UIColor *connectorColor;

/**
 * Width (in meters) of the line representing an indoor section of the route.
 * Minimum value is 0.01 and maximum value is 3.0.
 * Default value is 1.2.
 */
@property (nonatomic, readwrite) double indoorRouteLineWidth;

/**
 * Width (in meters) of the line representing an outdoor section of the route.
 * Minimum value is 1 and maximum value is 100.
 * Default value is 10.
 */
@property (nonatomic, readwrite) int outdoorRouteLineWidth;

/**
 * Auto parking status. If auto parking is enabled and there is no manually selected valid parking lots,
 * routing algorithm will automatically select best parking lots and will make route through them.
 * Default is YES (auto parking is enabled).
 */
@property (nonatomic, readwrite) BOOL autoParking;

/**
 * Represents value that indicates that the routing engine will avoid elevators.
 * Default is NO (Elevators are allowed).
 */
@property (nonatomic, readwrite) BOOL avoidElevators;

/**
 * Represents value that indicates that the routing engine will avoid escalators.
 * Default is NO (Escalators are allowed).
 */
@property (nonatomic, readwrite) BOOL avoidEscalators;

/**
 * Represents value that indicates that the routing engine will avoid stairs.
 * Default is NO (Stairs are allowed).
 */
@property (nonatomic, readwrite) BOOL avoidStairs;

/**
 * Represents value that indicates that the routing engine will avoid rapms.
 * Default is NO (Ramps are allowed).
 */
@property (nonatomic, readwrite) BOOL avoidRamps;

/**
 * Represents value that indicates that the routing engine will try to
 * follow corridors without going through spaces (shops, rooms etc.).
 * Default is NO.
 */
@property (nonatomic, readwrite) BOOL preferCorridors;

/**
 * Represents value that indicates that the routing engine will try to
 * enter venue through ground entrances.
 * Default is NO (All entrances will be used equally).
 */
@property (nonatomic, readwrite) BOOL preferGroundEntrances;

@end
/** @} */
