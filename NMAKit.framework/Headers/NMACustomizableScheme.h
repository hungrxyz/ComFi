/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACustomizableVariable.h"


/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */
/**
 * \class NMACustomizableScheme NMACustomizableScheme.h "NMACustomizableScheme.h"
 *
 * Represents a Customizable scheme. Customizable schemes are obtained from %NMAMapView% class
 * with getCustomizableSchemeWithName: or createCustomizableSchemeWithName: methods
 *
 */
@interface NMACustomizableScheme : NSObject

- (instancetype)init __attribute__((unavailable("Init not available. Please fetch object from NMAMapView class.")));

/**
 * Retrieves a color property
 *
 * \param colorProperty The %NMASchemeColorProperty% to retrieve.
 *
 * \param zoomLevel Zoom level for property.
 *
 * \note The zoom parameter takes a specific zoom level, and not a range.
 *
 * \return The %NMACustomizableColor% object.
 */
- (NMACustomizableColor *)colorForProperty:(NMASchemeColorProperty)colorProperty forZoomLevel:(float)zoomLevel;

/*!
 * Sets a color property.
 *
 * \param variableColor The NMACustomizableColor.
 * \param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setColorProperty:(NMACustomizableColor *)variableColor forZoomRange:(NMAZoomRange *)zoomRange;

/**
 * Retrieve value of an Integer property
 *
 * \param integerProperty The %NMASchemeIntegerProperty% to retrieve.
 *
 * \param zoomLevel Zoom level for property.
 *
 * \note The zoom parameter takes a specific zoom level, and not a range.
 *
 * \return The property value as int.
 */
- (int)integerForProperty:(NMASchemeIntegerProperty)integerProperty forZoomLevel:(float)zoomLevel;

/*!
 * Sets a property of Integer type.
 *
 * \param integerProperty The property to be modified.
 *
 * \param value Value used to set property.
 *
 * \param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setIntegerProperty:(NMASchemeIntegerProperty)integerProperty withValue:(int)value forZoomRange:(NMAZoomRange *)zoomRange;

/**
 * Retrieve value of a Float property
 *
 * \param floatProperty The %NMASchemeFloatProperty% to retrieve.
 *
 * \param zoomLevel Zoom level for property.
 *
 * \note The zoom parameter takes a specific zoom level, and not a range.
 *
 * \return The property value as float.
 */
- (float)floatForProperty:(NMASchemeFloatProperty)floatProperty forZoomLevel:(float)zoomLevel;

/*!
 * Sets a property of Float type.
 *
 * \param floatProperty The property to be modified.
 *
 * \param value Value used to set property.
 *
 * \param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setFloatProperty:(NMASchemeFloatProperty)floatProperty withValue:(float)value forZoomRange:(NMAZoomRange *)zoomRange;

/**
 * Returns the name of a customizable scheme object.
 *
 * \return name of customizable scheme or nil if scheme is not valid.
 */
- (NSString *)name;

@end
/** @}  */
