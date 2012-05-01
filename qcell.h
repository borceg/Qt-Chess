#ifndef QCELL_H
#define QCELL_H

#include <QLabel>
#include <QMouseEvent>

#include "qgame.h"

class QGame;

class QCell : public QLabel
{
    Q_OBJECT
public:
    QCell(QPoint position, QWidget *parent = 0);
    QPoint getPosC();

private:
    QPoint _position;
    QGame *_game;

protected:
    virtual void mousePressEvent(QMouseEvent *ev);
};

#endif // QCELL_H
