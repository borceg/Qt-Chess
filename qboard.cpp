#include "qboard.h"

QBoard::QBoard(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setMargin(10);
    hlayout->addWidget(this);

    parent->setLayout(hlayout);
    positionCells();
    drawCells();
}

void QBoard::positionCells()
{
    QGridLayout *grid_layout = new QGridLayout;
    grid_layout->setMargin(0);
    grid_layout->setSpacing(0);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Cells[i][j] = new QCell(QPoint (i, j), this);
            grid_layout->addWidget(Cells[i][j], i, j);
        }
    }
    setLayout(grid_layout);
}

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
