/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAAddress;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dContent NMAVenue3dContent.h "NMAVenue3dContent.h"
 *
 * \brief Contains POI (Point Of Interest) information of the spatial area in a venue.
 *
 * Examples of included POI information are the street address, the access information, the search tags, the space type, the category.
 *
 */
@interface NMAVenue3dContent : NSObject

/**
 * The human-readable name related to holder of the spatial area. This can be, for example, the name of the shop.
 * Can be nil if there is no name for the spatial area.
 *
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The phone number related to holder of the spatial area.
 * Can be nil if there is no phone number for the spatial area.
 *
 */
@property (nonatomic, readonly) NSString *phoneNumber;

/**
 * The URL address of the web site related to holder of the spatial area.
 * Can be nil if there is no URL for the spatial area.
 *
 */
@property (nonatomic, readonly) NSString *website;

/**
 * The postal address of the spatial area.
 *
 * \sa NMAAddress.
 */
@property (nonatomic, readonly) NMAAddress *address;

/**
 * The parent category identifier of the spatial area. This information can be used
 * for example to check type of the space: shopping, transportation-facility etc.
 *
 */
@property (nonatomic, readonly) NSString *parentCategoryId;

/**
 * The category identifier of the spatial area. For example, this information can be used
 * to check the type of a store, such as food and clothing.
 *
 * \sa NMAVenue3dLevel::spacesWithCategory:
 */
@property (nonatomic, readonly) NSString *placeCategoryId;

/**
 * The tags which describes the content holder. For example, the tags for an electronics retailer
 * may contain: television, phone, mobile, computer, and so on.
 * The tags can help to search inside NMAVenue3dVenue for specific key words.
 *
 */
@property (nonatomic, readonly) NSArray *searchTags;

/**
 * The unique venue identifier of the spatial area. This identifier is unique and
 * constant for each spatial area and can't be changed in later data updates.
 * Can be nil if there is no unique venue id for the spatial area.
 *
 */
@property (nonatomic, readonly) NSArray *uniqueVenueId;

@end
/** @} */
