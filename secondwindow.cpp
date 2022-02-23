#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <QSslSocket>


QString cur_date();

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{

    MainWindow w;
    //std::cout << cur_date().toStdString();
    QString cd = cur_date();
    QSqlDatabase db = w.connect_To_Sql();
    db.open();


    int lessons = 0;


    ui->setupUi(this);
    ui->groupBox->hide();
    setWindowFlags(Qt::Window);

    //Физкультура Литература Русский язык Физика Информатика Английский язык Алгебра История Геометрия Химия Биология ОБЖ Астрономия
    int heightLW = ui->listWidget->height(), widthLW = ui->listWidget->width();


    if(cd.toStdString() == "понедельник") {
        QSqlQuery query ("SELECT * FROM monday");
        lessons = 6;

        while(query.next()) {
            for(int i = 0; i < lessons; i++) {
                QString lesson = query.value(i).toString();
                QString UrlF = ":/img/Subjects_Pic/";
                UrlF.append(lesson);
                UrlF.append(".jpg");
                //std::cout << UrlF.toStdString();
                /*QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                ui->listWidget->addItem(item_1);
                UrlF = "";*/
                ui->listWidget->addItem(lesson);
            }

        }

        //int height = 1080/(lessons + 1);
        //QSize size(64, height);
        //ui->listWidget->setGridSize(size);

    }
     else if(cd.toStdString() == "вторник") {
         QSqlQuery query ("SELECT * FROM tuesday");
         lessons = 6;

         while(query.next()) {
             for(int i = 0; i < lessons; i++) {
                 QString lesson = query.value(i).toString();
                 QString UrlF = ":/img/Subjects_Pic/";
                 UrlF.append(lesson);
                 UrlF.append(".jpg");
                 //std::cout << UrlF.toStdString();
                 QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                 ui->listWidget->addItem(item_1);
                 UrlF = "";
             }

         }

         int height = 1080/(lessons + 1);
         QSize size(64, height);
         ui->listWidget->setGridSize(size);

     }
     else if(cd.toStdString() == "среда") {
         QSqlQuery query ("SELECT * FROM wednesday");
         lessons = 5;


         while(query.next()) {
             for(int i = 0; i < lessons; i++) {
                 QString lesson = query.value(i).toString();
                 QString UrlF = ":/img/Subjects_Pic/";
                 UrlF.append(lesson);
                 UrlF.append(".jpg");
                 //std::cout << UrlF.toStdString();
                 QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                 ui->listWidget->addItem(item_1);
                 UrlF = "";
             }

         }
         int height = 1080/(lessons + 1);
         QSize size(64, height);
         ui->listWidget->setGridSize(size);

     }
     else if(cd.toStdString() == "четверг") {
         QSqlQuery query ("SELECT * FROM thursday");
         lessons = 6;

         while(query.next()) {
             for(int i = 0; i < lessons; i++) {
                 QString lesson = query.value(i).toString();
                 QString UrlF = ":/img/Subjects_Pic/";
                 UrlF.append(lesson);
                 UrlF.append(".jpg");
                 //std::cout << UrlF.toStdString();
                 QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                 ui->listWidget->addItem(item_1);

                 UrlF = "";

             }

         }


         int height = 1080/(lessons + 1);
         QSize size(64, height);
         ui->listWidget->setGridSize(size);



     }
     else if(cd.toStdString() == "пятница") {
         QSqlQuery query ("SELECT * FROM friday");
         lessons = 6;
         int height = 1080/(lessons + 1);
         QSize size(64, height);
         ui->listWidget->setGridSize(size);

         while(query.next()) {
             for(int i = 0; i < lessons; i++) {
                 QString lesson = query.value(i).toString();
                 QString UrlF = ":/img/Subjects_Pic/";
                 UrlF.append(lesson);
                 UrlF.append(".jpg");
                 //std::cout << UrlF.toStdString();
                 QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                 ui->listWidget->addItem(item_1);
                 UrlF = "";
             }

         }

     }
     else if(cd.toStdString() == "суббота") {
         QSqlQuery query ("SELECT * FROM saturday");
         lessons = 5;
         int height = 1080/(lessons + 1);
         QSize size(64, height);
         ui->listWidget->setGridSize(size);
         while(query.next()) {
             for(int i = 0; i < lessons; i++) {
                 QString lesson = query.value(i).toString();
                 QString UrlF = ":/img/Subjects_Pic/";
                 UrlF.append(lesson);
                 UrlF.append(".jpg");
                 //std::cout << UrlF.toStdString();
                 QListWidgetItem *item_1 = new QListWidgetItem(QIcon(UrlF), lesson);
                 ui->listWidget->addItem(item_1);
                 UrlF = "";
             }

         }
     }


    QVBoxLayout *mainLayout = new QVBoxLayout(this);

       QToolBar *toolBar = new QToolBar();
       mainLayout->addWidget(toolBar);

    toolBar->addAction(ui->widget->pageAction(QWebEnginePage::Back));
    toolBar->addAction(ui->widget->pageAction(QWebEnginePage::Forward));
    toolBar->addAction(ui->widget->pageAction(QWebEnginePage::Reload));
    toolBar->addAction(ui->widget->pageAction(QWebEnginePage::Stop));
    toolBar->addWidget(locationEdit);
    layout()->setMenuBar(toolBar);


    setAttribute(Qt::WA_DeleteOnClose, true);
    progress = 0;
    QSslError();
    QFile file;
    file.setFileName(":/jquery.min.js");
    file.open(QIODevice::ReadOnly);
    jQuery = file.readAll();
    jQuery.append("\nvar qt = { 'jQuery': jQuery.noConflict(true) };");
    file.close();



    QUrl url("http://fordus.org.ua");

    ui->widget->load(url);

    connect(ui->widget, &QWebEngineView::loadFinished, this, &SecondWindow::adjustLocation);
    connect(ui->widget, &QWebEngineView::titleChanged, this, &SecondWindow::adjustTitle);
    connect(ui->widget, &QWebEngineView::loadProgress, this, &SecondWindow::setProgress);
    connect(ui->widget, &QWebEngineView::loadFinished, this, &SecondWindow::finishLoading);

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    locationEdit->setText(url.toString());
    connect(locationEdit, &QLineEdit::returnPressed, this, &SecondWindow::changeLocation);
    toolBar->addWidget(locationEdit);


    rotateAction = new QAction(this);
    rotateAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    rotateAction->setCheckable(true);
    rotateAction->setText(tr("Turn images upside down"));
    connect(rotateAction, &QAction::toggled, this, &SecondWindow::rotateImages);





}
void SecondWindow::adjustLocation()
{
    locationEdit->setText(ui->widget->url().toString());
}

void SecondWindow::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    ui->widget->load(url);
    ui->widget->setFocus();
}

void SecondWindow::adjustTitle()
{
    if (progress <= 0 || progress >= 100)
        setWindowTitle(ui->widget->title());
    else
        setWindowTitle(QStringLiteral("%1 (%2%)").arg(ui->widget->title()).arg(progress));
}

void SecondWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
}

void SecondWindow::finishLoading(bool)
{
    progress = 100;
    adjustTitle();
    ui->widget->page()->runJavaScript(jQuery);

    rotateImages(rotateAction->isChecked());
}
void SecondWindow::rotateImages(bool invert)
{
    QString code;

    if (invert)
        code = QStringLiteral("qt.jQuery('img').each( function () { qt.jQuery(this).css('transition', 'transform 2s'); qt.jQuery(this).css('transform', 'rotate(180deg)') } )");
    else
        code = QStringLiteral("qt.jQuery('img').each( function () { qt.jQuery(this).css('transition', 'transform 2s'); qt.jQuery(this).css('transform', 'rotate(0deg)') } )");
    ui->widget->page()->runJavaScript(code);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

//Получаем текущий день недели
QString cur_date() {

    QString date;
    date = QDate::currentDate().toString("dddd");
    return date;
}


void SecondWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QMessageBox msgBox;
    QString TeacherName;

    ui->widget->hide();
    ui->groupBox->show();
    ui->groupBox->setTitle("Lesson");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1"); // или, например, "my1.server.ru"
    db.setPort(3310);
    db.setDatabaseName("11M");
    db.setUserName("root");
    db.setPassword("");
    bool connected = db.open();
    /*if (!connected) {

        QMessageBox::information(this, "Connect", "Connect not successfull");
    }
    else {
        QMessageBox::information(this, "Connect", "Connect successfull");
    }
    */

    //std::cout << item->text().toStdString();

    QString l = item->text();
    QString teachername;

    QSqlQuery query;
    query.prepare("SELECT `Teacher` FROM Teachers WHERE `Lesson` = :lesson_name");
    query.bindValue(":lesson_name", l);
    query.exec();
    while(query.next()) {
        teachername = query.value(0).toString();
    }

    ui->label->setText(teachername);
    QString f = ":/Teachers_photo/Teachers_Photo/" + l + ".jpg";
    QPixmap pix(f);
    QSize s = ui->label_2->size();

    ui->label_2->setPixmap(pix);
}

void SecondWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1"); // или, например, "my1.server.ru"
    db.setPort(3310);
    db.setDatabaseName("11M");
    db.setUserName("root");
    db.setPassword("");
    bool connected = db.open();
    QString lesson;

    QSqlQuery query;
    query.prepare("SELECT `Lesson` FROM Teachers WHERE `Teacher` = :teacher_name");
    query.bindValue(":teacher_name", ui->label->text());
    query.exec();
    while(query.next()) {
        lesson = query.value(0).toString();
    }

    ui->groupBox->hide();
    QString url = "https://localhost:3010/room/" + lesson  + "/";
    QUrl q(url);
    ui->widget->setUrl(q);
    ui->widget->show();

}
