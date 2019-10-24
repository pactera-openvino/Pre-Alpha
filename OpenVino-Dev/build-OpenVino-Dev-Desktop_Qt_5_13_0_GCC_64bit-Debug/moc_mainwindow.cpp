/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OpenVino-Dev/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_MainWindow_destroyed"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "closeEvent"
QT_MOC_LITERAL(4, 47, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 60, 5), // "event"
QT_MOC_LITERAL(6, 66, 11), // "acceptImage"
QT_MOC_LITERAL(7, 78, 3), // "msg"
QT_MOC_LITERAL(8, 82, 15), // "acceptTotalFace"
QT_MOC_LITERAL(9, 98, 7), // "FaceNum"
QT_MOC_LITERAL(10, 106, 14), // "acceptFaceInfo"
QT_MOC_LITERAL(11, 121, 9), // "Face::Ptr"
QT_MOC_LITERAL(12, 131, 4), // "face"
QT_MOC_LITERAL(13, 136, 11), // "ImageFaceId"
QT_MOC_LITERAL(14, 148, 17), // "acceptupdatechart"
QT_MOC_LITERAL(15, 166, 7), // "malenum"
QT_MOC_LITERAL(16, 174, 9), // "femalenum"
QT_MOC_LITERAL(17, 184, 15), // "acceptinittable"
QT_MOC_LITERAL(18, 200, 11), // "TotalRecord"
QT_MOC_LITERAL(19, 212, 16), // "personAttribute*"
QT_MOC_LITERAL(20, 229, 9), // "pAttTotal"
QT_MOC_LITERAL(21, 239, 17), // "acceptupdatetable"
QT_MOC_LITERAL(22, 257, 4), // "pAtt"
QT_MOC_LITERAL(23, 262, 24), // "on_VisitorButton_clicked"
QT_MOC_LITERAL(24, 287, 24), // "on_VisitorButton_pressed"
QT_MOC_LITERAL(25, 312, 24), // "on_MeetingButton_clicked"
QT_MOC_LITERAL(26, 337, 20) // "on_LabButton_clicked"

    },
    "MainWindow\0on_MainWindow_destroyed\0\0"
    "closeEvent\0QCloseEvent*\0event\0acceptImage\0"
    "msg\0acceptTotalFace\0FaceNum\0acceptFaceInfo\0"
    "Face::Ptr\0face\0ImageFaceId\0acceptupdatechart\0"
    "malenum\0femalenum\0acceptinittable\0"
    "TotalRecord\0personAttribute*\0pAttTotal\0"
    "acceptupdatetable\0pAtt\0on_VisitorButton_clicked\0"
    "on_VisitorButton_pressed\0"
    "on_MeetingButton_clicked\0on_LabButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
      10,    2,   84,    2, 0x08 /* Private */,
      14,    2,   89,    2, 0x08 /* Private */,
      17,    2,   94,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,
      23,    0,  102,    2, 0x08 /* Private */,
      24,    0,  103,    2, 0x08 /* Private */,
      25,    0,  104,    2, 0x08 /* Private */,
      26,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QImage,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19,   18,   20,
    QMetaType::Void, 0x80000000 | 19,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_MainWindow_destroyed(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->acceptImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->acceptTotalFace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->acceptFaceInfo((*reinterpret_cast< Face::Ptr(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->acceptupdatechart((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->acceptinittable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< personAttribute*(*)>(_a[2]))); break;
        case 7: _t->acceptupdatetable((*reinterpret_cast< personAttribute*(*)>(_a[1]))); break;
        case 8: _t->on_VisitorButton_clicked(); break;
        case 9: _t->on_VisitorButton_pressed(); break;
        case 10: _t->on_MeetingButton_clicked(); break;
        case 11: _t->on_LabButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
