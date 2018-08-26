#include "qraph.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qraph w;
    w.show();

    return a.exec();
}
