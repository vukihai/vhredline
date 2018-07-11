#include "runningthread.h"
void RunningThread::setFolderPath(QString folderPath){
    this->folderPath = folderPath;
    this->run();
}
void RunningThread::run(){
    this->proc.moveToThread(this->xagt);
    QStringList argv;
    argv << "-o" << this->folderPath + "/collect" << "-f" << this->folderPath + "/temp.xml";
    if(sizeof(void*) != 8) {
        this->proc.start("./rsc/x64/xagt.exe", argv);
    } else {
        this->proc.start("./rsc/x86/xagt.exe", argv);
    }
    this->proc.waitForFinished(-1);
}
void RunningThread::setThread(QThread * t) {
    this->xagt = t;
}
