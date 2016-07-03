/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

  
/**
 * \class NMAMapContainer NMAMapContainer.h "NMAMapContainer.h"
 *
 * \brief A container of NMAMapObject instances, containers can be added to a NMAMapView
 * instance.
 *
 * <p>Applications can, as necessary, add or remove certain
 * types of %NMAMapObject objects to or from a %NMAMapContainer (refer to
 * \link addMapObject:\endlink for details). A %NMAMapContainer is also
 * useful for grouping together %NMAMapObject objects to allow application operations
 * on entire groups of map objects without requiring an iterative approach to
 * inspecting or changing the state of each individual %NMAMapObject (e.g. for changing
 * their visibility).</p>
 *
 * \note The zOrder of an NMAMapObject instance in a container is relative only to other
 * NMAMapObject instances within the same container. Note that containers are derived
 * from NMAMapObject also have zOrder.
 */
@interface NMAMapContainer : NMAMapObject

/**
 * The %NSArray of NMAMapObject objects within the %NMAMapContainer.
 */
@property (nonatomic, readonly, weak) NSArray *mapObjects;

/**
 * \brief Adds a %NMAMapObject to the %NMAMapContainer.
 *
 * %NMAMapObject types that can be added to a %NMAMapContainer include:
 *
 * <ul>
 * <li>NMAMapMarker</li>
 * <li>NMAMapCircle</li>
 * <li>NMAMapPolygon</li>
 * <li>NMAMapPolyline</li>
 * <li>nested NMAMapContainer objects</li>
 * </ul>
 *
 * \note Attempts to add an object twice to the same container will be ignored.
 *
 * \note %NMAMapRoute is not supported by %NMAMapContainer and cannot be added.
 * This type of object needs to be added directly to the %NMAMapView
 * (see \link NMAMapView::addMapObject:\endlink).
 *
 * \param aMapObject A %NMAMapObject to be added to the %NMAMapContainer.
 *
 * \return YES if the %NMAMapObject was added successfully, NO otherwise.
 *
 * \sa \link removeMapObject:\endlink
 */
- (BOOL)addMapObject:(NMAMapObject *)aMapObject;

/**
 * Removes the specified %NMAMapObject from the %NMAMapContainer.
 *
 * \note If the specified %NMAMapObject is not contained within the %NMAMapContainer,
 * the container will be unchanged.
 *
 * \param aMapObject A %NMAMapObject to remove from the %NMAMapContainer.
 *
 * \return YES if the %NMAMapObject was removed successfully, NO otherwise.
 *
 * \sa removeAllMapObjects
 */
- (BOOL)removeMapObject:(NMAMapObject *)aMapObject;

/**
 * Removes all NMAMapObject objects from the %NMAMapContainer.
 *
 * \return YES if all %NMAMapObject objects were removed successfully, NO otherwise.
 */
- (BOOL)removeAllMapObjects;

@end
/** @}  */
