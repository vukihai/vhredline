/****************************************************************************
** Meta object code from reading C++ file 'blackline.h'
**
** Created: Wed Jul 11 10:13:34 2018
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blackline.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blackline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BlackLine[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   10,   10,   10, 0x08,
      67,   10,   59,   10, 0x08,
      97,   10,   10,   10, 0x08,
     122,   10,   10,   10, 0x08,
     147,   10,   10,   10, 0x08,
     184,   10,   10,   10, 0x08,
     226,  221,   10,   10, 0x08,
     271,  221,   10,   10, 0x08,
     318,   10,   10,   10, 0x08,
     349,   10,   10,   10, 0x08,
     380,   10,   10,   10, 0x08,
     411,   10,   10,   10, 0x08,
     443,   10,   10,   10, 0x08,
     474,   10,   10,   10, 0x08,
     506,  221,   10,   10, 0x08,
     544,  221,   10,   10, 0x08,
     593,  221,   10,   10, 0x08,
     639,   10,   10,   10, 0x08,
     663,   10,   10,   10, 0x08,
     687,  221,   10,   10, 0x08,
     731,  221,   10,   10, 0x08,
     775,  221,   10,   10, 0x08,
     810,  221,   10,   10, 0x08,
     848,  221,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BlackLine[] = {
    "BlackLine\0\0runXagtSign(QString)\0"
    "changeText(Ui::BlackLine*)\0QString\0"
    "print_data_checkbox(QWidget*)\0"
    "on_handModeBtn_clicked()\0"
    "on_autoModeBtn_clicked()\0"
    "on_close_automode_menu_btn_clicked()\0"
    "on_close_handmode_menu_btn_clicked()\0"
    "arg1\0on_memory_ProcessListing_group_toggled(bool)\0"
    "on_system_SystemInfomation_group_toggled(bool)\0"
    "on_next_btn_handmode_clicked()\0"
    "on_back_btn_handmode_clicked()\0"
    "on_back_btn_automode_clicked()\0"
    "on_start_btn_automode_clicked()\0"
    "on_next_btn_automode_clicked()\0"
    "on_start_btn_handmode_clicked()\0"
    "on_memory_HookDetection_toggled(bool)\0"
    "on_memory_DriversEnumeration_group_toggled(bool)\0"
    "on_network_BrowserHistory_group_toggled(bool)\0"
    "on_finish_btn_clicked()\0on_cancel_btn_clicked()\0"
    "on_disk_FileEnumeration_group_toggled(bool)\0"
    "on_disk_DiskEnumeration_group_toggled(bool)\0"
    "on_other_Tasks_group_toggled(bool)\0"
    "on_other_Services_group_toggled(bool)\0"
    "on_other_CommonPersistenceMechanisms_group_toggled(bool)\0"
};

const QMetaObject BlackLine::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BlackLine,
      qt_meta_data_BlackLine, 0 }
};

const QMetaObject *BlackLine::metaObject() const
{
    return &staticMetaObject;
}

void *BlackLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BlackLine))
	return static_cast<void*>(const_cast< BlackLine*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BlackLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: runXagtSign((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: changeText((*reinterpret_cast< Ui::BlackLine*(*)>(_a[1]))); break;
        case 2: { QString _r = print_data_checkbox((*reinterpret_cast< QWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: on_handModeBtn_clicked(); break;
        case 4: on_autoModeBtn_clicked(); break;
        case 5: on_close_automode_menu_btn_clicked(); break;
        case 6: on_close_handmode_menu_btn_clicked(); break;
        case 7: on_memory_ProcessListing_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_system_SystemInfomation_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_next_btn_handmode_clicked(); break;
        case 10: on_back_btn_handmode_clicked(); break;
        case 11: on_back_btn_automode_clicked(); break;
        case 12: on_start_btn_automode_clicked(); break;
        case 13: on_next_btn_automode_clicked(); break;
        case 14: on_start_btn_handmode_clicked(); break;
        case 15: on_memory_HookDetection_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: on_memory_DriversEnumeration_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: on_network_BrowserHistory_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_finish_btn_clicked(); break;
        case 19: on_cancel_btn_clicked(); break;
        case 20: on_disk_FileEnumeration_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: on_disk_DiskEnumeration_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: on_other_Tasks_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_other_Services_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_other_CommonPersistenceMechanisms_group_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void BlackLine::runXagtSign(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
