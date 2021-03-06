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

#include "qboard.h"

QBoard::QBoard(QWidget *parent) :
    QWidget(parent)
{

    grid_layout = new QGridLayout;
    grid_layout->setMargin(5);
    grid_layout->setSpacing(0);
    positionCells();
    positionXY();
    setLayout(grid_layout);
    drawCells();
}

//Расставить клетки
void QBoard::positionCells(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Cells[i][j] = new QCell(QPoint (i, j), this);
            QBoard::grid_layout->addWidget(Cells[i][j], i + 1, j + 1);
        }
    }
}

//Расставить буквы и цифры для обозначения координат
void QBoard::positionXY(){
    QString let("ABCDEFGH  "), num("12345678  ");
    const int len_let = 9, len_num = 9;
    QLabel *lbl_let[len_let];
    for(int i = 0; i < 8; ++i){
        lbl_let[i] = new QLabel;
        lbl_let[i]->setText(let[i] + '\0');
        QBoard::grid_layout->addWidget(lbl_let[i], 0, (i + 1), Qt::AlignHCenter);
        lbl_let[i]->setMaximumSize(17, 17);
    }

    QLabel *lbl_num[len_num];
    for(int i = 0; i < 8; ++i){
        lbl_num[i] = new QLabel;
        lbl_num[i]->setText(num[i] + '\0');
        QBoard::grid_layout->addWidget(lbl_num[i], (i + 1), 0, Qt::AlignVCenter);
        lbl_num[i]->setMaximumSize(15, 15);
    }


    lbl_let[len_let - 1] = new QLabel;
    lbl_num[len_num - 1] = new QLabel;
    lbl_let[len_let - 1]->setMaximumSize(17, 17);
    lbl_num[len_num - 1]->setMaximumSize(15, 15);
    lbl_let[len_let - 1]->setText(let[len_let] + '\0');
    lbl_num[len_num - 1]->setText(num[len_num] + '\0');
    QBoard::grid_layout->addWidget(lbl_let[len_let - 1], len_let, 0);
    QBoard::grid_layout->addWidget(lbl_num[len_num - 1], 0, len_num);
}

//Закрасить клетки
void QBoard::drawCells()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if ( ( (i & 1) && !(j & 1) ) || ( !(i & 1) && (j & 1) ))
                Cells[i][j]->setStyleSheet("background-color: rgb(111, 111, 111)");
            else Cells[i][j]->setStyleSheet("background-color: rgb(255, 255, 255)");
        }
    }
}

