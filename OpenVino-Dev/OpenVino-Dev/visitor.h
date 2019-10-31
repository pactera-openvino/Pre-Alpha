#ifndef VISITOR_H
#define VISITOR_H

#include <QString>
#include <QThread>  //线程相关头文件
#include <QMutex>   //互斥锁相关头文件
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


#include "detectors.hpp"
#include "face.hpp"
#include "visualizer.hpp"

#include <ie_iextension.h>
#include <ext_list.hpp>

#include "opencv2/opencv.hpp"
#include "database.hpp"

class VisitorThread :public QThread
{
    Q_OBJECT
public:
    VisitorThread();
    virtual void run();  //线程函数，新创建的线程运行该函数内容。
    void stop();     //停止线程

    void UpdateTotalTable_TimeOut(void);
signals:
    void sendImage(QImage msg); //发送信号
    void sendTotalFace( int FaceNum); //发送信号
    void sendFaceInfo(Face::Ptr face , int ImageFaceId); //发送信号

    void updatechart(int malenum , int femalenum); //发送信号
    void inittable(int TotalRecord , struct personAttribute *pAttTotal); //初始化右侧列表框，发送数据更新右侧列表框
    void updatetable(struct personAttribute *pAtt);
private:
    bool VisitorRunning;   //运行标志
    QMutex mutex;    //互斥锁

    cv::VideoCapture cap;
    QTimer *updatetabletimer;
};

#endif // VISITOR_H
