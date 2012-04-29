#include <QtGui/QApplication>
#include "qgameplace.h"
#include <QResource>
#include <QDebug>
#include "qgame.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(res);

    QApplication a(argc, argv);
    QGamePlace *w = new QGamePlace;
    w->show();
    QGame(w->_boardPlace);

    return a.exec();
}
