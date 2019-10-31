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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_video;
    QListWidget *listWidget;
    QLabel *label;
    QWidget *widget;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1083, 609);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        label_video = new QLabel(centralWidget);
        label_video->setObjectName(QString::fromUtf8("label_video"));
        label_video->setGeometry(QRect(80, 10, 781, 411));
        sizePolicy.setHeightForWidth(label_video->sizePolicy().hasHeightForWidth());
        label_video->setSizePolicy(sizePolicy);
        label_video->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(880, 30, 191, 391));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(880, 430, 191, 161));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 61, 611));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(0, 30, 64, 64));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(0, 0));
        toolButton->setAutoFillBackground(false);
        toolButton->setStyleSheet(QString::fromUtf8("border-image: url(:/bt_ico/image/123.png);"));
        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(0, 150, 64, 64));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 90, 64, 61));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 220, 61, 36));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(80, 430, 781, 171));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_video->setText(QCoreApplication::translate("MainWindow", "video_disp_place", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\256\277\345\256\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
