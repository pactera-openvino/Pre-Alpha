#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QImage"
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QtCharts>

#include "opencv2/opencv.hpp"

#include "visitor.h"
#include "database.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItemModel* TotalTableModel = new QStandardItemModel(this);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void ReadFrame();
    void on_MainWindow_destroyed();
    void closeEvent( QCloseEvent * event );

    void acceptImage(QImage msg);//接收从访客识别线程发送的图像的槽函数， 接受到图像后用于显示
    void acceptTotalFace(int FaceNum);
    void acceptFaceInfo(Face::Ptr face , int ImageFaceId);//接收访客线程发送的脸部信息的槽函数，可根据信息显示 , ImageFaceId此参数表示这是这张图像中的第几人的id
    void acceptupdatechart(int malenum , int femalenum);
    void acceptinittable(int TotalRecord , struct personAttribute *pAttTotal);
    void acceptupdatetable(struct personAttribute *pAtt);

    void on_VisitorButton_clicked();

    void on_VisitorButton_pressed();

    void on_MeetingButton_clicked();

    void on_LabButton_clicked();

private:

    Ui::MainWindow *ui;

    VisitorThread *Visitor_thread;   //定义线程类型指针

    //cv::VideoCapture cap;

    int scene;
    QRect WidgetPos;/* 用来记录窗口位置，用于按键恢复到默认（非全屏）状态 */

    int FullScreen;
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

    QPieSeries *series;
};



#endif // MAINWINDOW_H
