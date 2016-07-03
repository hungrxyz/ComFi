/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

/**
 * The installation status of a NMAMapPackage.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
typedef NS_ENUM(NSUInteger, NMAMapPackageInstallation) {
    /** \brief The package is not installed */
    NMAMapPackageInstallationNone = 0,
    /** \brief The package was installed through its parent */
    NMAMapPackageInstallationImplicit,
    /** \brief The package was installed directly */
    NMAMapPackageInstallationExplicit
};

/**
 * The data groups which may be optionally selected for offline map downloads.
 *
 * The default data group selection state is:
 * \code
 *      Group                               Selected
 *      NMAMapDataGroupPhoneticNames        yes
 *      NMAMapDataGroupRealisticViews16x9   no
 *      NMAMapDataGroupRealisticViews3x5    no
 *      NMAMapDataGroupRealisticViews4x3    no
 *      NMAMapDataGroupRealisticViews5x3    no
 * \endcode
 *
 * \sa NMAMapLoader::selectDataGroup:
 *
 * Data groups not selected if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
typedef NS_ENUM(NSInteger, NMAMapDataGroup) {
    /** \brief Phonemes used for TTS guidance. */
    NMAMapDataGroupPhoneticNames            = 49,
    /** \brief Images for used with the navigation realistic view feature, with 16x9 aspect ratio. */
    NMAMapDataGroupRealisticViews16x9       = 50,
    /** \brief Images for used with the navigation realistic view feature, with 3x5 aspect ratio. */
    NMAMapDataGroupRealisticViews3x5        = 51,
    /** \brief Images for used with the navigation realistic view feature, with 4x3 aspect ratio. */
    NMAMapDataGroupRealisticViews4x3        = 52,
    /** \brief Images for used with the navigation realistic view feature, with 5x3 aspect ratio. */
    NMAMapDataGroupRealisticViews5x3        = 53
};


/**
 * \class NMAMapPackage NMAMapPackage.h "NMAMapPackage.h"
 *
 * \brief A collection of map data encompassing a particular region or country.
 *
 * Map data packages can be selectively installed or uninstalled using the
 * NMAMapLoader API. Installing a package makes its data available for offline
 * usage.
 *
 * \note NMAMapPackage objects are immutable; their properties will not change
 * after creation even if the state of the installed map data changes. In this
 * case, a new package list should be obtained.
 *
 * \sa NMAMapLoader
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
@interface NMAMapPackage : NSObject

/**
 * The parent of the map package if one exists, nil otherwise.
 */
@property (nonatomic, readonly, weak) NMAMapPackage *parent;

/**
 * An immutable list of the children of the map package if any exist,
 * an empty list otherwise.
 */
@property (nonatomic, readonly, strong) NSArray *children;

/**
 * The unique ID of the map package. This is used to identify map packages
 * for install/uninstall operations.
 */
@property (nonatomic, readonly) NSInteger packageId;

/**
 * The human readable title of the map package. The language of the
 * title string is dependent upon the device locale.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * The title of the package in English.
 */
@property (nonatomic, readonly) NSString *englishTitle;

/**
 * The maximum size (in KB) the map package will take up on disk.
 *
 * \note Actual install size may be smaller when multiple packages are installed.
 */
@property (nonatomic, readonly) long sizeOnDisk;

/**
 * Indicates whether or not this NMAMapPackage is currently installed on disk.
 */
@property (nonatomic, readonly) NMAMapPackageInstallation installationStatus;

@end
/** @} */
