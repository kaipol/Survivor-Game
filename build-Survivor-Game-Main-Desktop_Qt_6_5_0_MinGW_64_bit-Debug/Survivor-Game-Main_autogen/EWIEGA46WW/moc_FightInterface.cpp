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
    "game_end_type_signal",
    "type",
    "save_data_signal",
    "Heroes",
    "is_fight",
    "now_coin",
    "hero_level_up_signal",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "back_to_main",
    "time_control",
    "game_fail",
    "save_data",
    "Heroes_init",
    "name",
    "Monsters_move",
    "Monsters_generate",
    "bullet_generate",
    "bullet_move",
    "check_hero_attack",
    "get_level_up_change",
    "get_prop_type",
    "get_coin",
    "get_data",
    "continue_game",
    "get_map_type"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[15];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[21];
    char stringdata5[5];
    char stringdata6[17];
    char stringdata7[7];
    char stringdata8[9];
    char stringdata9[9];
    char stringdata10[21];
    char stringdata11[14];
    char stringdata12[11];
    char stringdata13[6];
    char stringdata14[13];
    char stringdata15[13];
    char stringdata16[10];
    char stringdata17[10];
    char stringdata18[12];
    char stringdata19[5];
    char stringdata20[14];
    char stringdata21[18];
    char stringdata22[16];
    char stringdata23[12];
    char stringdata24[18];
    char stringdata25[20];
    char stringdata26[14];
    char stringdata27[9];
    char stringdata28[9];
    char stringdata29[14];
    char stringdata30[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t qt_meta_stringdata_CLASSFightInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "FightInterface"
        QT_MOC_LITERAL(15, 18),  // "changeWidgetsignal"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 5),  // "Index"
        QT_MOC_LITERAL(41, 20),  // "game_end_type_signal"
        QT_MOC_LITERAL(62, 4),  // "type"
        QT_MOC_LITERAL(67, 16),  // "save_data_signal"
        QT_MOC_LITERAL(84, 6),  // "Heroes"
        QT_MOC_LITERAL(91, 8),  // "is_fight"
        QT_MOC_LITERAL(100, 8),  // "now_coin"
        QT_MOC_LITERAL(109, 20),  // "hero_level_up_signal"
        QT_MOC_LITERAL(130, 13),  // "keyPressEvent"
        QT_MOC_LITERAL(144, 10),  // "QKeyEvent*"
        QT_MOC_LITERAL(155, 5),  // "event"
        QT_MOC_LITERAL(161, 12),  // "back_to_main"
        QT_MOC_LITERAL(174, 12),  // "time_control"
        QT_MOC_LITERAL(187, 9),  // "game_fail"
        QT_MOC_LITERAL(197, 9),  // "save_data"
        QT_MOC_LITERAL(207, 11),  // "Heroes_init"
        QT_MOC_LITERAL(219, 4),  // "name"
        QT_MOC_LITERAL(224, 13),  // "Monsters_move"
        QT_MOC_LITERAL(238, 17),  // "Monsters_generate"
        QT_MOC_LITERAL(256, 15),  // "bullet_generate"
        QT_MOC_LITERAL(272, 11),  // "bullet_move"
        QT_MOC_LITERAL(284, 17),  // "check_hero_attack"
        QT_MOC_LITERAL(302, 19),  // "get_level_up_change"
        QT_MOC_LITERAL(322, 13),  // "get_prop_type"
        QT_MOC_LITERAL(336, 8),  // "get_coin"
        QT_MOC_LITERAL(345, 8),  // "get_data"
        QT_MOC_LITERAL(354, 13),  // "continue_game"
        QT_MOC_LITERAL(368, 12)   // "get_map_type"
    },
    "FightInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "game_end_type_signal",
    "type",
    "save_data_signal",
    "Heroes",
    "is_fight",
    "now_coin",
    "hero_level_up_signal",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "back_to_main",
    "time_control",
    "game_fail",
    "save_data",
    "Heroes_init",
    "name",
    "Monsters_move",
    "Monsters_generate",
    "bullet_generate",
    "bullet_move",
    "check_hero_attack",
    "get_level_up_change",
    "get_prop_type",
    "get_coin",
    "get_data",
    "continue_game",
    "get_map_type"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFightInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  152,    2, 0x06,    1 /* Public */,
       4,    1,  155,    2, 0x06,    3 /* Public */,
       6,    1,  158,    2, 0x06,    5 /* Public */,
       8,    0,  161,    2, 0x06,    7 /* Public */,
       9,    1,  162,    2, 0x06,    8 /* Public */,
      10,    0,  165,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  166,    2, 0x0a,   11 /* Public */,
      14,    0,  169,    2, 0x0a,   13 /* Public */,
      15,    0,  170,    2, 0x0a,   14 /* Public */,
      16,    0,  171,    2, 0x0a,   15 /* Public */,
      17,    0,  172,    2, 0x0a,   16 /* Public */,
      18,    1,  173,    2, 0x0a,   17 /* Public */,
      20,    0,  176,    2, 0x0a,   19 /* Public */,
      21,    0,  177,    2, 0x0a,   20 /* Public */,
      22,    0,  178,    2, 0x0a,   21 /* Public */,
      23,    0,  179,    2, 0x0a,   22 /* Public */,
      24,    0,  180,    2, 0x0a,   23 /* Public */,
      25,    1,  181,    2, 0x0a,   24 /* Public */,
      26,    1,  184,    2, 0x0a,   26 /* Public */,
      27,    1,  187,    2, 0x0a,   28 /* Public */,
      28,    1,  190,    2, 0x0a,   30 /* Public */,
      29,    0,  193,    2, 0x0a,   32 /* Public */,
      30,    1,  194,    2, 0x0a,   33 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
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
        // method 'game_end_type_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'save_data_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Heroes, std::false_type>,
        // method 'is_fight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'now_coin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'hero_level_up_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'back_to_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'time_control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'game_fail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Heroes_init'
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
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_coin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Heroes, std::false_type>,
        // method 'continue_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_map_type'
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
        case 1: _t->game_end_type_signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->save_data_signal((*reinterpret_cast< std::add_pointer_t<Heroes>>(_a[1]))); break;
        case 3: _t->is_fight(); break;
        case 4: _t->now_coin((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->hero_level_up_signal(); break;
        case 6: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 7: _t->back_to_main(); break;
        case 8: _t->time_control(); break;
        case 9: _t->game_fail(); break;
        case 10: _t->save_data(); break;
        case 11: _t->Heroes_init((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->Monsters_move(); break;
        case 13: _t->Monsters_generate(); break;
        case 14: _t->bullet_generate(); break;
        case 15: _t->bullet_move(); break;
        case 16: _t->check_hero_attack(); break;
        case 17: _t->get_level_up_change((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->get_prop_type((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->get_coin((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->get_data((*reinterpret_cast< std::add_pointer_t<Heroes>>(_a[1]))); break;
        case 21: _t->continue_game(); break;
        case 22: _t->get_map_type((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
            using _t = void (FightInterface::*)(int );
            if (_t _q_method = &FightInterface::game_end_type_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)(Heroes );
            if (_t _q_method = &FightInterface::save_data_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)();
            if (_t _q_method = &FightInterface::is_fight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)(int );
            if (_t _q_method = &FightInterface::now_coin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FightInterface::*)();
            if (_t _q_method = &FightInterface::hero_level_up_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
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
void FightInterface::game_end_type_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FightInterface::save_data_signal(Heroes _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FightInterface::is_fight()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FightInterface::now_coin(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FightInterface::hero_level_up_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
