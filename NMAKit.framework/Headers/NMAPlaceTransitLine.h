/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAPlaceTransitLineCategory;
@class NMAPlaceTransitLineStyle;


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 *
 * \class NMAPlaceTransitLine NMAPlaceTransitLine.h "NMAPlaceTransitLine.h"
 *
 * \brief Represents a public transport line.
 */
@interface NMAPlaceTransitLine : NSObject

/**
 * \brief The %NSString representing the line name.
 */
@property (nonatomic, readonly, strong) NSString *name;

/**
 * \brief The %NMAPlaceTransitLineCategory information for the line.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly) NMAPlaceTransitLineCategory *category;

/**
 * \brief The %NMAPlaceTransitLineStyle guideline information for the line.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly) NMAPlaceTransitLineStyle *style;

/**
 * \brief The %NSString of the operator serving the line.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *operatorName;

@end
/** @} */
