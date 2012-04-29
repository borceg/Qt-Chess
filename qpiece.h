#ifndef QPIECE_H
#define QPIECE_H

#ifdef Q_WS_WIN
#include <QtSvg\QSvgWidget>
#else
#include <QtSvg/QSvgWidget>
#endif

#include <QHBoxLayout>
#include "qboard.h"

class QBoard;

class QPiece : public QSvgWidget
{
private:
    enum State{Normal, Deleted};

public:
    enum Type{
        Rook,       //Ладья
        Knight,     //Конь
        Bishop,     //Слон
        Queen,      //Королева
        King,       //Король
        Pawn        //Пешка
    };
    QPiece(QWidget *board, QPoint position, Type type);

    void setPosition(QPoint val);
    void setState(State val);

    QPoint  position();
    bool    color();        //True - white, False - black piece
    State   state();        //Deleted or not
    Type    type();         //Pawn, King end etc.

private:
    void setType(Type val);
    void setColor(bool val);
    Type    _type;
    QPoint  _position;
    State   _state;
    bool    _color;
    QBoard *_board;
    QSvgWidget *_svgPiece;

};

#endif // QPIECE_H
