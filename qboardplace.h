#ifndef QBOARDPLACE_H
#define QBOARDPLACE_H

#include <QFrame>
#include "qboard.h"

class QBoard;

class QBoardPlace : public QFrame
{
    Q_OBJECT

public:
    QBoardPlace(QWidget *parent = 0);
    QBoard *_board;

private:
       virtual void resizeEvent(QResizeEvent*);

};

#endif // QBOARDPLACE_H
