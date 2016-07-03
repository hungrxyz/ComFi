/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"

@class NMAUrbanMobilityOperator;


/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \class NMAUrbanMobilityLine NMAUrbanMobilityLine.h "NMAUrbanMobilityLine.h"
 *
 * Defines a public transit line.
 *
 * \sa NMAUrbanMobilityOperator
 */
@interface NMAUrbanMobilityLine : NSObject

/**
 * The name of the line.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Means of transport which servers the line (Bus, Tram, Train, etc).
 */
@property (nonatomic, readonly) NMAUrbanMobilityTransitMode transitMode;

/**
 * Specific name of the transit mode which serves the line.
 */
@property (nonatomic, readonly) NSString *transitModeName;

/**
 * Transit operator which governs the line (might be not available).
 */
@property (nonatomic, readonly) NMAUrbanMobilityOperator *transitOperator;

/**
 * Direction which the line is heading.
 * Normally the direction matches the name of the last station of the line.
 */
@property (nonatomic, readonly) NSString *direction;

/**
 * Describes whether or not bikes are allowed on the line.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability bikeAllowed;

/**
 * Describes whether or not the line is barrier free.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability barrierFree;

/**
 * Number of minutes the line might be delayed for.
 * Value of 0 means that there are no delays expected on the line.
 */
@property (nonatomic, readonly) NSUInteger expectedDelay;

/**
 * Line color in \#RRGGBB format.
 */
@property (nonatomic, readonly) NSString *color;

/**
 * Line name color in \#RRGGBB format.
 */
@property (nonatomic, readonly) NSString *nameColor;

/**
 * Color of the border around the line name in \#RRGGBB format.
 */
@property (nonatomic, readonly) NSString *outlineColor;

/**
 * Unique ID for the line icon.
 */
@property (nonatomic, readonly) NSString *iconId;

/**
 * Shape of the border around the line name.
 */
@property (nonatomic, readonly) NSString *iconShape;

/**
 * Link to the tariff information web page.
 */
@property (nonatomic, readonly) NSURL *tariffUrl;

@end
/** @}  */
