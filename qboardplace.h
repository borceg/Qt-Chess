#ifndef QBOARDPLACE_H
#define QBOARDPLACE_H

#include <QFrame>
#include "qboard.h"

class QBoard;

class QBoardPlace : public QFrame
{
    Q_OBJECT
public:
    explicit QBoardPlace(QWidget *parent = 0);

private:
       QBoard *_board;

};

#endif // QBOARDPLACE_H
