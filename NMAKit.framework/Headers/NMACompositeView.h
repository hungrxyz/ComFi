/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAARController;

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */


/**
 * \class NMACompositeView NMACompositeView.h "NMACompositeView.h"
 *
 * \brief A UIView subclass used to display LiveSight.
 *
 * LiveSight provides an Augmented Reality experience in which a camera view is
 * displayed and overlayed with objects representing real world places or locations.
 *
 * \note The view will be blank until LiveSight is started on the AR controller.
 */
@interface NMACompositeView : UIView

#pragma mark LiveSight Mode

/**
 * \brief NMAARController is used to enter LiveSight mode and configure LiveSight functionality
 *
 * LiveSight mode is disabled by default.
 */
@property (nonatomic, readonly) NMAARController *arController;

/**
 * \brief A flag to enable or disable rendering.
 *
 * The flag can be used to pause rendering when the composite view is covered by another view.
 *
 * renderAllowed is YES by default.
 *
 */
@property (nonatomic, getter = isRenderAllowed) BOOL renderAllowed;

@end

/** @}  */
