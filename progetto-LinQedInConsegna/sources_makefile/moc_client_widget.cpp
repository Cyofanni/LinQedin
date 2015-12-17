/****************************************************************************
** Meta object code from reading C++ file 'client_widget.h'
**
** Created: Mon Feb 9 17:37:16 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headers/client_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      33,   13,   13,   13, 0x0a,
      53,   13,   13,   13, 0x0a,
      70,   13,   13,   13, 0x0a,
      87,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientWidget[] = {
    "ClientWidget\0\0mostraMioProfilo()\0"
    "pubblicaModifiche()\0insertContatto()\0"
    "removeContatto()\0mostraProfilo()\0"
};

void ClientWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientWidget *_t = static_cast<ClientWidget *>(_o);
        switch (_id) {
        case 0: _t->mostraMioProfilo(); break;
        case 1: _t->pubblicaModifiche(); break;
        case 2: _t->insertContatto(); break;
        case 3: _t->removeContatto(); break;
        case 4: _t->mostraProfilo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ClientWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClientWidget,
      qt_meta_data_ClientWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWidget))
        return static_cast<void*>(const_cast< ClientWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
