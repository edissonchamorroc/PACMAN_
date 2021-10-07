#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    setWindowTitle("PACMAN");

    scene->setSceneRect(0,0,600,650);

    scene->setBackgroundBrush(Qt::black);

    pacman=new pac(300,310);

    scene->addItem(pacman);

    ghosts.append(new fantasma(580,310,1));
    ghosts.append(new fantasma(20,20,2));
    ghosts.append(new fantasma(20,580,3));

    for(int i=0;i<3;i++){
        scene->addItem(ghosts.at(i));
    }


    lecturaPosicionMuros();

    lecturaPosicionMonedas();

    timer = new QTimer();

    connect(timer,&QTimer::timeout,this,&MainWindow::fantasmasMovimiento);

    timer->start(25);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QList<moneda*>::iterator ite=coins.begin();
    QList<pared*>::iterator it=paredes.begin();
    if(evento->key()==Qt::Key_W){
        pacman->MoveUp();
        if(evaluarPacmanColisionMuro(it)){
            pacman->MoveDown();
            evaluarPacmanEnMapa(it);
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
        if(evaluarPacmanColisionMuro(it)){
            pacman->MoveUp();
            evaluarPacmanEnMapa(it);
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
        if(evaluarPacmanColisionMuro(it)){
            pacman->MoveLeft();
            evaluarPacmanEnMapa(it);
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
        if(evaluarPacmanColisionMuro(it)){
            pacman->MoveRight();
            evaluarPacmanEnMapa(it);
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

void MainWindow::fantasmasMovimiento()
{
    QList<pared*>::iterator it=paredes.begin();

    for(int i=0;i<ghosts.size();i++){

        if(ghosts.at(i)->getPosicionX() < pacman->getPosx()){
            ghosts.at(i)->moveRight();
            if(evaluarFantasmaColisionMuro(it)){
                ghosts.at(i)->moveLeft();

            }

            if(ghosts.at(i)->collidesWithItem(pacman)){
              scene->removeItem(pacman);
              MainWindow::close();
          }
       }

        if(ghosts.at(i)->getPosicionX() > pacman->getPosx()){
            ghosts.at(i)->moveLeft();
            if(evaluarFantasmaColisionMuro(it)){
                ghosts.at(i)->moveRight();

            }

            if(ghosts.at(i)->collidesWithItem(pacman)){
               scene->removeItem(pacman);
               MainWindow::close();
            }

        }

        if(ghosts.at(i)->getPosicionY() > pacman->getPosy()){
            ghosts.at(i)->moveUp();
            if(evaluarFantasmaColisionMuro(it)){

                ghosts.at(i)->moveDown();

            }
            if(ghosts.at(i)->collidesWithItem(pacman)){
               scene->removeItem(pacman);
               MainWindow::close();
            }

        }

        if(ghosts.at(i)->getPosicionY() < pacman->getPosy()){
            ghosts.at(i)->moveDown();
            if(evaluarFantasmaColisionMuro(it)){
                ghosts.at(i)->moveUp();
            }
            if(ghosts.at(i)->collidesWithItem(pacman)){
               scene->removeItem(pacman);
               MainWindow::close();
            }

        }
    }


}


void MainWindow::lecturaPosicionMuros()
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
    lector.close();
}

void MainWindow::lecturaPosicionMonedas()
{
    lector.open("monedas.txt");
    string leido;
    int posicion[3],contador=0;
    if(!lector.fail()){
        while(!lector.eof()){
            lector>>leido;
            posicion[contador]=conversionStr2Int(leido);
            contador++;
            if(contador==3){
                coins.append(new moneda(posicion[0],posicion[1],posicion[2]));
                scene->addItem(coins.back());
                posicion[0]=0;posicion[1]=0;posicion[2]=0;
                contador=0;
            }

        }
    }
    lector.close();
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

bool MainWindow::evaluarFantasmaColisionMuro(QList<pared*>::iterator &ite)
{
    bool colision=false;

    for(ite=paredes.begin();ite!=paredes.end();ite++){
        for(int i=0;i<ghosts.size();i++){
            if(ghosts.at(i)->collidesWithItem(*ite)){
                 colision=true;
                break;
            }
        }
    }
    return colision;
}

bool MainWindow::evaluarFantasmaColisionFantasma()
{

}

bool MainWindow::evaluarPacmanColisionMuro(QList<pared*>::iterator &ite)
{

    bool colision=false;

    for(ite=paredes.begin();ite!=paredes.end();ite++){
        if(pacman->collidesWithItem(*ite)){
             colision=true;
            break;
        }
    }
    return colision;
}

bool MainWindow::evaluarColisionMoneda(QList<moneda*>::iterator &ite)
{

    for(ite=coins.begin();ite!=coins.end();ite++){
        if(pacman->collidesWithItem(*ite))
        {return true; break;}
    }
    return false;
}

void MainWindow::evaluarPacmanEnMapa(QList<pared *>::iterator &it)
{
    QList<pared*>::iterator it2=paredes.end();
    if(it==(it2-2)){
       pacman->setPosx(570);
       pacman->setPosy(310);

    }
    else if(it==(it2-1)){
        pacman->setPosx(10);
        pacman->setPosy(310);

    }

}


