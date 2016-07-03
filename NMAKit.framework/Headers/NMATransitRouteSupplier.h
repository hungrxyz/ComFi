/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMATransitRouteSupplier NMATransitRouteSupplier.h "NMATransitRouteSupplier.h"
 *
 * Contains structured information about a source data supplier.
 *
 * Data supplier information must be displayed in the client application.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitRouteSupplier : NSObject

/**
 * The source data supplier's title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * The source data supplier's website.
 */
@property (nonatomic, readonly) NSString *url;

/**
 * Additional information about the supplier, represented as NMATransitRouteSupplierNote.
 *
 * This information must be displayed to the end-user.
 */
@property (nonatomic, readonly) NSArray *notes;

@end

/** @}  */
