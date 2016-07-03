/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Constant that defines the public transit lines extended identifier.
 */
FOUNDATION_EXPORT NSString *const NMATransitLinesExtendedAttributeId;

/**
 * Constant that defines the public transit departures extended identifier.
 */
FOUNDATION_EXPORT NSString *const NMATransitDeparturesExtendedAttributeId;


/**
 * \class NMAExtendedAttribute NMAExtendedAttribute.h "NMAExtendedAttribute.h"
 * \brief Represents additional detailed information about a NMAPlace, an extensible
 * collection of attributes that can include:
 * <ul>
 * <li>Payment - a list of available payment methods (such as cash, credit card, or
 * direct debit, etc)</li>
 * <li>OpeningHours - a list of hours during which the place is open for business</li>
 * <li>AnnualClosings - a description of annual closing dates such as holidays or
 * other special occasions</li>
 * <li>Price - a price list</li>
 * <li>NearestLandmark - a description of the nearest landmark</li>
 * <li>LanguagesSpoken - a list of the languages that are spoken at the place</li>
 * <li>AvailableParking - a list of parking options available nearby</li>
 * <li>Smoking - a notification of whether smoking is allowed</li>
 * <li>DisabledAccess - a notification of whether disabled access is available</li>
 * <li>TransitLines - a list of available public transport transit lines</li>
 * <li>Departures - a list of next departures for available public transport transit lines</li>
 * <li>BlindGuide - a notification of whether a public transport stop has blind guide (tactile paving)</li>
 * <li>Elevator - a notification of whether a public transport stop has elevator</li>
 * <li>Escalator - a notification of whether a public transport stop has escalator</li></ul>
 *
 */
@interface NMAExtendedAttribute : NSObject

/**
 * \brief Gets the unique identifier for the %NMAExtendedAttribute.
 *
 * \note See the list of attributes in the class description.
 */
@property (nonatomic, readonly, strong) NSString *uniqueId;

/**
 * \brief The localized display label for the extended attribute, e.g. "Payment",
 * which can be displayed directly by the client application.
 */
@property (nonatomic, readonly, strong) NSString *label;

/**
 * \brief The localized text for the extended attribute as NSString, e.g. "VISA",
 * which can be can be displayed directly by the client application.
 *
 * <p>
 * If the text represents a list of items, the items are separated by a
 * line break entity (&lt;br/> if the text format is HTML-encoded
 * or newline if the text format is plain).</p>
 */
@property (nonatomic, readonly, strong) NSString *text;

@end
/** @} */
