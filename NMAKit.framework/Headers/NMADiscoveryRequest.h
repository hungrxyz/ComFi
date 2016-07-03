/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMADiscoveryRequest NMADiscoveryRequest.h "NMADiscoveryRequest.h"
 *
 * Represents a request to retrieve an NMADiscoveryPage object.
 *
 */
@interface NMADiscoveryRequest : NMARequest

/**
 * The text format of the request results.
 *
 * \note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

/** @} */
