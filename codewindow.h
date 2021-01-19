#ifndef CODEWINDOW_H
#define CODEWINDOW_H

#include <QtWidgets>

class codeWindow: public QDialog
{
    public:
        codeWindow(QString &code, QWidget *parent);
    private:
        QTextEdit *codeGenere;
        QPushButton *close;
};

#endif // CODEWINDOW_H
