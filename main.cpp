/*
Copyright (C) 2012  John24
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
*/

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
    _game->createPiece();
    _game->newGame();

    return a.exec();
}
