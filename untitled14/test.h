#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QPalette>
#define LINE 500
#include <QDebug>

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
    int width;
    int height;
    QPoint center;
    QPoint verTex[4];
    QPoint prePoint;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // TEST_H
