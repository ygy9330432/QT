#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    timerOne = this->startTimer(1000);
}

Test::~Test()
{
    delete ui;
}

void Test::paintEvent(QPaintEvent *event)
{
    width = this->size().width();
    height = this->size().height();
    r = qMin(width,height);
    int i = 0;
    QPainter pa;
    pa.begin(this);
    //pa.drawEllipse(QPointF(width / 2,height / 2),r / 2,r / 2);
    pa.translate(width / 2,height / 2);
    for(int i = 0;i < 4;i++)
    {
        pa.setBrush(Qt::blue);
        pa.drawRect(-r / 2,-height / 40,r / 15,height / 20);
        for(int j = 0;j < 3;j++)
        {
            pa.rotate(90 / 4.0);
            pa.setBrush(Qt::red);
            pa.drawRect(-r / 2.0,0,r / 18.0,height / 30.0);
        }
        pa.rotate(90 / 4.0);
    }
    pa.rotate(miaoZhen);
    pa.drawRect(-r / 2,0,r / 2,3);
    pa.end();
}

void Test::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerOne && miaoZhen < 360)
        miaoZhen += 6;
    else
        miaoZhen = 6;
    qDebug()<<miaoZhen;
    update();
}
