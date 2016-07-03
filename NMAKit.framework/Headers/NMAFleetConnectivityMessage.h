/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * \addtogroup NMA_FCE NMA Fleet Connectivity Extensions Group
 * @{
 */

/**
 * Abstract interface for incoming messages.
 */
@interface NMAFleetConnectivityMessage : NSObject

/**
 * Optional job ID of this message.
 */
@property (readonly, nonatomic) NSString *jobId;

/**
 * ID of the dispatcher of this message.
 */
@property (readonly, nonatomic) NSString *dispatcherId;

/**
 * ID of the asset for which this message was intended.
 * This will be equal to the asset ID that was set in the %NMAFleetConnectivityService.
 */
@property (readonly, nonatomic) NSString *assetId;

/**
 * Optional generic message specified by the dispatcher.
 */
@property (readonly, nonatomic) NSString *message;

/**
 * Creation time in seconds.
 */
@property (readonly, nonatomic) NSTimeInterval creationTime;

/**
 * Dictionary of strings with custom content sent by the dispatcher.
 */
@property (readonly, nonatomic) NSDictionary *content;

@end

/**  @}  */
