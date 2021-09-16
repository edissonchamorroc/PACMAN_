#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QList>
#include<cuerpo.h>



#include<QPainter>
#include<QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    cuerpo *bolita;
    //QList<pared*> paredes;
    //QList<pared*> paredes;

    QGraphicsScene *scene;
    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision();
    bool EvaluarVolisionMoneda();
    int EvaluarPosicion();
    int puntos=0;
};
#endif // MAINWINDOW_H
