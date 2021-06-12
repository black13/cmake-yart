#define _USE_MATH_DEFINES
#include <yart/camera/perspective.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <common.h>

int main(int argc, char* argv[])
{
	constexpr const unsigned g_width = 400;
	std::unique_ptr<yart::Camera> g_camera;

    g_camera = std::make_unique<yart::PerspectiveCamera>();
    return 0;
}
