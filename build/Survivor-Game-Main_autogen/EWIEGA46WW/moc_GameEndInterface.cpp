/****************************************************************************
** Meta object code from reading C++ file 'GameEndInterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Survivor-Game-Main/GameEndInterface.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameEndInterface.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS = QtMocHelpers::stringData(
    "GameEndInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "play_again_signal",
    "restart_game_signal",
    "get_end_type",
    "type",
    "play_again",
    "restart_game"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[18];
    char stringdata5[20];
    char stringdata6[13];
    char stringdata7[5];
    char stringdata8[11];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS_t qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "GameEndInterface"
        QT_MOC_LITERAL(17, 18),  // "changeWidgetsignal"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "Index"
        QT_MOC_LITERAL(43, 17),  // "play_again_signal"
        QT_MOC_LITERAL(61, 19),  // "restart_game_signal"
        QT_MOC_LITERAL(81, 12),  // "get_end_type"
        QT_MOC_LITERAL(94, 4),  // "type"
        QT_MOC_LITERAL(99, 10),  // "play_again"
        QT_MOC_LITERAL(110, 12)   // "restart_game"
    },
    "GameEndInterface",
    "changeWidgetsignal",
    "",
    "Index",
    "play_again_signal",
    "restart_game_signal",
    "get_end_type",
    "type",
    "play_again",
    "restart_game"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameEndInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    0,   53,    2, 0x06,    3 /* Public */,
       5,    0,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   55,    2, 0x0a,    5 /* Public */,
       8,    0,   58,    2, 0x0a,    7 /* Public */,
       9,    0,   59,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameEndInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameEndInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameEndInterface, std::true_type>,
        // method 'changeWidgetsignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'play_again_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restart_game_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_end_type'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'play_again'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restart_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameEndInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameEndInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeWidgetsignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->play_again_signal(); break;
        case 2: _t->restart_game_signal(); break;
        case 3: _t->get_end_type((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->play_again(); break;
        case 5: _t->restart_game(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameEndInterface::*)(int );
            if (_t _q_method = &GameEndInterface::changeWidgetsignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameEndInterface::*)();
            if (_t _q_method = &GameEndInterface::play_again_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameEndInterface::*)();
            if (_t _q_method = &GameEndInterface::restart_game_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *GameEndInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameEndInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameEndInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameEndInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GameEndInterface::changeWidgetsignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameEndInterface::play_again_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameEndInterface::restart_game_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
