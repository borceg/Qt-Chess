#include "qcell.h"

QCell::QCell(QPoint position, QWidget *parent) :
    QLabel(parent)
{
    _game = QGame::instance();
    _position = position;
}

QPoint QCell::getPosC()
{
    return _position;
}

void QCell::mousePressEvent(QMouseEvent *ev)
{
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


