/****************************************************************************
** Meta object code from reading C++ file 'widgetplaylists.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer/widgetplaylists.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetplaylists.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetPlayLists_t {
    QByteArrayData data[10];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPlayLists_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPlayLists_t qt_meta_stringdata_WidgetPlayLists = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WidgetPlayLists"
QT_MOC_LITERAL(1, 16, 26), // "onButtonAddPlaylistPressed"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 29), // "onButtonRemovePlaylistPressed"
QT_MOC_LITERAL(4, 74, 17), // "onPlaylistCreated"
QT_MOC_LITERAL(5, 92, 12), // "playlistName"
QT_MOC_LITERAL(6, 105, 17), // "onButtonAddTracks"
QT_MOC_LITERAL(7, 123, 20), // "onButtonRemoveTracks"
QT_MOC_LITERAL(8, 144, 14), // "onButtonSearch"
QT_MOC_LITERAL(9, 159, 21) // "chooseAnotherPlaylist"

    },
    "WidgetPlayLists\0onButtonAddPlaylistPressed\0"
    "\0onButtonRemovePlaylistPressed\0"
    "onPlaylistCreated\0playlistName\0"
    "onButtonAddTracks\0onButtonRemoveTracks\0"
    "onButtonSearch\0chooseAnotherPlaylist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPlayLists[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetPlayLists::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetPlayLists *_t = static_cast<WidgetPlayLists *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonAddPlaylistPressed(); break;
        case 1: _t->onButtonRemovePlaylistPressed(); break;
        case 2: _t->onPlaylistCreated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onButtonAddTracks(); break;
        case 4: _t->onButtonRemoveTracks(); break;
        case 5: _t->onButtonSearch(); break;
        case 6: _t->chooseAnotherPlaylist(); break;
        default: ;
        }
    }
}

const QMetaObject WidgetPlayLists::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetPlayLists.data,
      qt_meta_data_WidgetPlayLists,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WidgetPlayLists::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPlayLists::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPlayLists.stringdata0))
        return static_cast<void*>(const_cast< WidgetPlayLists*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetPlayLists::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
