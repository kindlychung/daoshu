/****************************************************************************
** Meta object code from reading C++ file 'controls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/daoshu/controls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controls_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controls_t qt_meta_stringdata_Controls = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Controls"
QT_MOC_LITERAL(1, 9, 8), // "valueSet"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "nMilliSec"
QT_MOC_LITERAL(4, 29, 14), // "timerCancelled"
QT_MOC_LITERAL(5, 44, 16), // "setButtonClicked"
QT_MOC_LITERAL(6, 61, 19), // "cancelButtonClicked"
QT_MOC_LITERAL(7, 81, 12), // "handleTimeup"
QT_MOC_LITERAL(8, 94, 12), // "handleCancel"
QT_MOC_LITERAL(9, 107, 9) // "decrement"

    },
    "Controls\0valueSet\0\0nMilliSec\0"
    "timerCancelled\0setButtonClicked\0"
    "cancelButtonClicked\0handleTimeup\0"
    "handleCancel\0decrement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controls *_t = static_cast<Controls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->timerCancelled(); break;
        case 2: _t->setButtonClicked(); break;
        case 3: _t->cancelButtonClicked(); break;
        case 4: _t->handleTimeup(); break;
        case 5: _t->handleCancel(); break;
        case 6: _t->decrement(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controls::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::valueSet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::timerCancelled)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Controls.data,
      qt_meta_data_Controls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controls.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Controls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Controls::valueSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controls::timerCancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
