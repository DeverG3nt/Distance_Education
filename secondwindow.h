#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H


#include <QDialog>
#include <QListWidget>
#include <QDate>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QLocale>
#include <QTableView>
#include <QNetworkAccessManager>
#include <QToolBar>
#include <QtWidgets>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();


private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
    QString jQuery;


    QLineEdit *locationEdit;
    QAction *rotateAction;
    int progress;
protected slots:
    void adjustLocation();
    void adjustTitle();
    void viewSource();
    void changeLocation();
    void rotateImages(bool invert);
    void setProgress(int p);
    void finishLoading(bool);
};

#endif // SECONDWINDOW_H
