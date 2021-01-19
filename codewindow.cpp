#include "codewindow.h"

codeWindow::codeWindow(QString &code, QWidget *parent = 0):QDialog(parent)
{
        codeGenere = new QTextEdit();
        codeGenere->setPlainText(code);
        codeGenere->setReadOnly(true);
        codeGenere->setFont(QFont("Courier"));
        codeGenere->setLineWrapMode(QTextEdit::NoWrap);

        close = new QPushButton("Schließen");

        QVBoxLayout *principalLayout = new QVBoxLayout;
        principalLayout->addWidget(codeGenere);
        principalLayout->addWidget(close);

        resize(350, 450);
        setLayout(principalLayout);

        connect(close, SIGNAL(clicked()), this, SLOT(accept()));

}
