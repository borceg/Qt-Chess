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
    void drawCells();
    QCell *Cells[8][8];
};

#endif // QBOARD_H
