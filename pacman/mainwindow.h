#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<pac.h>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QList>
#include<pared.h>
#include<moneda.h>
#include<fstream>
#include<string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ifstream lector;

public slots:

private:
    QGraphicsScene *scene;

    pac *pacman;

    QList<pared*> paredes;

    QList<moneda*> coins;

    Ui::MainWindow *ui;

    void keyPressEvent(QKeyEvent *evento);

    void lecturaMuros();

    void lecturaMonedas();

    int conversionStr2Int(string numero);

    bool evaluarColisionMuro();

    bool evaluarColisionMoneda(QList<moneda*>::iterator &ite);

    int evaluarPosicion();

    int puntos=0;


};
#endif // MAINWINDOW_H
