#define _USE_MATH_DEFINES
#include <yart/camera/perspective.h>
#include <yart/widget/widget.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <common.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Widget w;

    constexpr const unsigned g_width = 400;
    std::unique_ptr<yart::Camera> g_camera;

    g_camera = std::make_unique<yart::PerspectiveCamera>();

    w.resize(100, 100);
    w.show();
    return a.exec();


}