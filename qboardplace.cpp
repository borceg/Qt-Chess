#include "qboardplace.h"

QBoardPlace::QBoardPlace(QWidget *parent) :
    QFrame(parent)
{
    this->setStyleSheet("background-color: rgb(255, 170, 127);");
    this->setMinimumSize(400, 400);
}
