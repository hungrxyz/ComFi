/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAVenue3dService;
@class NMAVenue3dVenue;
@class NMAVenue3dVenueInfo;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * Represents values that describe the initialization status of the {@link NMAVenue3dService}
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dServiceInitializationStatus) {
    /**
     * The venue service is ready to be used.
     */
    NMAVenue3dServiceInitializationStatusOnlineSuccess,

    /**
     * The NMAVenue3dService failed to authenticate on the server, but
     * successfully initialized previously cached data.
     */
    NMAVenue3dServiceInitializationStatusOfflineSuccess,

    /**
     * The NMAVenue3dService failed to authenticate on the server and
     * there is no previously cached data.
     */
    NMAVenue3dServiceInitializationStatusAuthenticationFailed,

    /**
     * The NMAVenue3dService failed to initialize styles.
     */
    NMAVenue3dServiceInitializationStatusStyleInitializationFailed,

    /**
     * The NMAVenue3dService failed to initialize icons.
     */
    NMAVenue3dServiceInitializationStatusIconInitializationFailed,

    /**
     * The NMAVenue3dService failed to initialize index file.
     */
    NMAVenue3dServiceInitializationStatusIndexInitializationFailed,

    /**
     * The initialization wasn't started.
     */
    NMAVenue3dServiceInitializationStatusNotStarted,

    /**
     * The initialization in progress.
     */
    NMAVenue3dServiceInitializationStatusInProgress
};

/**
 * \brief Represents a interface that offers listeners and callback methods related to
 * getting venue.
 *
 * \note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dServiceListener<NSObject>

@optional

/**
 * On NMAVenue3dService initialization callback.
 *
 * @param venueService
 *            The {@link NMAVenue3dService} object initialized.
 * @param result
 *            The {@link NMAVenue3dServiceInitializationStatus} enum which represent current status of
 *            the service.
 */
- (void)venueServiceDidInitialize:(NMAVenue3dService *)venueService withResult:(NMAVenue3dServiceInitializationStatus)result;

/**
 * On NMAVenue3dVenue loading completed callback.
 *
 * @param venueService
 *            The {@link NMAVenue3dService} object returns venue.
 * @param venue
 *            The loaded {@link NMAVenue3dVenue}.
 */
- (void)venueService:(NMAVenue3dService *)venueService didGetVenue:(NMAVenue3dVenue *)venue;

@end


/**
 * \class NMAVenue3dService NMAVenue3dService.h "NMAVenue3dService.h"
 *
 * \brief NMAVenue3dService offers methods to search for venues and to get NMAVenue3dVenue objects based on search.
 *
 * Use of this object does not necessitate {@link NMAMapView} involvement.
 * <p>
 * This class can not be instantiated directly. Use \link NMAVenue3dService::sharedVenueService\endlink method
 * to get the singeton instance of the class instead.
 * </p>
 */
@interface NMAVenue3dService : NSObject

/**
 * \brief Returns the %NMAVenue3dService singleton instance.
 *
 * \note Use this method to obtain a %NMAVenue3dService instance. Do not call
 * init directly.
 *
 */
+ (instancetype)sharedVenueService;

/**
 * The venue service initialization status.
 */
@property (nonatomic, readonly) NMAVenue3dServiceInitializationStatus initializationStatus;

/**
 * Sets a HERE account token. In case of valid token and if private content
 * is used, <code>VenueService</code> will be using private bucket of a HERE account
 * instead of private bucket of the app.
 *
 * @param token a HERE account token.
 */
- (void)setHereAccountToken:(NSString *)token;

/**
 * Add a listener to the venue service. The listener must implement the NMAVenue3dServiceListener protocol.
 * The listener monitors the venue service initialization status and a venue loaded completion event.
 *
 * @param listener the NMAVenue3dServiceListener object to be added
 *
 * \sa NMAVenue3dServiceListener
 */
- (void)addListener:(id<NMAVenue3dServiceListener>)listener;

/**
 * Remove a listener from the venue service. The listener must implement the NMAVenue3dServiceListener protocol.
 * The listener monitors the venue service initialization status and a venue loaded completion event.
 *
 * @param listener the NMAVenue3dServiceListener object to be removed.
 */
- (void)removeListener:(id<NMAVenue3dServiceListener>)listener;

/**
 *  Sets a value indicating whether the HERE SDK or the HERE private 3D venue content is
 *  to be used. The HERE SDK content is used by default.
 *  <p>
 *  This method needs to be called before {@link NMAVenue3dService::start NMAVenue3DService::start}
 *  or {@link NMAVenue3dMapLayer::start NMAVenue3dMapLayer::start}.
 *  </p>
 *
 * @param usePrivateContent
 *        YES indicates that the HERE private 3D venue content is to be used,
 *        otherwise the HERE SDK content is used.
 */
- (void)setPrivateContent:(BOOL)usePrivateContent;

/**
 * Defines whether a normal or a test backend is used. The normal backend is used by default.
 * <p>
 * This method needs to be called before starting VenueMapLayer with \link NMAVenue3dMapLayer::start\endlink.
 * </p>
 *
 * @param useTestEnv  if YES, test environment is set, otherwise normal environment is used.
 */
- (void)setTestEnv:(BOOL)useTestEnv;

/**
 * Starts NMAVenue3dService asynchronously. The method will do nothing if NMAVenue3dService is already
 * initialized with status {@link NMAVenue3dServiceInitializationStatusOnlineSuccess}.
 * <p>
 * An initialization status is returned to objects registered as {@link NMAVenue3dServiceListener} to NMAVenue3dService.
 * </p>
 */
- (void)start;

/**
 * Asynchronously gets the {@link NMAVenue3dVenue} object that is specified by the given {@link NMAVenue3dVenueInfo} object.
 * <p>
 * Venue service listeners will be notified when the venue is loaded via the [NMAVenue3dServiceListener venueService:didGetVenue] method.
 * </p>
 *
 * \param venueInfo The %NMAVenue3dVenueInfo object specifying venue to be get.
 * \sa NMAVenue3dVenueInfo:
 */
- (void)getVenueWithInfo:(NMAVenue3dVenueInfo *)venueInfo;

/**
 * Asynchronously gets the {@link NMAVenue3dVenue} objects that are specified by the given list of {@link NMAVenue3dVenueInfo} objects.
 * <p>
 * Venue service listeners will be notified when a venue is loaded via the [NMAVenue3dServiceListener venueService:didGetVenue] method.
 * </p>
 *
 * \param venueInfoArray An array of %NMAVenue3dVenueInfo objects specifying venues to get.
 * \sa NMAVenue3dVenueInfo:
 */
- (void)getVenuesWithInfoArray:(NSArray *)venueInfoArray;

/**
 * Gets venue info object for the venue identifier.
 *
 * \param venueId venue id
 * \return Venue info object for the venue identifier
 *
 * \sa \link getVenueWithInfo:\endlink
 */
- (NMAVenue3dVenueInfo *)venueWithId:(NSString *)venueId;

/**
 * Searches for venues inside the given <code>NMAGeoBoundingBox</code>.
 *
 * \param boundingBox The area in which to search for venues.
 * \return An array of NMAVenue3dVenueInfo objects representing the venues found inside the specified area.
 *
 * \sa NMAVenue3dVenueInfo
 */
- (NSArray *)venuesInGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox;

/**
 * Searches for venues at the given <code>NMAGeoCoordinates</code>.
 *
 * \param coordinates The location around which to search for venues.
 * \return An array of NMAVenue3dVenueInfo objects representing the venues found near the specified location.
 *
 * \sa NMAVenue3dVenueInfo
 */
- (NSArray *)venuesAtGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Searches for a venue closest to the given <code>NMAGeoCoordinates</code>.
 *
 * \param coordinates The location around which to search for venues.
 *
 * \return The closet NMAVenue3dVenueInfo object to the specified point or nil if there is no any.
 *
 * \sa NMAVenue3dVenueInfo
 */
- (NMAVenue3dVenueInfo *)venueAtGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Searches for venues near the given <code>NMAGeoCoordinates</code>.
 *
 * \param coordinates The location around which to search for venues.
 * @param radius     The radius in meters where to search venues.
 * \return The array of NMAVenue3dVenueInfo objects found near the specified point
 *
 * \sa NMAVenue3dVenueInfo
 */
- (NSArray *)venuesAtGeoCoordinates:(NMAGeoCoordinates *)coordinates radius:(float)radius;

/**
 * Searches for a venue closest to the given <code>NMAGeoCoordinates</code> within a radius.
 *
 * \param coordinates The location around which to search for venues.
 * \param radius      The radius in meters where to search venues.
 *
 * \return The closet NMAVenue3dVenueInfo object to the specified point or nil if there is no any
 *
 * \sa NMAVenue3dVenueInfo
 */
- (NMAVenue3dVenueInfo *)venueAtGeoCoordinates:(NMAGeoCoordinates *)coordinates radius:(float)radius;

@end
/** @} */
