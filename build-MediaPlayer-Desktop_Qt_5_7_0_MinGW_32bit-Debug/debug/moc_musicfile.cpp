/****************************************************************************
** Meta object code from reading C++ file 'musicfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer/musicfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicFile_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicFile_t qt_meta_stringdata_MusicFile = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MusicFile"
QT_MOC_LITERAL(1, 10, 15), // "metaDataChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "MediaData*"
QT_MOC_LITERAL(4, 38, 5), // "music"
QT_MOC_LITERAL(5, 44, 11), // "mediaSetted"
QT_MOC_LITERAL(6, 56, 17), // "metaDataAvailable"
QT_MOC_LITERAL(7, 74, 12), // "setMediaData"
QT_MOC_LITERAL(8, 87, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 104, 4) // "item"

    },
    "MusicFile\0metaDataChanged\0\0MediaData*\0"
    "music\0mediaSetted\0metaDataAvailable\0"
    "setMediaData\0QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void MusicFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicFile *_t = static_cast<MusicFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->metaDataChanged((*reinterpret_cast< MediaData*(*)>(_a[1]))); break;
        case 1: _t->mediaSetted(); break;
        case 2: _t->metaDataAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setMediaData((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicFile::*_t)(MediaData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicFile::metaDataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MusicFile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicFile::mediaSetted)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MusicFile::staticMetaObject = {
    { &MediaFile::staticMetaObject, qt_meta_stringdata_MusicFile.data,
      qt_meta_data_MusicFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicFile.stringdata0))
        return static_cast<void*>(const_cast< MusicFile*>(this));
    return MediaFile::qt_metacast(_clname);
}

int MusicFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MediaFile::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MusicFile::metaDataChanged(MediaData * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicFile::mediaSetted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
