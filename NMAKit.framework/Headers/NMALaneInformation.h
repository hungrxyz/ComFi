/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 * @{
 */

/**
 * \enum NMALaneInformationDirection
 * \brief All possible directions the lane leads.
 *
 * A combination of the NMALaneInformationDirection forms a direction bitmask.
 *
 * \sa NMALaneInformation
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSUInteger, NMALaneInformationDirection) {
    /** \brief Indicates that the direction is undefined. */
    NMALaneInformationDirectionMaskUndefined       = 0,

    /** \brief Indicates that the direction of travel is straight ahead. */
    NMALaneInformationDirectionMaskStraight        = 1 << 0,

    /** \brief Indicates a slight right turn. */
    NMALaneInformationDirectionMaskSlightlyRight   = 1 << 1,

    /** \brief Indicates a right turn. */
    NMALaneInformationDirectionMaskRight           = 1 << 2,

    /** \brief Indicates a sharp right turn. */
    NMALaneInformationDirectionMaskSharpRight      = 1 << 3,

    /** \brief Indicates a left u-turn. */
    NMALaneInformationDirectionMaskUTurnLeft       = 1 << 4,

    /** \brief Indicates a sharp left turn. */
    NMALaneInformationDirectionMaskSharpLeft       = 1 << 5,

    /** \brief Indicates a left turn. */
    NMALaneInformationDirectionMaskLeft            = 1 << 6,

    /** \brief Indicates a slight left turn. */
    NMALaneInformationDirectionMaskSlightlyLeft    = 1 << 7,

    /** \brief Indicates a right merge. */
    NMALaneInformationDirectionMaskMergeRight      = 1 << 8,

    /** \brief Indicates a left merge. */
    NMALaneInformationDirectionMaskMergeLeft       = 1 << 9,

    /** \brief Indicates a merge of lanes. */
    NMALaneInformationDirectionMaskMergeLanes      = 1 << 10,

    /** \brief Indicates a right u-turn. */
    NMALaneInformationDirectionMaskUTurnRight      = 1 << 11,

    /** \brief Indicates a second right. */
    NMALaneInformationDirectionMaskSecondRight     = 1 << 12,

    /** \brief Indicates a second left. */
    NMALaneInformationDirectionMaskSecondLeft      = 1 << 13
};

/**
 * \enum NMALaneInformationRecommendationState
 * \brief Recommendation for taking the lane according to the lane connectivity.
 *
 * \sa NMALaneInformation
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationRecommendationState) {
    /** \brief The lane is not on the current route. */
    NMALaneInformationRecommendationStateNotRecommended,

    /** \brief The lane is on the route at least up to the next decision point, but not for the whole
       part of the route for which connectivity information is available. */
    NMALaneInformationRecommendationStateRecommended,

    /** \brief The lane is on the current route for the whole part of the route for which connectivity
       information is available. */
    NMALaneInformationRecommendationStateHighlyRecommended,

    /** \brief Recommendation information is not available. */
    NMALaneInformationRecommendationStateNotAvailable
};

/**
 * \enum NMALaneInformationMarkingType
 * \brief Marking types for the divider and center marking.
 *
 * \sa NMALaneInformation
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationMarkingType) {
    /** \brief Not Available */
    NMALaneInformationMarkingTypeNotAvailable,

    /** \brief Long dashed */
    NMALaneInformationMarkingTypeLongDashed,

    /** \brief Double solid line */
    NMALaneInformationMarkingTypeDoubleSolidLine,

    /** \brief Single solid line */
    NMALaneInformationMarkingTypeSingleSolidLine,

    /** \brief Double inner single outer dashed */
    NMALaneInformationMarkingTypeDoubleInnerSingleOuterDashed,

    /** \brief Double inner dashed outer single */
    NMALaneInformationMarkingTypeDoubleInnerDashedOuterSingle,

    /** \brief Short dashed */
    NMALaneInformationMarkingTypeShortDashed,

    /** \brief Shared area */
    NMALaneInformationMarkingTypeSharedArea,

    /** \brief Dashed blocks */
    NMALaneInformationMarkingTypeDashedBlocks,

    /** \brief Physical divider */
    NMALaneInformationMarkingTypePhysicalDivider,

    /** \brief Double dashed */
    NMALaneInformationMarkingTypeDoubleDashed,

    /** \brief No divider */
    NMALaneInformationMarkingTypeNoDivider,

    /** \brief Crossing alert */
    NMALaneInformationMarkingTypeCrossingAlert
};

/**
 * \enum NMALaneInformationCrossingRestriction
 * \brief Crossing restriction to enter or exit a HOV lane.
 *
 * \sa NMALaneInformation
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationCrossingRestriction) {
    /** \brief No restriction */
    NMALaneInformationCrossingRestrictionNoRestriction,

    /** \brief Left restriction */
    NMALaneInformationCrossingRestrictionLeft,

    /** \brief Right restriction */
    NMALaneInformationCrossingRestrictionRight,

    /** \brief Both directions restricted */
    NMALaneInformationCrossingRestrictionBoth
};


/**
 * \class NMALaneInformation NMALaneInformation.h "NMALaneInformation.h"
 * \brief Gives information about a lane, e.g. its type, direction and recommendation state.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMALaneInformation : NSObject

/**
 * \property directions
 *
 * \brief All the directions the lane leads to as an OR combination of one or more \p NMALaneInformationDirection values.
 *
 * \note directions can be used as a bitmask (e.g. for efficient indexing of image resources).
 */
@property (nonatomic, readonly) NSInteger directions;

/**
 * \property syntheticDirection
 *
 * \brief Gets whether the direction of the lane is synthetic.
 *
 * \note Synthetic directions are derived from the connectivity of the lane. Non-synthetic directions
 * represent actual physical arrows printed on the lane.
 */
@property (nonatomic, readonly, getter = isSyntheticDirection) BOOL syntheticDirection;

/**
 * \property recommendationState
 *
 * \brief Gets the recommendation state of the lane according to the current route.
 *
 * \note If the map data does not provide connectivity information for this lane, then the
 * recommendation state is set to \p NMALaneInformationRecommendationStateNotAvailable.
 */
@property (nonatomic, readonly) NMALaneInformationRecommendationState recommendationState;

/**
 * \property regular
 *
 * \brief Returns whether this is a regular lane.
 *
 * \note Regular lanes are lanes which have no specific use (i.e. they are not a special type such as hov, reversible, etc.)
 */
@property (nonatomic, readonly, getter = isRegular) BOOL regular;

/**
 * \property hov
 *
 * \brief Returns whether this is a high occupancy vehicle (HOV) lane.
 *
 * \note A HOV lane (or carpool lane) is reserved for carpool usage. Carpool lane requires a minimum number of
 * passengers in order for the car to use the carpool lane. HOV lanes may also be reserved for hybrids, motorcycles,
 * alternate fuel, etc. HOV Lane may require a fee
 */
@property (nonatomic, readonly, getter = isHov) BOOL hov;

/**
 * \property reversible
 *
 * \brief Returns whether this is a reversible lane.
 *
 * \note A reversible lane is a lane in which traffic may travel in either direction, depending on
 * certain conditions (also known as a tidal flow lane).
 */
@property (nonatomic, readonly, getter = isReversible) BOOL reversible;

/**
 * \property express
 *
 * \brief Returns whether this is an express lane.
 */
@property (nonatomic, readonly, getter = isExpress) BOOL express;

/**
 * \property acceleration
 *
 * \brief Returns whether this is an acceleration lane.
 *
 * \note An acceleration lane (or merge lane) allows traffic entering a highway to accelerate
 * to the speed of through traffic before merging with it.
 */
@property (nonatomic, readonly, getter = isAcceleration) BOOL acceleration;

/**
 * \property deceleration
 *
 * \brief Returns whether this is a deceleration lane.
 *
 * \note A deceleration lane is a lane adjacent to the primary road or street allowing drivers
 * to pull out of the through lane and decelerate safely before turning off a surface street or exiting a freeway.
 */
@property (nonatomic, readonly, getter = isDeceleration) BOOL deceleration;

/**
 * \property auxLane
 *
 * \brief Returns whether this is an auxiliary lane.
 *
 * \note An auxiliary lane is a lane other than a through lane, used to separate entering, exiting or turning traffic from the through traffic.
 */
@property (nonatomic, readonly, getter = isAuxLane) BOOL auxLane;

/**
 * \property slow
 *
 * \brief Returns whether this is a slow lane.
 */
@property (nonatomic, readonly, getter = isSlow) BOOL slow;

/**
 * \property passing
 *
 * \brief Returns whether this is a passing lane.
 */
@property (nonatomic, readonly, getter = isPassing) BOOL passing;

/**
 * \property regulatedAccess
 *
 * \brief Returns whether this is a regulated access lane.
 *
 * \note (Trucks only) A regulated access lane is a lane designated as a holding zone, used to regulate traffic using time intervals.
 */
@property (nonatomic, readonly, getter = isRegulatedAccess) BOOL regulatedAccess;

/**
 * \property driveableShoulder
 *
 * \brief Returns whether this is a driveable shoulder lane.
 *
 * \note A shoulder lane is reserved paved area on the side of the road (one or both sides) that are not
 * generally used for driving, although it is possible under certain circumstances. Only shoulder lanes
 * designated as a part-time driving lanes are included.
 */
@property (nonatomic, readonly, getter = isDriveableShoulder) BOOL driveableShoulder;

/**
 * \property turn
 *
 * \brief Returns whether this is a turn lane.
 *
 * \note Turn lane is an extra lane that is used for making a turn in order not to disrupt ongoing traffic.
 */
@property (nonatomic, readonly, getter = isTurn) BOOL turn;

/**
 * \property centerTurn
 *
 * \brief Returns whether this is a center turn lane.
 *
 * \note Center turn lane is a bidirectional turn lane located in the middle of a road that allows traffic
 * in both directions to turn left (right for left side driving countries).
 */
@property (nonatomic, readonly, getter = isCenterTurn) BOOL centerTurn;

/**
 * \property truckParking
 *
 * \brief Returns whether this is a truck parking lane.
 *
 * \note Truck parking lanes are wide shoulder lane that maybe used for truck parking as well as for emergency.
 */
@property (nonatomic, readonly, getter = isTruckParking) BOOL truckParking;

/**
 * \property dividerMarking
 *
 * \brief Gets the divider marking type for side marks.
 *
 * \note Divider markings are markings between lanes of same direction
 */
@property (nonatomic, readonly) NMALaneInformationMarkingType dividerMarking;

/**
 * \property centerMarking
 *
 * \brief Gets the divider marking type for the center mark.
 *
 * \note Center markings are markings between lanes in opposite direction.
 */
@property (nonatomic, readonly) NMALaneInformationMarkingType centerMarking;

/**
 * \property speedLimit
 *
 * \brief Gets the speed limit on this lane in the positive lane direction in km/h. Zero if the
 * speed limit is not available. In the case of zero, the speed limit is the speed limit of the
 * whole road (see %NMARoadElement).
 */
@property (nonatomic, readonly) NSUInteger speedLimit;

/**
 * \property heightRestriction
 *
 * \brief Gets the height restriction in cm or zero if there is no restriction or it is unknown.
 */
@property (nonatomic, readonly) NSUInteger heightRestriction;

/**
 * \property width
 *
 * \brief Gets the lane width in cm or zero if the lane width is not available.
 */
@property (nonatomic, readonly) NSUInteger width;

/**
 * \property crossingRestriction
 *
 * \brief Gets the crossing restriction of the lane. This indicates if it is illegal to enter or exit a lane.
 */
@property (nonatomic, readonly) NMALaneInformationCrossingRestriction crossingRestriction;

@end
/** @} */
