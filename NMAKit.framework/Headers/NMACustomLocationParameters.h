/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */

/**
 * Conditions which may be used to filter custom location requests.
 *
 * Conditions describe how a specified location attribute will be compared
 * to a specified value.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSInteger, NMACustomLocationCondition) {
    /** \brief The attribute must exactly match the value. */
    NMACustomLocationConditionExactMatch,
    /** \brief The attribute must be greater than the value. */
    NMACustomLocationConditionGreaterThan,
    /** \brief The attribute must be less than the value. */
    NMACustomLocationConditionLessThan,
    /** \brief The attribute must be less than or equal to the value. */
    NMACustomLocationConditionLessThanOrEqualTo,
    /** \brief The attribute must contain the value, but it can have other text before or after. */
    NMACustomLocationConditionLikePrePostWildcard,
    /** \brief The attribute must contain the value, but it can have other text after. */
    NMACustomLocationConditionLikePostWildcard,
    /** \brief The attribute must contain the value, but it can have other text before. */
    NMACustomLocationConditionLikePreWildcard,
    /** \brief The attribute must be null. */
    NMACustomLocationConditionNull,
    /** \brief The attribute must not be equal to the value. */
    NMACustomLocationConditionNot,

    /** \brief The number of conditions. This value should not be used in requests. */
    NMACustomLocationConditionCount
};

/**
 * The attributes of a custom location.
 *
 * The attributes enumerated here are the same as the properties found in the
 * NMACustomLocationResponse class.
 *
 * \sa NMACustomLocationResponse
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSInteger, NMACustomLocationAttribute) {
    /** \brief  */
    NMACustomLocationAttributeName1,
    /** \brief  */
    NMACustomLocationAttributeName2,
    /** \brief  */
    NMACustomLocationAttributeName3,
    /** \brief  */
    NMACustomLocationAttributeCustomerLocationId,
    /** \brief  */
    NMACustomLocationAttributeCustomerId,
    /** \brief  */
    NMACustomLocationAttributeCoordinatesLatitude,
    /** \brief  */
    NMACustomLocationAttributeCoordinatesLongitude,
    /** \brief  */
    NMACustomLocationAttributeRouteCoordinatesLatitude,
    /** \brief  */
    NMACustomLocationAttributeRouteCoordinatesLongitude,
    /** \brief  */
    NMACustomLocationAttributeDescription,
    /** \brief  */
    NMACustomLocationAttributeHouseNumber,
    /** \brief  */
    NMACustomLocationAttributeStreet,
    /** \brief  */
    NMACustomLocationAttributeCity,
    /** \brief  */
    NMACustomLocationAttributeState,
    /** \brief  */
    NMACustomLocationAttributePostalCode,
    /** \brief  */
    NMACustomLocationAttributeCountry,
    /** \brief  */
    NMACustomLocationAttributeCounty,
    /** \brief  */
    NMACustomLocationAttributeCountryName,
    /** \brief  */
    NMACustomLocationAttributePhone,
    /** \brief  */
    NMACustomLocationAttributeFax,

    /** \brief The number of attributes. This value should not be used in requests. */
    NMACustomLocationAttributeCount
};

/**
 * The operators used to combine multiple query conditions.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSInteger, NMACustomLocationOperator) {
    /** \brief  */
    NMACustomLocationOperatorAnd,
    /** \brief  */
    NMACustomLocationOperatorOr,

    /** \brief The number of operators. This value should not be used in requests. */
    NMACustomLocationOperatorCount
};


/**
 * Parameters used to filter the results of location requests made using
 * the NMACustomLocationManager.
 *
 * Parameters can be used to narrow the results of custom location requests by
 * comparing the attributes of the locations to specified values in different
 * ways. These comparisons are called "conditions"; a condition may be placed
 * upon one of the predefined attributes (NMACustomLocationAttribute) or on a
 * custom attribute specific to the location set.
 *
 * Parameters may also be used to limit the number of results returned by a
 * request.
 *
 * \note Parameters are optional and may be neglected in any location request.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomLocationParameters : NSObject

/**
 * The maximum number of locations to return.
 */
@property (nonatomic) NSUInteger resultLimit;

/**
 * The query string used to filter the results based on the predefined
 * location attributes.
 *
 * The query string is made up of zero or more conditions. The string may set
 * directly or built one condition at a time using the
 * addCondition:withAttribute:value:operator: method.
 */
@property (nonatomic) NSString *query;

/**
 * The query string used to filter the results based on custom location
 * attributes.
 *
 * The query string is made up of zero or more conditions. The string may set
 * directly or built one condition at a time using the
 * addCondition:withCustomAttribute:value:operator: method.
 */
@property (nonatomic) NSString *customAttributeQuery;

/**
 * Adds a condition to the query string.
 *
 * \param condition The type of condition to add, from NMACustomLocationCondition.
 * \param attribute The attribute to filter, from NMACustomLocationAttribute.
 * \param value The value to compare against in the condition.
 * \param oper The operator used to combine the new condition with the existing
 *             conditions. Has no effect if this is the first condition.
 */
- (void)addCondition:(NMACustomLocationCondition)condition
       withAttribute:(NMACustomLocationAttribute)attribute
               value:(NSString *)value operator:(NMACustomLocationOperator) oper;

/**
 * Adds a condition to the custom attribute query string.
 *
 * \param condition The type of condition to add, from NMACustomLocationCondition.
 * \param attribute The attribute to filter.
 * \param value The value to compare against in the condition.
 * \param oper The operator used to combine the new condition with the existing
 *             conditions. Has no effect if this is the first condition.
 */
- (void)   addCondition:(NMACustomLocationCondition)condition
    withCustomAttribute:(NSString *)attribute
                  value:(NSString *)value operator:(NMACustomLocationOperator) oper;

@end
/**  @}  */
