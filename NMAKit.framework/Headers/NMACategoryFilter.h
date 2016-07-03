/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * Defines types of categories filter.
 */
typedef NS_ENUM(NSUInteger, NMACategoryFilterType) {
    /** No category. */
    NMACategoryFilterTypeNone = 0,
    /** The accommodation category.*/
    NMACategoryFilterTypeAccommodation,
    /** The administrative-areas-buildings category. */
    NMACategoryFilterTypeAdministrativeAreasBuildings,
    /** The eat-drink category. */
    NMACategoryFilterTypeEatDrink,
    /** The going-out category. */
    NMACategoryFilterTypeGoingOut,
    /** The leisure-outdoor category. */
    NMACategoryFilterTypeLeisureOutdoor,
    /** The natural-geographical category. */
    NMACategoryFilterTypeNaturalGeographical,
    /** The shopping category. */
    NMACategoryFilterTypeShopping,
    /** The sights-museums category. */
    NMACategoryFilterTypeSightsMuseums,
    /** The transport category. */
    NMACategoryFilterTypeTransport,
    /** The petrol-station category. */
    NMACategoryFilterTypePetrolStation,
    /** The atm-bank-exchange category. */
    NMACategoryFilterTypeAtmBankExchange,
    /** The toilet-rest-area category. */
    NMACategoryFilterTypeToiletRestArea,
    /** The hospital-health-care-facility category. */
    NMACategoryFilterTypeHospitalHealthCareFacility
};


/**
 * \class NMACategoryFilter NMACategoryFilter.h "NMACategoryFilter.h"
 *
 * Represents a filter used when performing a search for popular places within
 * a specific location (exploring). The filter limits a search to specified categories.
 */
@interface NMACategoryFilter : NSObject

/*!
 * Adds a NMACategoryFilterType to the NMACategoryFilter.
 *
 * \param categoryFilterType An NMACategoryFilterType filter
 */
- (void)addCategoryFilterFromType:(NMACategoryFilterType)categoryFilterType;

/*!
 * Adds an NMACategory's uniqueId to the NMACategoryFilter.
 *
 * \param uniqueId An NSString for NMACategory's uniqueId
 */
- (void)addCategoryFilterFromUniqueId:(NSString *)uniqueId;

/*!
 * Returns a stringified NMACategoryFilter, within which individual
 * categories are separated by commas.
 *
 * \return The stringified, comma-delimited set of categories.
 */
- (NSString *)toString;

@end

/** @} */
