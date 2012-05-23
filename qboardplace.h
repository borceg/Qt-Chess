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

#ifndef QBOARDPLACE_H
#define QBOARDPLACE_H

#include <QFrame>
#include "qboard.h"

class QBoard;

class QBoardPlace : public QFrame
{
    Q_OBJECT

public:
    QBoardPlace(QWidget *parent = 0);
    QBoard *_board;

private:
       virtual void resizeEvent(QResizeEvent*);

};

#endif // QBOARDPLACE_H
