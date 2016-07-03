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
 * \class NMATransitRouteSupplierNote NMATransitRouteSupplierNote.h "NMATransitRouteSupplierNote.h"
 *
 * Contains giving additional information about a transit data supplier.
 *
 * This information must be exposed in the client application.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitRouteSupplierNote : NSObject

/**
 * The type of source supplier note.
 */
@property (nonatomic, readonly) NSString *type;

/**
 * The text of the note.
 *
 * The text may contain HTML including hyperlinks (i.e. <a href> elements). The text will be localized.
 */
@property (nonatomic, readonly) NSString *text;

/**
 * The URL to which note is referring, if any.
 */
@property (nonatomic, readonly) NSString *url;

/**
 * The text accompanying the URL to which note is referring, if any.
 */
@property (nonatomic, readonly) NSString *urlText;

@end

/** @}  */
