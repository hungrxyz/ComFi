/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAAddress;
@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */

/**
 * Represents a custom location created and accessed through the
 * Custom Location Extension.
 *
 * \note The information for some locations may not be complete.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomLocation : NSObject

/**
 * An ID for the location specified by its owner.
 */
@property (nonatomic, readonly) NSString *customerLocationId;

/**
 * The primary name of the location.
 */
@property (nonatomic, readonly) NSString *name1;

/**
 * The secondary name of the location.
 */
@property (nonatomic, readonly) NSString *name2;

/**
 * The tertiary name of the location.
 */
@property (nonatomic, readonly) NSString *name3;

/**
 * The address of the location.
 *
 * \note Not all address fields will be available for every location.
 */
@property (nonatomic, readonly) NMAAddress *address;

/**
 * The phone number of the location.
 */
@property (nonatomic, readonly) NSString *phone;

/**
 * The fax number of the location.
 */
@property (nonatomic, readonly) NSString *fax;

/**
 * The website of the location.
 */
@property (nonatomic, readonly) NSString *webURL;

/**
 * A custom description of the location.
 */
@property (nonatomic, readonly) NSString *locationDescription;

/**
 * A collection of attributes possessed by the location.
 */
@property (nonatomic, readonly) NSArray *customAttributes;

/**
 * The exact geo coordinates of the location.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *coordinates;

/**
 * The geo coordinates of the location to use for routing.
 *
 * The route coordinates of a location will typically be located at the
 * nearest accessible road to the location, and may differ from the basic
 * coordinates property.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *routeCoordinates;

@end
/**  @}  */
