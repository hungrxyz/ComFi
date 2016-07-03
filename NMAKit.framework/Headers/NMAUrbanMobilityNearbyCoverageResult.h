/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
@class NMAUrbanMobilityExploredCoverage;
@class NMAUrbanMobilityCity;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * ENUM values for \sa type parameter. It's a type of coverage in this area.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityCoverageType) {
    /** \brief real time type */
    NMAUrbanMobilityCoverageTypeRealTime = 0,         //0
    /** \brief  estimated routing type */
    NMAUrbanMobilityCoverageTypeSimpleRouting,        //1
    /** \brief  timetable type */
    NMAUrbanMobilityCoverageTypeTimeTable,            //2
    /** \brief  any others(unknown) type */
    NMAUrbanMobilityCoverageTypeUnknown               //3
};


/**
 * \class NMAUrbanMobilityNearbyCoverageResult NMAUrbanMobilityNearbyCoverageResult.h "NMAUrbanMobilityNearbyCoverageResult.h"
 *
 * \brief Represents a Response to nearby coverage request. Contains information about nearby stops, lines and city (in case if user is assumed to be in one).
 * Contains information about what can be used if routing is requested from same location
 * Related to tag "LocalCoverage" and includes data from tag "NearbyCoverage"
 */

@interface NMAUrbanMobilityNearbyCoverageResult : NSObject

/**
 * Refers to users location and can be used to collect feedback without disclosing users exact location
 */
@property (nonatomic, readonly) NSString *geoRef;

/**
 *  Radius (in meters) for which coverage information is provided.
 */
@property (nonatomic, readonly) NSInteger radius;

/*
 * Number of stops returned within radius.
 */
@property (nonatomic, readonly) NSInteger stopsCount;

/**
 * Number of transit lines returned.
 */
@property (nonatomic, readonly) NSInteger linesCount;

/**
 * Coverage type in returned area.
 */
@property (nonatomic, readonly) NMAUrbanMobilityCoverageType type;

/**
 * YES if there is public transport covered within radius otherwise NO.
 */
@property (nonatomic, readonly, getter = isCovered) BOOL covered;

/**
 * Contains information about what's available further away meaning that user need first change it's location to get routing.
 * Element %NMAUrbanMobilityExploredCoverage also includes info of closest station (if there is one inside of radius).
 * Also information of lines going through 5 closest stations is included here (if there are stations inside of radius).
 */
@property (nonatomic, readonly) NMAUrbanMobilityExploredCoverage *exploredCoverage;

/**
 * Coverage information about a %NMAUrbanMobilityCity
 */
@property (nonatomic, readonly) NMAUrbanMobilityCity *city;

@end
/** @}  */
