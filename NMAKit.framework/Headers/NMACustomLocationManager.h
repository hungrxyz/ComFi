/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMACustomLocationParameters;
@class NMACustomLocationResponse;
@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMARoute;

/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 *
 * The Custom Location group provides classes and protocols
 * that support custom location searches.
 * Four types of searches are currently supported:
 * Proximity, Area, Corridor, Attribute. To perform a search
 * use the {@link NMACustomLocationManager} class.
 *
 * @product nlp-hybrid-plus nlp-plus
 *
 * @{
 */

/**
 * The error domain for NMACustomLocationManager request errors.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const kNMACustomLocationErrorDomain;

/**
 * A completion block type used to handle the results of custom location requests.
 *
 * \param response The response of the custom location request, or nil if no response is available.
 * \param error The error of the custom location request containing an NMARequestError code, or nil
 *              if the request was successful.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef void (^NMACustomLocationCompletionBlock)(NMACustomLocationResponse *response, NSError *error);


/**
 * A singleton class used to perform search requests for custom locations.
 *
 * Using the Custom Location Extension, client applications may provide their own sets of
 * custom place locations to the Here SDK back end. Then, using the CLE SDK classes, the
 * application may search for and retrieve these custom locations, which can then be used
 * to supplement the places provided by standard Here searches, or for any other purpose
 * required by the application.
 *
 * The NMACustomLocationManager provides several methods for requesting custom locations.
 * Locations may be searched around a posiiton, inside a bounding box, along a route, and
 * more. Additional search parameters may be provided to filter the results, including
 * a layer ID, search radius, text query, and custom attributes.
 *
 * The results of search requests are packaged in an NMACustomLocationResponse object, which
 * is passed to the completion block provided to the request method. If there is an error
 * with the request, a request object is also passed to the completion block. Requests are
 * performed asynchronously, and may be executed simultaneously.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomLocationManager : NSObject

/**
 * Provides access to the singleton instance of NMACustomLocationManager.
 *
 * \note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
+ (instancetype)sharedLocationManager;

/**
 * Requests for custom locations near a pair of geo coordinates.
 *
 * \param coordinates The coordinates around which to perform the search.
 * \param radius The radius of the search area in meters.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 *
 * \sa NMACustomLocationParameters
 */
- (void)requestLocationsNearGeoCoordinates:(NMAGeoCoordinates *)coordinates
                                withRadius:(NSUInteger)radius
                                     layer:(NSUInteger)layerID
                                parameters:(NMACustomLocationParameters *)parameters
                                completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom locations inside a geo bounding box.
 *
 * \param boundingBox The bounding box inside which to perform the search.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestLocationsInGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
                               withLayer:(NSUInteger)layerID
                              parameters:(NMACustomLocationParameters *)parameters
                              completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom locations along a geo corridor.
 *
 * A geo corridor is a series of one or more geo coordinates representing a path
 * in the world. For example, a corridor can be used to find locations along a
 * given street between two intersections (if the coordinates of the intersections
 * are known).
 *
 * \param corridor The corridor along which to perform the search.
 * \param radius The radius of the search area in meters.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestLocationsAlongCorridor:(NSArray *)corridor
                           withRadius:(NSUInteger)radius
                                layer:(NSUInteger)layerID
                           parameters:(NMACustomLocationParameters *)parameters
                           completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom locations along a route.
 *
 * \param route The route on which to perform the search.
 * \param radius The radius of the search area in meters.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestLocationsOnRoute:(NMARoute *)route
                     withRadius:(NSUInteger)radius
                          layer:(NSUInteger)layerID
                     parameters:(NMACustomLocationParameters *)parameters
                     completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom locations that are on a given layer.
 *
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestLocationsWithLayer:(NSUInteger)layerID
                       parameters:(NMACustomLocationParameters *)parameters
                       completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom geometries that are inside a geo bounding box.
 *
 * \param boundingBox The %NMAGeoBoundingBox inside which the search should be performed.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestGeometriesInGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
                                withLayer:(NSUInteger)layerID
                               parameters:(NMACustomLocationParameters *)parameters
                               completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for custom geometries that intersect with the given geo coordinates.
 *
 * \param geoCoordinates The %NMAGeoCoordinates against which the intersection should be checked.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestGeometriesIntersectingCoordinates:(NMAGeoCoordinates *)geoCoordinates
                                       withLayer:(NSUInteger)layerID
                                      parameters:(NMACustomLocationParameters *)parameters
                                      completion:(NMACustomLocationCompletionBlock)completion;

/**
 * Requests for a custom geometry with the specified id.
 *
 * \param geometryId The id of the requested geometry.
 * \param layerID The layer in which to search.
 * \param parameters Optional parameters to filter the search results. If nil is passed,
 *                   a default search is performed.
 * \param completion The completion block to handle the results of the request.
 */
- (void)requestGeometryWithId:(NSUInteger)geometryId
                    withLayer:(NSUInteger)layerID
                   parameters:(NMACustomLocationParameters *)parameters
                   completion:(NMACustomLocationCompletionBlock)completion;

@end
/**  @}  */
