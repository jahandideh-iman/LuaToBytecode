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
#include "QTextDocumentWriter"
#include "qaction.h"
#include "QtANGLE\GLES2\gl2.h"


class CompilerMain;

class CompilerView : public QMainWindow
{
   Q_OBJECT

public:
    CompilerView();
    TextEditor* editor;


    void DisplayError(QString error);

private slots:
    void newFile();
    void open();
    void save();
    //void saveAs();

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
    //QAction* saveAsAct;
    QAction* exitAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    //debug
    QAction* debugAct;
    QLabel* infoLabel;


    QFile* file;
    QTextStream * input;
    QString fileName;

    QString displayError;
};

#endif // COMPILERVIEW_H
