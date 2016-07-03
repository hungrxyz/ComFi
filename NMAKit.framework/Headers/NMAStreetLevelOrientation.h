/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

/**
 * The NMAStreetLevelOrientation struct encapsulates the information required to
 * specify the viewing position within an NMAStreetLevelView.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
struct NMAStreetLevelOrientation {
    /**
     * The heading represents the viewing direction in the horizontal plane (north, south, east,
     * or west). The heading is specified in degrees, with 0 degrees pointing north, and rotating
     * clockwise as the value increases. The valid range is given by the NMAStreetLevelView#minimumHeading
     * and NMAStreetLevelView#maximumHeading properties.
     */
    CGFloat heading;
    /**
     * The pitch represents the viewing direction in the vertical plane containing the look vector. The
     * value is specified in degrees, with 0 degrees pointing at the horizon (parallel to the ground) and
     * 90 degrees pointing straight at the sky. The valid range is given by the NMAStreetLevelView#minimumPitch
     * and NMAStreetLevelView#maximumPitch properties.
     */
    CGFloat pitch;
};

/**
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef struct NMAStreetLevelOrientation NMAStreetLevelOrientation;

/**
 * @}
 */
