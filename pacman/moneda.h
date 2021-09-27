#ifndef MONEDA_H
#define MONEDA_H
#include<QGraphicsItem>
#include<QPainter>

class moneda:public QGraphicsItem
{
    int r,posx,posy;
public:
    moneda(int ra,int px,int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    int getPosx() const;
    int getPosy() const;
};

#endif // MONEDA_H
