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

#ifndef QPIECE_H
#define QPIECE_H

#ifdef Q_WS_WIN
#include <QtSvg\QSvgWidget>
#else
#include <QtSvg/QSvgWidget>
#endif

#include <QHBoxLayout>
#include <QMouseEvent>
#include "qboard.h"
#include "qgame.h"

class QBoard;
class QGame;

class QPiece : public QSvgWidget
{
private:
    enum State{Normal, Deleted};

public:
    enum Type{
        Rook,       //Ладья - 0
        Knight,     //Конь - 1
        Bishop,     //Слон - 2
        Queen,      //Королева - 3
        King,       //Король - 4
        Pawn        //Пешка - 5
    };
    QPiece(QWidget *board, bool color, Type type);

    void setPosition(QPoint val);
    void setState(State val);

    void movePiece(QPoint newPos);

    QPoint  position();
    bool    color();        //True - white, False - black piece
    State   state();        //Deleted or not
    Type    type();         //Pawn, King end etc.
    void setVis(bool val);
    bool _1stStep;

private:
    void setType(Type val);
    void setColor(bool val);
    Type    _type;
    QPoint  _position;
    State   _state;
    bool    _color;
    QBoard *_board;

protected:
    QGame *_game;
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // QPIECE_H
