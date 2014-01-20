#include "CompilerView.h"


CompilerView::CompilerView()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    //editor
    editor=new TextEditor(this);
    CompilerMain::GetSharedCompiler()->SetEditor(editor);
//-----------checking later
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    infoLabel = new QLabel();
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//------------checking later
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    //adding widget
    layout->addWidget(editor);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);

    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = "Ready";
    statusBar()->showMessage(message);

    setWindowTitle("Main");
    setMinimumSize(160, 160);
    resize(580, 420);
}

void CompilerView::newFile()
{
    infoLabel->setText("new file");
}

void CompilerView::open()
{
    editor->clear();
    fileName = QFileDialog::getOpenFileName();
    if(QFile::exists(fileName))
    {
        file =new QFile(fileName);
        file->open( QIODevice::ReadWrite);
        input=new QTextStream(file);
        while (!input->atEnd())
        {
            editor->setPlainText(editor->toPlainText()+input->readLine()+'\n');
            //infoLabel->setText(fileName);
        }
    }
    //CompilerMain::GetSharedCompiler()->
}

void CompilerView::save()
{
    file->remove();
    QTextDocumentWriter writer(fileName);
    writer.write(editor->document());

    //infoLabel->setText("file saved!");
	statusBar()->showMessage("File Saved");
}

//void CompilerView::saveAs()
//{
//    QString saveAsFileName = QFileDialog::getSaveFileName();
//    QFile saveAsFile(saveAsFileName);
//    saveAsFile.open(QIODevice::ReadWrite);
//    QTextDocumentWriter writer(saveAsFileName);
//    writer.write(editor->document());
//
//    infoLabel->setText("saved as!!");
//
//}

void CompilerView::cut()
{
    infoLabel->setText("cut");
}

void CompilerView::copy()
{
    infoLabel->setText("copy");
}

void CompilerView::paste()
{
    infoLabel->setText("paste");
}

void CompilerView::debug()
{

    displayError="";
	infoLabel->setText(displayError);
    CompilerMain::GetSharedCompiler()->Compile();





}


void CompilerView::createActions()
{

    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    //newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));


    openAct = new QAction(tr("Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));


    saveAct = new QAction(tr("Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));


   /* saveAsAct = new QAction(tr("Save As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));*/

    exitAct = new QAction(tr("Exit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    cutAct = new QAction(tr("Cut"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    copyAct = new QAction(tr("Copy"), this);
    copyAct->setShortcut(tr("Ctrl+C"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(tr("Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

    debugAct = new QAction("&Debug",this);
    debugAct->setShortcut(tr("Ctrl+R"));
    connect(debugAct, SIGNAL(triggered()),this,SLOT(debug()));
}



void CompilerView::createMenus()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    //fileMenu->addAction(saveAsAct);

    fileMenu->addSeparator();

    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    debugMenu = menuBar()->addMenu(tr("Debug"));
    debugMenu->addAction(debugAct);

}

void CompilerView::DisplayError(QString error)
{
    displayError.append(error+'\n');
    infoLabel->setText(displayError);
}
