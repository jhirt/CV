/****************************************************************************
** Meta object code from reading C++ file 'MenuView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/App/Menu/MenuView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_App__MenuView_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_App__MenuView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_App__MenuView_t qt_meta_stringdata_App__MenuView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "App::MenuView"
QT_MOC_LITERAL(1, 14, 27), // "ViewerMenuOpenFileTriggered"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 8), // "fileName"
QT_MOC_LITERAL(4, 52, 19), // "MenuOpenFileClicked"
QT_MOC_LITERAL(5, 72, 7) // "checked"

    },
    "App::MenuView\0ViewerMenuOpenFileTriggered\0"
    "\0fileName\0MenuOpenFileClicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_App__MenuView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void App::MenuView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuView *_t = static_cast<MenuView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ViewerMenuOpenFileTriggered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->MenuOpenFileClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MenuView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuView::ViewerMenuOpenFileTriggered)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject App::MenuView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_App__MenuView.data,
      qt_meta_data_App__MenuView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *App::MenuView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *App::MenuView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_App__MenuView.stringdata0))
        return static_cast<void*>(const_cast< MenuView*>(this));
    if (!strcmp(_clname, "Viewer"))
        return static_cast< Viewer*>(const_cast< MenuView*>(this));
    return QObject::qt_metacast(_clname);
}

int App::MenuView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void App::MenuView::ViewerMenuOpenFileTriggered(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
