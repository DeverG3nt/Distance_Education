#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriverCreator>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriverPlugin>
#include <QtSql/QSqlDriverCreatorBase>
#include <QtSql/QSqlResult>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <iostream>
#include <vector>
#include <fstream>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    bool Check_Password();
    QSqlDatabase connect_To_Sql();

    bool BtnIsPressed = false;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SecondWindow *window;
};
#endif // MAINWINDOW_H
