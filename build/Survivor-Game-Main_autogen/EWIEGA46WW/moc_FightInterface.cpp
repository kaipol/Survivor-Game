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
    "enter_shop_signal",
    "coin",
    "game_end_type_signal",
    "type",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "back_to_main",
    "time_control",
    "game_fail",
    "save_date",
    "Heroes_and_Monsters_init",
    "name",
    "Monsters_move",
    "Monsters_generate",
    "bullet_generate",
    "bullet_move",
    "check_hero_attack",
    "get_level_up_change",
    "get_prop_type"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t {
    uint offsetsAndSizes[50];
    char stringdata0[15];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[23];
    char stringdata5[18];
    char stringdata6[5];
    char stringdata7[21];
    char stringdata8[5];
    char stringdata9[14];
    char stringdata10[11];
    char stringdata11[6];
    char stringdata12[13];
    char stringdata13[13];
    char stringdata14[10];
    char stringdata15[10];
    char stringdata16[25];
    char stringdata17[5];
    char stringdata18[14];
    char stringdata19[18];
    char stringdata20[16];
    char stringdata21[12];
    char stringdata22[18];
    char stringdata23[20];
    char stringdata24[14];
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
        QT_MOC_LITERAL(64, 17),  // "enter_shop_signal"
        QT_MOC_LITERAL(82, 4),  // "coin"
        QT_MOC_LITERAL(87, 20),  // "game_end_type_signal"
        QT_MOC_LITERAL(108, 4),  // "type"
        QT_MOC_LITERAL(113, 13),  // "keyPressEvent"
        QT_MOC_LITERAL(127, 10),  // "QKeyEvent*"
        QT_MOC_LITERAL(138, 5),  // "event"
        QT_MOC_LITERAL(144, 12),  // "back_to_main"
        QT_MOC_LITERAL(157, 12),  // "time_control"
        QT_MOC_LITERAL(170, 9),  // "game_fail"
        QT_MOC_LITERAL(180, 9),  // "save_date"
        QT_MOC_LITERAL(190, 24),  // "Heroes_and_Monsters_init"
        QT_MOC_LITERAL(215, 4),  // "name"
        QT_MOC_LITERAL(220, 13),  // "Monsters_move"
        QT_MOC_LITERAL(234, 17),  // "Monsters_generate"
        QT_MOC_LITERAL(252, 15),  // "bullet_generate"
        QT_MOC_LITERAL(268, 11),  // "bullet_move"
        QT_MOC_LITERAL(280, 17),  // "check_hero_attack"
        QT_MOC_LITERAL(298, 19),  // "get_level_up_change"
        QT_MOC_LITERAL(318, 13)   // "get_prop_type"
    },
    "FightInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "hero_hp_equal_0_signal",
    "enter_shop_signal",
    "coin",
    "game_end_type_signal",
    "type",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "back_to_main",
    "time_control",
    "game_fail",
    "save_date",
    "Heroes_and_Monsters_init",
    "name",
    "Monsters_move",
    "Monsters_generate",
    "bullet_generate",
    "bullet_move",
    "check_hero_attack",
    "get_level_up_change",
    "get_prop_type"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFightInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       4,    0,  119,    2, 0x06,    3 /* Public */,
       5,    1,  120,    2, 0x06,    4 /* Public */,
       7,    1,  123,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  126,    2, 0x0a,    8 /* Public */,
      12,    0,  129,    2, 0x0a,   10 /* Public */,
      13,    0,  130,    2, 0x0a,   11 /* Public */,
      14,    0,  131,    2, 0x0a,   12 /* Public */,
      15,    0,  132,    2, 0x0a,   13 /* Public */,
      16,    1,  133,    2, 0x0a,   14 /* Public */,
      18,    0,  136,    2, 0x0a,   16 /* Public */,
      19,    0,  137,    2, 0x0a,   17 /* Public */,
      20,    0,  138,    2, 0x0a,   18 /* Public */,
      21,    0,  139,    2, 0x0a,   19 /* Public */,
      22,    0,  140,    2, 0x0a,   20 /* Public */,
      23,    1,  141,    2, 0x0a,   21 /* Public */,
      24,    1,  144,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

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
        // method 'enter_shop_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'game_end_type_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'back_to_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'time_control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'game_fail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_date'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Heroes_and_Monsters_init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Monsters_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Monsters_generate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bullet_generate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bullet_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'check_hero_attack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_level_up_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_prop_type'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
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
        case 2: _t->enter_shop_signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->game_end_type_signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 5: _t->back_to_main(); break;
        case 6: _t->time_control(); break;
        case 7: _t->game_fail(); break;
        case 8: _t->save_date(); break;
        case 9: _t->Heroes_and_Monsters_init((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->Monsters_move(); break;
        case 11: _t->Monsters_generate(); break;
        case 12: _t->bullet_generate(); break;
        case 13: _t->bullet_move(); break;
        case 14: _t->check_hero_attack(); break;
        case 15: _t->get_level_up_change((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->get_prop_type((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
        {
            using _t = void (FightInterface::*)(int );
            if (_t _q_method = &FightInterface::enter_shop_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)(int );
            if (_t _q_method = &FightInterface::game_end_type_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
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

// SIGNAL 2
void FightInterface::enter_shop_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FightInterface::game_end_type_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
