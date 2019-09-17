#include "qwnmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWNMainWindow w;
    w.show();
    return a.exec();
}
