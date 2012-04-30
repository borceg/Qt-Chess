#include "qpiece.h"

QPiece::QPiece(QWidget *board, QPoint position, Type type ) : QSvgWidget(board)
{

    _board = static_cast<QBoard *> (board);

    _color = position.x() > 4;  //Color changed
    setType(type);
    setPosition(position);
    //_game = QGame::instance(w->_boardPlace);
}

void QPiece::setPosition(QPoint val)
{
    _position = val;

    QWidget *parentWidget = _board->Cells[ val.x() ][ val.y() ];

    //Check layout
    if (parentWidget->layout())
    {
        parentWidget->layout()->addWidget(_svgPiece);
    }
    else
    {
        QHBoxLayout *layout = new QHBoxLayout(parentWidget);
        layout->setMargin(0);
        layout->addWidget(_svgPiece);
    }

    //Set cell parent for board
    this->setParent( _board->Cells[ val.x() ][ val.y() ]);
    this->setStyleSheet("background-color: rgb(255, 0, 0);");

}

void QPiece::setColor(bool val)     { _color = val; }
void QPiece::setState(State val)    { _state = val; }
void QPiece::setType(Type val)
{
    if ( _color ) //White pieces
    {
        if ( val == 0 ) _svgPiece = new QSvgWidget(":/images/white/rook.svg");
        if ( val == 1 ) _svgPiece = new QSvgWidget(":/images/white/knight.svg");
        if ( val == 2 ) _svgPiece = new QSvgWidget(":/images/white/bishop.svg");
        if ( val == 3 ) _svgPiece = new QSvgWidget(":/images/white/king.svg");
        if ( val == 4 ) _svgPiece = new QSvgWidget(":/images/white/queen.svg");
        if ( val == 5 ) _svgPiece = new QSvgWidget(":/images/white/pawn.svg");
    }
    if (!_color) //Black pieces
    {
        if ( val == 0 ) _svgPiece = new QSvgWidget(":/images/black/rook.svg");
        if ( val == 1 ) _svgPiece = new QSvgWidget(":/images/black/knight.svg");
        if ( val == 2 ) _svgPiece = new QSvgWidget(":/images/black/bishop.svg");
        if ( val == 3 ) _svgPiece = new QSvgWidget(":/images/black/king.svg");
        if ( val == 4 ) _svgPiece = new QSvgWidget(":/images/black/queen.svg");
        if ( val == 5 ) _svgPiece = new QSvgWidget(":/images/black/pawn.svg");
    }

}

QPoint          QPiece::position()  { return _position;}
bool            QPiece::color()     { return _color;}
QPiece::State   QPiece::state()     { return _state;}
QPiece::Type    QPiece::type()      { return _type;}

