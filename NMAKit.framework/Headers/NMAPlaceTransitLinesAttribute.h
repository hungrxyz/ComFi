/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAExtendedAttribute.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */


/**
 * \class NMAPlaceTransitLinesAttribute NMAPlaceTransitLinesAttribute.h "NMAPlaceTransitLinesAttribute.h"
 *
 * \brief Represents a Transit Lines Extended Attribute that is associated with
 * public transport stop/station and contains information about the lines and
 * destinations.
 */
@interface NMAPlaceTransitLinesAttribute : NMAExtendedAttribute

/**
 * The NSDictionary of NMAPlaceTranstiLine information for the public transport lines
 * using this stop/station.
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSDictionary *lines;

/**
 * An NSArray of NMAPlaceTransitDestination served from this stop/station.
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSArray *destinations;

@end

/** @} */
