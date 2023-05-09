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
    "game_end_type_signal",
    "type",
    "back_to_main",
    "Heroes_and_Monsters_init",
    "name",
    "time_control",
    "game_fail",
    "Monsters_move",
    "bullet_move"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFightInterfaceENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[15];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[23];
    char stringdata5[21];
    char stringdata6[5];
    char stringdata7[13];
    char stringdata8[25];
    char stringdata9[5];
    char stringdata10[13];
    char stringdata11[10];
    char stringdata12[14];
    char stringdata13[12];
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
        QT_MOC_LITERAL(64, 20),  // "game_end_type_signal"
        QT_MOC_LITERAL(85, 4),  // "type"
        QT_MOC_LITERAL(90, 12),  // "back_to_main"
        QT_MOC_LITERAL(103, 24),  // "Heroes_and_Monsters_init"
        QT_MOC_LITERAL(128, 4),  // "name"
        QT_MOC_LITERAL(133, 12),  // "time_control"
        QT_MOC_LITERAL(146, 9),  // "game_fail"
        QT_MOC_LITERAL(156, 13),  // "Monsters_move"
        QT_MOC_LITERAL(170, 11)   // "bullet_move"
    },
    "FightInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "hero_hp_equal_0_signal",
    "game_end_type_signal",
    "type",
    "back_to_main",
    "Heroes_and_Monsters_init",
    "name",
    "time_control",
    "game_fail",
    "Monsters_move",
    "bullet_move"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFightInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    0,   71,    2, 0x06,    3 /* Public */,
       5,    1,   72,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   75,    2, 0x0a,    6 /* Public */,
       8,    1,   76,    2, 0x0a,    7 /* Public */,
      10,    0,   79,    2, 0x0a,    9 /* Public */,
      11,    0,   80,    2, 0x0a,   10 /* Public */,
      12,    0,   81,    2, 0x0a,   11 /* Public */,
      13,    0,   82,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
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
        // method 'game_end_type_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'back_to_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Heroes_and_Monsters_init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'time_control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'game_fail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Monsters_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bullet_move'
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
        case 2: _t->game_end_type_signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->back_to_main(); break;
        case 4: _t->Heroes_and_Monsters_init((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->time_control(); break;
        case 6: _t->game_fail(); break;
        case 7: _t->Monsters_move(); break;
        case 8: _t->bullet_move(); break;
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
            if (_t _q_method = &FightInterface::game_end_type_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void FightInterface::game_end_type_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
