/****************************************************************************
** Meta object code from reading C++ file 'start_widget.h'
**
** Created: Mon Feb 9 17:37:22 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headers/start_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'start_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StartWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      32,   12,   12,   12, 0x0a,
      49,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StartWidget[] = {
    "StartWidget\0\0avviaLatoCliente()\0"
    "avviaLatoAdmin()\0avviaSimulazione()\0"
};

void StartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StartWidget *_t = static_cast<StartWidget *>(_o);
        switch (_id) {
        case 0: _t->avviaLatoCliente(); break;
        case 1: _t->avviaLatoAdmin(); break;
        case 2: _t->avviaSimulazione(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StartWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StartWidget,
      qt_meta_data_StartWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StartWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StartWidget))
        return static_cast<void*>(const_cast< StartWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int StartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
