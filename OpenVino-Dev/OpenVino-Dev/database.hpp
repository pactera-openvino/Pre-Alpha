#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVariantList>
#include <QSqlRecord>
#include <QSqlQueryModel>

using namespace std;

#define   ON               1
#define   OFF              0

#define   DEBUG_MODE       0
#define   PERSONTABLE      "humanTable"

static QSqlDatabase db;
static char qTBuffer[256] = {0};

enum RETVALUE{
    SUCC=0,
    FAIL,
    EXIST,
    OTHER,
};

typedef struct personAttribute
{
    int id;
    string name;
    string sex;
    int age;
    string expression;
    string clothcolor;
    string hair;
    string glass;
    string sleeves;
    string time;
}personAttributestr;

//struct personAttribute perAtrrArray[100];

typedef struct qryCond
{
    string startTime;
    string endTime;
    int    startAddr;
    int    dataLenth;
    char   flag;
}qryCondstr;

extern int QueryVistorsNum(struct personAttribute *perAttrPt, string str, struct qryCond *qryPt);
extern int QueryTableAccordingTime(struct personAttribute *perAttrPt, string str, struct qryCond *qryPt);
extern int QueryTotalPerson(string str, string type);
extern enum RETVALUE AddOnePersonAttribute(struct personAttribute *pt, string str);
extern enum RETVALUE DeleteOnePersonAttribute(struct personAttribute *pt, string str);
extern enum RETVALUE QueryWholeTable(string str);
extern enum RETVALUE CreatePersonAttributeTab(string str);
extern enum RETVALUE CreateDatabaseConnectionSwitch(QSqlDatabase db, bool on_off);

#endif // DATABASE_HPP
