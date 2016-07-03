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
 * \brief Events which occur during the lifecycle of an NMAAudioOutput.
 */
typedef NS_ENUM(NSInteger, NMAAudioOutputEvent) {
    NMAAudioOutputBegan,
    NMAAudioOutputSkipped,
    NMAAudioOutputEnded
};

/**
 * \brief Sources of audio output in the Here SDK.
 */
typedef NS_ENUM(NSInteger, NMAAudioOutputSource) {
    /** \brief The source of the output is not known. */
    NMAAudioOutputSourceUnknown,
    /** \brief The SDK user is the source of the output. */
    NMAAudioOutputSourceUser,
    /** \brief The output is from turn-by-turn guidance. */
    NMAAudioOutputSourceGuidance
};

/**
 * A block interface for responding to NMAAudioOutput lifecycle events.
 */
typedef void (^NMAAudioOutputEventBlock)(NMAAudioOutputEvent event);


/**
 * \brief A single segment of audio output.
 *
 * NMAAudioOutput represents one cohesive segment of audio output; for example,
 * a single sentence of TTS output or a single audio file. It is used with the
 * NMAAudioManager to play audio in an application.
 *
 * NMAAudioOutput is an abstract base class and should not be directly instantiated.
 * Instead, subclasses which implement the required interface functions should be
 * used.
 *
 * For convenience, the NMAAudioFileOutput and NMATTSAudioOutput classes have been
 * created for basic audio output functionality.
 *
 * \sa NMAAudioFileOutput
 * \sa NMATTSAudioOutput
 * \sa NMAAudioManager
 */
@interface NMAAudioOutput : NSObject

/**
 * A block which provides user-defined behaviour in response to lifecycle events.
 *
 * The event block is typically defined by the object which created the audio output.
 * It can be used for example to notify a listener when a given audio output starts
 * and finishes.
 *
 * The NMAAudioOutputEvent enum defines the types of events for which the block is
 * called.
 *
 * \sa NMAAudioOutputEvent
 */
@property (nonatomic, strong) NMAAudioOutputEventBlock eventBlock;

/**
 * The source of the audio output.
 *
 * Audio output objects created by the application should use NMAAudioOutputSourceUser.
 */
@property (nonatomic) NMAAudioOutputSource source;

/**
 * Plays the audio output.
 *
 * \note Subclasses must implement this method and call the super implementation at
 * the beginning of the method.
 */
- (void)play;

/**
 * Stops the audio output.
 *
 * \note Subclasses must implement this method and call the super implementation at
 * the end of the method.
 */
- (void)stop;

@end

/** @} */
