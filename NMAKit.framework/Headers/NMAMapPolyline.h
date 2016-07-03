/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAMapPolyline NMAMapPolyline.h "NMAMapPolyline.h"
 * Represents a NMAMapObject in the shape of a polyline.
 * <p>
 * A %NMAMapPolyline has multiple points that combine to create its path and
 * which are traversed in order. The line between
 * two consecutive points is always straight and is defined by the shortest
 * navigable way to move between them.</p>
 *
 * \note The NMAViewObject location property for an NMAMapPolyline returns the
 * coordinates of the first vertex (if available).
 */
@interface NMAMapPolyline : NMAMapObject

/*!
 * A convenience method for constructing an NMAMapPolyline.
 *
 * \param vertices An array of NMAGeoCoordinates which define the polyline
 */
+ (id)mapPolylineWithVertices:(NSArray *)vertices;

/**
 * The %NSArray of NMAGeoCoordinates that comprise the path of the
 * %NMAMapPolyline.
 */
@property (nonatomic, readonly) NSArray *vertices;

/**
 * The color for the %NMAMapPolyline.
 *
 * \note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong) UIColor *lineColor;

/**
 * The width, in pixels, for the %NMAMapPolyline.
 *
 * The line width must be in the range [0, 100]. The default width is 1 pixel.
 */
@property (nonatomic) NSUInteger lineWidth;

/**
 * Indicates whether the %NMAMapPolyline is dashed.
 *
 * \note The getter is \p isDashed.
 */
@property (nonatomic, getter = isDashed) BOOL dashed;

/**
 * The length, in pixels, for the primary dash of the %NMAMapPolyline.
 */
@property (nonatomic) NSUInteger dashPrimaryLength;

/**
 * The length, in pixels, for the secondary dash of the %NMAMapPolyline.
 */
@property (nonatomic) NSUInteger dashSecondaryLength;

/**
 * Indicates whether to render the %NMAMapPolyline with depth test.
 *
 * \note Rendering with depth test should be used if map object altitude
 * is relevant in your application. Rendering objects with different
 * heights while disabling depth test may cause object occlusion.
 */
@property (nonatomic) BOOL depthTestEnabled;

/*!
 * Initializes a %NMAMapPolyline instance with the specified %NSArray of
 * NMAGeoCoordinates objects.
 *
 * \param vertices A %NSArray of %NMAGeoCoordinates points defining the
 *                    %NMAMapPolyline
 * \return The %NMAMapPolyline
 */
- (id)initWithVertices:(NSArray *)vertices;

/*!
 * Determines the %NMAGeoCoordinates along the %NMAMapPolyline path that
 * is closest to the specified %NMAGeoCoordinates object.
 *
 * \param coordinates A %NMAGeoCoordinates to test for nearness to the
 *                    %NMAMapPolyline
 * \return The %NMAGeoCoordinates vertex along the %NMAMapPolyline path
 */
- (NMAGeoCoordinates *)nearestVertexToGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/*!
 * Determines the index of the %NMAMapPolyline path array that is closest
 * to the specified %NMAGeoCoordinates object.
 *
 * \param coordinates A %NMAGeoCoordinates to test for nearness to the
 *                    %NMAMapPolyline
 * \return The index of the %NMAGeoCoordinates vertex
 */
- (NSInteger)indexOfNearestVertexToGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/*!
 * Removes all vertices from the NMAMapPolyline's path.
 */
- (void)clearVertices;

/*!
 * Append a %NMAGeoCoordinates point to the end of the %NMAMapPolyline path.
 *
 * \param vertex A %NMAGeoCoordinates path point to append
 */
- (void)appendVertex:(NMAGeoCoordinates *)vertex;

/*!
 * Insert a %NMAGeoCoordinates point at the specified index of the %NMAMapPolyline path.
 *
 * \param vertex A %NMAGeoCoordinates path point to add.
 * \param index Position to insert. Index starts with 0.
 *
 * \note If index is equal or greater than the total number of vertices, the vertex will be
 * appended to the end of the polyline path.
 */
- (void)addVertex:(NMAGeoCoordinates *)vertex atIndex:(NSUInteger)index;

/*!
 * Remove the last %NMAGeoCoordinates point of the %NMAMapPolyline path.
 */
- (void)removeLastVertex;

/*!
 * Remove a %NMAGeoCoordinates point at the specified index of the %NMAMapPolyline path.
 *
 * \param index Position to remove. Index starts with 0 and must be smaller than the total number
 * of vertices.
 */
- (void)removeVertexAtIndex:(NSUInteger)index;

@end
/** @}  */
