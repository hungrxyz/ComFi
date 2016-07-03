/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * \addtogroup NMA_Map  NMA Mapping Group
 * @{
 */


/**
 * \class NMAMapTransitLayer NMAMapTransitLayer.h "NMAMapTransitLayer.h"
 *
 * Represents a NMAMapView layer that can display any combination
 * of transit stops, accesses, and lines (including none)
 */
@interface NMAMapTransitLayer : NSObject

/**
 * Highlights a specified array of transit lines. Previously
 * highlighted lines remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * \param uniqueIds The unique IDs of the translit lines to be highlighted.
 */
- (void)highlightTransitLinesFromUniqueIds:(NSArray *)uniqueIds;

/**
 * Highlights a specified array of transit stops. Previously
 * highlighted stops remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * \param uniqueIds The unique IDs of the translit stops to be highlighted.
 */
- (void)highlightTransitStopsFromUniqueIds:(NSArray *)uniqueIds;

/**
 * Highlights a specified array of transit accesses. Previously
 * highlighted accesses remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * \param uniqueIds The unique IDs of the translit accesses to be highlighted.
 */
- (void)highlightTransitAccessesFromUniqueIds:(NSArray *)uniqueIds;

/**
 * Highlights a specified array of transit line segments. Previously
 * highlighted line segments remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * \param uniqueIds The unique IDs of the translit line segments to be highlighted.
 */
- (void)highlightTransitLineSegmentsFromUniqueIds:(NSArray *)uniqueIds;

/**
 * Clears all transits layer objects from highlighted state to
 * non-highlighted state.
 */
- (void)clearTransitHighlights;

@end

/** @}  */
