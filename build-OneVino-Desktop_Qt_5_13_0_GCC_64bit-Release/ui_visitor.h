/********************************************************************************
** Form generated from reading UI file 'visitor.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITOR_H
#define UI_VISITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_Visitor
{
public:
    QLabel *label;
    QLabel *video;
    QLabel *label_3;
    QTableView *DetailView;
    QLabel *label_4;
    QTableView *TotalView;
    QLabel *label_5;
    QLabel *label_6;
    QChartView *SexChart;
    QChartView *EmChart;

    void setupUi(QDialog *Visitor)
    {
        if (Visitor->objectName().isEmpty())
            Visitor->setObjectName(QString::fromUtf8("Visitor"));
        Visitor->resize(1920, 1200);
        QFont font;
        font.setPointSize(33);
        Visitor->setFont(font);
        Visitor->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);"));
        label = new QLabel(Visitor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 56));
        label->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 33pt \"Ubuntu\";"));
        label->setScaledContents(false);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        video = new QLabel(Visitor);
        video->setObjectName(QString::fromUtf8("video"));
        video->setGeometry(QRect(0, 56, 1200, 800));
        video->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        label_3 = new QLabel(Visitor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 856, 1200, 54));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 30pt \"Ubuntu\";"));
        DetailView = new QTableView(Visitor);
        DetailView->setObjectName(QString::fromUtf8("DetailView"));
        DetailView->setGeometry(QRect(0, 910, 1200, 250));
        DetailView->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));
        label_4 = new QLabel(Visitor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1200, 56, 691, 56));
        label_4->setStyleSheet(QString::fromUtf8("font: 33pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        TotalView = new QTableView(Visitor);
        TotalView->setObjectName(QString::fromUtf8("TotalView"));
        TotalView->setGeometry(QRect(1200, 112, 720, 744));
        TotalView->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));
        label_5 = new QLabel(Visitor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1200, 856, 360, 54));
        label_5->setStyleSheet(QString::fromUtf8("font: 30pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        label_6 = new QLabel(Visitor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1560, 856, 360, 54));
        label_6->setStyleSheet(QString::fromUtf8("font: 30pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        SexChart = new QChartView(Visitor);
        SexChart->setObjectName(QString::fromUtf8("SexChart"));
        SexChart->setGeometry(QRect(1200, 910, 360, 250));
        SexChart->setStyleSheet(QString::fromUtf8(""));
        EmChart = new QChartView(Visitor);
        EmChart->setObjectName(QString::fromUtf8("EmChart"));
        EmChart->setGeometry(QRect(1560, 910, 360, 250));
        EmChart->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Visitor);

        QMetaObject::connectSlotsByName(Visitor);
    } // setupUi

    void retranslateUi(QDialog *Visitor)
    {
        Visitor->setWindowTitle(QCoreApplication::translate("Visitor", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Visitor", "OneVino", nullptr));
        video->setText(QString());
        label_3->setText(QCoreApplication::translate("Visitor", "\347\211\271\345\276\201\350\257\206\345\210\253\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("Visitor", "\350\257\206\345\210\253\344\277\241\346\201\257\347\273\237\350\256\241", nullptr));
        label_5->setText(QCoreApplication::translate("Visitor", "\346\200\247\345\210\253\347\216\207", nullptr));
        label_6->setText(QCoreApplication::translate("Visitor", "\350\241\250\346\203\205\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visitor: public Ui_Visitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITOR_H
