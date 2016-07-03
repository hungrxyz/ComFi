/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAZoomRange.h"
@class UIColor;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */
/**
* \enum NMACustomizablePropertyType
* \brief Determines the NMACustomizableVariable property type
*/
typedef NS_ENUM(NSUInteger, NMACustomizablePropertyType) {
    NMACustomizableFloatType,
    NMACustomizableIntegerType,
    NMACustomizableColorType
};

/**
* \enum NMASchemeColorProperty
*/
typedef NS_ENUM(NSUInteger, NMASchemeColorProperty) {
    NMASchemeAirportAreaColor,
    NMASchemeAllotmentColor,
    NMASchemeAmbientLightColor,
    NMASchemeAmusementParkColor,
    NMASchemeAnimalParkColor,
    NMASchemeAvoidBlockedRouteDashColor,
    NMASchemeAvoidBlockedRouteGapColor,
    NMASchemeAvoidBlockedRouteOutlineColor,
    NMASchemeBayHarbourColor,
    NMASchemeBayHarbourDisplayClass1Color,
    NMASchemeBayHarbourDisplayClass2Color,
    NMASchemeBayHarbourDisplayClass3Color,
    NMASchemeBayHarbourDisplayClass4Color,
    NMASchemeBayHarbourDisplayClass5Color,
    NMASchemeBayHarbourDisplayClass6Color,
    NMASchemeBayHarbourDisplayClass7Color,
    NMASchemeBayHarbourDisplayClass8Color,
    NMASchemeBeachColor,
    NMASchemeBillboardAdjacentColor,
    NMASchemeBillboardAdjacentOutlineColor,
    NMASchemeBillboardOffRouteColor,
    NMASchemeBillboardOffRouteOutlineColor,
    NMASchemeBuildingColor,
    NMASchemeBuilding1Color,
    NMASchemeBuilding1OutlineColor,
    NMASchemeBuildingOutlineColor,
    NMASchemeBuiltupAreaColor,
    NMASchemeBuiltupBorderBackgroundColor,
    NMASchemeBuiltupBorderColor,
    NMASchemeCanalWaterChannelColor,
    NMASchemeCanalWaterChannelDisplayClass1Color,
    NMASchemeCanalWaterChannelDisplayClass2Color,
    NMASchemeCanalWaterChannelDisplayClass3Color,
    NMASchemeCanalWaterChannelDisplayClass4Color,
    NMASchemeCanalWaterChannelDisplayClass5Color,
    NMASchemeCanalWaterChannelDisplayClass6Color,
    NMASchemeCanalWaterChannelDisplayClass7Color,
    NMASchemeCanalWaterChannelDisplayClass8Color,
    NMASchemeCemeteryColor,
    NMASchemeCongestionZoneColor,
    NMASchemeCongestionZoneBorderColor,
    NMASchemeCountryBoundaryBackgroundColor,
    NMASchemeCountryBoundaryColor,
    NMASchemeCountryBoundaryDisputedBackgroundColor,
    NMASchemeCountryBoundaryDisputedColor,
    NMASchemeDirectionalLight1Color,
    NMASchemeDirectionalLight2Color,
    NMASchemeDirectionalLight3Color,
    NMASchemeElevationMapColor0,
    NMASchemeElevationMapColor1,
    NMASchemeElevationMapColor2,
    NMASchemeElevationMapColor3,
    NMASchemeElevationMapColor4,
    NMASchemeElevationMapColor5,
    NMASchemeElevationMapColor6,
    NMASchemeElevationMapColor7,
    NMASchemeElevationMapShaderShadowColor,
    NMASchemeElevationMapShaderSpecularColor,
    NMASchemeEnvironmentalZoneColor,
    NMASchemeEnvironmentalZoneBorderColor,
    NMASchemeExitInfoStreetCategory0Color,
    NMASchemeExitInfoStreetCategory0OutlineColor,
    NMASchemeExitInfoStreetCategory0TollColor,
    NMASchemeExitInfoStreetCategory0TollOutlineColor,
    NMASchemeExitInfoStreetCategory1Color,
    NMASchemeExitInfoStreetCategory1OutlineColor,
    NMASchemeExitInfoStreetCategory1TollColor,
    NMASchemeExitInfoStreetCategory1TollOutlineColor,
    NMASchemeExitInfoStreetCategory2Color,
    NMASchemeExitInfoStreetCategory2OutlineColor,
    NMASchemeExitInfoStreetCategory2TollColor,
    NMASchemeExitInfoStreetCategory2TollOutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory0Color,
    NMASchemeExitInfoSimplifiedStreetCategory0OutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory0TollColor,
    NMASchemeExitInfoSimplifiedStreetCategory0TollOutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory1Color,
    NMASchemeExitInfoSimplifiedStreetCategory1OutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory1TollColor,
    NMASchemeExitInfoSimplifiedStreetCategory1TollOutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory2Color,
    NMASchemeExitInfoSimplifiedStreetCategory2OutlineColor,
    NMASchemeExitInfoSimplifiedStreetCategory2TollColor,
    NMASchemeExitInfoSimplifiedStreetCategory2TollOutlineColor,
    NMASchemeExtrudedBuildingsColor,
    NMASchemeExtrudedBuildingsColorHighlight0,
    NMASchemeExtrudedBuildingsColorHighlight0OverrideOutline,
    NMASchemeExtrudedBuildingsColorHighlight0OverrideRoof,
    NMASchemeExtrudedBuildingsColorHighlight0OverrideWallBottom,
    NMASchemeExtrudedBuildingsColorHighlight0OverrideWallTop,
    NMASchemeExtrudedBuildingsColorHighlight1,
    NMASchemeExtrudedBuildingsColorHighlight1OverrideOutline,
    NMASchemeExtrudedBuildingsColorHighlight1OverrideRoof,
    NMASchemeExtrudedBuildingsColorHighlight1OverrideWallBottom,
    NMASchemeExtrudedBuildingsColorHighlight1OverrideWallTop,
    NMASchemeExtrudedBuildingsColorHighlight2,
    NMASchemeExtrudedBuildingsColorHighlight2OverrideOutline,
    NMASchemeExtrudedBuildingsColorHighlight2OverrideRoof,
    NMASchemeExtrudedBuildingsColorHighlight2OverrideWallBottom,
    NMASchemeExtrudedBuildingsColorHighlight2OverrideWallTop,
    NMASchemeExtrudedBuildingsColorHighlight3,
    NMASchemeExtrudedBuildingsColorHighlight4,
    NMASchemeExtrudedBuildingsColorHighlight5,
    NMASchemeExtrudedBuildingsColorNamed,
    NMASchemeExtrudedBuildingsColorNamedOverrideOutline,
    NMASchemeExtrudedBuildingsColorNamedOverrideRoof,
    NMASchemeExtrudedBuildingsColorNamedOverrideWallBottom,
    NMASchemeExtrudedBuildingsColorNamedOverrideWallTop,
    NMASchemeExtrudedBuildingsColorOverrideOutline,
    NMASchemeExtrudedBuildingsColorOverrideRoof,
    NMASchemeExtrudedBuildingsColorOverrideWallBottom,
    NMASchemeExtrudedBuildingsColorOverrideWallTop,
    NMASchemeExtrudedBuildingsColorSelected,
    NMASchemeExtrudedBuildingsColorSelectedOverrideOutline,
    NMASchemeExtrudedBuildingsColorSelectedOverrideRoof,
    NMASchemeExtrudedBuildingsColorSelectedOverrideWallBottom,
    NMASchemeExtrudedBuildingsColorSelectedOverrideWallTop,
    NMASchemeFerryTunnelColor,
    NMASchemeFogDarkColor,
    NMASchemeFogLightColor,
    NMASchemeGolfCourseColor,
    NMASchemeGuidanceArrowColor,
    NMASchemeGuidanceArrowOutlineColor,
    NMASchemeGuidanceArrowShadowColor,
    NMASchemeHarborAreaColor,
    NMASchemeHospitalCampusColor,
    NMASchemeIndustrialComplexColor,
    NMASchemeIntermittentRiverColor,
    NMASchemeIntermittentRiverDisplayClass1Color,
    NMASchemeIntermittentRiverDisplayClass2Color,
    NMASchemeIntermittentRiverDisplayClass3Color,
    NMASchemeIntermittentRiverDisplayClass4Color,
    NMASchemeIntermittentRiverDisplayClass5Color,
    NMASchemeIntermittentRiverDisplayClass6Color,
    NMASchemeIntermittentRiverDisplayClass7Color,
    NMASchemeIntermittentRiverDisplayClass8Color,
    NMASchemeLakeColor,
    NMASchemeLakeDisplayClass1Color,
    NMASchemeLakeDisplayClass2Color,
    NMASchemeLakeDisplayClass3Color,
    NMASchemeLakeDisplayClass4Color,
    NMASchemeLakeDisplayClass5Color,
    NMASchemeLakeDisplayClass6Color,
    NMASchemeLakeDisplayClass7Color,
    NMASchemeLakeDisplayClass8Color,
    NMASchemeLandColor,
    NMASchemeLandCoverDesertColor,
    NMASchemeLandCoverGlacierColor,
    NMASchemeLineOfControlBackgroundColor,
    NMASchemeLineOfControlColor,
    NMASchemeMarkingDividerCenterColor,
    NMASchemeMarkingLaneDashedColor,
    NMASchemeMarkingLaneSolidColor,
    NMASchemeMilitaryBaseColor,
    NMASchemeNationalForestColor,
    NMASchemeNationalGrasslandColor,
    NMASchemeNationalHistoricParkColor,
    NMASchemeNationalMilitaryParkColor,
    NMASchemeNationalParkColor,
    NMASchemeNationalRecreationAreaColor,
    NMASchemeNationalReserveColor,
    NMASchemeNationalStateParkColor,
    NMASchemeNationalWildlifeRefugeColor,
    NMASchemeNativeReservationColor,
    NMASchemeNeighborhoodColor0,
    NMASchemeNeighborhoodColor1,
    NMASchemeNeighborhoodColor2,
    NMASchemeNeighborhoodColor3,
    NMASchemeNeighborhoodColor4,
    NMASchemeNeighborhoodColor5,
    NMASchemeOceanColor,
    NMASchemeOceanDisplayClass1Color,
    NMASchemeOceanDisplayClass2Color,
    NMASchemeOceanDisplayClass3Color,
    NMASchemeOceanDisplayClass4Color,
    NMASchemeOceanDisplayClass5Color,
    NMASchemeOceanDisplayClass6Color,
    NMASchemeOceanDisplayClass7Color,
    NMASchemeOceanDisplayClass8Color,
    NMASchemePanoramaCoverageColor,
    NMASchemePanoramaCoverageOutlineColor,
    NMASchemePanoramaHighlightPrimaryColor,
    NMASchemePanoramaHighlightSecondaryColor,
    NMASchemePanoramaRasterCoverageColor,
    NMASchemePanoramaRasterCoverageOutlineColor,
    NMASchemePanoramaRouteColor,
    NMASchemePanoramaRouteSecondaryColor,
    NMASchemePanoramaRouteArrowColor,
    NMASchemePanoramaRouteArrowHighlightColor,
    NMASchemePanoramaStreetColor,
    NMASchemeParkColor,
    NMASchemePedestrianAreaColor,
    NMASchemeRailyardColor,
    NMASchemeRiverColor,
    NMASchemeRiverDisplayClass1Color,
    NMASchemeRiverDisplayClass2Color,
    NMASchemeRiverDisplayClass3Color,
    NMASchemeRiverDisplayClass4Color,
    NMASchemeRiverDisplayClass5Color,
    NMASchemeRiverDisplayClass6Color,
    NMASchemeRiverDisplayClass7Color,
    NMASchemeRiverDisplayClass8Color,
    NMASchemeRunwayColor,
    NMASchemeSSAOColor,
    NMASchemeShoppingComplexColor,
    NMASchemeSkyColorBottom,
    NMASchemeSkyColorIntermediate,
    NMASchemeSkyColorTop,
    NMASchemeSportsComplexColor,
    NMASchemeStateBoundaryBackgroundColor,
    NMASchemeStateBoundaryColor,
    NMASchemeStateBoundaryDisputedBackgroundColor,
    NMASchemeStateBoundaryDisputedColor,
    NMASchemeStreetCategory0CenterLineColor,
    NMASchemeStreetCategory0CenterLineTunnelColor,
    NMASchemeStreetCategory0Color,
    NMASchemeStreetCategory0OutlineColor,
    NMASchemeStreetCategory0ThinColor,
    NMASchemeStreetCategory0TunnelColor,
    NMASchemeStreetCategory1Color,
    NMASchemeStreetCategory1OutlineColor,
    NMASchemeStreetCategory1ThinColor,
    NMASchemeStreetCategory1TunnelColor,
    NMASchemeStreetCategory2Color,
    NMASchemeStreetCategory2OutlineColor,
    NMASchemeStreetCategory2ThinColor,
    NMASchemeStreetCategory2TunnelColor,
    NMASchemeStreetCategory3Color,
    NMASchemeStreetCategory3OutlineColor,
    NMASchemeStreetCategory3ThinColor,
    NMASchemeStreetCategory3TunnelColor,
    NMASchemeStreetCategory4Color,
    NMASchemeStreetCategory4OutlineColor,
    NMASchemeStreetCategory4ThinColor,
    NMASchemeStreetCategory4TunnelColor,
    NMASchemeStreetPedestrianColor,
    NMASchemeStreetPedestrianOutlineColor,
    NMASchemeStreetPedestrianThinColor,
    NMASchemeStreetPedestrianTunnelColor,
    NMASchemeStreetWalkwayColor,
    NMASchemeStreetWalkwayOutlineColor,
    NMASchemeStreetWalkwayThinColor,
    NMASchemeStreetWalkwayTunnelColor,
    NMASchemeTMC_INCIDENTBLOCKINGColor,
    NMASchemeTMC_INCIDENTBLOCKINGSelectedColor,
    NMASchemeTMC_INCIDENTHIGHColor,
    NMASchemeTMC_INCIDENTHIGHSelectedColor,
    NMASchemeTMC_INCIDENTNORMALColor,
    NMASchemeTMC_INCIDENTNORMALSelectedColor,
    NMASchemeTMC_INCIDENTVERY_HIGHColor,
    NMASchemeTMC_INCIDENTVERY_HIGHSelectedColor,
    NMASchemeTransitAerialDefaultColor,
    NMASchemeTransitBackgroundColor,
    NMASchemeTransitBlendColor,
    NMASchemeTransitBusExpressDefaultColor,
    NMASchemeTransitBusIntercityDefaultColor,
    NMASchemeTransitBusPublicDefaultColor,
    NMASchemeTransitBusTouristicDefaultColor,
    NMASchemeTransitHighlightedBackgroundColor,
    NMASchemeTransitHighlightedFontOutlineColor,
    NMASchemeTransitInclinedDefaultColor,
    NMASchemeTransitMonorailDefaultColor,
    NMASchemeTransitRailCityMetroDefaultColor,
    NMASchemeTransitRailLightDefaultColor,
    NMASchemeTransitRailRegionalDefaultColor,
    NMASchemeTransitTrainHighSpeedDefaultColor,
    NMASchemeTransitTrainIntercityDefaultColor,
    NMASchemeTransitTrainRegionalDefaultColor,
    NMASchemeTransitWaterBackgroundColor,
    NMASchemeTransitWaterDefaultColor,
    NMASchemeTransitWaterHighlightedBackgroundColor,
    NMASchemeTransitWaterHighlightedFontOutlineColor,
    NMASchemeTruckLineColor,
    NMASchemeUniversityCampusColor,
    NMASchemeWaterColor0m,
    NMASchemeWaterColor3000m,
    NMASchemeWeatherDisplayLabelColor,
    NMASchemeWeatherDisplayLabelOutlineColor,
    NMASchemeWoodlandColor,
    NMASchemeWorldMountainsColor1500m,
    NMASchemeWorldMountainsColor3000m,
    NMASchemeColorPropertyCount
};

/**
* \enum NMASchemeFloatProperty
*/
typedef NS_ENUM(NSInteger, NMASchemeFloatProperty) {
    NMASchemeAvoidBlockedRouteOutlineWidth,
    NMASchemeAvoidBlockedRouteWidth,
    NMASchemeBillboardAdjacentOutlineWidth,
    NMASchemeBillboardAdjacentPointerHeight,
    NMASchemeBillboardOffRouteOutlineWidth,
    NMASchemeBillboardOffRoutePointerHeight,
    NMASchemeBuiltupBorderBackgroundWidth,
    NMASchemeBuiltupBorderWidth,
    NMASchemeCanalWaterChannelDisplayClass1Width,
    NMASchemeCanalWaterChannelDisplayClass2Width,
    NMASchemeCanalWaterChannelDisplayClass3Width,
    NMASchemeCanalWaterChannelDisplayClass4Width,
    NMASchemeCanalWaterChannelDisplayClass5Width,
    NMASchemeCanalWaterChannelDisplayClass6Width,
    NMASchemeCanalWaterChannelDisplayClass7Width,
    NMASchemeCanalWaterChannelDisplayClass8Width,
    NMASchemeCanalWaterChannelWidth,
    NMASchemeCountryBoundaryBackgroundWidth,
    NMASchemeCountryBoundaryWidth,
    NMASchemeCountryBoundaryDisputedBackgroundWidth,
    NMASchemeCountryBoundaryDisputedWidth,
    NMASchemeExitInfoStreetCategory0OutlineWidth,
    NMASchemeExitInfoStreetCategory0TollOutlineWidth,
    NMASchemeExitInfoStreetCategory1OutlineWidth,
    NMASchemeExitInfoStreetCategory1TollOutlineWidth,
    NMASchemeExitInfoStreetCategory2OutlineWidth,
    NMASchemeExitInfoStreetCategory2TollOutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory0OutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory0TollOutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory1OutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory1TollOutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory2OutlineWidth,
    NMASchemeExitInfoSimplifiedStreetCategory2TollOutlineWidth,
    NMASchemeExtrudedBuildingsDefaultHeight,
    NMASchemeExtrudedBuildingsGradientStopHeight,
    NMASchemeFarPlaneHorizonHeightPercent,
    NMASchemeFarPlaneHorizonHeightTiltRange,
    NMASchemeFarPlaneHorizonHeightTiltStart,
    NMASchemeIntermittentRiverDisplayClass1Width,
    NMASchemeIntermittentRiverDisplayClass2Width,
    NMASchemeIntermittentRiverDisplayClass3Width,
    NMASchemeIntermittentRiverDisplayClass4Width,
    NMASchemeIntermittentRiverDisplayClass5Width,
    NMASchemeIntermittentRiverDisplayClass6Width,
    NMASchemeIntermittentRiverDisplayClass7Width,
    NMASchemeIntermittentRiverDisplayClass8Width,
    NMASchemeIntermittentRiverWidth,
    NMASchemeLaneWidthM,
    NMASchemeLineOfControlBackgroundWidth,
    NMASchemeLineOfControlWidth,
    NMASchemeMarkingLaneWidth,
    NMASchemePanoramaRasterCoverageBlendWidthFactor,
    NMASchemePanoramaRasterCoverageOutlineWidthFactor,
    NMASchemePanoramaRouteArrowWidthM,
    NMASchemePanoramaStreetWidthM,
    NMASchemeRiverDisplayClass1Width,
    NMASchemeRiverDisplayClass2Width,
    NMASchemeRiverDisplayClass3Width,
    NMASchemeRiverDisplayClass4Width,
    NMASchemeRiverDisplayClass5Width,
    NMASchemeRiverDisplayClass6Width,
    NMASchemeRiverDisplayClass7Width,
    NMASchemeRiverDisplayClass8Width,
    NMASchemeRiverWidth,
    NMASchemeStateBoundaryBackgroundWidth,
    NMASchemeStateBoundaryWidth,
    NMASchemeStateBoundaryDisputedBackgroundWidth,
    NMASchemeStateBoundaryDisputedWidth,
    NMASchemeStreetCategory0CenterLineWidth,
    NMASchemeStreetCategory0OutlineWidth,
    NMASchemeStreetCategory0Width,
    NMASchemeStreetCategory1OutlineWidth,
    NMASchemeStreetCategory1Width,
    NMASchemeStreetCategory2OutlineWidth,
    NMASchemeStreetCategory2Width,
    NMASchemeStreetCategory3OutlineWidth,
    NMASchemeStreetCategory3Width,
    NMASchemeStreetCategory4OutlineWidth,
    NMASchemeStreetCategory4Width,
    NMASchemeStreetPedestrianOutlineWidth,
    NMASchemeStreetPedestrianWidth,
    NMASchemeStreetWalkwayOutlineWidth,
    NMASchemeStreetWalkwayWidth,
    NMASchemeZoneBorderWidth,
    NMASchemeFloatPropertyCount
};

/**
* \enum NMASchemeIntegerProperty
*/
typedef NS_ENUM(NSInteger, NMASchemeIntegerProperty) {
    NMASchemeBuiltupAreaMinPixelHeight,
    NMASchemeBuiltupAreaMinPixelWidth,
    NMASchemeElevationMapHeight0,
    NMASchemeElevationMapHeight1,
    NMASchemeElevationMapHeight2,
    NMASchemeElevationMapHeight3,
    NMASchemeElevationMapHeight4,
    NMASchemeElevationMapHeight5,
    NMASchemeElevationMapHeight6,
    NMASchemeElevationMapHeight7,
    NMASchemeElevationMapNumHeights,
    NMASchemeFogHeight,
    NMASchemePanoramaCoverageOutlineWidth,
    NMASchemePanoramaCoverageWidth,
    NMASchemeTransitAerialWidth,
    NMASchemeTransitBusExpressWidth,
    NMASchemeTransitBusIntercityWidth,
    NMASchemeTransitBusPublicWidth,
    NMASchemeTransitBusTouristicWidth,
    NMASchemeTransitInclinedWidth,
    NMASchemeTransitMonorailWidth,
    NMASchemeTransitOutlineWidth,
    NMASchemeTransitRailCityMetroWidth,
    NMASchemeTransitRailLightWidth,
    NMASchemeTransitRailRegionalWidth,
    NMASchemeTransitTrainHighSpeedWidth,
    NMASchemeTransitTrainIntercityWidth,
    NMASchemeTransitTrainRegionalWidth,
    NMASchemeTransitWaterWidth,
    NMASchemeTruckLineCategory0Width,
    NMASchemeTruckLineCategory1Width,
    NMASchemeTruckLineCategory2Width,
    NMASchemeTruckLineCategory3Width,
    NMASchemeTruckLineCategory4Width,
    NMASchemeIntegerPropertyCount
};


/**
 * \class NMACustomizableVariable NMACustomizableVariable.h "NMACustomizableVariable.h"
 *
 * Represents a map customization property.
 */
@interface NMACustomizableVariable : NSObject

/*!
 * Returns a string representation of the property
 */
@property (nonatomic, strong) NSString *variableName;

/*!
 * Returns the zoom level range where this variable customization will be applicable to
 *
 * \note This property is only relevant when SETTING a custom property
 */
@property (nonatomic, strong) NMAZoomRange *zoomRange;

/*!
 * Returns the type of property (e.g.: integer, float, color, font style, ..)
 */
@property (nonatomic, readonly) NMACustomizablePropertyType propertyType;

/*!
 * Returns the property identifier (id of NMASchemeColorProperty, or NMASchemeFloatProperty, etc.)
 */
@property (nonatomic, readonly) NSInteger propertyIdentifier;

/*!
 * When reading a property, this property indicates the respective zoom level
 *
 * \note This property is only relevant when READING a custom property
 */
@property (nonatomic) float zoomLevel;

/*!
 *
 * Utility method which returns a dictionary with all available customizable properties,
 * where the key is the respective property name, and the object an NMACustomizableVariable
 *
 * \note Read NMACustomizableVariable's propertyType to find out whether it is a
 * NMACustomizableVariable, NMACustomizableColor, and so on.
 *
 * \note This method is useful for example to iterate over all available properties programatically
 */
+ (NSDictionary<NSString *, NMACustomizableVariable *> *)allAvailableProperties;

@end


/**
 * \class NMACustomizableColor NMACustomizableVariable.h "NMACustomizableColor.h"
 *
 * Represents a map customization color property with red, green, blue components ranging
 * from 0 to 255.
 */
@interface NMACustomizableColor : NMACustomizableVariable

@property (nonatomic) NSInteger red;
@property (nonatomic) NSInteger green;
@property (nonatomic) NSInteger blue;

/*!
 * Utility method to configure the color from an UIColor object.
 *
 * \note This property is only relevant when SETTING a custom property
 * The alpha component of UIColor is not considered
 */
-(void)setColor:(UIColor *) color;

/*!
 * Utility method to configure the color from an UIColor object.
 *
 * \note This property is only relevant when READING a custom property
 * The alpha component of the returned UIColor is always 1.
 */
-(UIColor *)color;

@end
/** @}  */
