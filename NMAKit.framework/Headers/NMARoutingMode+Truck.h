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
 * The tunnel categories to avoid in truck routing.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMATunnelCategory) {
    /**
     * \brief Tunnel category not defined.
     */
    NMATunnelCategoryNone,
    /**
     * \brief Tunnel category B.
     */
    NMATunnelCategoryB,
    /**
     * \brief Tunnel category C.
     */
    NMATunnelCategoryC,
    /**
     * \brief Tunnel category D.
     */
    NMATunnelCategoryD,
    /**
     * \brief Tunnel category E.
     */
    NMATunnelCategoryE
};

/**
 * Hazardous goods types for use with truck routing.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_OPTIONS(NSUInteger, NMAHazardousGoodsType) {
    /**
     * \brief Explosive goods.
     */
    NMAHazardousGoodsTypeExplosive              = 1 << 0,
    /**
     * \brief Gas.
     */
    NMAHazardousGoodsTypeGas                    = 1 << 1,
    /**
     * \brief Flammable material.
     */
    NMAHazardousGoodsTypeFlammable              = 1 << 2,
    /**
     * \brief Combustible material.
     */
    NMAHazardousGoodsTypeCombustible            = 1 << 3,
    /**
     * \brief Organic material.
     */
    NMAHazardousGoodsTypeOrganic                = 1 << 4,
    /**
     * \brief Poison.
     */
    NMAHazardousGoodsTypePoison                 = 1 << 5,
    /**
     * \brief Radio-active material.
     */
    NMAHazardousGoodsTypeRadioActive            = 1 << 6,
    /**
     * \brief Corrosive material.
     */
    NMAHazardousGoodsTypeCorrosive              = 1 << 7,
    /**
     * \brief Goods which are poisonous upon inhalation.
     */
    NMAHazardousGoodsTypePoisonousInhalation    = 1 << 8,
    /**
     * \brief Goods which are harmful to water.
     */
    NMAHazardousGoodsTypeHarmfulToWater         = 1 << 9,
    /**
     * \brief Other types of hazardous goods.
     */
    NMAHazardousGoodsTypeOther                  = 1 << 10
};

/**
 * The truck type of the routed truck.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMATruckType) {
    /**
     * \brief Truck type not defined.
     */
    NMATruckTypeNone,
    /**
     * \brief Regular truck type.
     */
    NMATruckTypeTruck,
    /**
     * \brief Tractor truck type.
     */
    NMATruckTypeTractorTruck
};

/**
 * Contains options used when calculating a truck route.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMARoutingMode (NMATruckRoutingMode)

/**
 * The tunnel category to which the truck route should be restricted.
 *
 * \note The default value is NMATunnelCategoryNone.
 *
 * \note Truck routing only.
 */
@property (nonatomic) NMATunnelCategory tunnelCategory;

/**
 * An OR combination of NMAHazardousGoodsType values that apply
 * to the cargo for the truck route.
 *
 * \note The default value is 0 (no hazardous goods).
 *
 * \note Truck routing only.
 */
@property (nonatomic) NMAHazardousGoodsType hazardousGoods;

/**
 * Indicates whether the routed vehicle has a trailer.
 *
 * \note The default value is NO.
 *
 * \note Truck routing only.
 * \deprecated This value is not used. Use trailersCount instead.
 */
@property (nonatomic) BOOL hasTrailer DEPRECATED_ATTRIBUTE;

/**
 * The permitted vehicle gross weight in metric tons.
 *
 * \note The default value is 0 (no permitted gross weight).
 *
 * \note Truck routing only.
 * \deprecated This value is not used. Use limitedVehicleWeight instead.
 */
@property (nonatomic) float permittedGrossWeight DEPRECATED_ATTRIBUTE;

/**
 * The limited vehicle weight in metric tons.
 *
 * \note The default value is 0 (no vehicle weight limit).
 *
 * \note Truck routing only.
 */
@property (nonatomic) float limitedVehicleWeight;

/**
 * The vehicle weight per axle in metric tons.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) float weightPerAxle;

/**
 * The weight of the trailer in metric tons.
 *
 * The trailer weight is only considered if trailersCount is greater than 0.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 * \deprecated This value is not used. Use limitedVehicleWeight instead.
 */
@property (nonatomic) float trailerWeight DEPRECATED_ATTRIBUTE;

/**
 * The vehicle height in meters.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) float vehicleHeight;

/**
 * The vehicle width in meters.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) float vehicleWidth;

/**
 * The vehicle length in meters.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) float vehicleLength;

/**
 * Number of the trailers.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) NSUInteger trailersCount;

/**
 * Truck type of the routed truck.
 *
 * \note The default value is 0 (unspecified).
 *
 * \note Truck routing only.
 */
@property (nonatomic) NMATruckType truckType;

@end

/** @}  */
