/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * This enum defines the types of transit operators.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityOperatorType) {
    /** \brief Unknown type. */
    NMAUrbanMobilityOperatorTypeUnknown = 0,

    /** \brief Operator uses estimated times for departures and routing. */
    NMAUrbanMobilityOperatorTypeEstimated,

    /** \brief Operator uses time tables for departures and routing. */
    NMAUrbanMobilityOperatorTypeTimeTable,

    /** \brief Operator tracks real time changes to departures and routes. */
    NMAUrbanMobilityOperatorTypeRealTime
};


/**
 * \class NMAUrbanMobilityOperator NMAUrbanMobilityOperator.h "NMAUrbanMobilityOperator.h"
 *
 * Transit operator which governs transit lines.
 *
 * \note Disclaimers associated with the operator must be displayed to end-users.
 *
 * \sa NMAUrbanMobilityOperatorDisclaimer
 */
@interface NMAUrbanMobilityOperator : NSObject

/**
 * Unique code of the operator.
 */
@property (nonatomic, readonly) NSString *code;

/**
 * Name of the operator.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Type of the operator.
 */
@property (nonatomic, readonly) NMAUrbanMobilityOperatorType type;

/**
 * Disclaimers which needs to be shown to the end-users as a part of the agreement with the operator.
 */
@property (nonatomic, readonly) NSArray *disclaimers;

@end
/** @}  */
