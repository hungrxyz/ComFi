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
 * \class NMALink NMALink.h "NMALink.h"
 *
 * Represents a HERE Places resource link which requires another request to be made
 * in order to retrieve the full detauls of the resource. The link contains basic metadata
 * about the linked resource.
 *
 * The interface is typically subclassed to provide methods to make the appropriate resource
 * request.
 *
 */
@interface NMALink : NSObject

/**
 * Gets the unique identifier for the resource to which the %NMALink refers.
 *
 * \note An identifier for a linked object is optional, so this property could be nil.
 */
@property (nonatomic, strong, readonly) NSString *uniqueId;

/**
 * Gets the localized name for the resource to which the %NMALink refers.
 * </p>
 * <p>
 * Client applications can safely display this name to the user.
 *
 * \note A title for a linked object is optional, so this property could be nil.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 * Gets an URL of the icon for the resource to which assiciated with this NMALink.
 *
 * \note An icon URL for a NMALink object is optional, so this property could be nil.
 * Application can download the icon online with this URL, but it needs to use
 * its own icon for offline.
 */
@property (nonatomic, strong, readonly) NSString *iconUrl;

#pragma mark - DEPRECATED

/**
 * Gets the %NSString representation of the link URL.
 * </p>
 * <p>
 * This URL may be used to perform an HTTP GET request to the HERE Places REST service
 * to retrieve the full metadata of the linked resources for online.
 *
 * Use the request methods in dervied classes for offline. See also
 * NMAPlaceLink#detailsRequest and NMADiscoveryLink#request.
 * </p>
 * <p>
 * The request may return a HTML or JSON response. If url contains "places.hybrid.api.here.com",
 * it will return a JSON response as specified at http://developer.here.com/places
 * If URL contains other domains, it will most likely return a HTML response.
 *
 * \deprecated: This property is deprecated since release 3.2. Please use NMAPlaceLink#detailsRequest
 * and NMADiscoveryLink#request.
 *
 * \note For convenience it is recommended to use request methods in dervied classes when
 * available.
 */
@property (nonatomic, strong, readonly) NSString *url DEPRECATED_ATTRIBUTE;

@end
/** @} */
