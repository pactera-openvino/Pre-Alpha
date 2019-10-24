#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

#include <functional>
#include <iostream>
#include <fstream>
#include <random>
#include <memory>
#include <chrono>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iterator>
#include <map>
#include <list>
#include <set>
#include <QThread>

#include <inference_engine.hpp>

#include "database.hpp"

using namespace std;

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setStyleSheet("QMainWindow{border-image: url(:/bt_ico/image/OneVINO_Main.png);}");

    ui->label_video->setScaledContents(true);

    ui->VisitorButton->setStyleSheet("QToolButton{border-image: url(:/bt_ico/image/visitor_normal.png);}"
                                  "QToolButton:pressed{border-image: url(:/bt_ico/image/visitor_pressed.png);}");

    ui->MeetingButton->setStyleSheet("QToolButton{border-image: url(:/bt_ico/image/meeting_normal.png);}"
                                    "QToolButton:pressed{border-image: url(:/bt_ico/image/meeting_Pressed.png);}");

    ui->LabButton->setStyleSheet("QToolButton{border-image: url(:/bt_ico/image/lab_normal.png);}"
                                    "QToolButton:pressed{border-image: url(:/bt_ico/image/lab_Pressed.png);}");

    ui->DeviceChoice->addItem("CPU");
    ui->DeviceChoice->addItem("VPU");
    ui->DeviceChoice->addItem("GPU");
    ui->DeviceChoice->addItem("FPGA");
    //设置列字段名
    model->setColumnCount(8);//使用默认的1/2/3....
    //设置行字段名
    model->setRowCount(4);
    model->setHeaderData(0,Qt::Vertical, "ID");
    model->setHeaderData(1,Qt::Vertical, "性别");
    model->setHeaderData(2,Qt::Vertical, "年龄");
    model->setHeaderData(3,Qt::Vertical, "情绪");

    //设置一条数据/
    /*model->setItem(0, 0, new QStandardItem("张三"));
    model->setItem(0, 1, new QStandardItem("3"));
    model->setItem(0, 2, new QStandardItem("男"));*/

    //model->clear();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);

    QChart* chart = new QChart();

    //QPieSeries *series = new QPieSeries();
    series = new QPieSeries();
    series->append("男性", 0);
    series->append("女性", 0);

    series->setPieSize(1);
    //chart->setTitle("abcd");
    // 将系列添加到图表
    chart->addSeries(series);
    chart->layout()->setContentsMargins(0, 0, 0, 0);//设置外边界全部为0
    chart->setMargins(QMargins(0, 0, 0, 0));//设置内边界全部为0
    chart->setBackgroundRoundness(0);//设置背景区域无圆角->setBackgroundRoundness(0);//设置背景区域无圆角
    // 基于已添加到图表的 series 来创建默认的坐标轴
    chart->createDefaultAxes();

    chart->setAutoFillBackground(true);
/*
    QPieSlice *slice_red =series->slices().at(0);//可通过QPieSlice设置单项数据
    slice_red->setValue(20);

    QPieSlice *slice_remaile =series->slices().at(1);
    slice_remaile->setValue(200);
    */

    // 将图表绑定到视图
    ui->widget_test->setRenderHint(QPainter::Antialiasing);//设置抗锯齿，看起来更平滑（不明显）
    ui->widget_test->setChart(chart);
    ui->widget_test->setAutoFillBackground(true);



    QLabel* statusLabel = new QLabel;
    statusLabel->setText("文思海辉");
    ui->statusBar->addPermanentWidget(statusLabel);


    ui->statusBar->showMessage("abcedeads" ,3000);
    //msleep(500);
    ui->statusBar->showMessage("" ,3000);
    //model->setColumnCount(8);

/*
    QStringList strList;
    strList.append("ab");

    QStandardItemModel *ItemModel;
    ItemModel = new QStandardItemModel(this);

    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
       QString string = static_cast<QString>(strList.at(i));
       QStandardItem *item = new QStandardItem(string);
       ItemModel->appendRow(item);
    }*/

    // ui->textEdit->setText("123");
     //ui->textEdit->append("ccc");
     //ui->textEdit->clear();
    // ui->textEdit->append("asd");


   // ui->realtimelist->setEditTriggers(QAbstractItemView::NoEditTriggers);// 去掉listview 可双击修改的事件
    // ui->TotalList->setEditTriggers(QAbstractItemView::NoEditTriggers);// 去掉listview 可双击修改的事件
    //connect(&timer,SIGNAL(timeout()),this,SLOT(ReadFrame()));

    //QImage image = QImage(":/bt_ico/image/UI_main_1_1.png");
    //ui->label_video->setPixmap(QPixmap::fromImage(image));

    qRegisterMetaType<Face::Ptr>("Face::Ptr");//注册Face::Ptr,不然在connect的时候会出错

    /*
    WidgetPos = geometry();
    setWindowFlags(Qt::Window);
    //showFullScreen();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MainWindow_destroyed()
{
    std::cout<< "closed" <<std::endl;
}

void MainWindow::closeEvent( QCloseEvent * event )//关闭窗口会先处理该事件函数
{
    std::cout << "end thread" << std::endl;
    Visitor_thread->stop();
    std::cout << "closed and clear resources" <<std::endl;
}

/* 接收从VisitorThread线程发送过来的图像数据进行线索 */
void MainWindow::acceptImage(QImage msg)
{
    this->ui->label_video->setPixmap(QPixmap::fromImage(msg));
}

/* 接收从VisitorThread面部信息进行显示 */
void MainWindow::acceptFaceInfo(Face::Ptr face , int ImageFaceId)
{
   // this->model->setItem(0, ImageFaceId, new QStandardItem(QString::number(face->getId() , 10)));
    this->model->setItem(0, ImageFaceId, new QStandardItem(QString::fromStdString(face->getfacename())));
    this->model->setItem(1, ImageFaceId, new QStandardItem(face->isMale()?"男":"女"));
    this->model->setItem(2, ImageFaceId, new QStandardItem(QString::number(face->getAge() , 10)));

    auto emotion = face->getMainEmotion();
    this->model->setItem(3, ImageFaceId, new QStandardItem(emotion.first.data()));
}

void MainWindow::acceptTotalFace(int FaceNum)
{
    model->setColumnCount(FaceNum);//修改QTableView的为实际数量
}

void MainWindow::acceptupdatechart(int malenum , int femalenum)
{
    QPieSlice *slice_male =series->slices().at(0);//可通过QPieSlice设置单项数据
    slice_male->setValue(malenum);

    QPieSlice *slice_female =series->slices().at(1);//可通过QPieSlice设置单项数据
    slice_female->setValue(femalenum);
}

void MainWindow::acceptinittable(int TotalRecord , struct personAttribute *pAttTotal)
{
    /* 总表显示姓名/年龄/性别/时间 */
    TotalTableModel->setColumnCount(4);//使用默认的1/2/3....

    QStringList labels = QObject::trUtf8("姓名,年龄,性别,时间").simplified().split(",");
    TotalTableModel->setHorizontalHeaderLabels(labels);
    //设置行字段名
    TotalTableModel->setRowCount(TotalRecord);

    //model->clear();
    ui->TotalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TotalTable->setModel(TotalTableModel);
    ui->TotalTable->setShowGrid(false);

    for(int i=0;i<TotalRecord;i++)
    {
        this->TotalTableModel->setItem(i , 0 ,new QStandardItem(QString::fromStdString(pAttTotal[i].name)));
        this->TotalTableModel->setItem(i , 1 ,new QStandardItem(QString::number(pAttTotal[i].age  , 10)));
        this->TotalTableModel->setItem(i , 2 ,new QStandardItem(QString::fromStdString(pAttTotal[i].sex)));
        this->TotalTableModel->setItem(i , 3 ,new QStandardItem(QString::fromStdString(pAttTotal[i].time)));
    }
}

void MainWindow::acceptupdatetable(struct personAttribute *pAtt)
{
    int row_count = TotalTableModel->rowCount();
    row_count = row_count+1;

    std::cout << "update tablle.................." << std::endl;

    this->TotalTableModel->setItem(row_count-1 , 0 ,new QStandardItem(QString::fromStdString(pAtt->name)));
    this->TotalTableModel->setItem(row_count-1 , 1 ,new QStandardItem(QString::number(pAtt->age  , 10)));
    this->TotalTableModel->setItem(row_count-1 , 2 ,new QStandardItem(QString::fromStdString(pAtt->sex)));
    this->TotalTableModel->setItem(row_count-1 , 3 ,new QStandardItem(QString::fromStdString(pAtt->time)));
}

void MainWindow::on_VisitorButton_clicked()
{
    if(scene != 0)
    {
        /*其他场景正在运行，停止其他场景*/
    }

    scene = 1;
    //this->ui->VisitorButton->setChecked(false);
    this->ui->VisitorButton->setDown(false);
    this->ui->MeetingButton->setDown(true);
    this->ui->LabButton->setDown(true);

   // this->ui->VisitorButton->setStyle();
    //添加到按键事件里面
    Visitor_thread = new (VisitorThread);
    Visitor_thread->start();

    QObject::connect(Visitor_thread, SIGNAL(sendImage(QImage)), this, SLOT(acceptImage(QImage)));//连接信号与槽
    QObject::connect(Visitor_thread, SIGNAL(sendFaceInfo(Face::Ptr , int)), this, SLOT(acceptFaceInfo(Face::Ptr , int)));//连接信号与槽
    QObject::connect(Visitor_thread, SIGNAL(sendTotalFace(int)), this, SLOT(acceptTotalFace(int)));//连接信号与槽
    QObject::connect(Visitor_thread, SIGNAL(updatechart(int , int)), this, SLOT(acceptupdatechart(int , int)));//连接信号与槽
    QObject::connect(Visitor_thread, SIGNAL(inittable(int , struct personAttribute *)), this, SLOT(acceptinittable(int , struct personAttribute *)));//连接信号与槽
    QObject::connect(Visitor_thread, SIGNAL(updatetable(struct personAttribute *)), this, SLOT(acceptupdatetable(struct personAttribute *)));//连接信号与槽
}



void MainWindow::on_VisitorButton_pressed()
{
}

void MainWindow::on_MeetingButton_clicked()
{
    if(scene != 0)
    {
        /*其他场景正在运行，停止其他场景*/
        Visitor_thread->stop();
    }
    scene = 2;
    this->ui->MeetingButton->setDown(false);
    this->ui->VisitorButton->setDown(true);
    this->ui->LabButton->setDown(true);
}

void MainWindow::on_LabButton_clicked()
{
    if(scene != 0)
    {
        /*其他场景正在运行，停止其他场景*/
        Visitor_thread->stop();
    }
    scene = 3;
    this->ui->LabButton->setDown(false);
    this->ui->VisitorButton->setDown(true);
    this->ui->MeetingButton->setDown(true);

    this->ui->MeetingButton->setStatusTip("Pressed");
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{

    QWidget::keyPressEvent(ev);
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_F2)
    {
        if(FullScreen)
        {
            FullScreen = 0;
            this->setWindowFlags(Qt::SubWindow);
            this->showNormal();
            //this->setGeometry(WidgetPos);

            qDebug("out fullscreen");
        }
        else {
            FullScreen = 1;
            WidgetPos = this->geometry();//记录widget位置，恢复时使用
            this->setWindowFlags(Qt::Window);
            this->showFullScreen();
            qDebug("enter fullscreen");
        }

    }
    QWidget::keyReleaseEvent(ev);
}
