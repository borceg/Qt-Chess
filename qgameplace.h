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

#ifndef QGAMEPLACE_H
#define QGAMEPLACE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "qboardplace.h"


class QBoardPlace;

namespace Ui {
    class QGamePlace;
}

class QGamePlace : public QMainWindow
{
    Q_OBJECT

public:
    QBoardPlace *_boardPlace;
    QGamePlace(QWidget *parent = 0);
    ~QGamePlace();

private:
    Ui::QGamePlace *ui;

};

#endif // QGAMEPLACE_H
