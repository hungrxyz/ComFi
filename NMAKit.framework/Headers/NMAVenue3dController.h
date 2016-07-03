/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAGeoCoordinates;
@class NMAVenue3dAnimationParameters;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;
@class NMAVenue3dVenue;
@class NMAVenue3dBaseLocation;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dController NMAVenue3dController.h "NMAVenue3dController.h"
 *
 * \brief NMAVenue3dController encapsulates interactions of a viewable NMAVenue3dVenue. Methods of this class allow clients to
 * select and deselect levels and spaces.
 * <p>
 * This class can not be instantiated directly. Instead an instance of this class is returned by \link NMAVenue3dMapLayer::venueController\endlink or
 * \link NMAVenue3dMapLayer::controllerForVenue:\endlink.
 * </p>
 * \sa NMAVenue3dMapLayer
 */
@interface NMAVenue3dController : NSObject

/**
 * The NMAVenue3dVenue object this NMAVenue3dController is representing.
 */
@property (nonatomic, readonly) NMAVenue3dVenue *venue;

/**
 * The NMAVenue3dLevel object representing groud level.
 */
@property (nonatomic, readonly) NMAVenue3dLevel *groundLevel;

/**
 * Select a specific or access the selected {@link NMAVenue3dLevel}. The selected level is viewed as the topmost in the venue.
 * Levels on top of the selected level are hidden. Levels below the selected level are obscured by the level being selected.
 */
@property (nonatomic, weak) NMAVenue3dLevel *level;

/**
 * Select a specific or access the selected NMAVenue3dSpace inside NMAVenue3dVenue.
 * nil if no space is selected.
 *
 */
@property (nonatomic, weak) NMAVenue3dSpace *space;

/**
 * Deselect current NMAVenue3dSpace inside NMAVenue3dVenue.
 */
- (void)deselectSpace;

/**
 * Sets Venue Zoom on or off. Venue Zoom shows venues in enlarged mode. In this mode
 * the map is not visible but is replaced with a grey color. In order to use Venue Zoom it
 * it must be enabled. Use {@link NMAVenue3dMapLayer::enableVenueZoom:} to enable the feature.
 *
 * @param venueZoomInUse  If <code>true</code> Venue Zoom is in use, otherwise not.
 *
 * @return boolean value indicating if transition was actually made.
 *
 */
- (bool)useVenueZoom:(BOOL)venueZoomInUse;

/**
 * Returns scaled geocoordinate to be used in Venue Zoom.
 * In Venue Zoom mode coordinates need to be scaled in order to show map objects properly.
 *
 * @param geoCoordinate  Coordinate to be converted to scale coodintate.
 *
 */
- (NMAGeoCoordinates *)getScaledGeoCoordinatesFromNormal:(NMAGeoCoordinates *)geoCoordinate;

/**
 * Returns normal geocoordinate from scaled geocoordinate used in Venue Zoom.
 * In Venue Zoom mode coordinates need to be scaled in order to show map objects properly.
 *
 * @param geoCoordinate  Scaled coordinate to be converted to normal coodintate.
 *
 */
- (NMAGeoCoordinates *)getNormalGeoCoordinatesFromScaled:(NMAGeoCoordinates *)geoCoordinate;

/**
 * Returns the NMAVenue3dBaseLocation object based on the screen pixel coordinates.
 *
 * @param x  The horizontal screen pixel coordinate.
 * @param y  The vertivcal screen pixel coordinate.
 * @param prefereSpace  If true and user clicked on the NMAVenue3dSpace, returns the NMAVenue3dSpaceLocation
 *                      object, otherwise returns the NMAVenue3dSpaceLocation object.
 * @return The NMAVenue3dLevelLocation or NMAVenue3dSpaceLocation object, if taps point is
 *         inside the venue, the NMAVenue3dOutdoorLocation object otherwise.
 *
 */
- (NMAVenue3dBaseLocation *)getLocationAtX:(float)x
                                         Y:(float)y
                         WithSpacePrefered:(bool)prefereSpace;

@end
/** @} */
