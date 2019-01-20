/****************************************************************************
** Meta object code from reading C++ file 'myvideowidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer/myvideowidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myvideowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyVideoWidget_t {
    QByteArrayData data[12];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyVideoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyVideoWidget_t qt_meta_stringdata_MyVideoWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyVideoWidget"
QT_MOC_LITERAL(1, 14, 12), // "showControls"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "hideControls"
QT_MOC_LITERAL(4, 41, 16), // "leftMouseClicked"
QT_MOC_LITERAL(5, 58, 13), // "doubleClicked"
QT_MOC_LITERAL(6, 72, 13), // "escapePressed"
QT_MOC_LITERAL(7, 86, 12), // "spacePressed"
QT_MOC_LITERAL(8, 99, 9), // "upPressed"
QT_MOC_LITERAL(9, 109, 11), // "downPressed"
QT_MOC_LITERAL(10, 121, 11), // "leftPressed"
QT_MOC_LITERAL(11, 133, 12) // "rightPressed"

    },
    "MyVideoWidget\0showControls\0\0hideControls\0"
    "leftMouseClicked\0doubleClicked\0"
    "escapePressed\0spacePressed\0upPressed\0"
    "downPressed\0leftPressed\0rightPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyVideoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
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

void MyVideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyVideoWidget *_t = static_cast<MyVideoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showControls(); break;
        case 1: _t->hideControls(); break;
        case 2: _t->leftMouseClicked(); break;
        case 3: _t->doubleClicked(); break;
        case 4: _t->escapePressed(); break;
        case 5: _t->spacePressed(); break;
        case 6: _t->upPressed(); break;
        case 7: _t->downPressed(); break;
        case 8: _t->leftPressed(); break;
        case 9: _t->rightPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::showControls)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::hideControls)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::leftMouseClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::doubleClicked)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::escapePressed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::spacePressed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::upPressed)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::downPressed)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::leftPressed)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MyVideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyVideoWidget::rightPressed)) {
                *result = 9;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyVideoWidget::staticMetaObject = {
    { &QVideoWidget::staticMetaObject, qt_meta_stringdata_MyVideoWidget.data,
      qt_meta_data_MyVideoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyVideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyVideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyVideoWidget.stringdata0))
        return static_cast<void*>(const_cast< MyVideoWidget*>(this));
    return QVideoWidget::qt_metacast(_clname);
}

int MyVideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVideoWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MyVideoWidget::showControls()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyVideoWidget::hideControls()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MyVideoWidget::leftMouseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MyVideoWidget::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MyVideoWidget::escapePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MyVideoWidget::spacePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MyVideoWidget::upPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MyVideoWidget::downPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MyVideoWidget::leftPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void MyVideoWidget::rightPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
