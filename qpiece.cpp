#include "qpiece.h"

QPiece::QPiece(QWidget *board, QPoint position, Type type ) : QSvgWidget(board)
{
    _game = QGame::instance();
    _board = static_cast<QBoard *> (board);
    _1stStep = true;
    _color = position.x() > 4;  //Color changed
    setType(type);
    setPosition(position);
}

void QPiece::setPosition(QPoint val)
{
    _position = val;

    QWidget *parentWidget = _board->Cells[ val.x() ][ val.y() ];


    //Check layout
    if ( !parentWidget->layout() )
    {
        QHBoxLayout *layout = new QHBoxLayout(parentWidget);
        layout->setMargin(0);
    }

    parentWidget->layout()->addWidget(this);

    //Set cell parent for board
    this->setParent( _board->Cells[ val.x() ][ val.y() ]);
}

void QPiece::setColor(bool val)     { _color = val; }
void QPiece::setState(State val)    { _state = val; }
void QPiece::setType(Type val)
{
    QString img;
    if ( _color ) //White pieces
    {
        if ( val == QPiece::Rook )      img = ":/images/white/rook.svg";
        if ( val == QPiece::Knight )    img = ":/images/white/knight.svg";
        if ( val == QPiece::Bishop )    img = ":/images/white/bishop.svg";
        if ( val == QPiece::King )      img = ":/images/white/king.svg";
        if ( val == QPiece::Queen )     img = ":/images/white/queen.svg";
        if ( val == QPiece::Pawn )      img = ":/images/white/pawn.svg";
    }
    if ( !_color ) //Black pieces
    {
        if ( val == QPiece::Rook )      img = ":/images/black/rook.svg";
        if ( val == QPiece::Knight )    img = ":/images/black/knight.svg";
        if ( val == QPiece::Bishop )    img = ":/images/black/bishop.svg";
        if ( val == QPiece::King )      img = ":/images/black/king.svg";
        if ( val == QPiece::Queen )     img = ":/images/black/queen.svg";
        if ( val == QPiece::Pawn )      img = ":/images/black/pawn.svg";
    }
    this->load(img);
    _type = val;
}

QPoint          QPiece::position()  { return _position;}
bool            QPiece::color()     { return _color;}
QPiece::State   QPiece::state()     { return _state;}
QPiece::Type    QPiece::type()      { return _type;}

void QPiece::movePiece(QPoint newPos)
{
    setPosition(newPos);
}

void QPiece::mousePressEvent(QMouseEvent *event)
{
    qDebug() << _position.x() << _position.y();
    if ( _game->activeMove() && _game->turn != _color)
    {
        //Срубить фигуру
        _game->doMove( _position );
    }
    else //Выбрать фигуру
        if ( _game->turn == _color )
        {
            if ( _game->selectPiece() ) _game->setActiveMove(false);
            _game->setSelectPiece(this);
            _game->setActiveMove(true);
            _game->genMoves();
            /*if ( !_game->selectPiece() )*/ _game->_map[_game->selectPiece()->position().x()*8 + _game->selectPiece()->position().y()] = 0;

        }
}
