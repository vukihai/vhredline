#ifndef RUNNINGTHREAD_H
#define RUNNINGTHREAD_H

#include <QRunnable>
#include <QStringList>
#include <QString>
#include <QProcess>
class RunningThread : public QRunnable
{
public:
    RunningThread():QRunnable(){}
    void setFolderPath(QString);
    void run();
    void setThread(QThread  * t);
private:
    QProcess proc;
    QString folderPath;
    QThread *xagt;
};

#endif // RUNNINGTHREAD_H
