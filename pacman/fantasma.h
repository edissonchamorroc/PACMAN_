#ifndef FANTASMA_H
#define FANTASMA_H

#include<QGraphicsItem>
#include<QPainter>
#include<QObject>

class fantasma: public QObject, public QGraphicsItem
{
    int posicionX,posicionY,velocidad=1,forma=30;

public:
    fantasma();
    fantasma(int posx,int posy,int color);

    QImage *imagen;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    int getPosicionX() const;
    int getPosicionY() const;

};

#endif // FANTASMA_H
