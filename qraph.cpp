#include "qraph.h"
#include "ui_qraph.h"

Qraph::Qraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qraph)
{
    ui->setupUi(this);
    sc = new scene();
    ui->graphicsView->setScene(sc);
}

Qraph::~Qraph()
{
    delete ui;
}
