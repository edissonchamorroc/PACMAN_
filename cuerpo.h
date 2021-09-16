#ifndef CUERPO_H
#define CUERPO_H

#include<QObject>
#include<QGraphicsItem>
#include<QTimer>
#include<QPixmap>
#include<QPainter>

class cuerpo:public QGraphicsItem,public QObject
{
    int r,posx,posy,velocidad=3;
public:
    cuerpo();

    cuerpo(int ra,int px,int py);
    explicit cuerpo(QObject *parent =nullptr);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);

    QTimer *timer;

    QPixmap *pixmap;

    float filas, columnas, ancho, alto;

    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();

    int getPosx() const;
    int getPosy() const;

    void setPosx(int value);
    void setPosy(int value);

signals:

public slots:
    void actualizacion();


};

#endif // CUERPO_H
