/********************************************************************************
** Form generated from reading UI file 'reg_face.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_FACE_H
#define UI_REG_FACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *frame_label;
    QPushButton *takePic;
    QLineEdit *FileName;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(360, 300);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        frame_label = new QLabel(Dialog);
        frame_label->setObjectName(QString::fromUtf8("frame_label"));
        frame_label->setGeometry(QRect(65, 30, 230, 170));
        takePic = new QPushButton(Dialog);
        takePic->setObjectName(QString::fromUtf8("takePic"));
        takePic->setGeometry(QRect(230, 250, 89, 25));
        FileName = new QLineEdit(Dialog);
        FileName->setObjectName(QString::fromUtf8("FileName"));
        FileName->setGeometry(QRect(100, 250, 113, 25));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 253, 81, 17));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        frame_label->setText(QString());
        takePic->setText(QCoreApplication::translate("Dialog", "\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\247\223\345\220\215(\350\213\261\346\226\207)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_FACE_H
