/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAAudioOutput.h"

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \brief A collection of audio output consisting of one or more WAVE files.
 *
 * \note Audio output should never be played directly. Instead it should be passed
 * to the NMAAudioManager (via the playOutput method) to be played.
 */
@interface NMAAudioFileOutput : NMAAudioOutput

/**
 * Creates an NMAAudioFileOutput with the given files.
 */
+ (instancetype)audioOutputWithFiles:(NSArray *)files;

/**
 *  If YES, the audio file(s) will be deleted when this object is destroyed.
 */
@property (nonatomic) BOOL deleteWhenFinished;

@end

/** @} */
