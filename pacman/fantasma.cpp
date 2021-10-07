#include "fantasma.h"

int fantasma::getPosicionX() const
{
    return posicionX;
}

int fantasma::getPosicionY() const
{
    return posicionY;
}

fantasma::fantasma()
{

}

fantasma::fantasma(int posx, int posy,int color)
{
    posicionX=posx;

    posicionY=posy;

    setPos(posicionX,posicionY);

    switch (color) {
    case 1:{
        imagen=new QImage(":/imagenes/fantasmaAmarillos.png");
        break;
    }
    case 2:{
        imagen=new QImage(":/imagenes/fantasmaAzul.png");
        break;
    }
    case 3:{
        imagen=new QImage(":/imagenes/fantasmaRojo.png");
        break;
    }

    }





}

QRectF fantasma::boundingRect() const
{
    return QRectF(-forma/2,-forma/2,forma,forma);
}

void fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(),*imagen);

}

void fantasma::moveUp()
{
    posicionY-=velocidad;
    setPos(posicionX,posicionY);

}

void fantasma::moveDown()
{
    posicionY+=velocidad;
    setPos(posicionX,posicionY);

}

void fantasma::moveRight()
{
    posicionX+=velocidad;
    setPos(posicionX,posicionY);

}

void fantasma::moveLeft()
{
    posicionX-=velocidad;
    setPos(posicionX,posicionY);

}
