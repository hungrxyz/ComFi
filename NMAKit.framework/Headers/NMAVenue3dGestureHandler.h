/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapView.h"
#import "NMAVenue3dMapLayer.h"


/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \class NMAVenue3dGestureHandler NMAVenue3dGestureHandler.h "NMAVenue3dGestureHandler.h"
 *
 * \brief Provides an application with possibility to use Venue Zoom with conventional pinch zoom gesture.
 *
 * Up to the maximum zoom level supported by NMAMapView, the gestures are handled
 * by the current default gesture handler. When zooming more in with pinch gesture, the Venue Zoom is activated.
 * Zooming out using pinch gesture will deactivate Venue Zoom and return back to normal zoom range.
 */
@interface NMAVenue3dGestureHandler : NSObject <NMAMapGestureDelegate, NMAVenue3dMapLayerDelegate>

/**
 * Constructs a NMAVenue3dGestureHandler with the specified venue map layer.
 *
 * \param venueMapLayer A venue map layer object
 */
+ (instancetype)gestureHandlerWithVenueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer;
- (void)mapView:(NMAMapView *)mapView didReceivePinch:(float)pinch atLocation:(CGPoint)location;
- (void)venueMapLayer:(NMAVenue3dMapLayer *)venueMapLayer
     didDeselectVenue:(NMAVenue3dVenue *)venue
            withEvent:(NMAVenue3dDeselectEvent)event;
@end
/** @} */
