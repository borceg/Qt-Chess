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

#ifndef QBOARD_H
#define QBOARD_H

#include <QWidget>
#include <QLayout>
#include "qcell.h"

class QCell;

class QBoard : public QWidget
{
    Q_OBJECT
public:
    QBoard(QWidget *parent = 0);
    QCell *Cells[8][8];

private:
    void positionCells();
    void positionXY();
    void drawCells();
    QGridLayout *grid_layout;
};

#endif // QBOARD_H
