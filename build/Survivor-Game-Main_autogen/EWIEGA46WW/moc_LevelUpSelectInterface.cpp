/****************************************************************************
** Meta object code from reading C++ file 'LevelUpSelectInterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Survivor-Game-Main/LevelUpSelectInterface.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LevelUpSelectInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS = QtMocHelpers::stringData(
    "LevelUpSelectInterface",
    "change_type",
    "",
    "changeWidgetsignal",
    "back_to_fight",
    "prop_generate"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[23];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[14];
    char stringdata5[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS_t qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "LevelUpSelectInterface"
        QT_MOC_LITERAL(23, 11),  // "change_type"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 18),  // "changeWidgetsignal"
        QT_MOC_LITERAL(55, 13),  // "back_to_fight"
        QT_MOC_LITERAL(69, 13)   // "prop_generate"
    },
    "LevelUpSelectInterface",
    "change_type",
    "",
    "changeWidgetsignal",
    "back_to_fight",
    "prop_generate"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLevelUpSelectInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       3,    1,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   44,    2, 0x0a,    5 /* Public */,
       5,    0,   45,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject LevelUpSelectInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLevelUpSelectInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LevelUpSelectInterface, std::true_type>,
        // method 'change_type'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeWidgetsignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'back_to_fight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prop_generate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LevelUpSelectInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LevelUpSelectInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->change_type((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->changeWidgetsignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->back_to_fight(); break;
        case 3: _t->prop_generate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LevelUpSelectInterface::*)(int );
            if (_t _q_method = &LevelUpSelectInterface::change_type; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LevelUpSelectInterface::*)(int );
            if (_t _q_method = &LevelUpSelectInterface::changeWidgetsignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *LevelUpSelectInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LevelUpSelectInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLevelUpSelectInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LevelUpSelectInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LevelUpSelectInterface::change_type(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LevelUpSelectInterface::changeWidgetsignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
