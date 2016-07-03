/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \brief The base class for all objects displayed in an NMA SDK view.
 *
 * All objects displayed by an NMA view (such as NMAMapView or
 * %NMAStreetLevelView, if available)
 * have NMAViewObject as their base class. All such objects fall into
 * one of two categories: proxy objects, created by the SDK, and user objects, created
 * by the client application. These objects additionally inherit from NMAProxyObject
 * and NMAUserObject, respectively.
 *
 * \sa NMAProxyObject, NMAUserObject
 */
@interface NMAViewObject : NSObject

/**
 *  Determines whether the specified %NMAViewObject object is equal to this
 * %NMAViewObject.
 *
 * \param aViewObject A %NMAViewObject to compare with this %NMAViewObject
 *                    for equality
 * \return YES if the %NMAViewObject internal instances are equal, NO otherwise
 */
- (BOOL)isEqual:(id)aViewObject;

/**
 *  Determines whether this %NMAViewObject exists within the
 * specified %NSArray of %NMAViewObject objects.
 *
 * \param objects An array of %NMAViewObject objects to check for
 *                the existence of this %NMAViewObject
 * \return YES if this %NMAViewObject exists within the specified
 *         %NSArray, NO otherwise
 */
- (BOOL)isInArray:(NSArray *)objects;

/*!
 * \brief The geographical location of the view object.
 *
 * The meaning of the location for a particular object depends on that
 * object's type. Objects that don't have a location will return nil.
 * The meaning of the location for certain view objects is as follows:
 * <p>
 * NMAMapView objects:
 * <ul>
 *     <li>NMAMapCircle           - the center of the circle</li>
 *     <li>NMAMapContainer        - no location</li>
 *     <li>NMAMapMarker           - same as coordinates property</li>
 *     <li>NMAMapPolygon          - the first vertex</li>
 *     <li>NMAMapPolyline         - the first vertex</li>
 *     <li>NMAMapRoute            - the first waypoint of the route</li>
 * </ul>
 * </p>
 *
 * <p>
 * %NMAStreetLevelView objects (if %NMAStreetLevelView is avaialble):
 * <ul>
 *    <li>%NMAStreetLevelLink     - no location</li>
 *    <li>%NMAStreetLevelBuilding - geo coordinates of the building</li>
 * </ul></p>
 */
- (NMAGeoCoordinates *)location;

@end

/** @}  */
