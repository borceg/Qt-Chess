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

QGame *QGame::_instance = 0;

QGame::QGame()
{
    _res.registerResource("res.rcc");

    turn = true;
    _sPiece = 0;
    _activeMove = false;

    _map.resize(64);
    _aMvs.resize(64);

}

QGame *QGame::instance()
{
    if (!_instance)
    {
        _instance = new QGame();
    }
    return _instance;
}

void QGame::createPiece()
{
    _BRook[0]   = new  QPiece( _board, false, QPiece::Rook );
    _BKnight[0] = new  QPiece( _board, false, QPiece::Knight );
    _BBishop[0] = new  QPiece( _board, false, QPiece::Bishop );
    _BQueen     = new  QPiece( _board, false, QPiece::Queen );
    _BKing      = new  QPiece( _board, false, QPiece::King );
    _BBishop[1] = new  QPiece( _board, false, QPiece::Bishop );
    _BKnight[1] = new  QPiece( _board, false, QPiece::Knight );
    _BRook[1]   = new  QPiece( _board, false, QPiece::Rook );
    for (int i = 0; i < 8; ++i)
    {
        _BPawns[i] = new  QPiece( _board, false, QPiece::Pawn );
    }

    _WRook[0]   = new  QPiece( _board, true, QPiece::Rook );
    _WKnight[0] = new  QPiece( _board, true, QPiece::Knight );
    _WBishop[0] = new  QPiece( _board, true, QPiece::Bishop );
    _WQueen     = new  QPiece( _board, true, QPiece::Queen );
    _WKing      = new  QPiece( _board, true, QPiece::King );
    _WBishop[1] = new  QPiece( _board, true, QPiece::Bishop );
    _WKnight[1] = new  QPiece( _board, true, QPiece::Knight );
    _WRook[1]   = new  QPiece( _board, true, QPiece::Rook );
    for (int i = 0; i < 8; ++i)
    {
        _WPawns[i] = new  QPiece( _board, true, QPiece::Pawn );
    }
}

//Расстановка фигур на доске
void QGame::newGame()
{
    _BRook[0]->setPosition(_board->Cells[0][0]->getPosC());
    _BKnight[0]->setPosition(_board->Cells[0][1]->getPosC());
    _BBishop[0]->setPosition(_board->Cells[0][2]->getPosC());
    _BQueen->setPosition(_board->Cells[0][3]->getPosC());
    _BKing->setPosition(_board->Cells[0][4]->getPosC());
    _BBishop[1]->setPosition(_board->Cells[0][5]->getPosC());
    _BKnight[1]->setPosition(_board->Cells[0][6]->getPosC());
    _BRook[1]->setPosition(_board->Cells[0][7]->getPosC());
    for (int i = 0; i < 8; ++i)
    {
        _BPawns[i]->setPosition(_board->Cells[1][i]->getPosC());
    }

    _WRook[0]->setPosition(_board->Cells[7][0]->getPosC());
    _WKnight[0]->setPosition(_board->Cells[7][1]->getPosC());
    _WBishop[0]->setPosition(_board->Cells[7][2]->getPosC());
    _WQueen->setPosition(_board->Cells[7][3]->getPosC());
    _WKing->setPosition(_board->Cells[7][4]->getPosC());
    _WBishop[1]->setPosition(_board->Cells[7][5]->getPosC());
    _WKnight[1]->setPosition(_board->Cells[7][6]->getPosC());
    _WRook[1]->setPosition(_board->Cells[7][7]->getPosC());
    for (int i = 0; i < 8; ++i)
    {
        _WPawns[i]->setPosition(_board->Cells[6][i]->getPosC());
    }

    //Init map
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if ( i == 0 || i == 1 || i == 6 || i == 7) _map[i*8 + j] = 1;
        }
    }

}

void QGame::setBoard(QBoard *val)
{
    _board = val;
}

void QGame::setActiveMove(bool val)
{
    _activeMove = val;
    light(val);
}

bool QGame::activeMove()
{
    return _activeMove;
}

void QGame::setSelectPiece(QPiece *val)
{
    _sPiece = val;
}

QPiece *QGame::selectPiece()
{
    return _sPiece;
}

void QGame::doMove(QPoint newPos)
{

    _sPiece->movePiece(newPos);
    turn = !turn;
    _sPiece->_1stStep = false;

}

void QGame::genMoves()
{
    QPoint pos = _sPiece->position();
    int posX, posY;

    if ( _sPiece->type() == QPiece::Rook || _sPiece->type() == QPiece::Queen )
    {
        posX = pos.x();
        posY = pos.y();
        if ( posY > 0 ) --posY;
        qDebug() << "_map[posX*8 + posY]" << _map[posX*8 + posY];
        while ( !_map[posX*8 + posY] && (posY >= 0) )
        {
            _aMvs[posX*8 + posY] = 1;
            --posY;
            if ( posY < 0 ) break;
        }
        if ( posY >= 0 ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x();
        posY = pos.y();
        if ( posY < 7 ) ++posY;
        while ( !_map[posX*8 + posY] && (posY <= 7) )
        {
            _aMvs[posX*8 + posY] = 1;
            ++posY;
            if ( posY > 7 ) break;
        }
        if ( posY <= 7 ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x();
        posY = pos.y();
        if ( posX > 0 ) --posX;
        qDebug() << "_map[posX*8 + posY]" << _map[posX*8 + posY];
        while ( !_map[posX*8 + posY] && (posX >= 0) )
        {
            _aMvs[posX*8 + posY] = 1;
            --posX;
            if ( posX < 0 ) break;
        }
        if ( posX >= 0 ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x();
        posY = pos.y();
        if (posX < 7 ) ++posX;
        while ( !_map[posX*8 + posY] && (posX <= 7) )
        {
            _aMvs[posX*8 + posY] = 1;
            ++posX;
            if ( posX > 7 ) break;
        }
        if ( posX <= 7 ) _aMvs[posX*8 + posY] = 1;
    }

    if ( _sPiece->type() == QPiece::Bishop || _sPiece->type() == QPiece::Queen )
    {
        posX = pos.x(); posY = pos.y();
        if ( (posX > 0) && (posY > 0) ) { --posX; --posY; }
        while ( !_map[posX*8 + posY] && (posY >= 0 || posX >= 0) )
        {
            _aMvs[posX*8 + posY] = 1;
            if ( posY > 0 ) --posY;
            if ( posX > 0 ) --posX;
        }
        if ( (posY >= 0) && (posX >= 0) ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x(); posY = pos.y();
        if ( (posX < 7) && (posY < 7) ) { ++posX; ++posY; }
        while ( !_map[posX*8 + posY] && (posY <= 7 || posX <= 7) )
        {
            _aMvs[posX*8 + posY] = 1;
            if ( posY < 7 ) ++posY;
            if ( posX < 7 ) ++posX;
        }
        if ( (posY <= 7) && (posX <= 7) ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x(); posY = pos.y();
        if ( (posX > 0) && (posY < 7) ) { --posX; ++posY; }
        while ( !_map[posX*8 + posY] && (posX >= 0 || posY <= 7) )
        {
            _aMvs[posX*8 + posY] = 1;
            if ( posX > 0 ) --posX;
            if ( posY < 7 ) ++posY;
        }
        if ( (posX >= 0) && (posY <= 7) ) _aMvs[posX*8 + posY] = 1;

        posX = pos.x(); posY = pos.y();
        if ( (posX < 7) && (posY > 0) ) { ++posX; --posY; }
        while ( !_map[posX*8 + posY] && (posX <= 7 || posY >= 0) )
        {
            _aMvs[posX*8 + posY] = 1;
            if ( posX < 7 ) ++posX;
            if ( posY > 0 ) --posY;
        }
        if ( (posX <= 7) && (posY >= 0) ) _aMvs[posX*8 + posY] = 1;
    }

    if ( _sPiece->type() == QPiece::King )
    {
        posX = pos.x(); posY = pos.y();
        int dx[] = {-1, -1, -1,  0,  0,  1,  1,  1};
        int dy[] = {-1,  0,  1,  1,  1,  0, -1, -1};
        for(int i = 0; i < 8; ++i)
        {
            int nx = posX + dx[i];
            int ny = posY + dy[i];
            if ( nx >= 0 && nx < 8 && ny >= 0 && ny < 8 )
            {
                _aMvs[nx*8 + ny] = 1;
            }
        }
    }

    if ( _sPiece->type() == QPiece::Pawn )
    {
        posX = pos.x(); posY = pos.y();
        if ( _sPiece->color() )
        {
            if ( posX > 0 ) --posX;
        }
        else if ( posX < 7 ) ++posX;
        if ( _map[posX*8 + posY] == 0 )
        {
            _aMvs[posX*8 + posY] = 1;
            if ( _sPiece->color() && _sPiece->_1stStep ) --posX;
            else if ( !_sPiece->color() && _sPiece->_1stStep ) ++posX;
            if ( !_map[posX*8 + posY] ) _aMvs[posX*8 + posY] = 1;
        }
    }

    if ( _sPiece->type() == QPiece::Knight)
    {
        posX = pos.x(); posY = pos.y();
        int dx[] = { 1,  2,  2,  1, -1, -2, -2, -1};
        int dy[] = {-2, -1,  1,  2,  2,  1, -1, -2};
        for(int i = 0; i < 8; ++i)
        {
            int nx = posX + dx[i];
            int ny = posY + dy[i];
            if ( nx >= 0 && nx < 8 && ny >= 0 && ny < 8 )
            {
                _aMvs[nx*8 + ny] = 1;
            }
        }
    }

//    view_aMvs();
//    view_map();
}

void QGame::light(bool val)
{
    int i = _sPiece->position().x();
    int j = _sPiece->position().y();
    if ( val ) _board->Cells[i][j]->setStyleSheet("background-color: rgb(138,132,192)");
    else if ( ( (i & 1) && !(j & 1) ) || ( !(i & 1) && (j & 1) ))
        _board->Cells[i][j]->setStyleSheet("background-color: rgb(111, 111, 111)");
    else _board->Cells[i][j]->setStyleSheet("background-color: rgb(255, 255, 255)");
}

void QGame::resetMoves()
{
    for(int i = 0; i < 64; ++i) _aMvs[i] = 0;
}

void QGame::view_aMvs()
{
    qDebug() << "View Allowed Moves:";
    int i = 0;
    while (i < 64)
    {
        qDebug() << (i/8) << _aMvs[i] << _aMvs[i+1] << _aMvs[i+2] << _aMvs[i+3] << _aMvs[i+4] << _aMvs[i+5] << _aMvs[i+6] << _aMvs[i+7];
        i += 8;
    }
}

void QGame::view_map()
{
    qDebug() << "View Map:";
    int i = 0;
    while (i < 64)
    {
        qDebug() << (i/8) << _map[i] << _map[i+1] << _map[i+2] << _map[i+3] << _map[i+4] << _map[i+5] << _map[i+6] << _map[i+7];
        i += 8;
    }
}
