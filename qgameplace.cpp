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

#include "qgameplace.h"
#include "ui_qgameplace.h"


QGamePlace::QGamePlace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QGamePlace)
{
    ui->setupUi(this);
    _boardPlace = new QBoardPlace(this);
    QGridLayout *centr_layout = new QGridLayout;
    centr_layout->addWidget(_boardPlace);
    ui->centralWidget->setLayout(centr_layout);
//    QPiece(_board, _board->Cells[1][1]->getPositionCell(), QPiece::King );

}

QGamePlace::~QGamePlace()
{
    delete ui;
}
