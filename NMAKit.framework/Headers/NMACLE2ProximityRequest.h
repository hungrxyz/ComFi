/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Request.h"
#import "NMACLE2ResultListener.h"

NS_ASSUME_NONNULL_BEGIN

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * \class NMACLE2ProximityRequest NMACLE2ProximityRequest.h "NMACLE2ProximityRequest.h"
 *
 * Represents a custom location search request that uses the area around a location to retrieve
 * user-defined geometries.
 *
 * A new %NMACLE2ProximityRequest should be created for each distinct search.
 */
@interface NMACLE2ProximityRequest : NMACLE2Request

/*!
 * Creates a Proximity Search Request.
 *
 * \param layerId Name of the layer specifying the layer to search.
 * \param coordinates Specify the %NMAGeoCoordinates used as the search center.
 * \param radius An integer specifying the search radius in meters.
 *
 * \note Returns nil if initialization failed.
 *
 * <p>NMARequestErrorOperationNotAllowed indicates access to this operation is denied. Contact
 * your HERE representative for more information.</p>
 *
 */
- (nullable instancetype)initWithLayer:(NSString *)layerId center:(NMAGeoCoordinates *)coordinates radius:(int)radius;

/*!
 * Creates a Proximity Search Request that searches through multiple layers.
 *
 * \param layerIds An %NSArray with names specifying the layers to search.
 * \param coordinates Specify the %NMAGeoCoordinates used as the search center.
 * \param radius An integer specifying the search radius in meters.
 * \note Returns nil if initialization failed.
 *
 * <p>NMARequestErrorOperationNotAllowed indicates access to this operation is denied. Contact
 * your HERE representative for more information.</p>
 *
 */
- (nullable instancetype)initWithLayers:(NSArray<NSString *> *)layerIds center:(NMAGeoCoordinates *)coordinates radius:(int)radius;

/*!
 * Invokes an asynchronous query request with a specified listener.
 *
 * \param searchEventListener A listener to listen for search results
 * \return The appropriate NSError code. NMARequestErrorOperationNotAllowed
 * indicates access to this operation is denied. Contact your HERE representative
 * for more information.
 *
 * \sa \link startWithBlock:\endlink
 */
- (nullable NSError *)startWithListener:(id<NMACLE2ResultListener>)searchEventListener;

/*!
 * Invokes an asynchronous query request with a specified block.
 *
 * \param block A block to be executed upon completion of the request
 * \return The appropriate NSError code
 * \note code inside this block runs by default on the main thread/queue
 *
 * \sa NMARequestCompletionBlock
 * \sa \link startWithListener:\endlink
 */
- (nullable NSError *)startWithBlock:(NMACLE2RequestCompletionBlock)block;

/*!
 * Specifies the filter(s) to be used for a custom location request. When specified, only
 * geometries where expression evaluates to true will be returned.
 *
 * \param query A JavaScript expression as a string being evaluated for each geometry.
 */
- (void)setQuery:(NSString *)query;

@end

/**  @}  */

NS_ASSUME_NONNULL_END
