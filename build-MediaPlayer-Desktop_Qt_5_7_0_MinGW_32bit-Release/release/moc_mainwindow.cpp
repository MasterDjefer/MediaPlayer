/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "onButtonPlayPressed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "onButtonStopPressed"
QT_MOC_LITERAL(4, 52, 21), // "onButtonReplayPressed"
QT_MOC_LITERAL(5, 74, 16), // "onButtonPlaylist"
QT_MOC_LITERAL(6, 91, 10), // "onOpenFile"
QT_MOC_LITERAL(7, 102, 12), // "onFileChange"
QT_MOC_LITERAL(8, 115, 16), // "onPositionChange"
QT_MOC_LITERAL(9, 132, 8), // "position"
QT_MOC_LITERAL(10, 141, 27), // "videoWidgetLeftMouseClicked"
QT_MOC_LITERAL(11, 169, 24), // "videoWidgetDoubleClicked"
QT_MOC_LITERAL(12, 194, 24), // "videoWidgetEscapePressed"
QT_MOC_LITERAL(13, 219, 23), // "videoWidgetSpacePressed"
QT_MOC_LITERAL(14, 243, 12), // "upKeyPressed"
QT_MOC_LITERAL(15, 256, 14), // "downKeyPressed"
QT_MOC_LITERAL(16, 271, 14), // "leftKeyPressed"
QT_MOC_LITERAL(17, 286, 15), // "rightKeyPressed"
QT_MOC_LITERAL(18, 302, 19), // "fullScreenMouseDown"
QT_MOC_LITERAL(19, 322, 17), // "fullScreenMouseUp"
QT_MOC_LITERAL(20, 340, 26), // "onWidgetControlsEscPressed"
QT_MOC_LITERAL(21, 367, 15), // "onMusicReceived"
QT_MOC_LITERAL(22, 383, 17) // "onClientConnected"

    },
    "MainWindow\0onButtonPlayPressed\0\0"
    "onButtonStopPressed\0onButtonReplayPressed\0"
    "onButtonPlaylist\0onOpenFile\0onFileChange\0"
    "onPositionChange\0position\0"
    "videoWidgetLeftMouseClicked\0"
    "videoWidgetDoubleClicked\0"
    "videoWidgetEscapePressed\0"
    "videoWidgetSpacePressed\0upKeyPressed\0"
    "downKeyPressed\0leftKeyPressed\0"
    "rightKeyPressed\0fullScreenMouseDown\0"
    "fullScreenMouseUp\0onWidgetControlsEscPressed\0"
    "onMusicReceived\0onClientConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    1,  120,    2, 0x08 /* Private */,
      10,    0,  123,    2, 0x08 /* Private */,
      11,    0,  124,    2, 0x08 /* Private */,
      12,    0,  125,    2, 0x08 /* Private */,
      13,    0,  126,    2, 0x08 /* Private */,
      14,    0,  127,    2, 0x08 /* Private */,
      15,    0,  128,    2, 0x08 /* Private */,
      16,    0,  129,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    0,  131,    2, 0x08 /* Private */,
      19,    0,  132,    2, 0x08 /* Private */,
      20,    0,  133,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonPlayPressed(); break;
        case 1: _t->onButtonStopPressed(); break;
        case 2: _t->onButtonReplayPressed(); break;
        case 3: _t->onButtonPlaylist(); break;
        case 4: _t->onOpenFile(); break;
        case 5: _t->onFileChange(); break;
        case 6: _t->onPositionChange((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->videoWidgetLeftMouseClicked(); break;
        case 8: _t->videoWidgetDoubleClicked(); break;
        case 9: _t->videoWidgetEscapePressed(); break;
        case 10: _t->videoWidgetSpacePressed(); break;
        case 11: _t->upKeyPressed(); break;
        case 12: _t->downKeyPressed(); break;
        case 13: _t->leftKeyPressed(); break;
        case 14: _t->rightKeyPressed(); break;
        case 15: _t->fullScreenMouseDown(); break;
        case 16: _t->fullScreenMouseUp(); break;
        case 17: _t->onWidgetControlsEscPressed(); break;
        case 18: _t->onMusicReceived(); break;
        case 19: _t->onClientConnected(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE