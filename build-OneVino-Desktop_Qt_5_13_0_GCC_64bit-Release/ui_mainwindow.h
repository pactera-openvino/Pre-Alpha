/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *reg_button;
    QPushButton *visitor_bt;
    QPushButton *meeting_bt;
    QPushButton *lab_bt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1200);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/bt/image/Login_bg_version1.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        reg_button = new QPushButton(centralWidget);
        reg_button->setObjectName(QString::fromUtf8("reg_button"));
        reg_button->setGeometry(QRect(820, 280, 269, 87));
        reg_button->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"padding:11px;\n"
"border-radius:3px;\n"
"background:transparent;"));
        reg_button->setFlat(true);
        visitor_bt = new QPushButton(centralWidget);
        visitor_bt->setObjectName(QString::fromUtf8("visitor_bt"));
        visitor_bt->setGeometry(QRect(820, 400, 269, 101));
        visitor_bt->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"padding:11px;\n"
"border-radius:3px;\n"
"background:transparent;"));
        visitor_bt->setFlat(true);
        meeting_bt = new QPushButton(centralWidget);
        meeting_bt->setObjectName(QString::fromUtf8("meeting_bt"));
        meeting_bt->setGeometry(QRect(820, 510, 269, 101));
        meeting_bt->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"padding:11px;\n"
"border-radius:3px;\n"
"background:transparent;"));
        meeting_bt->setFlat(true);
        lab_bt = new QPushButton(centralWidget);
        lab_bt->setObjectName(QString::fromUtf8("lab_bt"));
        lab_bt->setGeometry(QRect(820, 620, 269, 101));
        lab_bt->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"padding:11px;\n"
"border-radius:3px;\n"
"background:transparent;"));
        lab_bt->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OneVino", nullptr));
        reg_button->setText(QString());
        visitor_bt->setText(QString());
        meeting_bt->setText(QString());
        lab_bt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
