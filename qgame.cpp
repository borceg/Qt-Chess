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

#include "qgame.h"

QGame::QGame(QBoardPlace *val)
{
    //_res = new QResource;
    _res.registerResource("res.rcc");

    _board = val->_board;

    newGame();
}

//Расстановка фигур на доске
void QGame::newGame()
{

    _Wpieces[0][0] = new  QPiece( _board, _board->Cells[0][0]->getPosC(), QPiece::Rook );
    _Wpieces[0][1] = new  QPiece( _board, _board->Cells[0][1]->getPosC(), QPiece::Knight );
    _Wpieces[0][2] = new  QPiece( _board, _board->Cells[0][2]->getPosC(), QPiece::Bishop );
    _Wpieces[0][3] = new  QPiece( _board, _board->Cells[0][3]->getPosC(), QPiece::Queen );
    _Wpieces[0][4] = new  QPiece( _board, _board->Cells[0][4]->getPosC(), QPiece::King );
    _Wpieces[0][5] = new  QPiece( _board, _board->Cells[0][5]->getPosC(), QPiece::Bishop );
    _Wpieces[0][6] = new  QPiece( _board, _board->Cells[0][6]->getPosC(), QPiece::Knight );
    _Wpieces[0][7] = new  QPiece( _board, _board->Cells[0][7]->getPosC(), QPiece::Rook );
    for (int i = 0; i < 8; ++i)
    {
        _Wpieces[1][i] = new  QPiece( _board, _board->Cells[1][i]->getPosC(), QPiece::Pawn );
    }

    _Bpieces[7][0] = new  QPiece( _board, _board->Cells[7][0]->getPosC(), QPiece::Rook );
    _Bpieces[7][1] = new  QPiece( _board, _board->Cells[7][1]->getPosC(), QPiece::Knight );
    _Bpieces[7][2] = new  QPiece( _board, _board->Cells[7][2]->getPosC(), QPiece::Bishop );
    _Bpieces[7][3] = new  QPiece( _board, _board->Cells[7][3]->getPosC(), QPiece::Queen );
    _Bpieces[7][4] = new  QPiece( _board, _board->Cells[7][4]->getPosC(), QPiece::King );
    _Bpieces[7][5] = new  QPiece( _board, _board->Cells[7][5]->getPosC(), QPiece::Bishop );
    _Bpieces[7][6] = new  QPiece( _board, _board->Cells[7][6]->getPosC(), QPiece::Knight );
    _Bpieces[7][7] = new  QPiece( _board, _board->Cells[7][7]->getPosC(), QPiece::Rook );
    for (int i = 0; i < 8; ++i)
    {
        _Bpieces[1][i] = new  QPiece( _board, _board->Cells[6][i]->getPosC(), QPiece::Pawn );
    }

}

//_piece = new  QPiece( _board, _board->Cells[1][1]->getPositionCell(), QPiece::King );
