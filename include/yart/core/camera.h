#pragma once

#include <yart/core/common.h>

namespace yart
{


class YART_API Camera
{
public:
    /** Create a Camera with default paramters.*/
    Camera() = default;

    /** Create a Camera.
     *
     *  Position the camera using position, focus and up.
     *
     *  @param position Position.
     *  @param focus Focus.
     *  @param up Rough up direction.
     */

    virtual ~Camera() = default;

};

} // namespace yart
