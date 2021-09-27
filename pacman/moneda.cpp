#include "moneda.h"


int moneda::getPosy() const
{
    return posy;
}

moneda::moneda( int ra,int px, int py)
{
    posx=px,posy=py;r=ra;

}

QRectF moneda::boundingRect() const
{
    return QRectF(-posx,-posy,2*r,2*r);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

int moneda::getPosx() const
{
    return posx;
}
