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
#include <QPoint>
#include <QDebug>
#include <QBitArray>
#include <iostream>
#include <iomanip>

class QGamePlace;
class QPiece;

class QGame
{
protected:
    static QGame *_instance;

public:
    static QGame *instance();
    QPiece *_WPawns[8], *_WKing, *_WQueen, *_WRook[2], *_WKnight[2], *_WBishop[2];
    QPiece *_BPawns[8], *_BKing, *_BQueen, *_BRook[2], *_BKnight[2], *_BBishop[2];
    QBoard *_board;
    bool turn;                  //Чей ход? True - white
    void setBoard(QBoard *val);
    void createPiece();
    void newGame();

    void setActiveMove(bool val);
    bool activeMove();

    void setSelectPiece(QPiece *val);
    QPiece *selectPiece();

    void doMove(QPoint newPos);
    void genMoves();
    void resetMoves();
    void light(bool val);
    QBitArray _aMvs;
    QBitArray _map;
private:
    QGame();
    //~QGame();
    QResource _res;
    QPiece *_sPiece;
    bool _activeMove;

    void view_aMvs();
    void view_map();
};

#endif // QGAME_H
