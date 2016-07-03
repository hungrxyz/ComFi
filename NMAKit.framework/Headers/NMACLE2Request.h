/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMACLE2Request;
@class NMACLE2Result;

NS_ASSUME_NONNULL_BEGIN

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * The possible NMACLE2Request error codes.
 */
typedef NS_ENUM(NSUInteger, NMACLE2Error) {
    NMACLE2ErrorNone,
    NMACLE2ErrorInvalidParameter,
    NMACLE2ErrorBusy,
    NMACLE2ErrorNetworkCommunication,
    NMACLE2ErrorOperationNotAllowed
};

/**
 * A typedef of a block parameter signature used with \link NMARequest::startWithBlock:\endlink.
 *
 * \note The block will be called on the main queue.
 *
 * \param request The search request being completed.
 * \param result The search results. It can be nil if no results are found or an error
 * is encountered.
 * \param error The error if the request failed, or nil if the request was successful.
 */
typedef void (^NMACLE2RequestCompletionBlock)(NMACLE2Request *request, NMACLE2Result *result, NSError *__nullable error);

/**
 * \class NMACLE2Request NMACLE2Request.h "NMACLE2Request.h"
 *
 * Represents a base interface for a search request.
 */
@interface NMACLE2Request : NSObject

@end

/**  @}  */

NS_ASSUME_NONNULL_END
