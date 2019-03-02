#include "test.h"

Test::Test()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800,800,"cyhcs",NULL,NULL);
    if(!window)
    {
        qDebug()<<"窗口创建失败!";
        glfwTerminate();
    }
    button = new QPushButton((QWidget *)window);
    //glfwTerminate();
}

Test::~Test()
{
    glfwTerminate();
}
