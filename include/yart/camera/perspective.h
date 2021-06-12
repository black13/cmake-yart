#pragma once

#include <yart/core/camera.h>

namespace yart
{

/** A persective camera.
 *
 *  The range of visible frustum of a perspective camera is determined
 *  by the field of view and aspect ratio.
 */
class YART_API PerspectiveCamera : public Camera
{
public:
    /** Create a PerspectiveCamera using default parameters.*/
    PerspectiveCamera();
};

} // namespace yart
