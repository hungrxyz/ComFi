/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAAudioOutput.h"

@class AVSpeechSynthesisVoice;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \brief A TTS audio output segment consisting of a single string.
 *
 * \note Audio output should never be played directly. Instead it should be passed
 * to the NMAAudioManager (via the playOutput method) to be played.
 */
@interface NMATTSAudioOutput : NMAAudioOutput

/**
 * Creates an NMATTSAudioOutput with the given text string.
 */
+ (instancetype)audioOutputWithText:(NSString *)text;

/**
 * The text string to speak.
 */
@property (nonatomic) NSString *text;

/**
 * The voice used to speak the text.
 *
 * \note By default, the voice will be selected based on the current locale of the device.
 */
@property (nonatomic) AVSpeechSynthesisVoice *voice;

/**
 * The pitch multiplier with which the text is spoken.
 *
 * \note The default value is 1.0;
 */
@property (nonatomic) float pitchMultiplier;

/**
 * The speech rate at which the text is spoken.
 *
 * \note The default value is AVSpeechUtteranceDefaultSpeechRate.
 */
@property (nonatomic) float speechRate;

@end

/** @} */
