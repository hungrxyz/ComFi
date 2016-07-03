/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * \class NMAUrbanMobilityTicket NMAUrbanMobilityTicket.h "NMAUrbanMobilityTicket.h"
 *
 * A single ticket which covers a portion of a journey
 */
@interface NMAUrbanMobilityTicket : NSObject

/**
 * Name of the ticket.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Price of the ticket.
 */
@property (nonatomic, readonly) double price;

/**
 * Currency the price is in.
 */
@property (nonatomic, readonly) NSString *currency;

/**
 * Name of the vendor.
 */
@property (nonatomic, readonly) NSString *vendor;

/**
 * List of strings, representig the IDs of the manevuer which this ticket covers.
 */
@property (nonatomic, readonly) NSArray *transitManeuverIds;

@end
