/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */


/**
 * Encapsulates the response to a custom location request made using
 * the NMACustomLocationManager.
 *
 * \sa NMACustomLocationManager
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomLocationResponse : NSObject

/**
 * The name of the layer on which locations were requested.
 */
@property (nonatomic, readonly) NSString *layerName;

/**
 * The Id of the layer on which locations were requested.
 */
@property (nonatomic, assign, readonly) unsigned int layerId;

/**
 * The maximum number of location results which were requested.
 */
@property (nonatomic, assign, readonly) unsigned int resultLimit;

/**
 * The array of NMACustomLocation objects found by the request.
 */
@property (nonatomic, readonly) NSArray *locations;

/**
 * The array of NMACustomGeometry objects found by the request.
 */
@property (nonatomic, readonly) NSArray *geometries;

@end
/**  @}  */
