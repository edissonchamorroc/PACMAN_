#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<pac.h>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QList>
#include<pared.h>
#include<moneda.h>
#include<fantasma.h>
#include<fstream>
#include<string>
#include<QTimer>



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

    QList<fantasma*> ghosts;

    QList<pared*> paredes;

    QList<moneda*> coins;

    Ui::MainWindow *ui;

    void keyPressEvent(QKeyEvent *evento);

    void lecturaPosicionMuros();

    void lecturaPosicionMonedas();

    int conversionStr2Int(string numero);

    bool evaluarPacmanColisionMuro(QList<pared*>::iterator &ite);

    bool evaluarFantasmaColisionMuro(QList<pared*>::iterator &ite);

    bool evaluarFantasmaColisionFantasma();

    bool evaluarColisionMoneda(QList<moneda*>::iterator &ite);

    void evaluarPacmanEnMapa(QList<pared*>::iterator &it);

    int puntos=0;

    QTimer *timer;

signals:
public slots:
    void fantasmasMovimiento();


};
#endif // MAINWINDOW_H
