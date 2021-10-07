#ifndef PAC_H
#define PAC_H
#include<QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QObject>
#include<iostream>

using namespace std;

class pac:public QGraphicsItem, public QObject
{
    int posx;
    int posy;
    int r;
    int velocidad=4;

public:
    pac(int x);
    pac(int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    int filas=0, columnas=0;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();



    void setPosy(int value);

    void setPosx(int value);

    int getPosx() const;

    int getPosy() const;

signals:
public slots:
    void actualizacion();

};

#endif // PAC_H
