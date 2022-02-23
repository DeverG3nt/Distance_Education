#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->lineEdit->setText("123Penis");
    std::ifstream fin("./.last_name.txt");
    std::string log, password;
    std::string str;
    setFixedSize(800, 600);

    while(!fin.eof()) {
        fin >> str;
    }
    //std::cout << str;
    int pos_;
    for(int i = 0; i < str.length(); i++)
        if(str[i] == ':')
            pos_ = i;

    for(int i = 0; i <= str.length(); i++) {
        if(i < pos_)
            log += str[i];
        else if(i > pos_)
            password += str[i];
        else if(i == pos_)
            continue;

    }

    QString Pass_QSTR, Log_QSTR;

    for(int i = 0, j = 0; i < log.length(), j < password.length(); i++, j++) {
        if(j < password.length() - 1)
            Pass_QSTR += password[j];

        if(i < log.length())
            Log_QSTR += log[i];


    }

    QTextStream out(stdout);
    //out << Log_QSTR << " " << Pass_QSTR;



    QSqlDatabase dab = QSqlDatabase::addDatabase("QMYSQL");

    dab.setHostName("127.0.0.1"); // или, например, "my1.server.ru"
    dab.setPort(3310);
    dab.setDatabaseName("11M");
    dab.setUserName("root");
    dab.setPassword("");
    bool connected = dab.open();
    /*if (!connected) {

        QMessageBox::information(this, "Connect", "Connect not successfull");
    }
    else {
        QMessageBox::information(this, "Connect", "Connect successfull");
    }*/


    QSqlQuery query1 ("SELECT * FROM Pupils");


    while(query1.next()) {
        QString Mname = query1.value(1).toString();
        QString Mpass = query1.value(2).toString();
        int mb1 = query1.value(3).toInt();
        //std::cout << std::endl << Mname.toStdString() << " " << Mpass.toStdString() << " - " << mb1 << std::endl;

        if(Mname == Log_QSTR && Mpass == Pass_QSTR) {

            if(mb1 == 1) {
                //std::cout << "penis";
                ui->lineEdit->setText(Log_QSTR);
                ui->lineEdit_2->setText(Pass_QSTR);
                ui->checkBox->click();
            }
            else
                break;
        }

    }
    //newConnect.close();
}

MainWindow::~MainWindow()
{
    //std::cout << "PENIS";
    QString log, passwd;
    log = ui->lineEdit->text();
    passwd = ui->lineEdit_2->text();
    std::ofstream F;
    if(Check_Password()) {

    F.open("./.last_name.txt", std::ios::out);

        F << log.toStdString() << ":" << passwd.toStdString();

    }
    F.close();


    delete ui;
}

QSqlDatabase MainWindow::connect_To_Sql() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1"); // или, например, "my1.server.ru"
    db.setPort(3310);
    db.setDatabaseName("11M");
    db.setUserName("root");
    db.setPassword("");
    return db;
}


bool MainWindow::Check_Password() {
    QSqlDatabase db;
    db = connect_To_Sql();
    bool connected = db.open();


    if (!connected) {

        return false; // Вернуть признак неудачного подключения.
    }
    else {
        //QMessageBox::information(this, "Connect", "Connect successfull");
    }
    QSqlQuery query ("SELECT * FROM Pupils");

    QTextStream out(stdout);

    QString log, passwd;
    log = ui->lineEdit->text();
    passwd = ui->lineEdit_2->text();



    bool isPass = false, isLog = false;
    //std::cout << isPass << isLog;

    while(query.next()) {
        QString Mname = query.value(1).toString();
        QString Mpass = query.value(2).toString();


        if(Mname == log && Mpass == passwd) {
            isPass = true; isLog = true;
            break;
        }

    }

    if(isPass && isLog)
        return true;
    else
        return false;

}


void MainWindow::on_pushButton_clicked()
{
    if(MainWindow::Check_Password()) {
        //QMessageBox::information(this, "Accepted", "Correct data");
        window = new SecondWindow(this);
        close();
        window->setFocus(Qt::ActiveWindowFocusReason);
        window->show();
    }
    else {
        QMessageBox::warning(this, "Warning!", "Password isn't correct!");
        ui->lineEdit_2->setText("");

    }


    QString log = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    if(ui->checkBox->isChecked()) {
        int con = 1;
        QSqlDatabase database;
        database = connect_To_Sql();
        bool connected = database.open();
        QSqlQuery query ("SELECT * FROM Pupils");
        query.prepare("UPDATE Pupils SET SavePass = :press WHERE login = :name AND passwd = :pas");
        query.bindValue(":press", con);
        query.bindValue(":name", log);
        query.bindValue(":pas", pass);
        query.exec();
        //std::cout << "Is pressed!";
    }
    else {
        int con = 0;
        QSqlDatabase database;
        database = connect_To_Sql();
        bool connected = database.open();
        QSqlQuery query ("SELECT * FROM Pupils");
        query.prepare("UPDATE Pupils SET SavePass = :press WHERE login = :name AND passwd = :pas");
        query.bindValue(":press", con);
        query.bindValue(":name", log);
        query.bindValue(":pas", pass);
        query.exec();
        //std::cout << "Not pressed!";
    }
    /*QString link = "http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));*/
}




