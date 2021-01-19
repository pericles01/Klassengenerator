#include <QApplication>
#include <gui.h>
 int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    Gui window;
    window.show();

    return app.exec();
}
