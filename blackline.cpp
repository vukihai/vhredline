#include "blackline.h"
#include "ui_blackline.h"
#include <string>
#include <QFileDialog>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

//Mo ra cua so che do tu dong
void show_AutoMode_Menu( Ui::BlackLine* ui){
    ui->label_folder_path->setVisible(true);
    ui->next_btn_automode->setVisible(true);
    ui->ram_checkbox_automode->setDisabled(false);
    ui->back_btn_automode->setVisible(false);
    ui->start_btn_automode->setVisible(false);
    ui->stackedWidget->setVisible(true);
    ui->autoModeBtn->setStyleSheet("background-color:red;color:white");
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_folder_path->setText("Bam nut 'Tiep theo' de chon thu muc luu ket qua thu thap duoc");
}
//Dong cua so che do tu dong
void hide_AutoMode_Menu( Ui::BlackLine* ui){
    ui->autoModeBtn->setStyleSheet("");
    ui->label_folder_path->setVisible(false);
    ui->stackedWidget->setVisible(false);
}
//Mo ra cua so che do co ban cua UET
void show_Standard_Menu(Ui::BlackLine *ui){
    ui->label_folder_path->setVisible(true);
    ui->next_btn_handmode_2->setVisible(true);
    ui->tab_hand_mode_widget_2->setDisabled(false);
    ui->back_btn_handmode_2->setVisible(false);
    ui->start_btn_handmode_2->setVisible(false);
    ui->stackedWidget->setVisible(true);
    ui->standardModeBtn->setStyleSheet("background-color:red;color:white");
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_folder_path->setText("Bam nut 'Tiep theo' de chon thu muc luu ket qua thu thap duoc");
}

//Dong cua so che do co ban cua UET
void hide_Standard_Menu(Ui::BlackLine *ui){
    ui->standardModeBtn->setStyleSheet("");
    ui->label_folder_path->setVisible(false);
    ui->stackedWidget->setVisible(false);
}

//Mo ra cua so che do thu cong
void show_HandMode_Menu( Ui::BlackLine* ui){
    ui->label_folder_path->setVisible(true);
    ui->next_btn_handmode->setVisible(true);
    ui->tab_hand_mode_widget->setDisabled(false);
    ui->back_btn_handmode->setVisible(false);
    ui->start_btn_handmode->setVisible(false);
    ui->stackedWidget->setVisible(true);
    ui->handModeBtn->setStyleSheet("background-color:red;color:white");
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_folder_path->setText("Bam nut 'Tiep theo' de chon thu muc luu ket qua thu thap duoc");
}
//Dong che do thu cong
void hide_HandMode_Menu( Ui::BlackLine* ui){
    ui->handModeBtn->setStyleSheet("");
    ui->label_folder_path->setVisible(false);
    ui->stackedWidget->setVisible(false);
}
//Check or uncheck tat ca cac checkbox trong group
void revert_checkBox(QGroupBox* group, bool check){
    QList<QCheckBox *> list = group -> findChildren<QCheckBox *>();
    foreach(QCheckBox *w, list) {
        w->setChecked(check);
    }
}
//Mo ra cua so hien thi trang thai hoat dong
void open_text_output(Ui::BlackLine *ui){
    ui->frame_output_text->setVisible(true);
    hide_AutoMode_Menu(ui);
    hide_HandMode_Menu(ui);
    ui->label_outpu_info->setText("Ðang x? lý");
    ui->progressBar->setValue(0);
    ui->finish_btn->setDisabled(true);
    ui->autoModeBtn->setDisabled(true);
    ui->handModeBtn->setDisabled(true);
}
//Dong cua so hien thi trang thai hoat dong
void hide_text_output(Ui::BlackLine *ui){
    ui->frame_output_text->setVisible(false);
    ui->autoModeBtn->setDisabled(false);
    ui->handModeBtn->setDisabled(false);
}

//Mo ra cua so chon folder
QString BlackLine::choseFolder(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Chon thu muc luu ket qua"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    return dir;
}
//constructor
BlackLine::BlackLine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BlackLine)
{
    ui->setupUi(this);
    hide_AutoMode_Menu(this->ui);
    hide_text_output(this->ui);
    ui->centralWidget->setStyleSheet("\
                                     QCheckBox:checked{\
                                         color: green;\
                                     }\
                                     QGroupBoxQCheckBox:checked{  \
                                         color:green; \
                                     }  \
                                     "
);
    this->xagt = new QThread();
    xagt->start();
    this->runner = new RunningThread();
    ((RunningThread * )runner)->setThread(this->xagt);
}
BlackLine::~BlackLine()
{
    delete ui;
}

//Bam vao nut Che do tu dong
void BlackLine::on_autoModeBtn_clicked()
{
    hide_Standard_Menu(this->ui);
    hide_HandMode_Menu(this->ui);
    show_AutoMode_Menu(this->ui);
}
//Bam vao nut x trong che do tu dong
void BlackLine::on_close_automode_menu_btn_clicked()
{
    hide_AutoMode_Menu(this->ui);
    this->ui->start_btn_handmode->setVisible(false);
}
//Bam  vao nut Che do tieu chuan
void BlackLine::on_standardModeBtn_clicked()
{
    hide_AutoMode_Menu(this->ui);
    hide_HandMode_Menu(this->ui);
    show_Standard_Menu(this->ui);
}
//bam vao nut x trong che do tieu chuan
void BlackLine::on_close_standard_menu_btn_clicked()
{
    hide_Standard_Menu(this->ui);
    this->ui->start_btn_handmode_2->setVisible(false);
}

//Bam vao nut Che do thu cong
void BlackLine::on_handModeBtn_clicked()
{
    hide_Standard_Menu(this->ui);
    hide_AutoMode_Menu(this->ui);
    show_HandMode_Menu(this->ui);
}
// Bam vao nut x trong che do thu cong
void BlackLine::on_close_handmode_menu_btn_clicked()
{
    hide_HandMode_Menu(this->ui);
    this->ui->start_btn_automode->setVisible(false);
}

///////////////////////////
//debug
//in ra stt doc check box
void BlackLine::changeText(Ui::BlackLine* ui){
    QList<QGroupBox *> grlist = ui->frame_handmode_menu->findChildren<QGroupBox*>();
    foreach(QGroupBox *g,grlist){

        QList<QCheckBox *> list = g-> findChildren<QCheckBox *>();
        int i=0;
        foreach(QCheckBox *w, list) {
            i++;
            QString x = QString::number(i);
            w->setText(x);
            w->setChecked(true);
        }
    }
}
QString BlackLine::print_data_checkbox(QWidget*w){
//    QFile file("fileCheckbox.txt");
//    if(!file.open(QFile::Text |QFile::Append)){
//        return;
//    }
//    QTextStream output(&file);
//            output<<"--tab "<<w->objectName()<<endl;

    QString result;
            QList<QGroupBox*> listGroupBox = w->findChildren<QGroupBox*>();
            foreach(QGroupBox* grBox, listGroupBox){
                if(!grBox->isChecked()) continue;
                result.append("<group ='");
                result.append(grBox->title());
                result.append("'>");
//                output<<"------------Groupbox "<<grBox->title()<<"  "<<grBox->isChecked()<<endl;
                QVector<QString> group_checked_box();
                QList<QCheckBox*> list_checkbox_in_group = grBox->findChildren<QCheckBox*>();
                foreach(QCheckBox* c_inGr,list_checkbox_in_group){
                    if(c_inGr->isChecked()){
                        c_inGr->hide();//chi co tac dung danh dau
                        result.append("<param>");
                        result.append(c_inGr->text());
                        result.append("</param>");

                    }
//                    output<<"-----------------------"<< c_inGr->text() <<"  " << c_inGr->isChecked()<<endl;
                }

                result.append("</group>");
            }
            QList<QCheckBox*> listCheckBox = w->findChildren<QCheckBox*>();
            foreach(QCheckBox *c,listCheckBox){
                if(!c->isHidden() && c->isChecked()){
//                    output<<"------------"<< c->text() <<"  " << c->isChecked()<<endl;
                    result.append("<group ='");
                    result.append(c->text());
                    result.append("'>");
                    result.append(c->text());
                    result.append("</group>");
                }
                else{
                    c->setVisible(true);
                }
            }

//    file.flush();
//    file.close();
            return result;
}

//debug
///////////////////////////



///////
//Cac ham duoi day thuc hien khi click vao checkbox dai dien cho 1 group
void BlackLine::on_memory_ProcessListing_group_toggled(bool arg1){
    revert_checkBox(this->ui->memory_ProcessListing_group,arg1);
}
void BlackLine::on_system_SystemInfomation_group_toggled(bool arg1){
    revert_checkBox(this->ui->system_SystemInfomation_group,arg1);
}
void BlackLine::on_memory_HookDetection_toggled(bool arg1){
    revert_checkBox(this->ui->memory_HookDetection,arg1);
}
void BlackLine::on_memory_DriversEnumeration_group_toggled(bool arg1){
    revert_checkBox(this->ui->memory_DriversEnumeration_group,arg1);
}
void BlackLine::on_network_BrowserHistory_group_toggled(bool arg1){
    revert_checkBox(this->ui->network_BrowserHistory_group,arg1);
}
void BlackLine::on_disk_FileEnumeration_group_toggled(bool arg1){
    revert_checkBox(this->ui->disk_FileEnumeration_group,arg1);
}
void BlackLine::on_disk_DiskEnumeration_group_toggled(bool arg1){
    revert_checkBox(this->ui->disk_DiskEnumeration_group,arg1);
}
void BlackLine::on_other_Tasks_group_toggled(bool arg1){
    revert_checkBox(this->ui->other_Tasks_group,arg1);
}
void BlackLine::on_other_Services_group_toggled(bool arg1){
    revert_checkBox(this->ui->other_Services_group,arg1);
}
void BlackLine::on_other_CommonPersistenceMechanisms_group_toggled(bool arg1){
    revert_checkBox(this->ui->other_CommonPersistenceMechanisms_group,arg1);
}

//
//////





void BlackLine::on_next_btn_handmode_clicked()
{
    folderPath = choseFolder();
    if(folderPath == "") return;
    this->ui->tab_hand_mode_widget->setDisabled(true);
    this->ui->start_btn_handmode->setVisible(true);
    this->ui->next_btn_handmode->setVisible(false);
    this->ui->label_folder_path->setVisible(true);
    this->ui->back_btn_handmode->setVisible(true);
    this->ui->label_folder_path->setText("Ket qua se duoc luu vao:  "+ folderPath);


}

void BlackLine::on_back_btn_handmode_clicked()
{
    this->ui->start_btn_handmode->setVisible(false);
    this->ui->next_btn_handmode->setVisible(true);
    show_HandMode_Menu(this->ui);
}

void BlackLine::on_back_btn_automode_clicked()
{
    this->ui->start_btn_automode->setVisible(false);
    this->ui->next_btn_automode->setVisible(true);
    show_AutoMode_Menu(this->ui);
}
void BlackLine::on_back_btn_handmode_2_clicked()
{
    this->ui->start_btn_handmode_2->setVisible(false);
    this->ui->next_btn_handmode_2->setVisible(true);
    show_Standard_Menu(this->ui);
}
void BlackLine::on_next_btn_handmode_2_clicked()
{
    folderPath = choseFolder();
    if(folderPath == "") return;
    this->ui->tab_hand_mode_widget_2->setDisabled(true);
    this->ui->start_btn_handmode_2->setVisible(true);
    this->ui->next_btn_handmode_2->setVisible(false);
    this->ui->label_folder_path->setVisible(true);
    this->ui->back_btn_handmode_2->setVisible(true);
    this->ui->label_folder_path->setText("Ket qua se duoc luu vao:  "+ folderPath);
}

void BlackLine::on_next_btn_automode_clicked()
{
    folderPath = choseFolder();
    if(folderPath == "") return;
    this->ui->ram_checkbox_automode->setDisabled(true);
    this->ui->start_btn_automode->setVisible(true);
    this->ui->next_btn_automode->setVisible(false);
    this->ui->label_folder_path->setVisible(true);
    this->ui->back_btn_automode->setVisible(true);
    this->ui->label_folder_path->setText("Ket qua se duoc luu vao:  "+ folderPath);
}

void BlackLine::on_finish_btn_clicked()
{
    hide_text_output(this->ui);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ham nay thuc hien che do thu cong
void BlackLine::on_start_btn_handmode_clicked()
{
    open_text_output(this->ui);
    //debug
    QString memory = print_data_checkbox(this->ui->tab_memory);
    QString disk = print_data_checkbox(this->ui->tab_disk);
    QString network = print_data_checkbox(this->ui->tab_network);
    QString other = print_data_checkbox(this->ui->tab_other);
    QString system = print_data_checkbox(this->ui->tab_system);
    QFile file("fileCheckbox.txt");
    if(file.open(QFile::Text |QFile::WriteOnly)){
        QTextStream output(&file);
        output<<memory<<endl;
        output<<network<<endl;
        output<<disk<<endl;
        output<<other<<endl;
        output<<disk<<endl;
    }
    file.flush();
    file.close();
    QString folder_To_Save = folderPath;
    //////////////////////////////////

    /*cau lenh duoi day dung de them text ra man hinh*/
//    this->ui->label_outpu_info->setText("anything");

    /*cau lenh duoi day dung de hien thi % (0->100) tren processBar*/
//    this->ui->progressBar->setValue(100);



    //////////////////////////////////
    /*hien thi nut hoan tat khi chay xong*/
    this->ui->finish_btn->setDisabled(false);

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ham nay thuc hien che do tu dong
void BlackLine::on_start_btn_automode_clicked()
{
    open_text_output(this->ui);
    bool copy_Ram_Required = this->ui->ram_checkbox_automode->isChecked();
    QString folder_To_Save = folderPath;
    //////////////////////////////////
    emit this->runXagtSign(folderPath);
    this->scr.setFolderPath(folder_To_Save);
//    ((RunningThread * )runner)->setFolderPath(folder_To_Save);
////    ((RunningThread * )runner)->set(folder_To_Save);

//    this->ui->label_outpu_info->setText("->dang thu thap tu dong");

//    this->scr.autoCollect();
//    QThreadPool::globalInstance()->start(this->runner);

//    //while()
//    this->ui->label_outpu_info->setText("->da thu thap tu dong");
//    if(copy_Ram_Required) {
//        this->ui->label_outpu_info->setText("->dang sao luu ram");
//        scr.ramBackup();
//        QThreadPool::globalInstance()->start(this->runner);
//        this->ui->label_outpu_info->setText("->da sao luu ram");
//    }

    //////////////////////////////////
    /*hien thi nut hoan tat khi chay xong*/
    this->ui->finish_btn->setDisabled(false);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ham nay thuc hien che do thu thap tuy chinh
void BlackLine::on_start_btn_handmode_2_clicked()
{
    open_text_output(this->ui);
    //debug
    QString memory = print_data_checkbox(this->ui->tab_memory_2);
    QString disk = print_data_checkbox(this->ui->tab_disk_2);
    QString network = print_data_checkbox(this->ui->tab_network_2);
    QString other = print_data_checkbox(this->ui->tab_other_2);
    QString system = print_data_checkbox(this->ui->tab_system_2);
    QFile file("fileCheckbox.txt");
    if(file.open(QFile::Text |QFile::WriteOnly)){
        QTextStream output(&file);
        output<<memory<<endl;
        output<<network<<endl;
        output<<disk<<endl;
        output<<other<<endl;
        output<<disk<<endl;
    }
    file.flush();
    file.close();
    QString folder_To_Save = folderPath;
    //////////////////////////////////

    /*cau lenh duoi day dung de them text ra man hinh*/
//    this->ui->label_outpu_info->setText("anything");

    /*cau lenh duoi day dung de hien thi % (0->100) tren processBar*/
//    this->ui->progressBar->setValue(100);



    //////////////////////////////////
    /*hien thi nut hoan tat khi chay xong*/
    this->ui->finish_btn->setDisabled(false);
}


// Ham nay duoc goi khi dang thu thap thong tin nhung nguoi dung bam nut huy
void BlackLine::on_cancel_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Xac nhan","Ban co chac chan khong",QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        hide_text_output(this->ui);
        //code o ben duoi


        ////////////////////////////
    }
    return;
}

//void BlackLine::runXagtSign(){

//}



