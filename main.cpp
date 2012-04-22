#include <QtGui/QApplication>
#include "qgameplace.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGamePlace w;
    w.show();

    return a.exec();
}
