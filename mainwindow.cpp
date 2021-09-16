#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    setWindowTitle("*****PACMAN*****");
    //ui->resultado.settex("0");
    scene->setSceneRect(0,0,400,400);
    scene->setBackgroundBrush(Qt::black);
    bolita=new cuerpo();
    scene->addItem(bolita);
    bolita->setPos(180,180);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QList<moneda*>::iterator itm;
}

bool MainWindow::EvaluarColision()
{

}

int MainWindow::EvaluarPosicion()
{

}

void

