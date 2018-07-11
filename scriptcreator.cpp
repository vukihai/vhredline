#include "scriptcreator.h"
#include <iostream>
void ScriptCreator::autoCollect() {
    this->copyScript("auto.xml");
    return ;
}
void ScriptCreator::ramBackup() {
    this->copyScript("ramBackup.xml");
    return;
}

void ScriptCreator::collectMemory(QString con){

    this->copyScript("memory.xml");
    QDomDocument doc("temp");
    QFile file(this->folderPath + "/temp.xml");
    file.open(QIODevice::ReadWrite);
    doc.setContent(&file);


    QDomDocument config(con);



    file.close();
    return;
}

void ScriptCreator::copyScript(QString source) {
    QString des = this->folderPath + "/temp.xml";
    QString src = "./rsc/" + source;
    if (QFile::exists(des))
    {
        QFile::remove(des);
    }

    QFile::copy(src, des);
}

void ScriptCreator::setFolderPath(QString fld) {
    this->folderPath = fld;
}
void ScriptCreator:: deleteParam(QDomDocument * doc, QString name, int index) {
    QDomNodeList listbyTag = doc->elementsByTagName("param");
    if(index<=listbyTag.count()) {
        QDomNode nodeByTag = listbyTag.at(index);
        QDomNode valueOfNode = nodeByTag.firstChild();
        valueOfNode.clear();
        QDomText text;
        text.setData("false");
        valueOfNode.appendChild(text);
    }
}
void ScriptCreator:: deleteCommand(QDomDocument *doc, int index){
    QDomNodeList list = doc->elementsByTagName("commands");
    int i=0;
    while(i<=index && i<=list.count()) {
        QDomNode node = list.at(i);
        if(i==index) {
            node.clear();
            break;
        } else {
            i++;
        }
    }
}
