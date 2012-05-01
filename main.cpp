#include <QtGui/QApplication>
#include "qgameplace.h"
#include <QResource>
#include <QDebug>
#include "qgame.h"
#include <QMouseEvent>


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(res);

    QApplication a(argc, argv);
    QGamePlace *w = new QGamePlace;
    w->show();
    QGame *_game = QGame::instance();
    _game->setBoard(w->_boardPlace->_board);
    _game->newGame();

    return a.exec();
}
