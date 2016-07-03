/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>
#import "NMAStreetLevelOrientation.h"
#import "NMATypes.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 *
 * The Street Level group provides classes, protocols, and enumerations
 * that allow you to display an interactive Street Level view.
 * It also provides functionality that allows your application to create
 * and add Street Level content.
 * Some key classes in this group are:
 * {@link NMAStreetLevelView}, {@link NMAStreetLevelCoverageResult},
 * and {@link NMAStreetLevelObject}.
 *
 * @{
 *
 * @product nlp-hybrid-plus nlp-plus
 */

@class NMAGeoCoordinates;
@class NMAImage;
@class NMAStreetLevelObject;
@class NMAStreetLevelView;
@class NMAViewObject;
@class NMAStreetLevelLink;
@class NMAStreetLevelCoverageResult;

/**
 * Result block called when checkCoverageAtGeoCoordinates:withRadius:completion: completes.
 *
 * \param coverageResult NMAStreetLevelCoverageResult containing the coverage details
 *
 * \note This block will be called on the main thread.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef void (^NMAStreetLevelCoverageCompletionBlock)(NMAStreetLevelCoverageResult *coverageResult);

/**
 * The types of touch gesture that can be performed on an NMAStreetLevelView.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSInteger, NMAStreetLevelGestureType) {
    /** \brief Tap Gesture - By default this attempts to select an NMAStreetLevelObject within the view */
    NMAStreetLevelGestureTypeTap              = 1 << 0,
    /** \brief Double Tap Gesture - By default this does nothing */
    NMAStreetLevelGestureTypeDoubleTap        = 1 << 1,
    /** \brief Pinch Gesture - By default this zooms the view */
    NMAStreetLevelGestureTypePinch            = 1 << 2,
    /** \brief Pan Gesture - By default this rotates the view */
    NMAStreetLevelGestureTypePan              = 1 << 3,
    /** \brief All gestures  */
    NMAStreetLevelGestureTypeAll              = 0xFF
};

/**
 * String Identifiers to support localizing Street Level View UI elements
 *
 * The street level imagery issue reporting UI is the only UI that currently requires
 * localized strings
 *
 * \see NMAStreetLevelLocalizationDelegate
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelLocalizedStringId) {
    /** \brief Report an Issue */
    NMAStreetLevelLocalizedStringIdReportAnIssue = 0
};


/**
 * \ingroup group NMA_StreetLevel NMA Street Level Group
 *
 * NMAStreetLevelView Localization Delegate.
 *
 * This delegate may be used to override the UI strings presented by the standard Here SDK
 * Street Level View UIViews.
 *
 * This is provided to allow the Street Level View "Report an Issue" UI flow to be localized
 * to the languages your app supports. If you do not implement this protocol the Street View
 * "Report an Issue" UI flow will be presented in English only.
 *
 * @see NMAStreetLevelLocalizedStringId for a list of all strings that may be localized
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@protocol NMAStreetLevelLocalizationDelegate<NSObject>
@optional

/**
 * A callback used to provide NMAStreetLevelView with a localized string
 *
 * You should use this callback to provide localized strings for the languages your app
 * supports.
 *
 * \param view NMAStreetLevelView requesting the localized string
 * \param localizedStringId NMAStreetLevelLocalizedStringId representing the string to be
 *        localized.
 * \return String localized to the current language. Return nil or an empty string if
 *         no localization is available (The UI will display English in this case).
 */
- (NSString *) streetLevelView:(NMAStreetLevelView *)view
    localizedStringForStringId:(NMAStreetLevelLocalizedStringId)localizedStringId;
@end


/**
 * NMAStreetLevelView Delegate
 *
 * A delegate that provides callback methods related to visible changes in the street level view
 * resulting from user interaction and programmatic state changes.
 *
 * Methods of this protocol are called on the main queue.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@protocol NMAStreetLevelViewDelegate<NSObject>
@optional

/**
 * A callback indicating that the NMAStreetLevelView is attempting to move to a different
 * section.
 *
 * This callback will occur as the result of a programmatic moveTo... method call or as the
 * result of the using tapping a navigation link within the the street view.
 *
 * \param view NMAStreetLevelView that is attempting to move to a new section
 * \param geoCoordinates NMAGeoCoordinates of the move request
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
             willMoveTo:(NMAGeoCoordinates *)geoCoordinates;

/**
 * A callback indicating that NMAStreetLevelView moved to a different section.
 *
 * \note If a moveTo request is made whilst a previous moveTo request is outstanding the first
 * request may be disregarded. Regardless, this method will only be called once to reflect the final
 * state of multiple competing move requests.
 *
 * \param view NMAStreetLevelView that has moved to a different section is attempting to move to a
 *             new section
 * \param geoCoordinates NMAGeoCoordinates of the center of the section that has been moved to.
 *                       Undefined if success == NO.
 * \param success YES if the street view has moved to a new section. NO if the move failed.
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
              didMoveTo:(NMAGeoCoordinates *)geoCoordinates
            withSuccess:(BOOL)success;

/**
 * A callback indicating that the user tapped on a NMAStreetLevelLink, use this callback
 * to customize the default link handling behaviour.
 *
 * Returning YES from this method will result in the default link handling behaviour which is to move
 * to the street level section represented by the link (streetLevelView:willMoveTo: will be called).
 *
 * Returning NO will result in no further handling of the link.
 *
 * See [NMAStreetLevelView navigationLinksVisible].
 *
 * \note If a link is tapped whilst a previous moveTo request is outstanding the first
 * request may be disregarded.
 *
 * \param view NMAStreetLevelView in which the link was tapped.
 * \param link NMAStreetLevelLink representing the link that was tapped.
 * \return YES for default link handling. NO otherwise.
 */
- (BOOL)streetLevelView:(NMAStreetLevelView *)view
       shouldMoveToLink:(NMAStreetLevelLink *)link;

/**
 * A callback indicating that NMAStreetLevelView camera will zoom.
 *
 * \param view NMAStreetLevelView being zoomed
 * \param zoomLevel current camera zoom level
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
           willZoomFrom:(float)zoomLevel;

/**
 * A callback indicating that NMAStreetLevelView camera did zoom.
 *
 * \param view NMAStreetLevelView being zoomed
 * \param zoomLevel new camera zoom level
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
              didZoomTo:(float)zoomLevel;

/**
 * A callback indicating that NMAStreetLevelView camera will change orientation.
 *
 * \param view NMAStreetLevelView changing orientation
 * \param orientation current camera orientation
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
         willOrientFrom:(NMAStreetLevelOrientation)orientation;

/**
 * A callback indicating that NMAStreetLevelView camera did change orientation.
 *
 * \param view NMAStreetLevelView changing orientation
 * \param orientation new camera orientation
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
            didOrientTo:(NMAStreetLevelOrientation)orientation;

/**
 * A callback indicating that NMAStreetLevelView camera position changed.
 *
 * This callback typically occurs when moving between sections with animation. The
 * camera transitions from one section next to the next.
 *
 * \param view The NMAStreetLevelView changing position
 * \param position The new camera geo position
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
    didChangePositionTo:(NMAGeoCoordinates *)position;

/**
 * A callback indicating that one or more NMAViewObject objects have been selected.
 *
 * The following objects may be selected by the user:
 * <ul>
 * <li>
 * NMAStreetLevelBuilding  (NMAProxyObject)
 * </li>
 * <li>
 * NMAStreetLevelIcon      (NMAUserObject)
 * </li>
 * <li>
 * NMAStreetLevelBillboard (NMAUserObject)
 * </li>
 * <li>
 * NMAStreetLevelRoute     (NMAUserObject)
 * </li>
 * </ul>
 *
 * Proxy objects represent objects in the street view that pre-exist as part of the HERE street level
 * model data (e.g. buildings). Although you will receieve a different instance of a proxy object
 * everytime it is selected the entity it represents reamains the same - therefore proxy object
 * comparisons should be made using the base class [NMAViewObject isEqual] method instead of comparing
 * instance pointers.
 *
 * User objects are objects added via [NMAStreetLevelView addStreetLevelObject:]
 *
 * /note NMAStreetLevelLink objects are handled via [NMAStreetLevelViewDelegate streetLevelView:shouldMoveToLink:]
 *
 * \param view NMAStreetLevelView in which objects were selected
 * \param selectedObjects NSArray of NMAStreetLevelSelectedObject. NMAStreetLevelSelectedObject
 *                contains the actual NMAViewObject-derived object selected.
 */
- (void)streetLevelView:(NMAStreetLevelView *)view
       didSelectObjects:(NSArray *)selectedObjects;

@end


/**
 * NMAStreetLevelView Gesture Delegate allows you to override the default
 * NMAStreetLevelView gestures.
 *
 * To customize a gesture implement a callback of this protocol, perform custom actions in the
 * callback and then call [NMAStreetLevelView performDefaultActionForGestureRecognizer:] if
 * you wish the default gesture action to be performed.
 *
 * Methods of this protocol are called on the main queue.
 *
 * \note Overriding a gesture without calling performDefaultActionForGestureRecognizer: can
 * disable street view camera control, object selection, and automatic link handling gestures.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@protocol NMAStreetLevelGestureDelegate<NSObject>
@optional

/**
 * Callback notification of a tap event on a map.
 *
 * \param view The NMAStreetLevelView instance that received the gesture
 * \param recognizer The recognizer for the gesture
 */
- (void)        streetLevelView:(NMAStreetLevelView *)view
    didReceiveTapFromRecognizer:(UITapGestureRecognizer *)recognizer;

/**
 * Callback notification of a double tap event on a map.
 *
 * \param view The NMAStreetLevelView instance that received the gesture
 * \param recognizer The recognizer for the gesture
 */
- (void)              streetLevelView:(NMAStreetLevelView *)view
    didReceiveDoubleTapFromRecognizer:(UITapGestureRecognizer *)recognizer;

/**
 * Callback notification of a pinch-to-zoom event on a map.
 *
 * \param view The NMAStreetLevelView instance that received the gesture
 * \param recognizer The recognizer for the gesture
 */
- (void)          streetLevelView:(NMAStreetLevelView *)view
    didReceivePinchFromRecognizer:(UIPinchGestureRecognizer *)recognizer;

/**
 * Callback notification of a rotate event on a map.
 *
 * \param view The NMAStreetLevelView instance that received the gesture
 * \param recognizer The recognizer for the gesture
 */
- (void)        streetLevelView:(NMAStreetLevelView *)view
    didReceivePanFromRecognizer:(UIPanGestureRecognizer *)recognizer;

@end


/**
 * \class NMAStreetLevelView NMAStreetLevelView.h "NMAStreetLevelView.h"
 *
 * NMAStreetLevelView provides a 3D view of a street level scene that
 * the user can interact with.
 *
 * At any given time the view is presenting a "Street Level Section" (unless it
 * is currently animating between sections). Think of a city as being divided
 * into many sections. Each section has it's own imagery and buildings.
 *
 * To understand the properties that control what the user sees it is helpful to
 * imagine that the user is looking through the view finder of a camera that is
 * positioned in the center of the current street level section at
 * [NMAStreetLevelView position]. The camera may be pointed in different directions
 * by manipulating the [NMAStreetLevelView heading], [NMAStreetLevelView pitch]
 * and [NMAStreetLevelView zoom] properties.
 *
 * \note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelView : UIView

#pragma mark - Coverage Checking

/**
 * Checks if street level coverage is available at the specified coordinates
 * within the specified radius.
 *
 * Note that this method is asynchronous. When the result is available, the completion
 * block will be invoked on the main thread.
 *
 * This method do nothing if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \param coordinates The location at which to check street level coverage availability.
 * \param radius The maximum radius at which to search for coverage.
 * \param block The block to be invoked when request has completed
 */
+ (void)checkCoverageAtGeoCoordinates:(NMAGeoCoordinates *)coordinates
                           withRadius:(float)radius
                           completion:(NMAStreetLevelCoverageCompletionBlock)block;

#pragma mark - Street Level View Delegates

/**
 * An event handler for the NMAStreetLevelView.
 *
 * \note An object may be installed as the NMAStreetLevelView's delegate in order to respond
 * to certain street level view events, such as object selection or map movement. See the
 * NMAStreetLevelViewDelegate protocol for the full list of events.
 *
 */
@property (nonatomic, weak) id<NMAStreetLevelViewDelegate> delegate;

/**
 * The gesture handler for the %NMAMapView
 *
 * \note Replace this property with a custom class implementing the %NMAMapGesture
 * protocol to customize the gesture response behaviour of the map. Set to nil
 * to restore the original gesture behaviour.
 *
 */
@property (nonatomic, weak) id<NMAStreetLevelGestureDelegate> gestureDelegate;

@property (nonatomic, weak) id<NMAStreetLevelLocalizationDelegate> localizationDelegate;


#pragma mark - Street Level View Appearance

/**
 * Used to control street geometry visibility. Street geometry is the line
 * drawn on the top of road elements inside NMAStreetLevelView.
 */
@property (nonatomic) BOOL streetGeometryVisible;

/**
 * Used to control NMAStreetLevelLink visibility.
 *
 * If links are visible tapping them results in a call to
 * [NMAStreetLevelViewDelegate streetLevelView:shouldMoveToLink:] followed by a move to the
 * street level section the link represents.
 *
 * This property defaults to YES.
 */
@property (nonatomic) BOOL navigationLinksVisible;

/**
 * Set the navigation link images.
 *
 * \note By default links are rendered using arrow images.
 *
 * \param image NMAImage for the navigation link, pass nil for default images.
 * \param pressed pressed state that the image is used for.
 * \return YES if image was set successfully.
 */
- (BOOL)setNavigationLinkImage:(NMAImage *)image
               forPressedState:(BOOL)pressed;


#pragma mark - Street Level View State Information

/**
 * NSArray of NMAStreetLevelBuilding for all buildings in the current
 * street level section.
 *
 * This property will return nil if building information is not yet available.
 *
 * \note You should only access this property after a successful moveTo request and
 * not while the view is transitioning between street level sections.
 * See [NMAStreetLevelViewDelegate streetLevelView:didMoveTo:withSuccess:].
 */
@property (nonatomic, readonly) NSArray *buildings;

#pragma mark - Street Level View Issue Report Link Manipulation

/**
 * The issue reporting link position for the %NMAStreetLevelView.
 *
 * \note Valid values are NMALayoutPositionTopLeft, NMALayoutPositionTopRight,
 * NMALayoutPositionBottomLeft and NMALayoutPositionBottomRight.
 */
@property (nonatomic, readwrite) NMALayoutPosition reportLinkPosition;

/**
 * The distance in points that the report link will be from the top or
 *  bottom edge of the %NMAStreetLevelView.
 *
 * \note Values less than 5.0 will be ignored.
 */
@property (nonatomic, readwrite) float reportLinkVerticalMargin;

/**
 * The distance in points that the report link will be from the left or
 *  right edge of the %NMAStreetLevelView.
 *
 * \note Values less than 5.0 will be ignored.
 */
@property (nonatomic, readwrite) float reportLinkHorizontalMargin;

#pragma mark - Street Level Here Copyright Logo Manipulation

/**
 * The copyright logo position for the %NMAStreetLevelView.
 *
 * \note Valid values are NMALayoutPositionTopLeft, NMALayoutPositionTopCenter,
 * NMALayoutPositionTopRight, NMALayoutPositionBottomLeft, NMALayoutPositionBottomCenter,
 * and NMALayoutPositionBottomRight.
 */
@property (nonatomic) NMALayoutPosition copyrightLogoPosition;

/**
 * The distance in points that the copyright logo will be from the top or
 *  bottom edge of the %NMAStreetLevelView.
 *
 * \note Values less than 10.0 will be ignored.
 */
@property (nonatomic) float copyrightLogoVerticalMargin;

/**
 * The distance in points that the copyright logo will be from the left or
 *  right edge of the %NMAStreetLevelView.
 *
 * \note Values less than 10.0 will be ignored.
 *
 * \note Does not apply when the copyrightLogoPosition is NMALayoutPositionTopCenter
 * or NMALayoutPositionBottomCenter.
 */
@property (nonatomic) float copyrightLogoHorizontalMargin;


#pragma mark - Street Level View Camera Orientation and Zoom

/**
 * center position (camera) for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *position;

/**
 * The heading level for the NMAStreetLevelView.
 *
 * \note Values must be in the range [minimumHeading, maximumHeading].
 * Invalid values will be clamped to this range.
 *
 * \note Changes to this property will not be reflected until after the street level
 * has redrawn.
 */
@property (nonatomic) float heading;

/**
 * minimum heading level for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) float minimumHeading;

/**
 * maximum heading level for the %NMAStreetLevelView.
 */
@property (nonatomic, readonly) float maximumHeading;

/**
 * The pitch level for the NMAStreetLevelView.
 *
 * \note Values must be in the range [minimumPitch, maximumPitch].
 * Invalid values will be clamped to this range.
 *
 * \note Changes to this property will not be reflected until after the street level
 * has redrawn.
 */
@property (nonatomic) float pitch;

/**
 * Mimimum pitch level for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) float minimumPitch;

/**
 * Maximum pitch level for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) float maximumPitch;

/**
 * The zoom level for the NMAStreetLevelView.
 *
 * \note Values must be in the range [minimumZoom, maximumZoom].
 * Invalid values will be clamped to this range.
 *
 * \note Changes to this property will not be reflected until after the street level
 * has redrawn.
 */
@property (nonatomic) float zoom;

/**
 * minimum zoom level for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) float minimumZoom;

/**
 * maximum zoom level for the NMAStreetLevelView.
 */
@property (nonatomic, readonly) float maximumZoom;

/**
 * Programmatic rotating the camera orienation by screen point movement
 * in the current NMAStreetLevelView.
 *
 * \param from Screen Point to rotate from.
 * \param to Screen Point to rotate to.
 */
- (void)rotateFromScreenPoint:(CGPoint)from
                toScreenPoint:(CGPoint)to;


#pragma mark - Street Level View Gesture

/**
 * Enable one or more NMAStreetLevelView gestures.
 *
 * Note that all gestures are enabled by default.
 *
 * \param gestures A bit-mask combination of one or more
 *        NMAStreetLevelGestureType values
 *        (<code>NMAStreetLevelGestureTypeAll</code> enables all gestures).
 */
- (void)enableStreetLevelGestures:(NSUInteger)gestures;

/**
 * Disable one or more NMAStreetLevelView gestures.
 *
 * \param gestures A bit-mask combination of one or more NMAStreetLevelGestureType values.
 *
 * \note: Pass NMAStreetLevelGestureTypeAll to disable all gestures.
 */
- (void)disableStreetLevelGestures:(NSUInteger)gestures;

/**
 * Queries whether or not a gesture type is enabled on the NMAStreetLevelView.
 *
 * \param gesture The gesture type to query.
 * \return YES if the gesture type is enabled, NO if the gesture type is disabled.
 */
- (BOOL)isStreetLevelGestureEnabled:(NMAStreetLevelGestureType)gesture;

/**
 * Performs the default street level view action for a gesture recognizer. This method
 * can be called within an NMAStreetLevelGestureDelegate to have the street view provide it's
 * default behaviour in addition to any custom behaviour provided by the delegate.
 *
 * \param recognizer UIGestureRecognizer for which to perform an action
 */
- (void)performDefaultActionForGestureRecognizer:(UIGestureRecognizer *)recognizer;


#pragma mark - Moving Street Level View to a new Street Level Section

/**
 * Searches for the street level section closest to the geo coordinates within a
 * specified radius and, if a section is found, moves the the street view to that section.
 *
 * <p>[NMAStreetLevelViewDelegate streetLevelView:didMoveTo:withSuccess:] will report the
 * ultimate result of the move request.</p>
 *
 * \note Calling this method whilst a move request is still outstanding will effectively
 * cancel the current move request.
 *
 * \param geoCoordinates NMAGeoCoordinates for the center of the search radius.
 * \param radius Search radius in Meters.
 * \param animation Whether the street view will animate the transition between sections.
 * \param orientation new camera orientation if the move is successful.
 * \param zoom new camera zoom level if the move is successful.
 */
- (void)moveToSectionAtGeoCoordinates:(NMAGeoCoordinates *)geoCoordinates
                     withSearchRadius:(float)radius
                            animation:(BOOL)animation
                          orientation:(NMAStreetLevelOrientation)orientation
                                 zoom:(float)zoom;

/**
 * Searches for the street level section closest to the geo coordinates within a
 * specified radius and, if a section is found, moves the the street view to that section.
 *
 * <p>[NMAStreetLevelViewDelegate streetLevelView:didMoveTo:withSuccess:] will report the
 * ultimate result of the move request.</p>
 *
 * \note Calling this method whilst a move request is still outstanding will effectively
 * cancel the current move request.
 *
 * \param geoCoordinates NMAGeoCoordinates for the center of the search radius.
 * \param radius Search radius in Meters.
 * \param animation Whether the street view will animate the transition between sections.
 * \param cameraTarget The camera will be oriented to point to this coordinate if the move
 *                     is successful.
 * \param zoom new camera zoom level if the move is successful.
 */
- (void)moveToSectionAtGeoCoordinates:(NMAGeoCoordinates *)geoCoordinates
                     withSearchRadius:(float)radius
                            animation:(BOOL)animation
                         cameraTarget:(NMAGeoCoordinates *)cameraTarget
                                 zoom:(float)zoom;

/**
 * Cancels an outstanding "moveToSection" request and moves the street view back to the
 * previous street level section.
 *
 * <p>A typical use case for this method is to implement a user cancel or timeout if network
 * connectivity is lost DURING moving to a new section. Note that all moves will eventually
 * succeed/fail with a [NMAStreetLevelViewDelegate streetLevelView:didMoveTo:withSuccess:]
 * callback when network connectivity resumes.</p>
 *
 * <p>If there is no previous section (i.e. for a newly initialized street view) or if there is not
 * a currently outstanding move request then this method does nothing.</p>
 *
 * \note If a move has reached a certain point then cancellation is not possible and the view
 * will move to the new section regardless. Also note that calling cancel will not result in
 * [NMAStreetLevelViewDelegate streetLevelView:didMoveTo:withSuccess:] indicating that the move
 * failed - the view will successsfully move to the previous or next section.
 *
 * \param animation Whether the street view will animate the transition between sections.
 */
- (void)cancelMoveToSectionWithAnimation:(BOOL)animation;


#pragma mark - Street Level View Conversion Routines

/**
 * Converts a specifed on-screen point in the current NMAStreetLevelView
 * from a geo coordinates.
 *
 * \note This method will return unpredictable results if the geo coordinates supplied
 * are not be "visible" within the current street view. For example, if the coordinates
 * are behind the camera.
 *
 * \param geoCoordinates NMAGeoCoordinates to be converted.
 * \return The on-screen %CGPoint, or CGPoint.x = CGPoint.y = -CGFLOAT_MAX
 *         if the NMAGeoCoordinates object is either off-screen or nil
 */
- (CGPoint)screenPointFromGeoCoordinates:(NMAGeoCoordinates *)geoCoordinates;

/**
 * Converts a specifed on-screen point in the current NMAStreetLevelView
 * to a geo coordinates.
 *
 * \note Trying to convert a screen point that does not fall on a physical object in the
 * view will result in nil being returned. For example, trying to get geo coordinates for
 * points in the sky will result in nil.
 *
 * \param point A screen point to be converted.
 * \return NMAGeoCoordinates instance, or nil if a reasonble conversion could not
 *         be made.
 */
- (NMAGeoCoordinates *)geoCoordinatesFromScreenPoint:(CGPoint)point;

/**
 * Creates the camera orientation required to display given screen point in the
 * center of the street view.
 *
 * \param point Screen point to center the street at.
 * \return NMAStreetLevelOrientation camera orientation to display the the screen point
 *         in the center of the street view, or NMAStreetLevelOrientation::heading =
 *         NMAStreetLevelOrientation::pitch = -CGFLOAT_MAX if an error occurs.
 */
- (NMAStreetLevelOrientation)cameraOrientationFromScreenPoint:(CGPoint)point;


#pragma mark - Street Level Object Manipulation

/**
 * Retrieve all NMAViewObjects for the screen point
 *
 * \param point A screen point to be retrieved.
 * \return NSArray of NMAStreetLevelSelectedObject objects for this screen point.
 * The possible objects can contain at NMAStreetLevelSelectedObject from NSArray:
 * NMAStreetLevelBillboard, NMAStreetLevelBuilding,
 * NMAStreetLevelIcon, NMAStreetLevelLink, NMAStreetLevelRoute
 *
 */
- (NSArray *)streetLevelObjectsAtScreenPoint:(CGPoint)point;

/**
 * Adds a NMAStreetLevelObject to the NMAStreetLevelView.
 *
 * \param object NMAStreetLevelObject to add.
 * \return YES if the NMAStreetLevelObject was added successfully, NO otherwise
 *
 * \note Returns NO if the object has already been added (duplicates are not allowed).
 */
- (BOOL)addStreetLevelObject:(NMAStreetLevelObject *)object;

/**
 * Removes an existing %NMAStreetLevelObject from the %NMAStreetLevelView.
 *
 * \note The object will be removed asynchronously on the next pass of the street view render
 * loop. Therefore the object may still be present in the userObjects property when this
 * method returns.
 *
 * \param object NMAStreetLevelObject to remove.
 */
- (void)removeStreetLevelObject:(NMAStreetLevelObject *)object;

/**
 * Array of NMAStreetLevelObject representing the current list of objects added
 * via [NMAStreetLevelView addStreetLevelObject:]
 */
@property (nonatomic, readonly) NSArray *userObjects;

@end

/**  @}  */
