#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QToolBar>
#include <QIcon>

class MainWindow : public QMainWindow
{
    Q_OBJECT


protected:
    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator = (const MainWindow&);

    bool construct();
//these are MenuBar initial;
    bool initMenuBar();
    bool initFileMenu(QMenuBar*);
    bool initViewMenu(QMenuBar*);
    bool initProjectMenu(QMenuBar*);
    bool initHelpMenu(QMenuBar*);
    bool makeAction(QAction*& action,QWidget* parent,QString text,int short_key);
//these are ToolBar initial:
    bool initToolBar();
    bool initPersonToolItem(QToolBar* tb);
    bool makeAction(QAction* &action,QWidget* parent,QString tip,QString icon);


    QAction* findMenuBarAction(QString text);
public:
    static MainWindow* NewInstance();
    ~MainWindow();
protected slots:
    void onFileMenu_Quit();
};

#endif // MAINWINDOW_H
