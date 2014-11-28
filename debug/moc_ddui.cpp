/****************************************************************************
** Meta object code from reading C++ file 'ddui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ddui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ddui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DDui_t {
    QByteArrayData data[8];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DDui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DDui_t qt_meta_stringdata_DDui = {
    {
QT_MOC_LITERAL(0, 0, 4), // "DDui"
QT_MOC_LITERAL(1, 5, 14), // "signalNotifyUI"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 23), // "signalResponseDataReady"
QT_MOC_LITERAL(4, 45, 20), // "signalDeleteDownload"
QT_MOC_LITERAL(5, 66, 15), // "slotReponseToUI"
QT_MOC_LITERAL(6, 82, 3), // "cmd"
QT_MOC_LITERAL(7, 86, 3) // "lst"

    },
    "DDui\0signalNotifyUI\0\0signalResponseDataReady\0"
    "signalDeleteDownload\0slotReponseToUI\0"
    "cmd\0lst"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DDui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       3,    3,   41,    2, 0x06 /* Public */,
       4,    2,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    6,    7,

       0        // eod
};

void DDui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DDui *_t = static_cast<DDui *>(_o);
        switch (_id) {
        case 0: _t->signalNotifyUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->signalResponseDataReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 2: _t->signalDeleteDownload((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->slotReponseToUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DDui::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DDui::signalNotifyUI)) {
                *result = 0;
            }
        }
        {
            typedef void (DDui::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DDui::signalResponseDataReady)) {
                *result = 1;
            }
        }
        {
            typedef void (DDui::*_t)(QStringList , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DDui::signalDeleteDownload)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DDui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DDui.data,
      qt_meta_data_DDui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DDui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DDui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DDui.stringdata))
        return static_cast<void*>(const_cast< DDui*>(this));
    return QWidget::qt_metacast(_clname);
}

int DDui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void DDui::signalNotifyUI(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DDui::signalResponseDataReady(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DDui::signalDeleteDownload(QStringList _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
