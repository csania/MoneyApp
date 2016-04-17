/****************************************************************************
** Meta object code from reading C++ file 'AddTransactionDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:\GitRepository\MoneyApp\MoneyApp\MoneyApp3\AddTransactionDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddTransactionDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddTransactionDialog_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddTransactionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddTransactionDialog_t qt_meta_stringdata_AddTransactionDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AddTransactionDialog"
QT_MOC_LITERAL(1, 21, 9), // "pressedOk"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "pressedCancel"
QT_MOC_LITERAL(4, 46, 15) // "clickedOnPeople"

    },
    "AddTransactionDialog\0pressedOk\0\0"
    "pressedCancel\0clickedOnPeople"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddTransactionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddTransactionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddTransactionDialog *_t = static_cast<AddTransactionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pressedOk(); break;
        case 1: _t->pressedCancel(); break;
        case 2: _t->clickedOnPeople(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddTransactionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddTransactionDialog.data,
      qt_meta_data_AddTransactionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddTransactionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddTransactionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddTransactionDialog.stringdata0))
        return static_cast<void*>(const_cast< AddTransactionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddTransactionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
