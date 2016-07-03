/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \brief Represents values that describe the route sections types used in indoor routing.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteSectionType) {
    /**
     * Route section is inside a venue.
     */
    NMAVenue3dRouteSectionTypeVenue,

    /**
     * Route section is outside a venue.
     */
    NMAVenue3dRouteSectionTypeOutdoor,

    /**
     * Route section describes a direct line from the start to the end point of the section,
     * where there is no turn-by-turn routing data is available. This typically may occur
     * in sections where one end is inside a venue and other end outside a venue.
     */
    NMAVenue3dRouteSectionTypeLink
};


/**
 * \class NMAVenue3dRouteSection "NMAVenue3dRouteSection.h"
 *
 * \brief Base class for indoor route sections. Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connects indoor and outdoor locations.
 *
 * \sa    NMAVenue3dVenueRouteSection
 * \sa    NMAVenue3dOutdoorRouteSection
 * \sa    NMAVenue3dLinkRouteSection
 */
@interface NMAVenue3dRouteSection : NSObject

@end
/** @} */
