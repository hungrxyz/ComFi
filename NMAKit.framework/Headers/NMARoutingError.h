/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#ifndef NMASDK_NMARoutingError_h
#define NMASDK_NMARoutingError_h

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Defines types of error codes that can be returned from route calculation
 * operations.
 */
typedef NS_ENUM(NSUInteger, NMARoutingError) {
    /** \brief There was no error, route calcualtion succeeded. */
    NMARoutingErrorNone = 0,
    /** \brief There was an unknown error. */
    NMARoutingErrorUnknown,
    /** \brief There was an out-of-memory error. */
    NMARoutingErrorOutOfMemory,
    /** \brief There was an error due to invalid parameters. */
    NMARoutingErrorInvalidParameters,
    /** \brief There was an error due to another request already being processed. */
    NMARoutingErrorInvalidOperation,
    /** \brief There was an error because no route could be found. */
    NMARoutingErrorGraphDisconnected,
    /**
     * \brief There was an error because no route could be found, possibly due to some option
     * (e.g. disabled highways) preventing it.
     */
    NMARoutingErrorGraphDisconnectedCheckOptions,
    /** \brief There was an error because no starting waypoint could be found. */
    NMARoutingErrorNoStartPoint,
    /** \brief There was an error because no destination waypoint could be found. */
    NMARoutingErrorNoEndPoint,
    /**
     * \brief There was an error because the destination point is unreachable, possibly due to
     * some option (e.g. disabled highways) preventing it.
     */
    NMARoutingErrorNoEndPointCheckOptions,
    /**
     * \brief There was an error because pedestrian mode was specified yet is not practical
     * (e.g. the route is too long).
     */
    NMARoutingErrorCannotDoPedestrian,
    /** \brief There was an error because the application user cancelled the route calculation. */
    NMARoutingErrorRoutingCancelled,
    /**
     * \brief There was an error because the route calculation request included options that
     * prohibit successful completion.
     */
    NMARoutingErrorViolatesOptions,
    /** \brief There was an error because the service could not digest the requested route
     * parameters.
     */
    NMARoutingErrorRouteCorrupted,
    /** \brief There was an error due to invalid or missing HERE Developer credentials. */
    NMARoutingErrorInvalidCredentials,
    /** \brief There was an error because there is not enough local map data to perform route
     * calculation. Client can redownload map data and calculate route again.
     */
    NMARoutingErrorInsufficientMapData,
    /** \brief The online route calculation request has timed out because the server has not
     * responded or the device system resources have been exhausted. The route calculation request
     * should be retried.
     */
    NMARoutingErrorRequestTimeout
};

/** @}  */

#endif /* NMASDK_NMARoutingError_h */
