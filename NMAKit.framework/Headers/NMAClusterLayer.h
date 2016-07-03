/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAClusterTheme;
@class NMAMapMarker;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAClusterLayer NMAClusterLayer.h "NMAClusterLayer.h"
 *
 * %NMAClusterLayer is a container of %NMAMapMarker.
 * Once added to the layer markers will start to cluster when the layer is attached to the map.
 */
@interface NMAClusterLayer : NSObject

/**
 * Theme used during cluster markers rendering.
 */
@property (nonatomic) NMAClusterTheme *theme;

/**
 * Array of %NMAMapMarker instances stored in this layer.
 */
@property (nonatomic, readonly) NSArray *markers;

/**
 * Constructs an empty %NMAClusterLayer.
 */
+ (instancetype)clusterLayer;

/**
 * Adds a marker to this layer.
 *
 * \param marker %NMAMapMarker to be added.
 *
 * \return YES if the marker was successfully added.
 */
- (BOOL)addMarker:(NMAMapMarker *)marker;

/**
 * Adds an array of markers to this layer.
 *
 * \param markers Array of %NMAMapMaker instances.
 *
 * \return YES if at least one marker was successfully added.
 */
- (BOOL)addMarkers:(NSArray *)markers;

/**
 * Removes a marker from this layer.
 *
 * \param marker %NMAMapMarker to be removed.
 *
 * \return YES if the marker was successfully removed.
 */
- (BOOL)removeMarker:(NMAMapMarker *)marker;

/**
 * Removes an array of markers from this layer.
 *
 * \param markers Array of %NMAMapMaker instances.
 *
 * \return YES if at least one marker was successfully removed.
 */
- (BOOL)removeMarkers:(NSArray *)markers;
@end
/** @}  */
