#include "qwdigmanual.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWDigManual w;
    w.show();
    return a.exec();
}
