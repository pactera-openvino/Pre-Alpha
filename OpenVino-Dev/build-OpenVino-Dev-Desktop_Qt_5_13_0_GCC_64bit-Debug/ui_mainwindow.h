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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QComboBox *DeviceChoice;
    QSpacerItem *verticalSpacer_2;
    QToolButton *VisitorButton;
    QToolButton *MeetingButton;
    QToolButton *LabButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_video;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QTableView *TotalTable;
    QChartView *widget_test;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1083, 618);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8("alternate-background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:2, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(-1, 0, 0, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        DeviceChoice = new QComboBox(centralWidget);
        DeviceChoice->setObjectName(QString::fromUtf8("DeviceChoice"));
        DeviceChoice->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));

        verticalLayout_3->addWidget(DeviceChoice);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        VisitorButton = new QToolButton(centralWidget);
        VisitorButton->setObjectName(QString::fromUtf8("VisitorButton"));
        sizePolicy.setHeightForWidth(VisitorButton->sizePolicy().hasHeightForWidth());
        VisitorButton->setSizePolicy(sizePolicy);
        VisitorButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(VisitorButton);

        MeetingButton = new QToolButton(centralWidget);
        MeetingButton->setObjectName(QString::fromUtf8("MeetingButton"));
        sizePolicy.setHeightForWidth(MeetingButton->sizePolicy().hasHeightForWidth());
        MeetingButton->setSizePolicy(sizePolicy);
        MeetingButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(MeetingButton);

        LabButton = new QToolButton(centralWidget);
        LabButton->setObjectName(QString::fromUtf8("LabButton"));
        sizePolicy.setHeightForWidth(LabButton->sizePolicy().hasHeightForWidth());
        LabButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(LabButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(2, 2);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 1);
        verticalLayout_3->setStretch(5, 1);
        verticalLayout_3->setStretch(6, 5);

        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_video = new QLabel(centralWidget);
        label_video->setObjectName(QString::fromUtf8("label_video"));
        sizePolicy.setHeightForWidth(label_video->sizePolicy().hasHeightForWidth());
        label_video->setSizePolicy(sizePolicy);
        label_video->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_video);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TotalTable = new QTableView(centralWidget);
        TotalTable->setObjectName(QString::fromUtf8("TotalTable"));

        verticalLayout_2->addWidget(TotalTable);

        widget_test = new QChartView(centralWidget);
        widget_test->setObjectName(QString::fromUtf8("widget_test"));
        sizePolicy.setHeightForWidth(widget_test->sizePolicy().hasHeightForWidth());
        widget_test->setSizePolicy(sizePolicy);
        widget_test->setAutoFillBackground(true);
        widget_test->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(widget_test);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 3);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OneVINO", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\351\200\211\346\213\251", nullptr));
        VisitorButton->setText(QString());
        MeetingButton->setText(QString());
        LabButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_video->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
