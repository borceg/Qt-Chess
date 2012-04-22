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
    explicit QGamePlace(QWidget *parent = 0);
    ~QGamePlace();

private:
    Ui::QGamePlace *ui;
    QBoardPlace *_boardPlace;

};

#endif // QGAMEPLACE_H
