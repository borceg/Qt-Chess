#ifndef QCELL_H
#define QCELL_H

//#include <QWidget>
#include <QLabel>

class QCell : public QLabel
{
    Q_OBJECT
public:
    explicit QCell(QPoint position, QWidget *parent = 0);

private:
    QPoint _position;
};

#endif // QCELL_H
