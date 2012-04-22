#ifndef QBOARD_H
#define QBOARD_H

#include <QWidget>
#include <QLayout>
#include "qcell.h"

class QBoard : public QWidget
{
    Q_OBJECT
public:
    explicit QBoard(QWidget *parent = 0);

private:
    void positionCells();
    void positionXY();
    void drawCells();
    QCell *Cells[8][8];
    QGridLayout *grid_layout;
};

#endif // QBOARD_H
