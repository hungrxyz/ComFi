/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAMapPackage.h"

@class NMAMapLoader;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

#pragma mark -
#pragma mark NMAMapLoaderResult codes

/**
 * Represents status for {@link NMAMapLoader} operations. The status is returned
 * through the {@link NMAMapLoaderDelegate} protocol.
 */
typedef NS_ENUM(NSUInteger, NMAMapLoaderResult) {
    /** \brief The NMAMapLoader operation was completed without error. */
    NMAMapLoaderResultSuccess,

    /** \brief The NMAMapLoader operation was called with invalid parameters. */
    NMAMapLoaderResultInvalidParameters,

    /** \brief The NMAMapLoader operation was cancelled by the user. */
    NMAMapLoaderResultOperationCancelled,

    /** \brief The NMAMapLoader could not be initialized. */
    NMAMapLoaderResultInitializationFailed,

    /** \brief The NMAMapLoader could not connect to the data server. */
    NMAMapLoaderResultConnectionFailed,

    /** \brief A suitable package could not be found (getMapPackageAtGeoCoordinates:). */
    NMAMapLoaderResultSearchFailed
};

#pragma mark -
#pragma mark NMAMapLoaderDelegate

/**
 * The NMAMapLoaderDelegate responds to callback messages sent by the NMAMapLoader.
 * The callbacks correspond to specific map loader functionality. Only one delegate
 * may be installed on the map loader at a time, using the setDelegate method.
 *
 * \note Methods of this protocol will be called on the main queue.
 */
@protocol NMAMapLoaderDelegate<NSObject>

@optional
/*!
 * Called during certain {@link NMAMapLoader} operations to indicate the current
 * progress of that operation.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param progress The progress of the current operation from 0.0 (beginning) to 1.0 (complete).
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didUpdateProgress:(float)progress;

/*!
 * Callback associated with the NMAMapLoader getMapPackages method
 * call.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param mapLoaderResult The {@link NMAMapLoaderResult} for this
 *            operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didGetPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the
 * {@link NMAMapLoader} installMapPackages method call.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param mapLoaderResult The {@link NMAMapLoaderResult} for this
 *            operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didInstallPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the
 * {@link NMAMapLoader} uninstallMapPackages method call.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param mapLoaderResult The {@link NMAMapLoaderResult} for this
 *            operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didUninstallPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the {@link NMAMapLoader} checkForMapDataUpdate
 * method call.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param updateIsAvailable True if an update is available, false otherwise.
 * \param currentMapVersion Representation of the current map data version
 *            in the form "Major.Minor.Feature.Build" where each section is
 *            an unsigned integer.
 * \param newestMapVersion Representation of the newest map data version in
 *            the form "Major.Minor.Feature.Build" where each section is an
 *            unsigned integer.
 * \param mapLoaderResult The <code>NMAMapLoaderResult</code> for this
 *            operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didFindUpdate:(BOOL)updateIsAvailable
      fromVersion:(NSString *)currentMapVersion
        toVersion:(NSString *)newestMapVersion
       withResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the {@link NMAMapLoader} getMapDataUpdateSize method.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param size The size of the map data update in KB.
 * \param mapLoaderResult The <code>NMAMapLoaderResult</code> of the operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didGetUpdateSize:(NSUInteger)size
       withResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the {@link NMAMapLoader} performMapDataUpdate
 * method call.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param mapLoaderResult The <code>NMAMapLoaderResult</code> for this
 *            operation.
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didUpdateWithResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback associated with the {@link NMAMapLoader} getMapPackageAtCoordinates: method.
 *
 * \param mapLoader The NMAMapLoader (singleton) instance sending the callback.
 * \param package The smallest package containing the specified NMAGeoCoordinates that could be
 * found, or nil if a package could not be found.
 * \param coordinates The coordinates used to locate the package.
 * \param mapLoaderResult The <code>NMAMapLoaderResult</code> of the operation.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
- (void)mapLoader:(NMAMapLoader *)mapLoader didGetMapPackage:(NMAMapPackage *)package atGeoCoordinates:(NMAGeoCoordinates *)coordinates withResult:(NMAMapLoaderResult)mapLoaderResult;

/**
 * Callback sent when the NMAMapLoader loses its server connection during an operation.
 *
 * If a map loader operation is interrupted by a loss of connection, it will automatically be
 * resumed when the connection is restored. This callback is sent to give the client
 * application or end user the option to cancel the current operation instead of waiting.
 */
- (void)mapLoaderDidLoseConnection:(NMAMapLoader *)mapLoader;

/**
 * Callback sent when the NMAMapLoader reestablishes its connection to the data server.
 *
 * The current operation will be automatically resumed.
 */
- (void)mapLoaderDidFindConnection:(NMAMapLoader *)mapLoader;

@end


#pragma mark -
#pragma mark NMAMapLoader


/**
 * \class NMAMapLoader NMAMapLoader.h "NMAMapLoader.h"
 *
 * \brief Provides various methods which facilitate usage of offline map data
 * capabilities. Calls made to NMAMapLoader are asynchronous and return results
 * through the {@link NMAMapLoaderDelegate} interface.
 * </p>
 * <p>Usage</p>
 * <p>
 * The NMAMapLoader may only perform a single operation at a time. Therefore,
 * if a method is called before the callback for a previous method call has been
 * made, the call will fail and return NO.
 * </p>
 *
 * <p>Incremental Updates</p>
 * <p>
 * All map data downloaded by the client application has a version. This includes
 * data downloaded through the NMAMapLoader and data downloaded automatically as
 * a result of map browsing. At any given time, all cached map data has the same
 * version.
 * </p>
 * <p>
 * Periodically, new versions of the map database are released. To ensure that
 * the client application is always using the freshest map data available, the
 * map cache should be updated regularly. This is accomplished by first calling
 * -checkForMapDataUpdate. If an update is available, it can be performed by
 * calling -performMapDataUpdate.
 * </p>
 * <p>
 * When map data is updated, only the differences between the current version
 * and the new version need to be downloaded. These "incremental updates" allow
 * the map data to be kept up to date without having to delete and re-download
 * the entire map cache every time. Thus, the size of a map data update is
 * typically much smaller than the size of the cache itself.
 * </p>
 *
 * \note NMAMapLoader is a singleton which must be obtained using the
 * {@link sharedMapLoader} method.
 *
 * \note NMAMapLoader requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAMapLoader : NSObject

/*!
 * Returns the %NMAMapLoader singleton instance.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note Use this method to obtain a %NMAMapLoader instance. Do not call
 * init directly.
 *
 * \return shared %NMAMapLoader instance
 */
+ (NMAMapLoader *)sharedMapLoader;

/*!
 * The current {@link NMAMapLoaderDelegate} for the NMAMapLoader.
 * To remove the current delegate, set this property to nil.
 */
@property (nonatomic, weak) id<NMAMapLoaderDelegate> delegate;

/*!
 * Indicates whether or not the NMAMapLoader is currently performing
 * an operation.
 *
 * \note The getMapPackageAtGeoCoordinates operation may be performed while
 * other operations are in progress (including itself).
 */
@property (nonatomic, readonly) BOOL active;

/*!
 * \brief The root item of the package hierarchy, representing the entire world map.
 *
 * The package hierarchy is accessed through the root package using its children
 * property (and the children of the children, and so on).
 *
 * When packages are installed or uninstalled, a new list is generated to reflect the
 * updated state. Existing package lists are static and thus become obsolete when a
 * new list is generated.
 *
 * \note May be nil if the package list has not yet been retrieved. Use the getMapPackages
 * method to populate the list.
 *
 * @ditaprop atomic
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
@property (atomic, readonly, strong) NMAMapPackage *rootPackage;

/*!
 * Requests the list of available {@link NMAMapPackage}s. The list of available
 * packages is returned in {@link NMAMapLoaderDelegate} via the
 * mapLoader:didGetPackagesWithResult: callback.
 *
 * \note {@link NMAMapPackage}s returned represent a snapshot of the
 * current packages only; their state is not updated dynamically. Therefore,
 * if any operation which modifies the state of an NMAMapPackage is performed
 * (install/uninstall/update), packages will have to be retrieved again to
 * reflect this state change.
 *
 * \return YES if the request has been made successfully, NO if the
 *         NMAMapLoader is currently busy processing another request.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
- (BOOL)getMapPackages;

/*!
 * Requests that the specified {@link NMAMapPackage}s be installed.
 *
 * \note Status of the installation can be monitored through the
 * {@link NMAMapLoaderDelegate} didUpdateProgress: and didInstallPackagesWithResult:
 * callbacks.
 *
 * \note If an already-installed package is selected again for installation, it
 * will be skipped (and the NMAMapLoader will return immediately with success
 * if it was the only package requested).
 *
 * \param mapPackages The array of {@link NMAMapPackage} objects to install.
 *            If the array is empty or nil is passed,
 *            {@link ::NMAMapLoaderResultInvalidParameters} will be
 *            returned in the callback.
 * \return YES if the request has been made successfully, NO if the
 *         NMAMapLoader is currently busy processing another request.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
- (BOOL)installMapPackages:(NSArray *)mapPackages;

/*!
 * Requests that the specified {@link NMAMapPackage}s be uninstalled.
 *
 * \note Status of the uninstallation can be monitored through the
 * {@link NMAMapLoaderDelegate} didUpdateProgress: and didUninstallPackagesWithResult:
 * callbacks.
 *
 * \param theMapPackages The array of {@link NMAMapPackage} integer ID's to uninstall.
 *            If an invalid ID value is contained in the array, the array is
 *            empty, or nil is passed,
 *            {@link ::NMAMapLoaderResultInvalidParameters} will be
 *            returned in the callback.
 * \return YES if the request has been made successfully, NO if the
 *         NMAMapLoader is currently busy processing another request.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
- (BOOL)uninstallMapPackages:(NSArray *)theMapPackages;

/*!
 * Requests that a check be performed to see if an updated map data version
 * is available. Please see the Incremental Updates section of the
 * {@link NMAMapLoader} documentation for more info on map version updates.
 *
 * \note The result is obtained through the {@link NMAMapLoaderDelegate}
 * didFindUpdate:fromVersion:toVersion:withResult: callback.
 *
 * \return YES if the request has been made successfully, NO if the
 *         NMAMapLoader is currently busy processing another request.
 */
- (BOOL)checkForMapDataUpdate;

/*!
 * Gets the size of a pending map data version update.
 *
 * \note The result is obtained through the {@link NMAMapLoaderDelegate}
 * mapLoader:didGetUpdateSize:withSuccess: callback.
 *
 * \return The size in KB of an update to the latest map data version, or 0 if
 * an update is not available.
 */
- (BOOL)getMapDataUpdateSize;

/*!
 * Requests that the map data version be updated if an update is available.
 * Please see the Incremental Updates section of the {@link NMAMapLoader}
 * documentation for more info on map version updates.
 *
 * \note Status of the map update can be monitored through the
 * {@link NMAMapLoaderDelegate} didUpdateProgress: and didUpdateWithResult: callbacks.
 *
 * \return YES if the request has been made successfully, NO if the
 *         NMAMapLoader is currently busy processing another request.
 */
- (BOOL)performMapDataUpdate;

/*!
 * Request the currently running NMAMapLoader operation be cancelled.
 * Cancellation is completed once the completion callback for the currently
 * running operation has been made with the
 * {@link NMAMapLoaderResult#NMAMapLoaderResultOperationCancelled} result.
 *
 * \return YES if an operation was cancelled, NO if the map loader was not
 * performing an operation or the operation could not be cancelled.
 */
- (BOOL)cancelCurrentOperation;

/*!
 * Try to find a NMAMapPackage which contains the given NMAGeoCoordinates.
 *
 * <p>
 * This method will try to find a map package based on a map location (NMAGeoCoordinates).
 * If it can be identified, the smallest package containing the point is returned. For
 * some input coordinates a larger package will be returned, but it should never be higher
 * than country level (i.e. continental packages will not be returned).
 * </p>
 * <p>
 * The result of this operation is passed via the NMAMapLoaderDelegate
 * -mapLoader:didGetMapPackage:atCoordinates:withResult.
 * </p>
 *
 * \return YES if the request was made successfully, NO otherwise.
 *
 * @product nlp-hybrid nlp-hybrid-plus
 */
- (BOOL)getMapPackageAtGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Selects a map data group for installation.
 *
 * Each map package is divided into several data groups. Some of these groups
 * may be optionally selected for installation if needed by the application.
 * Conversely, data groups which may be selected by default can be deselected
 * by the application if not needed, saving disk space.
 *
 * Data groups not selected if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \note Changes to the data group selection are only reflected in subsequent
 * installations. To add data groups to previously installed packages, call
 * performMapDataUpdate after changing the group selection.
 *
 * \sa NMAMapDataGroup
 */
- (void)selectDataGroup:(NMAMapDataGroup)dataGroup;

/**
 * Deselects a map data group for installation.
 */
- (void)deselectDataGroup:(NMAMapDataGroup)dataGroup;

/**
 * Checks if a map data group is currently selected.
 */
- (BOOL)isDataGroupSelected:(NMAMapDataGroup)dataGroup;

@end
/** @} */
