/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@protocol NMAResultListener;
@class NMARequest;
@class NMAGeoBoundingBox;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Search result text output formats.
 */
typedef NS_ENUM(NSUInteger, NMATextFormat) {
    /** \brief The request results will be rendered as HTML */
    NMATextFormatHTML = 0,
    /** \brief The request results will be rendered as plain text */
    NMATextFormatPlain
};

/**
 * A typedef of a block parameter signature used with \link NMARequest::startWithBlock:\endlink.
 *
 * <p>
 * The following table shows corresponding request and result types.
 * <ul>
 * <li>NMARequest                         - Expected Search Results</li>
 * <li>NMAGeocodeRequest                  - NSArray(NMAGeocodeResult)</li>
 * <li>NMAReverseGeocodeRequest           - NSArray(NMAReverseGeocodeResult)</li>
 * <li>NMADiscoveryRequest                - NMADiscoveryPage</li>
 * <li>NMAPlaceRequest                    - NMAPlace</li>
 * <li>NMAMediaCollectionPageRequest      - NMAMediaCollectionPage</li>
 * <li>NMASuggestionRequest               - NSArray(NSString)</li>
 * <li>NMACategoryGraphRequest            - NSArray(NMACategory)</li>
 * \if INTERNAL
 * <li>NMATilesRequest                   - NMATilesLink</li>
 * \endif
 * <li>NMAPlaceTransitSchedulePageRequest - NMAPlaceTransitSchedulePage</li>
 * </ul>
 * </p>
 *
 * \note The block will be called on the main queue.
 *
 * \param request The search request being completed.
 * \param data Search results. Search result type varies according to the
 * search request initiated. It can be nil if no results are found or an error
 * is encountered.
 * \param error The error if the request failed, or nil if the request was successful.
 *
 * \sa \link NMARequest::startWithBlock:\endlink
 *
 * \sa NMASearchResultType
 */
typedef void (^NMARequestCompletionBlock)(NMARequest *request,
                                          id          data,
                                          NSError *   error);


/**
 * \class NMARequest NMARequest.h "NMARequest.h"
 *
 * Represents a base interface for a search request.
 */
@interface NMARequest : NSObject<NSCoding>

/**
 * User-defined Tag as convenience method to identify %NMARequest.
 *
 * \note The default value for userTag is empty string and user should
 * assign any tag value with their own convention.
 */
@property (nonatomic, strong) NSString *userTag;

/**
 * NSString representing the preferred language for request responses.
 *
 * Default Value: [[NSLocale preferredLanguages] objectAtIndex:0].
 *
 * \note languagePreference should be a valid code according to the IETF BCP-47 standard
 * (see http://tools.ietf.org/html/bcp47 ).
 */
@property (nonatomic, strong) NSString *languagePreference;

/**
 * The maximum number of items in the response.
 *
 * \note The default value is 20.
 */
@property (nonatomic) NSUInteger collectionSize;

/**
 * The bounding box in which to perform the search.
 *
 * The viewport can act as an implicit location context in the absence of an
 * explicit location context. To ensure you get the best results possible, you
 * should match the viewport to your map if there is a map visible to the user.
 */
@property (nonatomic) NMAGeoBoundingBox *viewport;

/**
 * The NSArray of sources have been added for a NMAPlace.
 *
 * @see \link NMARequest::addSource:\endlink
 */
@property (nonatomic, readonly) NSArray *sources;

/*!
 * Invokes an asynchronous query request with a specified listener.
 *
 * \param aSearchEventListener A listener to listen for search results
 * \return The appropriate NSError code. NMARequestErrorOperationNotAllowed
 * indicates access to this operation is denied. Contact your HERE representative
 * for more information.
 *
 * \sa \link startWithBlock:\endlink
 */
- (NSError *)startWithListener:(id<NMAResultListener>)aSearchEventListener;

/*!
 * Invokes an asynchronous query request with a specified block.
 *
 * \param aBlock A block to be executed upon completion of the request
 * \return The appropriate NSError code
 *
 * \sa NMARequestCompletionBlock
 * \sa \link startWithListener:\endlink
 */
- (NSError *)startWithBlock:(NMARequestCompletionBlock)aBlock;

/*!
 * Cancels any pending query request.
 */
- (BOOL)cancel;

/*!
 * This function adds the a reference
 * identifier to be returned in the request results. See also
 * \link NMAPlace::referenceIdentifiersForSource:\endlink.
 *
 * Examples of reference identifiers are:
 * "NMAPlacesSourcePVID" for HERE's core content product which provides map and POI data,
 * "NMAPlacesSourceVenuesAll" for HERE's venue maps product whcih provides indoor
 * maps for thousands of venues, "NMAPlacesSourceBuilding" for extruded building.
 *
 * \param source A string containing the source identifier to add.
 */
- (void)addSource:(NSString *)source;

@end
/** @}  */
