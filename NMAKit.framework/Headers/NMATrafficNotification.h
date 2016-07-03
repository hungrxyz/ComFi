/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Common NMA Common Group
 * @{
 */


/**
 * Traffic notification for the current navigation session.
 *
 * \note This class should not be instantiated directly.
 */
@interface NMATrafficNotification : NSObject

/**
 * Array of NMATrafficNotificationInfo objects associated with the traffic notification
 */
@property (nonatomic, readonly) NSArray *trafficNotificationInfo;

@end

/** @} */
