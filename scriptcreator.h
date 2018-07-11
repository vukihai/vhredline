#ifndef SCRIPTCREATOR_H
#define SCRIPTCREATOR_H

#include<QtXml>
#include<QString>
#include<QFile>
#include<QProcess>
#include<QtXml>
class ScriptCreator
{
public:
    void autoCollect();
    void ramBackup();
    void collectMemory(QString conf);
    void collectProcessListing();
    void collectBrowser();
    void collectFileEnum();
    void setFolderPath(QString fld);
    bool isFinish();
    void stop();
private:
    QDomDocument doc;
    QString folderPath;
    void copyScript(QString source);
    QProcess proc;
    void deleteParam(QDomDocument * doc, QString name, int index);
    void deleteCommand(QDomDocument * doc, int index);
};
#endif // SCRIPTCREATOR_H
