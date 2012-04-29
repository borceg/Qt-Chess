#ifndef QBOARD_H
#define QBOARD_H

#include <QWidget>
#include <QLayout>
#include "qcell.h"

class QCell;

class QBoard : public QWidget
{
    Q_OBJECT
public:
    QBoard(QWidget *parent = 0);
    QCell *Cells[8][8];

private:
    void positionCells();
    void positionXY();
    void drawCells();
    QGridLayout *grid_layout;
};

#endif // QBOARD_H
