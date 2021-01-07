#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "diagramitems.h"
#include "scene.h"
#include <QAction>




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
    void actionGroupClicked(QAction*);

private:

    void createActions();
    void createConnections();


    Ui::MainWindow *ui;
    Scene *scene;
    QGraphicsRectItem *rect;
    QActionGroup *actionGroup;
//    QGraphicsEllipseItem *ellipse;
//    QGraphicsTextItem *text;
};
#endif // MAINWINDOW_H
