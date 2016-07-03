/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Represents values describing public transport routing options that can be used to enforce
 * special conditions on a calculated route.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSUInteger, NMATransitRoutingOption) {
    /**
     * \brief The routing engine will avoid public bus transport.
     */
    NMATransitRoutingOptionAvoidPublicBus          = 1 << 0,

    /**
     * \brief The routing engine will avoid tourist bus.
     */
    NMATransitRoutingOptionAvoidTouristicBus       = 1 << 1,

    /**
     * \brief The routing engine will avoid intercity bus.
     */
    NMATransitRoutingOptionAvoidIntercityBus       = 1 << 2,

    /**
     * \brief The routing engine will avoid express bus.
     */
    NMATransitRoutingOptionAvoidExpressBus         = 1 << 3,

    /**
     * \brief The routing engine will avoid metro rail.
     */
    NMATransitRoutingOptionAvoidMetroRail          = 1 << 4,

    /**
     * \brief The routing engine will avoid light rail.
     */
    NMATransitRoutingOptionAvoidLightRail          = 1 << 5,

    /**
     * \brief The routing engine will avoid regional rail.
     */
    NMATransitRoutingOptionAvoidRegionalRail       = 1 << 6,

    /**
     * \brief The routing engine will avoid regional train.
     */
    NMATransitRoutingOptionAvoidRegionalTrain      = 1 << 7,

    /**
     * \brief The routing engine will avoid intercity train.
     */
    NMATransitRoutingOptionAvoidIntercityTrain     = 1 << 8,

    /**
     * \brief The routing engine will avoid high speed train.
     */
    NMATransitRoutingOptionAvoidHighSpeedTrain     = 1 << 9,

    /**
     * \brief The routing engine will avoid mono rail.
     */
    NMATransitRoutingOptionAvoidMonoRail           = 1 << 10,

    /**
     * \brief The routing engine will avoid aerial.
     */
    NMATransitRoutingOptionAvoidAerial             = 1 << 11,

    /**
     * \brief The routing engine will avoid inclined.
     */
    NMATransitRoutingOptionAvoidInclined           = 1 << 12,

    /**
     * \brief The routing engine will avoid boat.
     */
    NMATransitRoutingOptionAvoidWater              = 1 << 13
};

/**
 * Contains options used when calculating a public transit route.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMARoutingMode (NMATransitRoutingMode)

/**
 * The OR-ed #NMATransitRoutingOption values for the NMARoutingMode.
 *
 * \note The default value is 0 (no options selected).
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) NSUInteger transitRoutingOptions;

/**
 * The maximum number of vehicle changes allowed during the trip.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) NSUInteger maximumChanges;

@end

/** @}  */
