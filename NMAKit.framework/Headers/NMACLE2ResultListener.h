/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATypes.h"

NS_ASSUME_NONNULL_BEGIN

@class NMACLE2Request;
@class NMACLE2Result;

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * Represents an event listener that reports information about query
 * progress changes or query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMACLE2ResultListener<NSObject>

@required
/**
 * \brief Callback when a request has completed.
 *
 * \param request An %NMACLE2Request object of the type shown on the left in the list above.
 *
 * \param result An object of type %NMACLE2Result containing the request's result objects.
 *
 * \param error NSError for this request. Nil if the request completed successfully,
 * otherwise, this value is populated with an NMACLEError error code and a domain of
 * NMACLE2RequestError.
 */
- (void)          request:(NMACLE2Request *)request
    didCompleteWithResult:(NMACLE2Result *)result
                    error:(nullable NSError *)error;
@end

/** @} */

NS_ASSUME_NONNULL_END