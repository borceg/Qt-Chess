#include "qgameplace.h"
#include "ui_qgameplace.h"


QGamePlace::QGamePlace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QGamePlace)
{
    ui->setupUi(this);
    _boardPlace = new QBoardPlace(this);
    QGridLayout *centr_layout = new QGridLayout;
    centr_layout->addWidget(_boardPlace);
    ui->centralWidget->setLayout(centr_layout);
//    QPiece(_board, _board->Cells[1][1]->getPositionCell(), QPiece::King );

}

QGamePlace::~QGamePlace()
{
    delete ui;
}
