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

#ifndef QCELL_H
#define QCELL_H

#include <QLabel>
#include <QMouseEvent>

#include "qgame.h"

class QGame;

class QCell : public QLabel
{
    Q_OBJECT
public:
    QCell(QPoint position, QWidget *parent = 0);
    QPoint getPosC();

private:
    QPoint _position;
    QGame *_game;

protected:
    virtual void mousePressEvent(QMouseEvent *ev);

};

#endif // QCELL_H
