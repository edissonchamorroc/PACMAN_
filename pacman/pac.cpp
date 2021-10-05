#include "pac.h"


void pac::setPosy(int value)
{
    posy = value;
}

void pac::setPosx(int value)
{
    posx = value;
}

pac::pac(int x)
{
    
}

pac::pac(int x, int y)
{
    timer =new QTimer();
    
    posx=x;
    
    posy=y;

    r=15;

    setPos(posx,posy);

    filas=0;

    columnas=0;

    pixmap=new QPixmap(":/imagenes/pacman.png");

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&pac::actualizacion);

}



QRectF pac::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void pac::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(-r,-r,*pixmap,columnas,filas,2*r,2*r);

}


void pac::MoveRight()
{
    this->posx+=velocidad;
    filas=0;
    setPos(posx,posy);
}

void pac::MoveLeft()
{
    this->posx-=velocidad;
    filas=31;
    setPos(posx,posy);
}

void pac::MoveUp()
{
    this->posy-=velocidad;
    filas=61;
    setPos(posx,posy);
}

void pac::MoveDown()
{
    this->posy+=velocidad;
    filas=91;
    setPos(posx,posy);
}

void pac::actualizacion()
{
    columnas+=32;
    if(columnas>=150){
        columnas=0;
    }

    this->update(-r,-r,2*r,2*r);
}

