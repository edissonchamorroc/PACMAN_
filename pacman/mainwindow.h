#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<pac.h>
#include<QGraphicsScene>
#include<QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

private:
    QGraphicsScene *scene;
    pac *pacman;
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
