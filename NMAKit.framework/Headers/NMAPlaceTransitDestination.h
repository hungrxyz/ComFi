/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 * \class NMAPlaceTransitDestination NMAPlaceTransitDestination.h "NMAPlaceTransitDestination.h"
 * \brief Represents a destination served from station/stop.
 */
@interface NMAPlaceTransitDestination : NSObject

/**
 * \brief The %NSString of the name of destination.
 */
@property (nonatomic, readonly, strong) NSString *destination;

/**
 * \brief The %NSString of the name of the NMAPlaceTransitLine serving the destination.
 */
@property (nonatomic, readonly, strong) NSString *line;

@end
/** @} */
