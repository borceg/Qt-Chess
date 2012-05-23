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

#include "qboardplace.h"

QBoardPlace::QBoardPlace(QWidget *parent) :
    QFrame(parent)
{
    this->setStyleSheet("background-color: rgb(255, 170, 127);");
    this->setMinimumSize(400, 400);
    _board = new QBoard(this);
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setMargin(0);
    hlayout->addWidget(_board);

    setLayout(hlayout);
}

void QBoardPlace::resizeEvent(QResizeEvent *event)
{
    int lesser = std::min(this->width(), this->height());
    resize(lesser, lesser);
    int newX = ( static_cast<QWidget *>(parent())->width() - width() ) / 2;
    move( newX, y() );
}
