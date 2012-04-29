#include "qcell.h"

QCell::QCell(QPoint position, QWidget *parent) :
    QLabel(parent)
{

    _position = position;
}

QPoint QCell::getPosC()
{
    return _position;
}
