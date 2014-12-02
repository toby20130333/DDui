/****************************************************************************
** Meta object code from reading C++ file 'nodehttpmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nodehttp/nodehttpmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodehttpmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NodeHttpManager_t {
    QByteArrayData data[8];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeHttpManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeHttpManager_t qt_meta_stringdata_NodeHttpManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NodeHttpManager"
QT_MOC_LITERAL(1, 16, 11), // "sendMsgToUI"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "cmd"
QT_MOC_LITERAL(4, 33, 3), // "lst"
QT_MOC_LITERAL(5, 37, 12), // "slotLoginApi"
QT_MOC_LITERAL(6, 50, 15), // "slotRegisterApi"
QT_MOC_LITERAL(7, 66, 14) // "slotCityAddApi"

    },
    "NodeHttpManager\0sendMsgToUI\0\0cmd\0lst\0"
    "slotLoginApi\0slotRegisterApi\0"
    "slotCityAddApi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeHttpManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x0a /* Public */,
       6,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QStringList,    4,

       0        // eod
};

void NodeHttpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeHttpManager *_t = static_cast<NodeHttpManager *>(_o);
        switch (_id) {
        case 0: _t->sendMsgToUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 1: _t->slotLoginApi((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->slotRegisterApi((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 3: _t->slotCityAddApi((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NodeHttpManager::*_t)(int , const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHttpManager::sendMsgToUI)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NodeHttpManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NodeHttpManager.data,
      qt_meta_data_NodeHttpManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NodeHttpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeHttpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NodeHttpManager.stringdata))
        return static_cast<void*>(const_cast< NodeHttpManager*>(this));
    return QObject::qt_metacast(_clname);
}

int NodeHttpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void NodeHttpManager::sendMsgToUI(int _t1, const QStringList & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
