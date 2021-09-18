#include "pac.h"

pac::pac()
{

}

pac::pac(int x, int y, int r)
{
    posx=x;

    posy=y;

    this->r=r;

    setPos(posx,posy);

}

QRectF pac::boundingRect() const
{
    return QRectF(10,10,2*r,2*r);
}

void pac::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}

void pac::MoveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void pac::MoveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void pac::MoveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);
}

void pac::MoveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}

