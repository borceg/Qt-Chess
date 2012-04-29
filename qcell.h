#ifndef QCELL_H
#define QCELL_H

#include <QLabel>

class QCell : public QLabel
{
    Q_OBJECT
public:
    QCell(QPoint position, QWidget *parent = 0);
    QPoint getPosC();

private:
    QPoint _position;

protected:

};

#endif // QCELL_H
