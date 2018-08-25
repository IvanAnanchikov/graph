#ifndef QRAPH_H
#define QRAPH_H

#include <QMainWindow>

namespace Ui {
class Qraph;
}

class Qraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Qraph(QWidget *parent = 0);
    ~Qraph();

private:
    Ui::Qraph *ui;
};

#endif // QRAPH_H
