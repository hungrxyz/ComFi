/*
 * Copyright © 20YY-201X HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityProvider NMAUrbanMobilityProvider.h "NMAUrbanMobilityProvider.h"
 *
 * \brief Represents a public transport data provider. One data provider (such as an aggregation website
 * or API) can provide data for multiple \sa NMAUrbanMobilityOperator which provide transit in a specific
 * location.
 */
@interface NMAUrbanMobilityProvider : NSObject

/*
 * Name of provider. It's the localized name.
 */
@property (nonatomic, readonly) NSString *name;

@end
/** @}  */
