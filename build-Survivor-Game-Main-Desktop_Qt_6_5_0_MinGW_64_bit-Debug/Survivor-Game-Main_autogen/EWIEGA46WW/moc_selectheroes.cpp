/****************************************************************************
** Meta object code from reading C++ file 'SelectHeroes.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Survivor-Game-Main/SelectHeroes.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectHeroes.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS = QtMocHelpers::stringData(
    "SelectHeroesInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "selectHerosignal",
    "name",
    "selectMapsignal",
    "type",
    "hero_to_fight",
    "restart_select"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[22];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[17];
    char stringdata5[5];
    char stringdata6[16];
    char stringdata7[5];
    char stringdata8[14];
    char stringdata9[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS_t qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "SelectHeroesInterface"
        QT_MOC_LITERAL(22, 18),  // "changeWidgetsignal"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 5),  // "Index"
        QT_MOC_LITERAL(48, 16),  // "selectHerosignal"
        QT_MOC_LITERAL(65, 4),  // "name"
        QT_MOC_LITERAL(70, 15),  // "selectMapsignal"
        QT_MOC_LITERAL(86, 4),  // "type"
        QT_MOC_LITERAL(91, 13),  // "hero_to_fight"
        QT_MOC_LITERAL(105, 14)   // "restart_select"
    },
    "SelectHeroesInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "selectHerosignal",
    "name",
    "selectMapsignal",
    "type",
    "hero_to_fight",
    "restart_select"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSelectHeroesInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    1,   47,    2, 0x06,    3 /* Public */,
       6,    1,   50,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   53,    2, 0x0a,    7 /* Public */,
       9,    0,   56,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SelectHeroesInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSelectHeroesInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SelectHeroesInterface, std::true_type>,
        // method 'changeWidgetsignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'selectHerosignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'selectMapsignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'hero_to_fight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'restart_select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SelectHeroesInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SelectHeroesInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeWidgetsignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->selectHerosignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->selectMapsignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->hero_to_fight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->restart_select(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectHeroesInterface::*)(int );
            if (_t _q_method = &SelectHeroesInterface::changeWidgetsignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SelectHeroesInterface::*)(QString );
            if (_t _q_method = &SelectHeroesInterface::selectHerosignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SelectHeroesInterface::*)(int );
            if (_t _q_method = &SelectHeroesInterface::selectMapsignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *SelectHeroesInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectHeroesInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSelectHeroesInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SelectHeroesInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SelectHeroesInterface::changeWidgetsignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SelectHeroesInterface::selectHerosignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SelectHeroesInterface::selectMapsignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
