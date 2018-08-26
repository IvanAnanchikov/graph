#ifndef QRAPH_H
#define QRAPH_H

#include <QMainWindow>
#include "scene.hpp"
#include <QTimer>
#include <QResizeEvent>

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
    scene *sc;
    void resizeEvent(QResizeEvent * event);
    QTimer *timer;

private slots:
    void slotTimer();
    void on_Rotate_clockwise_clicked();
    void on_Rotate_counterclockrwise_clicked();
};

#endif // QRAPH_H
