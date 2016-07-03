/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAGeoCoordinates;
@class NMAMapView;
@class NMAVenue3dAnimationController;
@class NMAVenue3dController;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;
@class NMAVenue3dMapLayer;
@class NMAVenue3dRoutingController;
@class NMAVenue3dVenue;
@class NMAVenue3dVenueInfo;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \brief Represents values that describe the source which has called deselection
 * of the venue.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dDeselectEvent) {
    /**
     * Map was moved out from the venue viewport.
     */
    NMAVenueDeselectEventMapMoved,

    /**
     * Map was zoom out to the specific zoom level where venue shouldn't be
     * shown and venue fully in view port.
     */
    NMAVenueDeselectEventMapZoomedOut,

    /**
     * Map was tapped outside the venue.
     */
    NMAVenueDeselectEventMapTappedOutside,

    /**
     * The NMAVenue3dMapLayer was switched off.
     */
    NMAVenueDeselectEventLayerDisabled,

    /**
     * Other venue was selected.
     */
    NMAVenueDeselectEventSelectedOther,

    /**
     * Venue was deselected manually through API.
     */
    NMAVenueDeselectEventManual
};

/**
 * Represents a delegate that offers listeners and callback methods related to
 * venue map layer.
 *
 * \note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dMapLayerDelegate<NSObject>

@optional

/**
 * This callback method is triggered when a venue is tapped.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with tapped venue.
 * @param venue
 *            The {@link NMAVenue3dVenue} with tapped venue.
 * @param point screen position on the tapped point
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
          didTapVenue:(NMAVenue3dVenue *)venue
              atPoint:(CGPoint)point;

/**
 * This callback method is triggered when a venue is selected.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with selected venue.
 * @param venue
 *            The selected {@link NMAVenue3dVenue}.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
       didSelectVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when a venue is deselected.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with deselected venue.
 * @param venue
 *            The deselected {@link NMAVenue3dVenue}.
 * @param event
 *            The event which has called deselection of the venue.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
     didDeselectVenue:(NMAVenue3dVenue *)venue
            withEvent:(NMAVenue3dDeselectEvent)event;

/**
 * This callback method is triggered when a space is tapped.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with selected space.
 * @param space
 *            The selected {@link NMAVenue3dSpace}.
 * @param venue
 *            The {@link NMAVenue3dVenue} with selected space.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
       didSelectSpace:(NMAVenue3dSpace *)space
              inVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when a space is deselected.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with deselected space.
 * @param space
 *            The deselected {@link NMAVenue3dSpace}.
 * @param venue
 *            The {@link NMAVenue3dVenue} with deselected space.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
     didDeselectSpace:(NMAVenue3dSpace *)space
              inVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when a floor is changed.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} where floor is changed.
 * @param oldLevel
 *            The previously selected {@link NMAVenue3dLevel}.
 * @param newLevel
 *            The currently selected {@link NMAVenue3dLevel}.
 * @param venue
 *            The {@link NMAVenue3dVenue} where floor is changed.
 */
- (void) venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
    didChangeFromLevel:(NMAVenue3dLevel *)oldLevel
               toLevel:(NMAVenue3dLevel *)newLevel
               inVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when a venue becomes visible in the triggering area
 * The triggering area is centered to the viewport. The width of the triggering area is two-thirds of the map width
 * and the height is the same as the width.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with venue visible in viewport.
 * @param venue
 *            The visible venue {@link NMAVenue3dVenue}.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
         didShowVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when when a venue disappears from the triggering area.
 * The triggering area is centered to the viewport. The width of the  triggering area is two-thirds of the map width
 * and the height is the same as the width.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with venue visible in viewport.
 * @param venue
 *            The hidden venue {@link NMAVenue3dVenue}.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
         didHideVenue:(NMAVenue3dVenue *)venue;

/**
 * This callback method is triggered when NMAVenue3dMapLayer::start completes.
 *
 * @param venueMapLayer
 *            The venue map layer {@link NMAVenue3dMapLayer} started.
 */
- (void)venueMapLayerDidStart:(NMAVenue3dMapLayer *)venueMapLayer;

@end

/**
 * Represents a delegate for Venue Zoom notifications.
 *
 * \note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dVenueZoomDelegate<NSObject>

/**
 * This callback method is triggered when Venue Zoom is activated or deactivated.
 *
 * @param venueMapLayer
 *            The {@link NMAVenue3dMapLayer} with the venue where the event happens.
 *
 * @param venue
 *            The {@link NMAVenue3dVenue} where Venue Zoom is activated or deactivated.
 *
 * @param active
 *            Indicates if Venue Zoom is activated or deactivated.
 */
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer didUpdateVenueZoomInVenue:(NMAVenue3dVenue *)venue
            withValue:(bool)active;

@optional
@end


/**
 * \brief NMAVenue3dMapLayer provides a map with indoor venue maps.
 *
 * When the %NMAVenue3dMapLayer is started, venues such as shopping malls and airports can be seen on
 * the map as interactive 3D models. Also spaces inside venues and access information like entrances can be seen.
 * <p>
 * After getting a %NMAVenue3dMapLayer object, NMAVenue3dMapLayer::delegate need to be set in order to receive layer events,
 * and the layer must be activated by calling {@link NMAVenue3dMapLayer::start}.
 * </p>
 * <p>
 * NMAVenue3dMapLayer is an add-on to the base map functionality with its own content loading and cache.
 * For this reason in certain situations there may be a small delay before a venue can be seen on the map
 * because if it is not already in the cache it needs to be downloaded separately.
 * </p>
 *
 * \note This class can not be instantiated directly. NMAVenue3dMapLayer object can be fetched via
 * NMAMapView::venue3dMapLayer
 *
 */
@interface NMAVenue3dMapLayer : NSObject

/**
 * An event handler for the NMAVenue3dMapLayer.
 * <p>
 * An object may be installed as the NMAVenue3dMapLayer delegate in order to respond
 * to certain NMAVenue3dMapLayer events, such as venue selection or floor changing. See the
 * NMAVenue3dMapLayerDelegate protocol for the full list of events.
 * </p>
 */
@property (nonatomic, weak) id<NMAVenue3dMapLayerDelegate> delegate;

/**
 * An event handler for the Venue Zoom events.
 * <p>
 * This delegate gets notified when Venue Zoom is activated or deactivated.
 * </p>
 */
@property (nonatomic, weak) id<NMAVenue3dVenueZoomDelegate> venueZoomDelegate;

/**
 * NMAVenue3dController object of the selected venue or nil if there is no selected venue.
 */
@property (nonatomic, readonly) NMAVenue3dController *venueController;


/**
 * NMAVenue3dRoutingController object which can be used to calculate and show route in which at least one end is inside a venue.
 */
@property (nonatomic, readonly) NMAVenue3dRoutingController *venueRoutingController;

/**
 * Controls whether the venue map layer is visible.
 *
 * The default value is YES. Updating visible state is done in the background, so changes to this property
 * may not be immediately reflected in its value.
 *
 * \note Changes to this property will deselect selected venues. *
 */
@property (nonatomic) BOOL visible;

/**
 * The flag to indicates whether or not to check if the venue is visisble in current map view port.
 *
 * venueMapLayer:didShowVenue: or venueMapLayer:didHideVenue: will be called back to the delegate {@link NMAVenue3dMapLayerDelegate}
 * if venue visiblity is changed in the current map view port.
 *
 * \note By default, the value is NO
 */
@property (nonatomic) BOOL shouldCheckVenuesInViewport;

/**
 * Controls whether venue floor changes are animated.
 *
 * The default value is NO.
 *
 */
@property (nonatomic) BOOL animatesFloorChange;

/**
 * Controls whether venue selection is animated.
 *
 * The default value is NO.
 *
 */
@property (nonatomic) BOOL animatesVenueSelection;

/**
 * The margin for current {@link NMAVenue3dVenue} view in screen points.
 * The default is (0, 0, 0, 0).
 */
@property (nonatomic) UIEdgeInsets margins;

/**
 * Start {@link NMAVenue3dService} asynchronously.
 *
 * \note The venue service must be started before the venue map layer can be used.
 */
- (void)start;

/**
 * Returns the {@link NMAVenue3dController} of the given venue.
 *
 * @param venue {@link NMAVenue3dVenue} object.
 * @return The {@link NMAVenue3dController} of the venue or nil if there is no such venue on the map.
 */
- (NMAVenue3dController *)controllerForVenue:(NMAVenue3dVenue *)venue;

/**
 * Select a NMAVenue3dVenue in a 3D view mode.
 * <p>
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method opens a previous donwloaded venue.
 * \link NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:\endlink
 * is called when the venue has been opened.
 * </p>
 *
 * @param venue The {@link NMAVenue3dVenue} to be selected.
 */
- (void)selectVenue:(NMAVenue3dVenue *)venue;

/**
 * Select a NMAVenue3dVenue.
 * <p>
 * Asynchronously opens the {@link NMAVenue3dVenue} identified by given venue id in a 3D view mode.
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method is asynchronous, because it involves venue downloading if the venue is not already
 * in the cache.
 * \link NMAVenue3dServiceListener::venueService:didGetVenue:\endlink
 * callback method is
 * called when the venue has been downloaded.
 * \link NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:\endlink
 * callback method is called when the venue has been opened.
 * </p>
 *
 * @param venueId The identifier of the venue to be opened.
 * @return The {@link NMAVenue3dVenueInfo} for the venue if a venue for the given identifier exists, otherwise nil.
 *
 */
- (NMAVenue3dVenueInfo *)selectVenueWithVenueId:(NSString *)venueId;

/**
 * Select a NMAVenue3dVenue.
 * <p>
 * Asynchronously opens the {@link NMAVenue3dVenue} identified by given venue id and
 * {@link NMAVenue3dSpace} identified by the given space id in a 3D view mode .
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method is asynchronous, because it involves venue downloading if the venue is not already
 * in the cache.
 * \link NMAVenue3dServiceListener::venueService:didGetVenue:\endlink
 * callback method is called when the venue has been downloaded.
 * \link NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:\endlink
 * callback method is called when the venue has been opened.
 * </p>
 *
 * @param venueId The identifier of the venue to be opened.
 * @param spaceId The identifier of the space to be opened. If nil, only the venue will be opened.
 * @return The {@link NMAVenue3dVenueInfo} for the venue if a venue for the given identifier exists, otherwise nil.
 *
 */
- (NMAVenue3dVenueInfo *)selectVenueWithVenueId:(NSString *)venueId spaceId:(NSString *)spaceId;

/**
 * Cancels ongoing venue selections.
 *
 * @return YES if a venue selection was cancelled, NO if there was no selection ongoing.
 */
- (BOOL)cancelVenueSelection;

/**
 * Deselect and close the current NMAVenue3dVenue.
 */
- (void)deselectVenue;

/**
 * Check if the venue layer has loaded and displayed a specific venue on the map.
 *
 * @param venueId  A venue identifier to be checked.
 *
 * @return YES if the venue is visible, NO if it is not.
 *
 * @sa \link NMAVenue3dVenue::uniqueId\endlink
 */
- (BOOL)isVenueVisible:(NSString *)venueId;

/**
 * Enables or disables Venue Zoom. Venue Zoom allows bigger zoom levels for opened venues.
 * By default Venue Zoom is not used.
 * In order to view a particular venue in Venue Zoom mode, use
 * {@link NMAVenue3dController::useVenueZoom:}.
 *
 * @param enable
 *            if <code>true</code>, Venue Zoom is enabled, otherwise not.
 *
 */
- (void)enableVenueZoom:(bool)enable;

/**
 * Returns boolean value indicating whether Venue Zoom is enabled or not.
 *
 * @return <code>true</code> if Venue Zoom is enabled, otherwise <code>false</code>.
 *
 */
- (BOOL)isVenueZoomEnabled;

@end
/** @} */
