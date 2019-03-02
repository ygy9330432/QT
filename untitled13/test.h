#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <glfw3.h>
#include <QDebug>
#include <QPushButton>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test();
    ~Test();

private:
    QPushButton *button;
};

#endif // TEST_H
