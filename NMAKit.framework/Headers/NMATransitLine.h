/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATransitManager.h"

@class UIColor;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \class NMATransitLine NMATransitLine.h "NMATransitLine.h"
 *
 * Represents a public transit line, for example a subway or metro rail.
 *
 * \note Some lines may not have complete information available.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitLine : NSObject

/**
 * The unique identifying string of the line.
 */
@property (nonatomic, readonly) NSString *uniqueId;

/**
 * The officially published name of the line.
 */
@property (nonatomic, readonly) NSString *officialName;

/**
 * The local or colloquial name of the line, if available.
 */
@property (nonatomic, readonly) NSString *informalName;

/**
 * A shortened name for the line, if available.
 */
@property (nonatomic, readonly) NSString *shortName;

/**
 * The transportation type of the line.
 * \sa NMATransitType
 */
@property (nonatomic, readonly) NMATransitType transitType;

/**
 * The color associated with the line if available, otherwise nil.
 */
@property (nonatomic, readonly) UIColor *color;

/**
 * The uniqueId of the system of which this line is a part.
 */
@property (nonatomic, readonly) NSString *systemId;

@end

/** @}  */
