/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARouteManager.h"
#import "NMARoutingError.h"

@class NMARouter;


/**
 * Base interface for route calculation class. Represents controls for performing
 * a type of routing request. It defines routing type specific operations and listeners.
 */
@interface NMARouter : NSObject

/**
 * Indicates whether or not the route calculation is ongoing.
 *
 * \note Any requests made while the NMARouter is busy will fail.
 */
@property (nonatomic, getter = isBusy) BOOL busy;

/**
 * \brief Cancels the current route calculation.
 *
 * \note This API is asynchronous as it takes some time cancel all underlying operations.
 * Use isBusy to check whether calculation is still ongoing or not.
 */
- (void)cancel;

@end
/** @}  */
