#include "MainWindow.h"
#include <QList>
#include <QObjectList>

struct ActoinList
{
    QString action_name;
    int short_key;
    bool Sperate;
};

MainWindow::MainWindow()
{

}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();

    if( (ret == NULL) || !ret->construct())
    {
        delete ret;
        ret = NULL;
    }
    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;
    ret = ret && initMenuBar();
    ret = ret && initToolBar();

    return ret;
}

bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();

    ret = ret && initFileMenu(mb);
    ret = ret && initViewMenu(mb);
    ret = ret && initProjectMenu(mb);
    ret = ret && initHelpMenu(mb);

    setMenuBar(mb);
    return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File",mb);
    bool ret = (menu != NULL);
    if(ret)
    {
        QAction* action = NULL;

        ActoinList acname[] =
        {
            {"New Project",Qt::CTRL + Qt::Key_N,false},
            {"Open Project",Qt::CTRL + Qt::Key_O,false},
            {"Open Recent Project",0,true},
            {"Save",Qt::CTRL + Qt::Key_S,false},
            {"Save As",Qt::CTRL + Qt::ALT + Qt::Key_S,true},
            {"Print...",Qt::CTRL + Qt::Key_P,true},
            {"Close Project",0,false},
            {"Quit",Qt::CTRL + Qt::Key_Q,false}
        };

        int Array_len = sizeof(acname)/sizeof(acname[0]);

        for(int i = 0;i < Array_len;i++)
        {
            ret = ret && makeAction(action,menu,acname[i].action_name,acname[i].short_key);
            if(ret)
            {
                menu->addAction(action);
            }
            else
            {
                break;
            }

            if(acname[i].Sperate)
            {
                menu->addSeparator();
            }
        }
        //these are connect function;
        connect(findMenuBarAction("Quit"),SIGNAL(triggered(bool)),this,SLOT(onFileMenu_Quit()));

    }


    if( ret )
    {
        mb->addMenu(menu);    // add Menu add to application Menu Bar
    }
    else
    {
        delete menu;
    }

    return ret;
}



bool MainWindow::initViewMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("View",mb);
    bool ret = (menu != NULL);
    if(ret)
    {
        QAction* action = NULL;

        ActoinList acname[] =
        {
            {"Generated view",Qt::CTRL + Qt::Key_G,false},
            {"Generated forms",Qt::CTRL + Qt::Key_F,false}
        };

        int Array_len = sizeof(acname)/sizeof(acname[0]);

        for(int i = 0;i < Array_len;i++)
        {
            ret = ret && makeAction(action,menu,acname[i].action_name,acname[i].short_key);
            if(ret)
            {
                menu->addAction(action);
            }
            else
            {
                break;
            }

            if(acname[i].Sperate)
            {
                menu->addSeparator();
            }
        }
    }


    if( ret )
    {
        mb->addMenu(menu);    // add Menu add to application Menu Bar
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initProjectMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Project",mb);
    bool ret = (menu != NULL);
    if(ret)
    {
        QAction* action = NULL;

        ActoinList acname[] =
        {
            {"Project Schedule",0,false}
        };

        int Array_len = sizeof(acname)/sizeof(acname[0]);

        for(int i = 0;i < Array_len;i++)
        {
            ret = ret && makeAction(action,menu,acname[i].action_name,acname[i].short_key);
            if(ret)
            {
                menu->addAction(action);
            }
            else
            {
                break;
            }

            if(acname[i].Sperate)
            {
                menu->addSeparator();
            }
        }
    }


    if( ret )
    {
        mb->addMenu(menu);    // add Menu add to application Menu Bar
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initHelpMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Help",mb);
    bool ret = (menu != NULL);
    if(ret)
    {
        QAction* action = NULL;

        ActoinList acname[] =
        {
            {"About",0,false}
        };

        int Array_len = sizeof(acname)/sizeof(acname[0]);

        for(int i = 0;i < Array_len;i++)
        {
            ret = ret && makeAction(action,menu,acname[i].action_name,acname[i].short_key);
            if(ret)
            {
                menu->addAction(action);
            }
            else
            {
                break;
            }

            if(acname[i].Sperate)
            {
                menu->addSeparator();
            }
        }
    }


    if( ret )
    {
        mb->addMenu(menu);    // add Menu add to application Menu Bar
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action,QWidget* parent,QString text,int short_key)
{
    bool ret = true;

    action = new QAction(text, parent);

    if( action != NULL )
    {
        action->setShortcut(QKeySequence(short_key));
    }
    else
    {
        ret = false;
    }

    return ret;
}

QAction* MainWindow::findMenuBarAction(QString text)
{
    QAction* ret = NULL;
    const QObjectList& list = menuBar()->children();

    for(int i = 0;i<list.count();i++)
    {
        QMenu* menu = dynamic_cast<QMenu*>(list[i]);

        if(menu != NULL)
        {
            QList<QAction*>actions = menu->actions();
            for(int j = 0;j<actions.count();j++)
            {
                if(actions[j]->text().startsWith(text))
                {
                    ret = actions[j];
                    break;
                }
            }
        }
    }
    return ret;
}

MainWindow::~MainWindow()
{

}
