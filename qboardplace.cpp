#include "qboardplace.h"

QBoardPlace::QBoardPlace(QWidget *parent) :
    QFrame(parent)
{
    this->setStyleSheet("background-color: rgb(255, 170, 127);");
    this->setMinimumSize(400, 400);
    _board = new QBoard(this);
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setMargin(0);
    hlayout->addWidget(_board);

    setLayout(hlayout);
}

void QBoardPlace::resizeEvent(QResizeEvent *event)
{
    int lesser = std::min(this->width(), this->height());
    resize(lesser, lesser);
    int newX = ( static_cast<QWidget *>(parent())->width() - width() ) / 2;
    move( newX, y() );
}
