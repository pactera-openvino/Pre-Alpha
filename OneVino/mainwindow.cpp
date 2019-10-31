#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

#include <QDebug>
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
#include <QMessageBox>

#include "reg_face.h"
#include "visitor.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reg_button_clicked()
{
    std::cout << "Get Video Width/Height!!!!!!!!" << std::endl;
    //setStyleSheet("QMainWindow{border-image: url(:/bt/image/Login_bg_point.png);}");
    Dialog dialog;
    if(dialog.exec() != QDialog::Accepted)//如果是取消就返回
    {
        return;
    }
}

void MainWindow::on_meeting_bt_clicked()
{
    QMessageBox::information(this, "提示", "开发中，敬请期待!!!",QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_lab_bt_clicked()
{
    QMessageBox::information(this, "提示", "开发中，敬请期待!!!",QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_visitor_bt_clicked()
{
    Visitor dialog;
    dialog.setWindowModality(Qt::ApplicationModal);
    if(dialog.exec() != Visitor::Accepted)//如果是取消就返回
    {
        return;
    }
}
