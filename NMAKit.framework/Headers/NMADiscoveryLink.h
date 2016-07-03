/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALink.h"

@class NMADiscoveryRequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */


/**
 * \class NMADiscoveryLink NMADiscoveryLink.h "NMADiscoveryLink.h"
 *
 * \brief Represents a discovery search results link that can be used to perform another discovery search.
 */
@interface NMADiscoveryLink : NMALink

/**
 * Creates an NMADiscoveryRequest object to perform another NMADiscoveryPage request.
 *
 * \note Attempts to read this property could return nil.
 *
 * \return The NMADiscoveryRequest
 */
- (NMADiscoveryRequest *)request;

@end

/** @} */
