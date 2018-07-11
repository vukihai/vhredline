#include <QtGui/QApplication>
#include "blackline.h"
#include "runnerman.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlackLine w;
    w.show();
    RunnerMan * r = new RunnerMan();
    QThread * xagt = new QThread();
    r->setXagt(xagt);
    r->start();


    //QObject::connect(&w,SIGNAL(runXagtSign(QString)),r,SLOT(runXagtSlot(QString)));
    return a.exec();
}
