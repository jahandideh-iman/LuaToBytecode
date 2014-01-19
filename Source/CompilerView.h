#ifndef COMPILERVIEW_H
#define COMPILERVIEW_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include "TextEditor.h"
#include <QFileDialog>
#include "qfile.h"
#include "qtextstream.h"
#include "CompilerMain.h"

class CompilerMain;

class CompilerView : public QMainWindow
{
    Q_OBJECT

public:
    CompilerView();
    TextEditor* editor;

private slots:
    void newFile();
    void open();
    void save();
    void cut();
    void copy();
    void paste();
    //debug
    void debug();
private:
    void createActions();
    void createMenus();

    //menus
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* debugMenu;

    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* exitAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    //debug
    QAction* debugAct;
    QLabel* infoLabel;


    QFile* file;
    QTextStream * input;
};

#endif // COMPILERVIEW_H
