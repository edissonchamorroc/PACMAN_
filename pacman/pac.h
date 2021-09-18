#ifndef PAC_H
#define PAC_H
#include<QGraphicsItem>
#include<QPainter>

class pac:public QGraphicsItem
{
    int posx;
    int posy;
    int r;
    int velocidad=4;

public:
    pac();
    pac(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

};

#endif // PAC_H
