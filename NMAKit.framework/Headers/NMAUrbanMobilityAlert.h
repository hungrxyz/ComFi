/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityOperator;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * \class NMAUrbanMobilityAlert NMAUrbanMobilityAlert.h "NMAUrbanMobilityAlert.h"
 * All available information about one transit alert.
 */
@interface NMAUrbanMobilityAlert : NSObject

/**
 * Get unique Id for this alert. Might help to identify
 * if this alert was already processed on the client.
 *
 * \return alert id.
 */
@property (nonatomic, readonly) NSString *uniqueId;

/**
 * Get the %NMAUrbanMobilityOperator whose services are affected by this alert.
 *
 * \return affected operator.
 */
@property (nonatomic, readonly) NMAUrbanMobilityOperator *transitOperator;

/**
 * Get array of %NMAUrbanMobilityLine objects affected by this alert.
 *
 * \return array of lines.
 */
@property (nonatomic, readonly) NSArray *lines;

/**
 * Get alert information text to display to the user.
 * Information text is localized to the locale of the region.
 * If given language is not supported, English version is returned.
 *
 * \return alert information text.
 */
@property (nonatomic, readonly) NSString *info;

/**
 * Get the NSDate from which this alert is valid.
 *
 * \return valid from date.
 */
@property (nonatomic, readonly) NSDate *validFrom;

/**
 * Get the NSDate till which this alert is valid.
 *
 * \return valid till date.
 */
@property (nonatomic, readonly) NSDate *validTill;

/**
 * Get a link to the original source of this alert
 * (Twitter feed, Agency API, RSS etc.).
 *
 * \return link (as NSString) to the alert's source, or nil if not available.
 */
@property (nonatomic, readonly) NSString *sourceUrl;

/**
 * Get a link to the image which, if present, should be displayed along with this alert.
 *
 * \return url (as NSString) to the image, or nil if not available.
 */
@property (nonatomic, readonly) NSString *imageUrl;

/**
 * Get display text which, if present, should be displayed
 * next to image obtained by #imageUrl.
 *
 * \return display text, or nil if not available.
 */
@property (nonatomic, readonly) NSString *imageCaption;

@end
/** @}  */
