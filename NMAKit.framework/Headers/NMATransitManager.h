/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATransitAccess;
@class NMATransitLine;
@class NMATransitManager;
@class NMATransitObject;
@class NMATransitStop;
@class NMATransitSystem;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * Represents values describing the types of transit that an application user
 * might take.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMATransitType) {
    /** \brief A public bus. */
    NMATransitTypePublicBus,
    /** \brief A tourist bus. */
    NMATransitTypeTouristicBus,
    /** \brief An intercity bus. */
    NMATransitTypeIntercityBus,
    /** \brief An express bus. */
    NMATransitTypeExpressBus,
    /** \brief A metro railway. */
    NMATransitTypeMetroRail,
    /** \brief A light railway. */
    NMATransitTypeLightRail,
    /** \brief A regional railway. */
    NMATransitTypeRegionalRail,
    /** \brief A regional train. */
    NMATransitTypeRegionalTrain,
    /** \brief An intercity train. */
    NMATransitTypeIntercityTrain,
    /** \brief A high-speed train. */
    NMATransitTypeHighSpeedTrain,
    /** \brief Monorail! */
    NMATransitTypeMonorail,
    /** \brief Aerial transit. */
    NMATransitTypeAerial,
    /** \brief Inclined transit. */
    NMATransitTypeInclined,
    /** \brief A water taxi or ferry. */
    NMATransitTypeWater,
    /** \brief An airline. */
    NMATransitTypeAirline,
    /** \brief An unknown transit type. */
    NMATransitTypeUnknown
};

/**
 * Possible result codes of NMATransitManager upon completion of an operation.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMATransitManagerError) {
    NMATransitManagerErrorNone,
    NMATransitManagerErrorBusy,
    NMATransitManagerErrorInvalidParameters,
    /** \deprecated NMATransitManagerErrorTimeOut is deprecated. */
    NMATransitManagerErrorTimeOut __attribute__((deprecated)),
    /** \brief NMATransitManagerErrorNotFound returns when there is no connectivity and no cached data. */
    NMATransitManagerErrorNotFound,
    NMATransitManagerErrorUnknown
};

/**
 * \brief A delegate protocol to be implemented by classes using the NMATransitManager,
 * used to receive the results of information requests.
 *
 * All NMATransitManager requests will result in a didCompleteWithError: callback being
 * sent. In the case of an operation failure, this is the only callback sent. If an
 * operation is successful, the delegate will also receive one of the "didGet..."
 * callbacks, depending on which type of information was requested.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@protocol NMATransitManagerDelegate<NSObject>
@optional
/**
 * \brief Called by NMATransitManager after successfully completing a request for
 * NMATransitAccess information (e.g. requestAccessInfoForId:).
 *
 * \param transitManager The NMATransitManager singleton
 * \param access The NMATransitAccess object requested
 * \param uniqueId The identifying string used to make the original request
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)transitManager:(NMATransitManager *)transitManager didGetAccessInfo:(NMATransitAccess *)access forId:(NSString *)uniqueId;

/**
 * \brief Called by NMATransitManager after successfully completing a request for
 * NMATransitLine information (e.g. requestLineInfoForId:).
 *
 * \param transitManager The NMATransitManager singleton
 * \param line The NMATransitLine object requested
 * \param uniqueId The identifying string used to make the original request
 */
- (void)transitManager:(NMATransitManager *)transitManager didGetLineInfo:(NMATransitLine *)line forId:(NSString *)uniqueId;

/**
 * \brief Called by NMATransitManager after successfully completing a request for
 * NMATransitStop information (e.g. requestStopInfoForId:).
 *
 * \param transitManager The NMATransitManager singleton
 * \param stop The NMATransitStop object requested
 * \param uniqueId The identifying string used to make the original request
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)transitManager:(NMATransitManager *)transitManager didGetStopInfo:(NMATransitStop *)stop forId:(NSString *)uniqueId;

/**
 * \brief Called by NMATransitManager after successfully completing a request for
 * NMATransitSystem information (e.g. requestSystemInfoForId:).
 *
 * \param transitManager The NMATransitManager singleton
 * \param system The NMATransitSystem object requested
 * \param uniqueId The identifying string used to make the original request
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)transitManager:(NMATransitManager *)transitManager didGetSystemInfo:(NMATransitSystem *)system forId:(NSString *)uniqueId;

/**
 * \brief Called upon completion of an NMATransitManager operation, whether or not
 * the operation was successful.
 *
 * \param transitManager The NMATransitManager singleton
 * \param error An error object if the operation failed, otherwise nil
 */
- (void)transitManager:(NMATransitManager *)transitManager didCompleteWithError:(NSError *)error;

@end


/**
 * \class NMATransitManager NMATransitManager.h "NMATransitManager.h"
 *
 * \brief A singleton object used to obtain public transit infrastructure information.
 *
 * The NMATransitManager may be used to obtain information about public transit systems,
 * lines, stops, and accesses. This can be done via unique identifying strings
 * or objects obtained from an NMAMapView (via gesture or programmatic
 * object selection).
 *
 * \note The NMATransitManager is a singleton and should only be accessed using the
 * sharedTransitManager class method.
 * \note Requests made through the NMATransitManager are asynchronous. Cocurrent
 * requests are not supported.
 */
@interface NMATransitManager : NSObject

/**
 * \brief Used to access the shared NMATransitManager singleton object.
 */
+ (NMATransitManager *)sharedTransitManager;

/**
 * \brief An object implementing the NMATransitManagerDelegate protocol which will
 * receive the results of information requests.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, weak) id<NMATransitManagerDelegate> delegate;

/**
 * Starts a request for the NMATransitAccess object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting access.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)requestAccessInfoForId:(NSString *)uniqueId;

/**
 * \brief Starts a request for the NMATransitLine object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting a transit line.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)requestLineInfoForId:(NSString *)uniqueId;

/**
 * \brief Starts a request for the NMATransitStop object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting transit stop info.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)requestStopInfoForId:(NSString *)uniqueId;

/**
 * \brief Starts a request for the NMATransitSystem object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting transit system info.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)requestSystemInfoForId:(NSString *)uniqueId;

/**
 * \brief Starts a request for the transit information associated with the given
 * NMATransitObject.
 *
 * \note The NMATransitObject may represent a line, access, or stop.
 * \sa NMATransitObject
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)requestInfoForObject:(NMATransitObject *)object;

@end
/** @}  */
