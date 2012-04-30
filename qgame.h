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

#ifndef QGAME_H
#define QGAME_H

#include <QResource>
#include "qpiece.h"
#include "qgameplace.h"

class QGamePlace;

class QGame
{
protected:
    static QGame *_instance;

public:
    bool turn;                  //Чей ход? True - white
    QPiece *_Wpieces[2][8];
    QPiece *_Bpieces[2][8];
    QBoard *_board;
    static QGame *instance();
    void setBoard(QBoard *val);
    void newGame();
    QGame();
    //~QGame();

private:
    QResource _res;
    QPiece *_selectPiece;
    bool _activeMove;
};

#endif // QGAME_H
