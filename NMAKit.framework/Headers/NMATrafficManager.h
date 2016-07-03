/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;
@class NMARoute;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * \brief Error codes indicating the result of a traffic event request.
 */
typedef NS_ENUM(NSInteger, NMATrafficRequestError) {
    /** No error. */
    NMATrafficRequestErrorNone,
    /** Invalid parameters were given to the request, e.g. a nil route. */
    NMATrafficRequestErrorInvalidParameters,
    /** The traffic request operation cannot be performed at this time. */
    NMATrafficRequestErrorInvalidOperation,
    /** An unknown error occurred. */
    NMATrafficRequestErrorUnknown
};

/**
 * \brief A completion block used to handle the result of a traffic event request.
 *
 * \param events An NSArray of NMATrafficEvent objects
 * \param error NMATrafficRequestErrorNone if the request was successful, otherwise
 *              an error code indicating the nature of the failure.
 */
typedef void (^NMATrafficCompletionBlock)(NSArray *events, NMATrafficRequestError error);

/**
 * \brief An interface for responding to traffic events sent by the
 * NMATrafficManager.
 */
@protocol NMATrafficManagerObserver<NSObject>

@required

/*
 * \brief Called when traffic data is updated.
 *
 * \deprecated This callback is deprecated as of HERE SDK 3.1. It may be called in scenarios in
 * which traffic data is not updated.
 */
- (void)trafficDataDidUpdate DEPRECATED_ATTRIBUTE;

/*
 * \brief Called when traffic data request is finished.
 */
- (void)trafficDataDidFinish;

@end


/**
 * \class NMATrafficManager NMATrafficManager.h "NMATrafficManager.h"
 * \brief Manages traffic services for the NMA SDK.
 *
 * <p>
 * This is a singleton class and thus should never be retained, released, or
 * instantiated. The singleton instance is accessed via the
 * sharedTrafficManager method.
 * </p>
 */
@interface NMATrafficManager : NSObject

/**
 * \brief Returns the NMATrafficManager singleton instance.
 *
 * \note Use this method to obtain a NMATrafficManager instance. Do not call
 * init directly.
 *
 * \return shared NMATrafficManager instance
 */
+ (NMATrafficManager *)sharedTrafficManager;

/**
 * \brief Sets the interval at which traffic data is refreshed.
 *
 * This method MUST be called before the HERE SDK uses any traffic in the current app session - e.g.
 * before sharedTrafficManager is called, before traffic is enabled on an NMAMapView and before routing
 * with traffic is performed. If this method is called too late then NO will be returned.
 *
 * Traffic refresh interval defaults to a value determined by the HERE traffic servers.
 *
 * \param refreshInterval the refresh interval in seconds. Must be within the range 60..300.
 * \return YES if the interval was set successfully, NO if traffic is already initialized or if
 * refreshInterval is outside the valid range.
 */
+ (BOOL)setRefreshInterval:(NSTimeInterval)refreshInterval;

/**
 * \brief Add a NMATrafficManagerObserver
 *
 * \param observer to be added
 */
- (void)addObserver:(id<NMATrafficManagerObserver>)observer;

/**
 * \brief Remove a NMATrafficManagerObserver
 *
 * \param observer to be removed
 */
- (void)removeObserver:(id<NMATrafficManagerObserver>)observer;

/*!
 * \brief Request traffic information for given route.
 *
 * This method downloads the latest traffic information available along the specified
 * route, so a data connection is required. Once downloaded, the traffic information
 * can be viewed on a map or individual traffic events can be retrieved via the
 * getTrafficEventsOnRoute:withCompletion and getTrafficEventsOnRouteElements:withCompletion
 * methods.
 *
 * This method returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \param route The route on which to query traffic events.
 * \return requestId A request identifier if traffic is successfully requested,
 *                   nil if the request fails.
 *
 * \note Traffic requests may fail if too many are made in a short period of time.
 */
- (NSNumber *)requestTrafficOnRoute:(NMARoute *)route;

/*!
 * \brief Cancel a traffic request.
 *
 * \param requestId id of the traffic request.
 */
- (void)cancelRequest:(NSNumber *)requestId;

/**
 * \brief Retrieve the traffic events on a given route.
 *
 * This method retrieves traffic events for a route that have been previously
 * downloaded, for example by calling requestTrafficOnRoute or displaying the
 * traffic on a map.
 *
 * The results are delivered asynchronously via an NMATrafficCompletionBlock.
 * The block will contain a list of NMATrafficEvent objects if the request was
 * successful, or a nil array and an NMATrafficRequestError code if the request
 * failed.
 *
 * For example:
 *
 *  [[NMATrafficManager sharedTrafficManager] requestTrafficOnRoute:myRoute];
 *
 *  (...wait for the trafficDataDidFinish method of NMATrafficManagerObserver)
 *
 *  - (void)trafficDataDidFinish {
 *      [[NMATrafficManager sharedTrafficManager] getTrafficEventsOnRoute:myRoute
 *          withCompletion: ^(NSArray *eventList, NMATrafficRequestError error) {
 *              if (error == NMATrafficRequestErrorNone) {
 *                  for (NMATrafficEvent *event in eventList) {
 *                      // do something with the traffic event
 *                  }
 *              }
 *          }];
 * }
 */
- (void)getTrafficEventsOnRoute:(NMARoute *)route
                 withCompletion:(NMATrafficCompletionBlock)completionBlock;

/**
 * \brief Retrieve the traffic events for a given list of route elements.
 *
 * The results are delivered asynchronously via an NMATrafficCompletionBlock.
 * The block will contain a list of NMATrafficEvent objects if the request was
 * successful, or a nil array and an NMATrafficRequestError code if the request
 * failed.
 *
 * \sa getTrafficEventsOnRoute:withCompletion:
 */
- (void)getTrafficEventsOnRouteElements:(NSArray *)routeElements
                         withCompletion:(NMATrafficCompletionBlock)completionBlock;

@end
/** @}  */
