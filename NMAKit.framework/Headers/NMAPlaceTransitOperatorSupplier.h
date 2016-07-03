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
 * \class NMAPlaceTransitOperatorSupplier NMAPlaceTransitOperatorSupplier.h "NMAPlaceTransitOperatorSupplier.h"
 * \brief Represents a supplier of the public transport operator's schedule.
 */
@interface NMAPlaceTransitOperatorSupplier : NSObject

/**
 * \brief The %NSString of supplier title.
 */
@property (nonatomic, readonly, strong) NSString *title;

@end
/** @} */
