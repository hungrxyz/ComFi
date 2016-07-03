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
 */


/**
 * \class NMACategory NMACategory.h "NMACategory.h"
 *
 * Represents a category with which a NMAPlace can be associated.
 *
 * Categories can be used to search for places (e.g. a search that is based on a
 * category with which certain places are associated).
 *
 */
@interface NMACategory : NSObject

/**
 * Gets the unique identifier for the category.
 */
@property (nonatomic, readonly, strong) NSString *uniqueId;

/**
 * Gets the display name for the category. The name is localized to the current
 * locale of the device.
 */
@property (nonatomic, readonly, strong) NSString *name;

/**
 * Gets the URL of the category icon.
 *
 * \note Application can download the icon online with this URL, but it
 * needs to use its own icon for offline.
 */
@property (nonatomic, readonly, strong) NSString *iconUrl;

/**
 * Gets the parent of this category.
 * </p>
 * <p>
 * Note that an NMACategory might have no parent category, in which case this
 * method would return nil.
 */
@property (nonatomic, readonly, strong) NMACategory *parentCategory;

/**
 * Gets the list of subcategories %NMACategory of this category.
 * </p>
 * <p>
 * Note an NMACategory might have no subcategories, in which case this
 * method would return empty array.
 */
@property (nonatomic, readonly, strong) NSArray *subCategories;

@end
/** @} */
