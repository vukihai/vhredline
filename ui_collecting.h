/********************************************************************************
** Form generated from reading ui file 'collecting.ui'
**
** Created: Thu Jul 5 14:30:19 2018
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_COLLECTING_H
#define UI_COLLECTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Collecting
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Collecting)
    {
    if (Collecting->objectName().isEmpty())
        Collecting->setObjectName(QString::fromUtf8("Collecting"));
    Collecting->resize(605, 79);
    buttonBox = new QDialogButtonBox(Collecting);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(250, 30, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    label = new QLabel(Collecting);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(30, 30, 371, 31));

    retranslateUi(Collecting);
    QObject::connect(buttonBox, SIGNAL(accepted()), Collecting, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), Collecting, SLOT(reject()));

    QMetaObject::connectSlotsByName(Collecting);
    } // setupUi

    void retranslateUi(QDialog *Collecting)
    {
    Collecting->setWindowTitle(QApplication::translate("Collecting", "Dialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Collecting", "-> thu thap du lieu bo nho ...... 60% (1/6)", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Collecting);
    } // retranslateUi

};

namespace Ui {
    class Collecting: public Ui_Collecting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLECTING_H
