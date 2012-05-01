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
    if ( ev->button() == Qt::LeftButton)
    {
    if ( _game->activeMove() )
    {
        _game->doMove( _position );
        _game->setActiveMove(false);
    }
    }
}
