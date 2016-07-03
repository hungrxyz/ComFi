/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMASafetySpotNotificationInfo;


/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 * @{
 */

/**
 * Represents safety spot notification object.
 */
@interface NMASafetySpotNotification : NSObject

/**
 * Array of NMASafetySpotNotificationInfo objects associated with the safety spot notification
 */
@property (nonatomic, readonly) NSArray<NMASafetySpotNotificationInfo *> *safetySpotNotificationInfo;

@end

/**  @}  */
