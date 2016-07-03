/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAAudioManager;
@class NMAAudioOutput;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * System audio route changed notification.
 *
 * This notification is posted when the system changes the audio route. The route will be
 * changed when the current route is set to NMAAudioRouteBluetoothHFP and no audio device
 * supporting Bluetooth HFP is connected when an NMAAudioOutput playback attempt is made.
 */
FOUNDATION_EXPORT NSString *const NMAAudioRouteDidChangeNotification;

/**
 * Audio routing mode
 */
typedef NS_ENUM(NSUInteger, NMAAudioRoute) {
    /**
     * Standard iOS audio routing behaviour. Uses the last connected audio output device
     * or the last device selected using the iOS MPVolumeView control.
     */
    NMAAudioRouteDefault = 0,

    /**
     * Force audio output to the device speaker.
     *
     * Not supported on iOS7.
     */
    NMAAudioRouteDeviceSpeaker,

    /**
     * Force audio output to a device that supports Bluetooth HFP (Hands Free Protocol)
     * if such a device is connected. iOS defines this as AVAudioSessionPortBluetoothHFP.
     *
     * Note that many Bluetooth stereo headsets and car multimedia systems support
     * AVAudioSessionPortBluetoothHFP and AVAudioSessionPortBluetoothA2DP protocols. If
     * both protocols are available then it is NOT recommended to use
     * NMAAudioRouteBluetoothHFP as it will result in lower quality (voice call quality)
     * audio, this is particularly noticable if the iOS music player (or other app) is
     * playing audio. When a bluetooth device supports both protocols it is better to use
     * NMAAudioRouteDefault and optionally give the user control of the audio output by
     * adding an MPVolumeView control to your app.
     *
     * Not supported on iOS7.
     */
    NMAAudioRouteBluetoothHFP
};

/**
 * \brief A delegate interface for NMAAudioManager.
 *
 * Through the NMAAudioManagerDelegate protocol, a delegate object can be notified
 * before audio playback starts and after playback completes. Optionally, the delegate
 * may also decide to take responsibility for playing a particular output, or even to
 * not play the output at all.
 *
 * \sa NMAAudioManager::delegate
 */
@protocol NMAAudioManagerDelegate<NSObject>

@optional

/**
 * Called when the audio manager has output to play.
 *
 * If the delegate returns YES, or the delegate does not implement this method, the
 * output is played immediately. If the delegate returns NO, the delegate takes over
 * responsiblity for handling the output.
 *
 * When the delegate takes responsibility for handling audio output, it may wish to
 * delay the playback for a time. For example, in cases where the client application
 * is managing the audio session, the delegate may require some time to properly
 * configure the session before proceeding with playback. When the client application
 * is ready to play the output, it does so by calling NMAAudioOutput::play.
 *
 * If the delegate does not want the audio to be played at all, it must return NO from
 * this method and call NMAAudioManager::skipCurrentOutput. When NO is returned, the
 * audio manager will be paused until either play is called on the output or
 * skipCurrentOutput is called on the manager.
 *
 * \note Some audio output (e.g. navigation voice commands) is time-sensitive and thus
 *       should not be delayed for any significant period of time. If a large delay is
 *       required for such output, it's better to just skip the output entirely.
 */
- (BOOL)audioManager:(NMAAudioManager *)audioManager shouldPlayOutput:(NMAAudioOutput *)output;

/**
 * Called immediately before output is played by the NMAAudioManager.
 *
 * \note This method will not be called if audioManager:shouldPlayOutput: returned NO.
 */
- (void)audioManagerWillPlayOutput:(NMAAudioManager *)audioManager;

/**
 * Called immediately after output is played by the NMAAudioManager.
 *
 * \note This method will not be called if audioManager:shouldPlayOutput: returned NO.
 */
- (void)audioManagerDidPlayOutput:(NMAAudioManager *)audioManager;

@end


/**
 * \brief Manages the playback of audio output from files or TTS.
 *
 * The NMAAudioManager singleton is used to play audio output segments. It is also
 * responsible for managing the app's AVAudioSession to properly handle audio behaviour
 * in all circumstances. This includes setting the audio session category, and activating
 * and deactivating the session as needed to play output and combine appropriately with
 * other audio sources (such as background music).
 *
 * Currently, only serial playback is supported. The audio manager maintains a queue of
 * audio output, the elements of which are played in FIFO order.
 *
 * \note Must only be called on the main thread.
 */
@interface NMAAudioManager : NSObject

/**
 * Accesses the NMAAudioManager singleton object.
 */
+ (NMAAudioManager *)sharedAudioManager;

/**
 * The delegate of the NMAAudioManager, implementing the NMAAudioPlayerDelegate protocol.
 *
 * \sa NMAAudioManagerDelegate
 */
@property (nonatomic, weak) id<NMAAudioManagerDelegate> delegate;

/**
 * Controls whether the NMAAudioManager manages the application's audio session.
 *
 * If managesAudioSession is YES, the NMAAudioManager will change the type of the
 * audio session and activate and deactivate the session as necessary to play SDK
 * audio output.
 *
 * If managesAudioSession is NO, it is up to the application to properly configure
 * the audio session. In this case, the NMAAudioManager will notify its delegate
 * when SDK audio is available via the audioManager:shouldPlayOutput method of
 * NMAAudioManagerDelegate.
 *
 * Typically, the audio session management policy should be set when the application
 * is first launched or before the first usage of SDK audio output. It is not
 * recommended to change this property while audio playback features are in use.
 *
 * \note The default value is YES.
 *
 * \sa NMAAudioManagerDelegate
 */
@property (nonatomic) BOOL managesAudioSession;

/**
 * Requests playback of an output segment.
 *
 * Output segments are played in the order in which they are received. If no audio is
 * currently playing when this method is called, the provided output will be played
 * immediately. Otherwise, the output will be added to the end of the queue.
 *
 * \note This method is used to add new output to the audio playback queue. It should
 *       not be called for output already in the queue; for example, output received
 *       from the audioManager:shouldPlayOutput: method of NMAAudioManagerDelegate.
 */
- (void)playOutput:(NMAAudioOutput *)output;

/**
 * Skips the output at the front of the queue.
 *
 * If the current output has already started playing, it will be interrupted. The next
 * output item in the queue will be played.
 */
- (void)skipCurrentOutput;

/**
 * \brief Stops playing the current output immediately and clears any queued output.
 */
- (void)stopOutputAndClearQueue;

/**
 * Removes all output from the audio queue.
 *
 * \note If audio is currently playing, it will be allowed to finish.
 */
- (void)clearQueue;

/**
 * Force audio output to a specific audio route.
 *
 * The new audio route will be applied on the next NMAAudioOutput playback. If the
 * route is not available at that time (e.g. BT HFP device never connected or
 * disconnected) then the route will revert to NMAAudioRouteDefault before playback
 * and an NMAAudioRouteDidChangeNotification notification  will be posted.
 *
 * \param audioRoute NMAAudioRoute to use
 * \return YES if the route was set, NO otherwise (e.g. if route is not supported
 *         on iOS7)
 *
 * \note Calling this method does not cause a NMAAudioRouteDidChangeNotification
 *       notification to be posted.
 */
- (BOOL)setAudioRoute:(NMAAudioRoute)audioRoute;

/**
 * The current audio output route
 */
@property (nonatomic, readonly) NMAAudioRoute audioRoute;

@end

/** @}  */
