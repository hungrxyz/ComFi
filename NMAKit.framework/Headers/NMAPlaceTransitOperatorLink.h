/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMALink;


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 * \class NMAPlaceTransitOperatorLink NMAPlaceTransitOperatorLink.h "NMAPlaceTransitOperatorLink.h"
 * \brief Represents an additional link associated with transit operator.
 */
@interface NMAPlaceTransitOperatorLink : NSObject

/**
 * \brief The %NSString of operator link text.
 */
@property (nonatomic, readonly, strong) NSString *text;

/**
 * \brief The %NMALink to the operator information.
 */
@property (nonatomic, readonly, strong) NMALink *url;

@end
/** @} */
