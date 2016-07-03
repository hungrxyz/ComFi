/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * A struct for representing a 3D vector.
 */
typedef struct NMAVector3d {
    CGFloat x;
    CGFloat y;
    CGFloat z;
} NMAVector3d;

/**
 * \brief Check if two vectors are equal
 *
 * \param v1 first vector
 * \param v2 second vector
 * \return true if two vectors are equal, false otherwise
 *
 */
CG_INLINE BOOL NMAVector3dEqualToVector(const NMAVector3d v1, const NMAVector3d v2)
{
    return (v1.x == v2.x && v1.y == v2.y && v1.z && v2.z);
}

/**
 * \brief Convenient method for creating a new NMAVector3d
 *
 * \param x X axis value
 * \param y Y axis value
 * \param z Z axis value
 * \return a new NMAVector3d struct
 *
 */
CG_INLINE NMAVector3d NMAVector3dMake(CGFloat x, CGFloat y, CGFloat z)
{
    NMAVector3d vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

/**  @}  */
