#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTimerEvent>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();

private:
    Ui::Test *ui;
    int width,height;
    int r;
    int miaoZhen = 0;
    int timerOne;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
};

#endif // TEST_H
