/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/*!
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */
/**
 * Normal scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalDay;

/**
 * Normal scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalNight;

/**
 * Normal scheme presented in "day" with less color palette.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeReducedDay;

/**
 * Normal scheme presented in "night" with less color palette.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeReducedNight;

/**
 * Normal scheme presented in "day" colors, with highlighted transit lines.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalDayTransit;

/**
 * Normal scheme presented in "night" colors, with highlighted transit
 * lines.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalNightTransit;

/**
 * Terrain bitmap scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTerrainDay;

/**
 * Satellite tile scheme presented in "day" colors.
 *
 * \note No roads are shown. For satellite and roads use #NMAMapSchemeHybridDay
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeSatelliteDay;

/**
 * Satellite tile scheme presented in "night" colors.
 *
 * \note No roads are shown.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeSatelliteNight;

/**
 * Satellite tile scheme presented in "day" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridDay;

/**
 * Satellite tile scheme presented in "night" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridNight;

/**
 * Satellite tile scheme presented in "day" with roads but less color palette.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridReducedDay;

/**
 * Satellite tile scheme presented in "day" colors, with roads and
 * highlighted transit lines.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridDayTransit;

/**
 * Car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeCarNavigationDay;

/**
 * Car navigation scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeCarNavigationNight;

/*
 * Satellite tile car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridCarNavigationDay;

/**
 * Satellite tile pedestrian navigation scheme presented in "day" colors.
 *
 * \note When using this scheme it is recommended to enable pedestrian features
 * on the map view, see \link NMAMapView#showPedestrianFeature:(NMAMapPedestrianFeatureType)\endlink
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridPedestrianDay;

/*
 * Satellite tile car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridCarNavigationNight;

/**
 * Pedestrian navigation scheme presented in "day" colors.
 *
 * \note When using this scheme it is recommended to enable pedestrian features on the map view, see \link  NMAMapView#showPedestrianFeature:\endlink.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemePedestrianDay;

/**
 * Pedestrian navigation scheme presented in "night" colors.
 *
 * \note When using this scheme it is recommended to enable pedestrian features on the map view, see \link NMAMapView#showPedestrianFeature:\endlink.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemePedestrianNight;

/**
 * Truck scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTruckDay;

/**
 * Truck scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTruckNight;

/**
 * Satellite tile scheme presented in "day" colors with truck related attributes
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridTruckDay;

/**
 * Satellite tile scheme presented in "night" colors with truck related attributes
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridTruckNight;

/*
 * Normal scheme presented in "day" colors that is suitable for truck guidance.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTruckNavigationDay;

/*
 * Normal scheme presented in "night" colors that is suitable for truck guidance.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTruckNavigationNight;

/*
 * Satellite tile scheme presented in "day" colors, with visible roads, that is suitable for
 * for truck guidance.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridTruckNavigationDay;

/*
 * Satellite tile scheme presented in "night" colors, with visible roads, that is suitable
 * for truck guidance.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridTruckNavigationNight;

/*
 * Traffic optimized version of NMAMapSchemeNormalDay.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalDayWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeNormalNight.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalNightWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeHybridDay.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridDayWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeHybridNight.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridNightWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeCarNavigationDay.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeCarNavigationDayWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeCarNavigationNight.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeCarNavigationNightWithTraffic;

/*
 * Traffic optimized version of NMAMapSchemeHybridCarNavigationDay.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridCarNavigationDayWithTraffic;


/*!
 * \class NMAMapScheme NMAMapScheme.h "NMAMapScheme.h"
 *
 * Represents a collection of schemes that a NMAMapView supports.
 * Each of the schemes in this class can be set by way of the
 * NMAMapView::mapScheme property.
 */
@interface NMAMapScheme : NSObject

/*!
 * Determines whether the specified scheme is supported (is valid for the
 * application).
 *
 * \param scheme A %NSString representing the scheme to check
 * \return YES if the scheme is valid, NO otherwise
 */
+ (BOOL)isValid:(NSString *)scheme;

@end
/** @}  */
