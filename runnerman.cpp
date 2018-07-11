#include "runnerman.h"

void RunnerMan::runXagtSlot(QString folderPath) {
    this->proc.moveToThread(this->xagt);
    QStringList argv;
    argv << "-o" << folderPath + "/collect" << "-f" << folderPath + "/temp.xml";
    if(sizeof(void*) != 8) {
        this->proc.start("./rsc/x64/xagt.exe", argv);
    } else {
        this->proc.start("./rsc/x86/xagt.exe", argv);
    }
    this->proc.waitForFinished(-1);
}
void RunnerMan::setXagt(QThread * t) {
    this->xagt = t;
}
