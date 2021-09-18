#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,700,500);
    pacman=new pac(0,0,20);
    scene->addItem(pacman);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        pacman->MoveUp();
    }
    else if(evento->key()==Qt::Key_S){
        pacman->MoveDown();
    }
    else if(evento->key()==Qt::Key_D){
        pacman->MoveRight();
    }
    else if(evento->key()==Qt::Key_A){
        pacman->MoveLeft();
    }
}

