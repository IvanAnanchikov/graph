#include "qraph.h"
#include "ui_qraph.h"

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
