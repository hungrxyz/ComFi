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
 * \class NMAAddress NMAAddress.h "NMAAddress.h"
 * Represents address information for a geographic location.
 * \sa NMAPlaceLocation
 */
@interface NMAAddress : NSObject

/**
 * The floor number in a multi-story building.
 */
@property (nonatomic, strong) NSString *floorNumber;

/**
 * The house number.
 */
@property (nonatomic, strong) NSString *houseNumber;

/**
 * The suite number or unit name.
 */
@property (nonatomic, strong) NSString *suiteNumberOrName;

/**
 * The street name.
 */
@property (nonatomic, strong) NSString *street;

/**
 * The district name.
 */
@property (nonatomic, strong) NSString *district;

/**
 * The county name.
 */
@property (nonatomic, strong) NSString *county;

/**
 * The city name.
 */
@property (nonatomic, strong) NSString *city;

/**
 * The state name.
 */
@property (nonatomic, strong) NSString *state;

/**
 * The postal code.
 */
@property (nonatomic, strong) NSString *postalCode;

/**
 * The country code.
 *
 * \note The country code defined in "ISO 3166-1 alpha-3" three letter format.
 */
@property (nonatomic, strong) NSString *countryCode;

/**
 * The country name.
 */
@property (nonatomic, strong) NSString *countryName;

/**
 * The descriptive label for the %NMAAddress.
 */
@property (nonatomic, strong) NSString *label;

/**
 * The %NSString representation of the address formatted according to local standards.
 */
@property (nonatomic, strong) NSString *formattedAddress;

/**
 * Gets the %NSDictionary containing all additional key-value
 * %NMAAddress data.
 *
 * \return The %NSDictionary of additional key-value data
 */
- (NSDictionary *)additionalData;

@end
/** @}  */
