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

#include "qcell.h"

QCell::QCell(QPoint position, QWidget *parent) :
    QLabel(parent)
{
    _position = position;
}

QPoint QCell::getPosC()
{
    return _position;
}

void QCell::mousePressEvent(QMouseEvent *ev)
{
    _game = QGame::instance();
    int i = this->getPosC().x();
    int j = this->getPosC().y();
    qDebug() << i << j;
    if ( _game->activeMove() && _game->_aMvs[i*8 + j] ) {
        //Переместить фигуру
        _game->setActiveMove(false);
        _game->doMove( _position );
        _game->resetMoves();
        _game->_map[_position.x()*8 + _position.y()] = 1;
    }
}


