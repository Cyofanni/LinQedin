/****************************************************************************
** Meta object code from reading C++ file 'admin_widget.h'
**
** Created: Mon Feb 9 17:37:14 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headers/admin_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      34,   12,   12,   12, 0x0a,
      48,   12,   12,   12, 0x0a,
      64,   12,   12,   12, 0x0a,
      83,   12,   12,   12, 0x0a,
     103,   12,   12,   12, 0x0a,
     123,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AdminWidget[] = {
    "AdminWidget\0\0removeFromLinQedIn()\0"
    "showProfilo()\0changeToBasic()\0"
    "changeToBusiness()\0changeToExecutive()\0"
    "insertNuovoUtente()\0count_clicks()\0"
};

void AdminWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdminWidget *_t = static_cast<AdminWidget *>(_o);
        switch (_id) {
        case 0: _t->removeFromLinQedIn(); break;
        case 1: _t->showProfilo(); break;
        case 2: _t->changeToBasic(); break;
        case 3: _t->changeToBusiness(); break;
        case 4: _t->changeToExecutive(); break;
        case 5: _t->insertNuovoUtente(); break;
        case 6: _t->count_clicks(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AdminWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdminWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdminWidget,
      qt_meta_data_AdminWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWidget))
        return static_cast<void*>(const_cast< AdminWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdminWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
