#ifndef GUI_H
#define GUI_H
#include <QApplication>
#include <QtWidgets>

class Gui: public QWidget
{
    Q_OBJECT
    public:
        Gui();
    private slots:
        void generateCode();

    private:
        QLineEdit *name;
        QLineEdit *motherClass;
        QCheckBox *protections;
        QCheckBox *generateConstructor;
        QCheckBox *generateDestructor;
        QGroupBox *groupComment;
        QLineEdit *autor;
        QDateEdit *date;
        QTextEdit *role;
        QPushButton *generate;
        QPushButton *quit;

};

#endif // GUI_H
