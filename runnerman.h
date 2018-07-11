#ifndef RUNNERMAN_H
#define RUNNERMAN_H

#include <QThread>
#include <QDebug>
#include <QProcess>
class RunnerMan : public QThread
{
    Q_OBJECT
public:
//    explicit RunnerMan(QObject *parent = 0);
    void run(){
    }
    void setXagt(QThread *);
signals:

public slots:
    void runXagtSlot(QString folderPath);
private:
    QProcess proc;
    QThread * xagt;
};

#endif // RUNNERMAN_H
