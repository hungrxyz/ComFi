/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATypes.h"

@class NMARequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Defines the name for Places API error domain
 */
FOUNDATION_EXPORT NSString *const NMA_PLACES_ERROR_DOMAIN;

/**
 * Represents an event listener that reports information about query
 * progress changes and query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAResultListener<NSObject>

@required
/**
 * \brief Callback when a request has completed.
 *
 * The following list shows NMA requrest types on the left and the corresponding
 * result data types on the right. The data type of the first argument received by
 * this method is one of the types on the left, the data type of the second
 * argument is one of those on the right.
 * \code
 * NMAGeocodeRequest                  NSArray(NMAGeocodeResult)
 * NMAReverseGeocodeRequest           NSArray(NMAReverseGeocodeResult)
 * NMADiscoveryRequest                NMADiscoveryPage
 * NMAPlaceRequest                    NMAPlace
 * NMAMediaCollectionPageRequest      NMAMediaCollectionPage
 * NMASuggestionRequest               NSArray(NSString)
 * \endcode
 *
 * \param request An object of the type shown on the left in the list above.
 *
 * \param data An object containing the search results, the possible types are
 *        shown on the right-hand side in the list above. Can be nil if no
 *        results found or an error was encountered.
 *
 * \param error NSError for this request. Nil if the request completed
 * successfully. Otherwise, this value is populated with an NMARequestError
 * error code and a domain of NMA_PLACES_ERROR_DOMAIN.
 */
- (void)        request:(NMARequest *)request
    didCompleteWithData:(id)data
                  error:(NSError *)error;

@end

/** @} */
