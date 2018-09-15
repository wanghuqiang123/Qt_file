#include "MainWindow.h"
#include <QLabel>

bool MainWindow::initToolBar()
{
    bool ret = true;
    QToolBar* tb = addToolBar("Tool Bar");

    tb->setIconSize(QSize(30,30));

    ret = ret && initPersonToolItem(tb);

    return ret;
}

bool MainWindow::initPersonToolItem(QToolBar *tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action,tb,"New Project",":/new/prefix1/UI_Icon/pic/new.png");
    if(ret)
    {
        tb->addAction(action);
    }

    return ret;
}
bool MainWindow::makeAction(QAction* &action,QWidget* parent,QString tip,QString icon)
{
    bool ret = true;
    action = new QAction("",parent);

    if(action != NULL)
    {
        action->setIcon(QIcon(icon));
        action->setIconText(tip);
    }
    else
    {
        ret = false;
    }

    return ret;
}
