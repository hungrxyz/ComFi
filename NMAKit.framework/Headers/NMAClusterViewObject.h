/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"

@class NMAGeoBoundingBox;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAClusterViewObject NMAClusterViewObject.h "NMAClusterViewObject.h"
 *
 * Cluster map proxy object. Returned when using \p NMAMapView:objectsAtPoint.
 */
@interface NMAClusterViewObject : NMAProxyObject

/**
 * Array of %NMAMapMarker instances stored in this cluster.
 */
@property (nonatomic, readonly) NSArray *markers;

/**
 * Bounding box of the cluster.
 */
@property (nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

@end
/** @}  */
