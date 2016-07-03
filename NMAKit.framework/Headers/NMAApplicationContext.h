/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * Defines types of error codes that can be returned when setting the HERE Authentication
 * Credentials and License Key.
 */
typedef NS_ENUM(NSUInteger, NMAApplicationContextError) {
    /** \brief There was no error. */
    NMAApplicationContextErrorNone = 0,
    /** \brief There was no license key e.g. license key is empty string. */
    NMAApplicationContextErrorLicenseKeyEmpty,
    /** \brief There was an error due to namespace, application Id or token mismatched. */
    NMAApplicationContextErrorLicenseKeyMismatch,
    /** \brief There was an error due to invalid platform, e.g. Android license key used on iOS. */
    NMAApplicationContextErrorLicenseInvalidPlatform,
    /** \brief There was an error due to expired license key.*/
    NMAApplicationContextErrorLicenseExpired
};

/**
 * \brief Indicates that the NMAApplicationContext isOnline status has changed.
 *
 * In order to receive this notification, register with NSNotificationCenter
 * using this notification name and a nil notification sender.
 */
FOUNDATION_EXPORT NSString *const NMAApplicationContextOnlineStatusDidChangeNotification;


/**
 * \class NMAApplicationContext NMAApplicationContext.h "NMAApplicationContext.h"
 *
 * Use this interface to set mandatory authentication crendentials
 *
 * \note YOU MUST SET AUTHENTICATION CREDENTIALS in order to use the APIs
 * contained within this SDK. Some APIs may appear to work without valid
 * credentials but they may stop functioning in the near future when server side
 * configurations change, so please obtain and use valid credentials.
 */
@interface NMAApplicationContext : NSObject

/**
 * Sets the mandatory HERE Authentication Credentials and License Key.
 *
 * These credentials MUST be set once before attempting to use any other APIs in the HERE SDK.
 * You may only call this method once. It is recommended to call this method in
 * [UIApplicationDelegate didFinishLaunchingWithOptions]
 *
 * \param appId Application ID
 * \param appCode Application context token
 * \param licenseKey License Key
 * \return The status i.e. check NMAApplicationContextError for failure reason
 */
+ (NMAApplicationContextError)setAppId:(NSString *)appId appCode:(NSString *)appCode licenseKey:(NSString *)licenseKey;

/**
 * \brief Returns the LicenseKey.
 */
+ (NSString *)licenseKey;

/**
 * \brief Return the SDK version
 * \return The SDK verion
 */
+ (NSString *)sdkVersion;

/**
 * \brief Controls whether the HERE SDK is ALLOWED to access network services.
 *
 * \note If set to NO then the HERE SDK will not access the network to download
 * map data, perform searches, calculate routes or when providing any other service.
 */
+ (void)setNetworkAccessAllowed:(BOOL)networkAccessAllowed;

/**
 * \brief Indicates whether the HERE SDK is ALLOWED to access network services.
 *
 * Defaults to YES.
 *
 * \note If NO is returned then the HERE SDK will not access the network to
 * download map data, perform searches, calculate routes or when providing any
 * other service.
 */
+ (BOOL)isNetworkAccessAllowed;

/**
 * \brief Indicates whether the HERE SDK is currently online and accessing
 * network services.
 *
 * \note This reflects the actual online status of the HERE SDK. If
 * isNetworkAccessAllowed returns YES but no data connection is available then
 * this method will return NO. If isNetworkAccessAllowed returns NO then this
 * method returns NO.
 */
+ (BOOL)isOnline;

/**
 * \brief Indicates whether the HERE SDK is initialized.
 *
 * \note If NO is returned then the HERE SDK is not ready to handle any service.
 */
+ (BOOL)isInitialized;

@end

/** @}  */
