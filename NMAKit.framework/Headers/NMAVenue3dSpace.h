/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dArea.h"

@class UIImage;
@class NMAVenue3dContent;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * Represents the type of a venue space.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dSpaceType) {
    /**
     * \brief Represents a standard NMAVenue3dSpace object.
     */
    NMAVenue3dSpaceTypeGeneral,

    /**
     * \brief Represents NMAVenue3dSpace object which is a facility: elevators, stairs, toilets, ATM's etc.
     */
    NMAVenue3dSpaceTypeFacility
};

/**
 * \class NMAVenue3dSpace NMAVenue3dSpace.h "NMAVenue3dSpace.h"
 */


/**
 * \brief A physical space in a NMAVenue3dVenue such as a shop in a mall.
 *
 * When the NMAVenue3dMapLayer is used, the NMAVenue3dSpace can be interacted with by tapping on it.
 *
 *  @see NMAVenue3dContent
 *  @see NMAVenue3dVenue
 */
@interface NMAVenue3dSpace : NMAVenue3dArea

/**
 * The {@link NMAVenue3dContent} object belonging to this <code>NMAVenue3dSpace</code>.
 */
@property (nonatomic, readonly) NMAVenue3dContent *content;

/**
 * The floor number. For ground floor it's 0. For underground floors:
 * -1, -2, -3... For above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

/**
 * The floor synonym, for example: 1, B, P1, MEZZ etc.
 */
@property (nonatomic, readonly) NSString *floorSynonym;

/**
 * The name of the NMAVenue3dVenue where this NMAVenue3dSpace is located.
 *
 */
@property (nonatomic, readonly) NSString *venueName;

/**
 * The icon of the NMAVenue3dSpace, which is displayed on the the map.
 *
 */
@property (nonatomic, readonly) UIImage *icon;

/**
 * The space type.
 */
@property (nonatomic, readonly) NMAVenue3dSpaceType type;

@end
/** @} */
