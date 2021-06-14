#define _USE_MATH_DEFINES
#include <QtWidgets>
#include <QApplication>
#include <QStyleFactory>
#include <yart/camera/perspective.h>
#include <yart/widget/widget.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <common.h>

#include "mainWindow.h"



#include <iostream>
using namespace std;

int main(int argc_, char** argv_)
{
	QApplication app(argc_, argv_);

	app.setApplicationName(argv_[0]);
	app.setApplicationVersion(".01");

	// Nicked this style snippet from:
	// https://gist.github.com/QuantumCD/6245215
	app.setStyle(QStyleFactory::create("Fusion"));

	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
	darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

	darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);

	app.setPalette(darkPalette);

	app.setStyleSheet("QToolTip { color: #ffffff; "
		"background-color: #2a82da; "
		"border: 1px solid white; }");
	// End of snippet

	mainWindow_t main;

	main.show();

	return app.exec();
}
