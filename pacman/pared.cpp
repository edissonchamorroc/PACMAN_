#include "pared.h"

int pared::getPosx() const
{
    return posx;
}

int pared::getPosy() const
{
    return posy;
}

pared::pared()
{

}

pared::pared(int w, int h, int px, int py)
{
    ancho=w;
    alto=h;
    posx=px;
    posy=py;
}

QRectF pared::boundingRect() const
{
    return QRectF(-posx,-posy,ancho,alto);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}


