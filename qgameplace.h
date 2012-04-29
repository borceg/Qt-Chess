#ifndef QGAMEPLACE_H
#define QGAMEPLACE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "qboardplace.h"


class QBoardPlace;

namespace Ui {
    class QGamePlace;
}

class QGamePlace : public QMainWindow
{
    Q_OBJECT

public:
    QBoardPlace *_boardPlace;
    QGamePlace(QWidget *parent = 0);
    ~QGamePlace();

private:
    Ui::QGamePlace *ui;

};

#endif // QGAMEPLACE_H
