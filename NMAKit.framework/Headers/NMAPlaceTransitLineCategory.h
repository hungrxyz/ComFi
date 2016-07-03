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
 * \class NMAPlaceTransitLineCategory NMAPlaceTransitLineCategory.h "NMAPlaceTransitLineCategory.h"
 * \brief Represents the category information for the public transport line.
 */
@interface NMAPlaceTransitLineCategory : NSObject

/**
 * \brief Gets the category unique identifier.
 */
@property (nonatomic, readonly, strong) NSString *uniqueId;

/**
 * \brief Gets the localized name of the category.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *title;

/**
 * \brief Gets the locally used name for the category.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *localName;

/**
 * \brief Gets the icon for the category.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *iconUrl;

@end
/** @} */
