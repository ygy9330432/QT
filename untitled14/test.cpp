#include "test.h"

Test::Test(QWidget *parent) :
    QWidget(parent)
{
    QPalette pal;
    pal.setBrush(QPalette::Window,QBrush(Qt::black));
    this->setPalette(pal);
    verTex[0].setX(this->size().width() / 2 - 50);
    verTex[0].setY(this->size().height() / 2 - 50);
}

Test::~Test()
{

}

void Test::paintEvent(QPaintEvent *event)
{
    width = this->size().width();
    height = this->size().height();
    center.setX(width / 2);
    center.setY(height / 2);
    //verTex[0].setX(width / 2 - 50);
    //verTex[0].setY(height / 2 - 50);
    verTex[1].setX(verTex[0].x() + LINE);
    verTex[1].setY(verTex[0].y());
    verTex[2].setX(verTex[0].x() + LINE);
    verTex[2].setY(verTex[0].y() + LINE);
    verTex[3].setX(verTex[0].x());
    verTex[3].setY(verTex[0].y() + LINE);
    QPainter pa;
    pa.begin(this);
    pa.setPen(QColor(Qt::blue));
    pa.drawRect(verTex[0].x(),verTex[0].y(),500,500);
    pa.drawRect(0.5 * (center.x() + verTex[0].x()),0.5 * (center.y() + verTex[0].y()),LINE / 2,LINE / 2);
    for(int i = 0;i < 4;i++)
    {
        pa.setPen(QColor(Qt::blue));
        pa.drawLine(QPointF(verTex[i]),QPointF(0.5 * (center.x() + verTex[i].x()),0.5 * (center.y() + verTex[i].y())));
        pa.setPen(QColor(Qt::red));
        pa.drawLine(QPointF(0.5 * (center.x() + verTex[i].x()),0.5 * (center.y() + verTex[i].y())),QPointF(center));
    }
    qDebug()<<verTex[0];
    pa.end();
}

void Test::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        prePoint.setX(event->pos().x() - verTex[0].x());
        prePoint.setY(event->pos().y() - verTex[0].y());
    }
}

void Test::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        verTex[0].setX(event->pos().x() - prePoint.x());
        verTex[0].setY(event->pos().y() - prePoint.y());
    }
    this->update();
}
