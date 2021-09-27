#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,600,650);

    scene->setBackgroundBrush(Qt::black);

    pacman=new pac(300,300,15);

    scene->addItem(pacman);

    lecturaMuros();

    for(int i=20;i<=380;i+=10){
           if(i<185 | i>210){
          coins.append(new moneda(3,-i,-15));
          scene->addItem(coins.back());
           }
          }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QList<moneda*>::iterator ite=coins.begin();
    if(evento->key()==Qt::Key_W){
        pacman->MoveUp();
        if(evaluarColisionMuro()){
            pacman->MoveDown();
        }
        if(evaluarColisionMoneda(ite)){
            scene->removeItem(*ite);
            coins.erase(ite);
            puntos++;
            ui->puntaje->setDecMode();
            ui->puntaje->display(puntos);
        }

    }
    else if(evento->key()==Qt::Key_S){
        pacman->MoveDown();
        if(evaluarColisionMuro()){
            pacman->MoveUp();
        }
        if(evaluarColisionMoneda(ite)){
            scene->removeItem(*ite);
            coins.erase(ite);
            puntos++;
            ui->puntaje->setDecMode();
            ui->puntaje->display(puntos);
        }
    }
    else if(evento->key()==Qt::Key_D){
        pacman->MoveRight();
        if(evaluarColisionMuro()){
            pacman->MoveLeft();
        }
        if(evaluarColisionMoneda(ite)){
            scene->removeItem(*ite);
            coins.erase(ite);
            puntos++;
            ui->puntaje->setDecMode();
            ui->puntaje->display(puntos);
        }
    }
    else if(evento->key()==Qt::Key_A){
        pacman->MoveLeft();
        if(evaluarColisionMuro()){
            pacman->MoveRight();
        }
        if(evaluarColisionMoneda(ite)){
            scene->removeItem(*ite);
            coins.erase(ite);
            puntos++;
            ui->puntaje->setDecMode();
            ui->puntaje->display(puntos);
        }
    }
}

void MainWindow::lecturaMuros()
{
    lector.open("paredes.txt");
    string leido;
    int posicion[4],contador=0;
    if(!lector.fail()){
        while(!lector.eof()){
            lector>>leido;
            posicion[contador]=conversionStr2Int(leido);
            contador++;
            if(contador==4){
                paredes.append(new pared(posicion[0],posicion[1],posicion[2],posicion[3]));
                scene->addItem(paredes.back());
                posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                contador=0;

            }

        }
    }
}

int MainWindow::conversionStr2Int(string numero)
{
    int multi=1,char2int=0;

    if(numero.at(0)=='-'){
        string numero2;
        for(int i=0;i<numero.size()-1;++i)
        {
            multi*=10;
            if(i!=0)numero2+=numero.at(i);
        }
       multi/=10;
       for(int i=0;i<numero2.size();++i){
          char2int+=(numero2.at(i)-48)*multi;
          multi/=10;
          }
       char2int*=-1;
    }
    else{
        for(int i=0;i<numero.size()-1;++i)
        {
            multi*=10;
        }
        for(int i=0;i<numero.size();++i){
        char2int+=(numero.at(i)-48)*multi;
        multi/=10;
        }
    }
    return char2int;
}

bool MainWindow::evaluarColisionMuro()
{
    QList<pared*>::iterator ite;
    bool colision=false;

    for(ite=paredes.begin();ite!=paredes.end();ite++){
        if(pacman->collidesWithItem(*ite)) colision=true;
    }
    return colision;
}

bool MainWindow::evaluarColisionMoneda(QList<moneda*>::iterator &ite)
{

    for(ite=coins.begin();ite!=coins.end();ite++){
        if(pacman->collidesWithItem(*ite)) return true; break;
    }
    return false;
}

