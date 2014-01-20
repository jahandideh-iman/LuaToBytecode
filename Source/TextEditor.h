#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QPlainTextEdit>
#include <QObject>
#include <QSize>
#include <QPaintEvent>
#include <QWidget>
#include <QResizeEvent>

class LineNumberArea;

class TextEditor : public QPlainTextEdit
{
    //Q_OBJECT

public:
    TextEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *lineNumberArea;
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(TextEditor *editor) : QWidget(editor) {
        textEditor = editor;
    }

    QSize sizeHint() const {
        return QSize(textEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) {
        textEditor->lineNumberAreaPaintEvent(event);
    }

private:
    TextEditor *textEditor;
};

#endif // TEXTEDITOR_H
