/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * Type of the link as enum for convinient use.
 * The allowed values are:
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityDisclaimerType) {
    /** \brief Disclaimer type agency: Operator information URL. */
    NMAUrbanMobilityDisclaimerTypeAgency = 0,
    /** \brief Disclaimer type logo: Operator logo URL. */
    NMAUrbanMobilityDisclaimerTypeAgencyLogo,
    /** \brief Disclaimer type tariff: Tariff information URL. */
    NMAUrbanMobilityDisclaimerTypeTariff,
    /** \brief Disclaimer type website: Website URL. */
    NMAUrbanMobilityDisclaimerTypeWebsite,
    /** \brief Disclaimer type unknown. */
    NMAUrbanMobilityDisclaimerTypeUnknown
};


/**
 * \class NMAUrbanMobilityOperatorDisclaimer NMAUrbanMobilityOperatorDisclaimer.h "NMAUrbanMobilityOperatorDisclaimer.h"
 *
 * Disclaimer information associated with a transit operator.
 *
 * This information must be exposed in the client application.
 *
 * \sa NMAUrbanMobilityOperator
 */
@interface NMAUrbanMobilityOperatorDisclaimer : NSObject

/**
 * Gets the NMAUrbanMobilityOperatorDisclaimer text.
 */
@property (nonatomic, readonly) NSString *text;

/**
 * Gets the NSString representation of the NMAUrbanMobilityOperatorDisclaimer url.
 */
@property (nonatomic, readonly) NSString *url;

/**
 * Gets clickable part of text. If not available (empty string) the full text need to be
 * clickable.
 * For example if {@link text} returns "Lorem ipsum dolor sit amet,
 * consectetur adipiscing elit." and {@link urlText} returns "Lorem ipsum" then only
 * Lorem ipsum part should be clickable.
 * \return clickable part of text, or nil if not available.
 */
@property (nonatomic, readonly) NSString *urlText;

/**
 * Gets the NMAUrbanMobilityOperatorDisclaimer type as  %NMAUrbanMobilityDisclaimerType , i.e. is it url to agency web-site or tariff information url.
 */
@property (nonatomic, readonly) NMAUrbanMobilityDisclaimerType disclaimerType;

/**
 * If YES, it is mandatory to display the NMAUrbanMobilityOperatorDisclaimer on client applications.
 * Otherwise the application can choose whether to show this NMAUrbanMobilityOperatorDisclaimer or not.
 * Default value is YES.
 */
@property (nonatomic, readonly, getter = isRequired) BOOL required;

@end
/** @}  */
