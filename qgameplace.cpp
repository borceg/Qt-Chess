#include "qgameplace.h"
#include "ui_qgameplace.h"


QGamePlace::QGamePlace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QGamePlace)
{
    ui->setupUi(this);
    _boardPlace = new QBoardPlace(this);
    QGridLayout *centr_layout = new QGridLayout;
    centr_layout->addWidget(_boardPlace/*, 1, 1, 8, 8*/);


    ui->centralWidget->setLayout(centr_layout);

}

QGamePlace::~QGamePlace()
{
    delete ui;
}
