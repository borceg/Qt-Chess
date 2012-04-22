#include "qboard.h"

QBoard::QBoard(QWidget *parent) :
    QWidget(parent)
{

    QGridLayout *grid_layout = new QGridLayout;
    grid_layout->setMargin(5);
    grid_layout->setSpacing(0);

    QString let("ABCDEFGH  "), num("12345678  ");
    const int len_let = 9, len_num = 9;
    QLabel *lbl_let[len_let];
    for(int i = 0; i < 8; ++i){
        lbl_let[i] = new QLabel;
        lbl_let[i]->setText(let[i] + '\0');
        grid_layout->addWidget(lbl_let[i], 0, (i + 1), Qt::AlignHCenter);
        lbl_let[i]->setMaximumSize(17, 17);
    }

    QLabel *lbl_num[len_num];
    for(int i = 0; i < 8; ++i){
        lbl_num[i] = new QLabel;
        lbl_num[i]->setText(num[i] + '\0');
        grid_layout->addWidget(lbl_num[i], (i + 1), 0, Qt::AlignVCenter);
        lbl_num[i]->setMaximumSize(15, 15);
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Cells[i][j] = new QCell(QPoint (i, j), this);
            grid_layout->addWidget(Cells[i][j], i + 1, j + 1);
        }
    }

    lbl_let[len_let] = new QLabel;
    lbl_num[len_num] = new QLabel;
    lbl_let[len_let]->setMaximumSize(17, 17);
    lbl_num[len_num]->setMaximumSize(15, 15);
    lbl_let[len_let]->setText(let[len_let] + '\0');
    lbl_num[len_num]->setText(num[len_num] + '\0');
    grid_layout->addWidget(lbl_let[len_let], len_let, 0);
    grid_layout->addWidget(lbl_num[len_num], 0, len_num);

    setLayout(grid_layout);
    drawCells();
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
