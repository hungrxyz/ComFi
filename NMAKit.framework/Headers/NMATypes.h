/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#ifndef NMASDK_NMATypes_h
#define NMASDK_NMATypes_h

/**
 * \addtogroup NMA_Common  NMA Common Group
 *
 * The Common group includes classes, protocols, and enumerations
 * that are generally used by other packages in the iOS SDK.
 * Some important classes in this group are
 * {@link NMAGeoCoordinates} and {@link NMAPositioningManager}.
 *
 * @{
 */

/**
 *  The minimum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMinimumZIndex;

/**
 *  The maximum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMaximumZIndex;


/**
 * Lower limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMinimumZoomLevel;

/**
 * Upper limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMaximumZoomLevel;


/**
 *  Represents fixed locations or regions within a bounding rectangle.
 */
typedef NS_ENUM(NSUInteger, NMALayoutPosition) {
    NMALayoutPositionTopLeft,
    NMALayoutPositionTopCenter,
    NMALayoutPositionTopRight,
    NMALayoutPositionCenterLeft,
    NMALayoutPositionCenter,
    NMALayoutPositionCenterRight,
    NMALayoutPositionBottomLeft,
    NMALayoutPositionBottomCenter,
    NMALayoutPositionBottomRight
};


/**
 * \brief Represents the display order of the various rendering layers of a map.
 *
 * Objects at NMAMapLayerTypeForeground are rendered on top of objects at NMAMapLayerTypePointOfInterest
 * which are rendered on top of objects at NMAMapLayerTypeRoad and so on.
 *
 * Objects within each layer may be further organized by a Z Index that dictates the ordering
 * within the layer. For examples, NMAMapObject objects that you create via the various NMAMapObject
 * dervied classes reside at NMAMapLayerTypeForeground and their Z Index can be set via the
 * NMAMapObject#zIndex: property.
 */
typedef NS_ENUM(NSUInteger, NMAMapLayerType) {
    /**
     * Objects at this layer are placed on top of any other objects (they appear closer to the viewer
     * than other objects).
     *
     * \note NMAMapObject objects that you create via the various NMAMapObject dervied classes reside
     * at this layer.
     */
    NMAMapLayerTypeForeground,

    /**
     * Objects at this layer are used to augment Point of Interest information.
     *
     * \note %NMAMapTileLayer (if available) objects can not currently be placed at this layer.
     */
    NMAMapLayerTypePointOfInterest,

    /**
     * Objects at this layer are used to augment Transit Stop information. Transit stops are rendered
     * on top of roads .
     *
     * \note %NMAMapTileLayer (if available) objects can not currently be placed at this layer.
     */
    NMAMapLayerTypeTransitStop,

    /**
     * Objects at this layer add some information to the road network. For example, traffic or traffic
     * incident markers would be added at this level. Objects at this level  appear on top of roads.
     */
    NMAMapLayerTypeRoad,

    /**
     * Objects at this layer add information to area features. For example, heat maps would be added at
     * this layer. Objects at this layer appear on top of the map background but underneath roads.
     */
    NMAMapLayerTypeArea,

    /**
     * Objects at this layer are placed directly over (on top of or in front of) objects at
     * the NMAMapLayerTypeReplacement layer. Use this layer for opaque or transparent objects
     * that should appear on top of the basic map data.
     */
    NMAMapLayerTypeBackground,

    /**
     * Objects at this layer are intended replace the basic map data. For example, custom satellite
     * data would be rendered at this layer. Note that placing objects at this layer does not
     * disable rendering of the basic map data.
     */
    NMAMapLayerTypeReplacement
};


/**
 *  Represents supported pixel formats for render buffers and bitmaps
 */
typedef NS_ENUM(NSUInteger, NMAPixelFormat) {
    /** \brief Format is unknown.                    */
    NMAPixelFormatUnknown,
    /** \brief Format is RGBA (4 bytes per pixel)    */
    NMAPixelFormatRGBA,
    /** \brief Format is BGRA (4 bytes per pixel)    */
    NMAPixelFormatBGRA,
    /** \brief Format is RGB (3 bytes per pixel)     */
    NMAPixelFormatRGB,
    /** \brief Format is R5G6B5 (2 bytes per pixel)  */
    NMAPixelFormatR5G6B5
};

/**
 * \brief Error codes that may be returned from places search requests.
 */
typedef NS_ENUM(NSUInteger, NMARequestError) {
    /** \brief No error.                                                   */
    NMARequestErrorNone = 0,
    /** \brief Unknown error.                                              */
    NMARequestErrorUnknown,
    /** \brief Request is missing an address parameter.                    */
    NMARequestErrorAddressMissing,
    /** \brief Location context is invalid.                                */
    NMARequestErrorLocationContextInvalid,
    /** \brief Request is missing location context parameter.              */
    NMARequestErrorLocationContextMissing,
    /** \brief Request is missing a country code in the address parameter. */
    NMARequestErrorCountryCodeMissing,
    /** \brief Request missing search text parameter.                      */
    NMARequestErrorSearchTextMissing,
    /** \brief Invalid query parameter.                                    */
    NMARequestErrorInvalidParameter,
    /** \brief Network communications error.                               */
    NMARequestErrorNetworkCommunication,
    /** \brief Backend server unreachable.                                 */
    NMARequestErrorNetworkServer,
    /** \brief Request input missing.                                      */
    NMARequestErrorNetworkEmptyInput,
    /** \brief Application ID and/or token are missing or invalid.         */
    NMARequestErrorInvalidCredentials,
    /** \brief Request failed due to an HTTP error.                        */
    NMARequestErrorHttp,
    /** \brief Unknown network error.                                      */
    NMARequestErrorNetworkUnknown,
    /** \brief Functionality not supported                                 */
    NMARequestErrorNotSupported,
    /**
     * \brief An entity is not ready. All poll functions return this when one needs to
     * poll again.  Also if an operation is in progress
     */
    NMARequestErrorNotReady,
    /** \brief When something was not found                                */
    NMARequestErrorNotFound,
    /** \brief When resource already exists                                */
    NMARequestErrorAlreadyExists,
    /** \brief Out of memory                                               */
    NMARequestErrorOutOfMemory,
    /** \brief When operation fails (e.g.extracting of file failed)        */
    NMARequestErrorOperationFailed,
    /** \brief Operation aborted by user                                   */
    NMARequestErrorAborted,
    /** \brief Search index failure                                        */
    NMARequestErrorFinderIndexFailure,
    /** \brief Resource moved (e.g. resource URI changed)                  */
    NMARequestErrorMovedPermanently,
    /** \brief Resource contend remains the same                           */
    NMARequestErrorNotModified,
    /** \brief Invalid request (places component might need to be updated) */
    NMARequestErrorBadRequest,
    /** \brief Resource no longer exists                                   */
    NMARequestErrorResourceGone,
    /** \brief An error occured during document parsing (json, etc.)       */
    NMARequestErrorParse,
    /** \brief Request timeout                                             */
    NMARequestErrorTimeout,
    /** \brief Access to this operation is denied. Contact your HERE representative for more information.      */
    NMARequestErrorOperationNotAllowed
};


/**
 * Defines the color of the route.
 * Color is pre-defined by the map scheme according to the type.
 */
typedef NS_ENUM(NSUInteger, NMARouteDisplayType) {
    /**
     * \brief The "default" type of the route.
     */
    NMARouteDisplayTypePrimary,
    /**
     * \brief Secondary route can be used for example to show
     * another route with different settings or dynamic penalties.
     */
    NMARouteDisplayTypeSecondary,
    /**
     * \brief The route color is set by the user
     */
    NMARouteDisplayTypeUserDefined
};

/**
 *  Defines the pedestrian map feature type used to show or hide map features that pedestrians may
 * encounter while walking.
 */
typedef NS_ENUM(NSInteger, NMAMapPedestrianFeatureType) {
    /** \brief Crosswalk                */
    NMAMapPedestrianFeatureTypeCrosswalk,
    /** \brief Stairway                 */
    NMAMapPedestrianFeatureTypeStairs,
    /** \brief Escalator                */
    NMAMapPedestrianFeatureTypeEscalator,
    /** \brief Elevator                 */
    NMAMapPedestrianFeatureTypeElevator,
    /** \brief Tunnel                   */
    NMAMapPedestrianFeatureTypeTunnel,
    /** \brief Bridge                   */
    NMAMapPedestrianFeatureTypeBridge,
    /** \brief All pedestrian features  */
    NMAMapPedestrianFeatureTypeAll
};

/**
 *  Defines the fleet map feature type used to show or hide map features important to fleet vehicles.
 */
typedef NS_ENUM(NSInteger, NMAMapFleetFeatureType) {
    NMAMapFleetFeatureTypeEnvironmentalZones,
    NMAMapFleetFeatureTypeCongestionZones,
    NMAMapFleetFeatureTypeTruckRestrictions,
    NMAMapFleetFeatureTypeAll
};

#endif
/** @}  */
