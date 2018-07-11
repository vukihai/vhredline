#ifndef BLACKLINE_H
#define BLACKLINE_H

#include <QMainWindow>
#include "scriptcreator.h"
#include "runningthread.h"
namespace Ui {
    class BlackLine;
}

class BlackLine : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlackLine(QWidget *parent = 0);
    ~BlackLine();
    QString choseFolder();

private slots:
    void changeText(Ui::BlackLine*);
    QString print_data_checkbox(QWidget*);
    void on_handModeBtn_clicked();

    void on_autoModeBtn_clicked();

    void on_close_automode_menu_btn_clicked();

    void on_close_handmode_menu_btn_clicked();

    void on_memory_ProcessListing_group_toggled(bool arg1);

    void on_system_SystemInfomation_group_toggled(bool arg1);

    void on_next_btn_handmode_clicked();

    void on_back_btn_handmode_clicked();

    void on_back_btn_automode_clicked();

    void on_start_btn_automode_clicked();

    void on_next_btn_automode_clicked();

    void on_start_btn_handmode_clicked();

    void on_memory_HookDetection_toggled(bool arg1);

    void on_memory_DriversEnumeration_group_toggled(bool arg1);

    void on_network_BrowserHistory_group_toggled(bool arg1);

    void on_finish_btn_clicked();

    void on_cancel_btn_clicked();

    void on_disk_FileEnumeration_group_toggled(bool arg1);

    void on_disk_DiskEnumeration_group_toggled(bool arg1);

    void on_other_Tasks_group_toggled(bool arg1);

    void on_other_Services_group_toggled(bool arg1);

    void on_other_CommonPersistenceMechanisms_group_toggled(bool arg1);

    void on_pushButton_clicked();

private:
    Ui::BlackLine *ui;
    QString folderPath;
    QThread * xagt;
    QRunnable * runner;
    ScriptCreator scr;
signals:
    void runXagtSign(QString);
};

#endif // BLACKLINE_H
