/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMARequest.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */


/**
 * \class NMAGeocodeRequest NMAGeocodeRequest.h "NMAGeocodeRequest.h"
 *
 * Represents a request to retrieve NMAPlaceLocation data by way of NMAGeocoder search services.
 *
 * \note A %NMAGeocodeRequest is a kind of NMARequest, and its response is an instance of NMAGeocodeResult.
 */
@interface NMAGeocodeRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \deprecated This method is deprecated as of NMA SDK 3.1. As this type of search no longer support this.
 */
@property (nonatomic) NMATextFormat textFormat DEPRECATED_ATTRIBUTE;

@end

/** @} */
