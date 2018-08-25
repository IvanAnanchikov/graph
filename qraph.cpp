#include "qraph.h"
#include "ui_qraph.h"

Qraph::Qraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qraph)
{
    ui->setupUi(this);
}

Qraph::~Qraph()
{
    delete ui;
}
