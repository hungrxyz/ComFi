/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NMAVoiceGender)
{
    /**
     * \brief Female voice
     */
    NMAVoiceGenderFemale,
    /**
     * \brief Male voice
     */
    NMAVoiceGenderMale,
    /**
     * \brief Female or Male voice
     */
    NMAVoiceGenderBoth,
    /**
     * \brief Unknown gender for the voice
     */
    NMAVoiceGenderUnknown
};


/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 * @{
 */

/*!
 * \class NMAVoicePackage NMAVoicePackage.h "NMAVoicePackage.h"
 * Return information about voice packages.
 * Used in NMAVoiceCatalog.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAVoicePackage : NSObject

/**
 * Id of the voice package.
 */
@property (nonatomic, readonly) NSUInteger packageId;

/**
 * Name of the voice package localized to the package locale, nil if not available.
 */
@property (nonatomic, readonly, weak) NSString *name;

/**
 * Gender of the voice package.
 */
@property (nonatomic, readonly) NMAVoiceGender gender;

/**
 * Language of the installed voice package in English, nil if the voice package is not installed.
 */
@property (nonatomic, readonly, weak) NSString *language;

/**
 * Language of the voice package localized to the package locale, nil if it is not available.
 */
@property (nonatomic, readonly) NSString *localizedLanguage;

/**
 * The BCP-47 language code representing the language of the package, nil if voice
 * package is not available or BCP-47 language tag could not be found.
 */
@property (nonatomic, readonly, weak) NSString *languageCode;

/**
 * Check if the voice package needs to be updated. YES if the installed voice package and the
 * voice package from the server in the voice catalog have different versions; NO otherwise
 */
@property (nonatomic, readonly, getter = isUpdateAvailable) BOOL updateAvailable;

/**
 * Check if the voice package is installed. YES if installed; NO otherwise.
 */
@property (nonatomic, readonly, getter = isInstalled) BOOL installed;

/**
 * Size of the package after download to device, in number of megabytes
 *
 * Returns -1 if the package is not available for download
 */
@property (nonatomic, readonly) float downloadSize;

/**
 * Size of the package after unzipping to device, in number of megabytes
 */
@property (nonatomic, readonly) float installationSize;

/**
 * Indicates whether the voice package can be uninstalled. YES if can be uninstalled; NO otherwise
 */
@property (nonatomic, getter = isRemovable) BOOL removable;

/**
 * Indicate the quality of the voice if it is available; nil if voice quality is not available
 */
@property (nonatomic, readonly) NSString *quality;

@end

/** @} */
