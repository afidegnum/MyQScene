#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
//    scene->setSceneRect(0,0,200,200);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    createActions();
    createConnections();

}

void MainWindow::createActions(){
    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(true);
    actionGroup->addAction(ui->actionDrawLine);
    actionGroup->addAction(ui->actionDrawRect);
    actionGroup->addAction(ui->actionSelect);
}

void MainWindow::createConnections(){
    connect(actionGroup, SIGNAL(triggered(QAction*)),
            this, SLOT(actionGroupClicked(QAction*)));
}

void MainWindow::actionGroupClicked(QAction *action){
    scene->setMode(Scene::Mode(action->data().toInt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

