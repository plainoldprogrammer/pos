#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet( "QMainWindow { background-color: #808080 }" );
    w.show();

    return a.exec();
}
