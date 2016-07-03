/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * Attributes of a road element.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMARoadElementAttribute) {
    NMARoadElementAttributeUndefined                = 0x00000000,

    /** Road direction. */
    NMARoadElementAttributeDirectionNoCars          = 0x00000000,
    NMARoadElementAttributeDirectionForward         = 0x00000001,
    NMARoadElementAttributeDirectionBackward        = 0x00000002,
    NMARoadElementAttributeDirectionBoth            = 0x00000003,

    /** \brief Road type.      */
    NMARoadElementAttributeDirtRoad                 = 0x00000100,
    NMARoadElementAttributeUsageFeeRequired         = 0x00000200,
    NMARoadElementAttributeCarpool                  = 0x00000400,
    NMARoadElementAttributeUrban                    = 0x00000800,
    NMARoadElementAttributeTollroad                 = 0x00001000,
    NMARoadElementAttributeNoThroughTraffic         = 0x00002000,
    NMARoadElementAttributeTunnel                   = 0x00004000,
    NMARoadElementAttributeSliproad                 = 0x00040000,
    NMARoadElementAttributeHighway                  = 0x00080000,
    NMARoadElementAttributeUnderConstruction        = 0x00100000,
    NMARoadElementAttributeHasLaneDir               = 0x00200000,
    NMARoadElementAttributeHasLaneExit              = 0x00400000,
    NMARoadElementAttributeFerry                    = 0x00800000,
    NMARoadElementAttributeRailFerry                = 0x01000000,

    NMARoadElementAttributeDirectionNoTruck         = 0x02000000,
    NMARoadElementAttributeDirectionTruckForward    = 0x04000000,
    NMARoadElementAttributeDirectionTruckBackward   = 0x08000000,
    NMARoadElementAttributeDirectionTruckBoth       = 0x0C000000
};

/**
 * Road element classifications.
 *
 * <p>
 * The NAMRoadElementType describes the nature of the road that a NMARoadElement
 * is part of. A road element may only have one type, or none if the road is an
 * unclassified type or the information is not available.
 * </p>
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMARoadElementType) {
    NMARoadElementTypeUndefined = 0,
    NMARoadElementTypeMotorway,
    NMARoadElementTypeMultiCarriageway,
    NMARoadElementTypeSingleCarriageway,
    NMARoadElementTypeRoundabout,
    NMARoadElementTypeSliproad,
    NMARoadElementTypePedestrianZone,
    NMARoadElementTypePedestrianWalkway,
    NMARoadElementTypeServiceAccessParking,
    NMARoadElementTypeServiceAccessOther,
    NMARoadElementTypeServiceRoad
};

/**
 * Plural type identifies when a Junction is made up of multiple Road Elements.
 * It also implies that a maneuver may require different explication than implied
 * by the geometry.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMARoadElementPluralType) {
    /** \brief Junction is not plural */
    NMARoadElementPluralTypeNone = 0,

    /**
     * \brief Indicates that only one command should be given despite the fact that two
     * Junctions occur – one at each end of the turn lane. It is only necessary to
     * state "turn left/right" near the beginning of the maneuver because at the
     * end the driver does not have a choice in direction.
     */
    NMARoadElementPluralTypeManeuver,

    /**
     * \brief Indicates that a road segment should not be viewed as an individual piece of
     * road but as part of the intersection. A separate guidance manoeuvre should
     * not exist for this segment.
     */
    NMARoadElementPluralTypeConnector,

    /**
     * \brief Indicates a maneuver that cannot be explained in one command or at all. A
     * graphic may be needed to illustrate the turn. For example, a driver may need
     * to go right to make a left turn.
     */
    NMARoadElementPluralTypeIndeterminate
};


/**
 * \class NMARoadElement NMARoadElement.h "NMARoadElement.h"
 *
 * Represents a section of a road.
 * </p>
 * <p>
 * To determine whether an object is the same as this NMARoadElement, use isEqual:.
 * isEqual returns YES if all properties of the objects contain the same values.
 * Please note that road elements from different sources may contain different
 * attributes for the same road element, e.g. road elements from NMATrafficEvent
 * v.s. road elements from NMAManeuver. Compare uniqueIds of two road elements if
 * you only want to know whether they are the same road elements with the same
 * geometries.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMARoadElement : NSObject

/**
 * The unique identifier of the NMARoadElement.
 */
@property (nonatomic, readonly, weak) NSString *uniqueId;

/**
 * The attributes of the NMARoadElement. Can be a combination of any values
 * from \p NMARoadElementAttribute.
 */
@property (nonatomic, readonly) NSUInteger attributes;

/**
 * The type of the road element.
 * \sa NMARoadElementType
 */
@property (nonatomic, readonly) NMARoadElementType type;

/**
 * The plural type of the road element.
 * \sa NMARoadElementPluralType
 */
@property (nonatomic, readonly) NMARoadElementPluralType pluralType;

/**
 * The name of the road element, or an empty string if the
 * data is not available.
 */
@property (nonatomic, readonly, weak) NSString *roadName;

/**
 * The abbreviated name of the road element. For example,
 * I5 for the Interstate 5 in the US. This property will contain an
 * empty string if the abbreviated name is unavailable.
 */
@property (nonatomic, readonly, weak) NSString *abbreviatedName;

/**
 * The speed limit of the NMARoadElement in m/s, or 0 if
 * the information is not available.
 */
@property (nonatomic, readonly) NSUInteger speedLimit;

/**
 * The average speed of traffic on the NMARoadElement in m/s,
 * or 0 if the information is not available.
 */
@property (nonatomic, readonly) NSUInteger averageSpeed;

/**
 * The number of lanes of the road element, or 0 if the
 * data is unavailable.
 */
@property (nonatomic, readonly) NSUInteger numberOfLanes;


@end
/** @} */
