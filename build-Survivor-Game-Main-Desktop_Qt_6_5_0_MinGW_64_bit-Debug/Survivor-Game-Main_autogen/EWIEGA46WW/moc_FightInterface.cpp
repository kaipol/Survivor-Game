/****************************************************************************
** Meta object code from reading C++ file 'FightInterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Survivor-Game-Main/FightInterface.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FightInterface.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFightInterfaceENDCLASS = QtMocHelpers::stringData(
    "FightInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "hero_hp_equal_0_signal",
    "back_to_main",
    "Heroes_and_Monsters_init",
    "name",
    "time_control",
    "game_fail",
    "play_again"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[15];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[23];
    char stringdata5[13];
    char stringdata6[25];
    char stringdata7[5];
    char stringdata8[13];
    char stringdata9[10];
    char stringdata10[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t qt_meta_stringdata_CLASSFightInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "FightInterface"
        QT_MOC_LITERAL(15, 18),  // "changeWidgetsignal"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 5),  // "Index"
        QT_MOC_LITERAL(41, 22),  // "hero_hp_equal_0_signal"
        QT_MOC_LITERAL(64, 12),  // "back_to_main"
        QT_MOC_LITERAL(77, 24),  // "Heroes_and_Monsters_init"
        QT_MOC_LITERAL(102, 4),  // "name"
        QT_MOC_LITERAL(107, 12),  // "time_control"
        QT_MOC_LITERAL(120, 9),  // "game_fail"
        QT_MOC_LITERAL(130, 10)   // "play_again"
    },
    "FightInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "hero_hp_equal_0_signal",
    "back_to_main",
    "Heroes_and_Monsters_init",
    "name",
    "time_control",
    "game_fail",
    "play_again"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFightInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    0,   59,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   60,    2, 0x0a,    4 /* Public */,
       6,    1,   61,    2, 0x0a,    5 /* Public */,
       8,    0,   64,    2, 0x0a,    7 /* Public */,
       9,    0,   65,    2, 0x0a,    8 /* Public */,
      10,    0,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FightInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFightInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFightInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FightInterface, std::true_type>,
        // method 'changeWidgetsignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'hero_hp_equal_0_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'back_to_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Heroes_and_Monsters_init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'time_control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'game_fail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play_again'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FightInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FightInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeWidgetsignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->hero_hp_equal_0_signal(); break;
        case 2: _t->back_to_main(); break;
        case 3: _t->Heroes_and_Monsters_init((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->time_control(); break;
        case 5: _t->game_fail(); break;
        case 6: _t->play_again(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FightInterface::*)(int );
            if (_t _q_method = &FightInterface::changeWidgetsignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)();
            if (_t _q_method = &FightInterface::hero_hp_equal_0_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *FightInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FightInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFightInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FightInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FightInterface::changeWidgetsignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FightInterface::hero_hp_equal_0_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
