#include <QWidget>

#include <yart/core/common.h>

class YART_API Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget* parent = nullptr);
};