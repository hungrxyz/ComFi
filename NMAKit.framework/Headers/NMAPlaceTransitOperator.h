/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAPlaceTransitOperatorSupplier;


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 *
 * \class NMAPlaceTransitOperator NMAPlaceTransitOperator.h "NMAPlaceTransitOperator.h"
 *
 * \brief Represents a public transport operator.
 */
@interface NMAPlaceTransitOperator : NSObject

/**
 * \brief The %NSString representing the unique operator identifier.
 */
@property (nonatomic, readonly, strong) NSString *uniqueId;

/**
 * \brief The %NSString representing the operator name.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *title;

/**
 * \brief The %NMAPlaceTransitOperatorSupplier of the operator's schedule information.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly) NMAPlaceTransitOperatorSupplier *supplier;

/**
 * \brief Dictionary of NMAPlaceTransitOperatorLink additional links to be
 * displayed next to the departure informaiton of the operator. Possible keys
 * are operator, agency and tariff.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly) NSDictionary *links;

@end
/** @} */
