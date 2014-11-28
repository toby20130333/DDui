/****************************************************************************
** Meta object code from reading C++ file 'datainterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/datainterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datainterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataInterface_t {
    QByteArrayData data[16];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataInterface_t qt_meta_stringdata_DataInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DataInterface"
QT_MOC_LITERAL(1, 14, 23), // "signalResponseDataReady"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "error"
QT_MOC_LITERAL(4, 45, 3), // "cmd"
QT_MOC_LITERAL(5, 49, 9), // "finalData"
QT_MOC_LITERAL(6, 59, 14), // "signalNotifyUI"
QT_MOC_LITERAL(7, 74, 10), // "notifyData"
QT_MOC_LITERAL(8, 85, 15), // "slotRequestData"
QT_MOC_LITERAL(9, 101, 13), // "parameterList"
QT_MOC_LITERAL(10, 115, 20), // "slotResponseNotifyUI"
QT_MOC_LITERAL(11, 136, 13), // "processResult"
QT_MOC_LITERAL(12, 150, 15), // "creatConnection"
QT_MOC_LITERAL(13, 166, 16), // "slotChangeCursor"
QT_MOC_LITERAL(14, 183, 4), // "flag"
QT_MOC_LITERAL(15, 188, 8) // "strError"

    },
    "DataInterface\0signalResponseDataReady\0"
    "\0error\0cmd\0finalData\0signalNotifyUI\0"
    "notifyData\0slotRequestData\0parameterList\0"
    "slotResponseNotifyUI\0processResult\0"
    "creatConnection\0slotChangeCursor\0flag\0"
    "strError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    3,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   58,    2, 0x0a /* Public */,
      10,    3,   63,    2, 0x0a /* Public */,
      12,    0,   70,    2, 0x0a /* Public */,
      13,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    3,    4,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    4,    9,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    3,    4,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

 // properties: name, type, flags
      15, QMetaType::QString, 0x00095003,

       0        // eod
};

void DataInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataInterface *_t = static_cast<DataInterface *>(_o);
        switch (_id) {
        case 0: _t->signalResponseDataReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->signalNotifyUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 2: _t->slotRequestData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->slotResponseNotifyUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 4: _t->creatConnection(); break;
        case 5: _t->slotChangeCursor((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataInterface::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataInterface::signalResponseDataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (DataInterface::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataInterface::signalNotifyUI)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DataInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataInterface.data,
      qt_meta_data_DataInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataInterface.stringdata))
        return static_cast<void*>(const_cast< DataInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int DataInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getError(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setError(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataInterface::signalResponseDataReady(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataInterface::signalNotifyUI(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
