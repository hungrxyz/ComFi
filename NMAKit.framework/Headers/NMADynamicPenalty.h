/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMARoadElement;
@class NMAMapPolygon;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Defines the possible traffic penalty modes used for route calculation and traffic event handling.
 *
 * Time awareness (e.g. avoiding bridges that are closed for certain portion of a day) is not
 * affected by traffic penalty modes.
 */
typedef NS_ENUM(NSInteger, NMATrafficPenaltyMode) {
    /**
     * Do not consider real time traffic flow or long term road closures (usually due to construction
     * work) when calculating a route.
     */
    NMATrafficPenaltyModeDisabled = 0,

    /**
     * Create a single traffic optimized route that considers all available traffic information
     * including real time traffic flow and long term closures coming from real time traffic
     * information.
     */
    NMATrafficPenaltyModeOptimal,

    /**
     * Do NOT consider real time traffic flow but do consider long term closures coming from real
     * time traffic information when calculating a route.
     */
    NMATrafficPenaltyModeAvoidLongTermClosures
};

/**
 * Defines possible driving directions.
 */
typedef NS_ENUM(NSUInteger, NMADrivingDirection) {
    /** \brief An indication for both driving direction, forward and backward. */
    NMADrivingDirectionBoth = 0,
    /** \brief An indication for forward driving direction. */
    NMADrivingDirectionForward,
    /** \brief An indication for backward driving direction. */
    NMADrivingDirectionBackward
};


/**
 * \class NMADynamicPenalty NMADynamicPenalty.h "NMADynamicPenalty.h"
 *
 * \brief This class represents a policy containing road, area, and traffic restriction factors that are taken
 * into account while calculating routes.
 *
 * These restriction factors are also known as penalties.
 * For example, you can use this class to set an area penalty to indicate that
 * the travel speed in an area is 50% slower than the legal speed limit.
 */
@interface NMADynamicPenalty : NSObject

/**
 * \brief Constructs a default %NMADynamicPenalty.
 */
- (instancetype)init;

/**
 * \brief Sets a banned area which is excluded from the routing calculation.
 *
 * An area is defined in terms of %NMAMapPolygon.
 *
 * \param area
 *            area to with penalty is being added.
 *
 * \return YES if banned area is added successfully. NO if area is nil.
 */
- (BOOL)addBannedArea:(NMAMapPolygon *)area;

/**
 * \brief Removes a banned area, if added previously.
 * \note Area is defined in terms of %NMAGeoPolygon.
 *
 * \param area
 *            area to be removed from penalty policy
 */
- (BOOL)removeBannedArea:(NMAMapPolygon *)area;

/**
 * \brief Removes all previously-added areas and their penalty from this policy.
 */
- (void)removeAllAreaPenalties;

/**
 * \brief Sets a penalty for a road segment.
 * \note Road penalties are defined as a speed that overrides the original speed of the road segment.
 * Road penalties are in kilometers per hour and must be between 0 and 254.
 * A penalty of 0 blocks the road segment from route calculations altogether.
 * Segments can be blocked in the forward, backward, or both directions.
 * If a road segment is excluded in the backward direction, it can still be accessed in the forward
 * direction. If you want to completely exclude the segment, block both directions.
 *
 * \param element to identify the road segment.
 *
 * \param direction - The road's direction represented by %NMADrivingDirection to be used to apply
 *            penalty.
 *
 * \param newSpeed- New Speed for the segment in kilometers per hour. Must be in between 0 to
 *            254.
 *
 * \return YES if road penalty is added successfully. NO if element is nil OR newSpeed is less than 0 or greater than 254 OR otherwise.
 */
- (BOOL)addPenaltyForRoadElement:(NMARoadElement *)element withDrivingDirection:(NMADrivingDirection)direction speed:(NSUInteger)newSpeed;

/**
 * \brief Remove a road segment from the penalty policy. This will remove penalties for every
 * %NMADrivingDirection.
 *
 * \param element to identify the road segment.
 *
 * \return YES if road penalty is removed successfully. NO otherwise.
 */
- (BOOL)removePenaltyForRoadElement:(NMARoadElement *)element;

/**
 * \brief Removes all previously-added road penalties.
 */
- (void)removeAllRoadElementPenalties;

/**
 * To decide route calculation should take traffic into account.
 *
 * This property defaults to NMATrafficPenaltyModeDisabled.
 */
@property (nonatomic) NMATrafficPenaltyMode trafficPenaltyMode;

#pragma mark - DEPRECATED

/**
 * \brief Sets a penalty for an area.
 *
 * An area is defined in terms of %NMAMapPolygon. Adding penalty to an area reduces the original speed in
 * the area to the given factor. For example, a penalty value of 10 reduces the speed by 10% of the original
 * speed in the defined area. Use a penalty value of 100 to block the area from being used route calculations.
 *
 * \param penalty
 *            penalty for the area. Must be between 0 and 100, inclusive.
 * \param area
 *            area to with penalty is being added.
 *
 * \return YES if area penalty is added successfully. NO if area is nil OR penalty is greater than 100 OR otherwise.
 *
 * \deprecated As of SDK 3.2. Use \a addBannedArea. The \a penalty argument has no effect. Any area added
 * is blocked from the routing calculation.
 */
- (BOOL)addPenalty:(NSUInteger)penalty forArea:(NMAMapPolygon *)area DEPRECATED_ATTRIBUTE;

/**
 * \brief Removes an area and its penalty from this policy, if added previously.
 * \note Area is defined in terms of %NMAGeoPolygon.
 *
 * \param area
 *            area to be removed from penalty policy
 *
 * \deprecated As of SDK 3.2. Use \a removeBannedArea.
 */
- (BOOL)removePenaltyForArea:(NMAMapPolygon *)area DEPRECATED_ATTRIBUTE;

@end

/**  @}  */
