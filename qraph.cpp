#include "qraph.hpp"
#include "ui_qraph.h"
#include "scene.hpp"

Qraph::Qraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qraph)
{
    ui->setupUi(this);
    sc = new scene();
    ui->graphicsView->setScene(sc);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Qraph::slotTimer);
    timer->start(100);
    sc->Cursor = false;
    //QBrush redBrush(Qt::red);

}

Qraph::~Qraph()
{
    delete ui;
}

void Qraph::slotTimer()
{
 //переопределить размеры графической сцены в зависимости
 //от размеров окна
    timer->stop();
    sc->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Qraph::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Qraph::on_Rotate_clockwise_clicked()
{
    ui->graphicsView->rotate(90);
}

void Qraph::on_Rotate_counterclockrwise_clicked()
{
    ui->graphicsView->rotate(-90);
}

void Qraph::on_Rectangle_clicked()
{
    //sc->Cursor = false;
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(5);
    rectangle = sc->addRect(50,50,100,100,blackPen,blueBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

void Qraph::on_Ellipse_clicked()
{
    QBrush greenBrush(Qt::green);
    QPen grayPen(Qt::gray);
    grayPen.setWidth(5);
    ellipse = sc->addEllipse(200,200,50,50,grayPen,greenBrush);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}

void Qraph::on_actionSave_As_triggered()
{
    QImage image(sc->width(), sc->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    sc->render(&painter);
    image.save("result.png");
}
