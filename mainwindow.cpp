#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GoLibraryExample.h"
#include <QDebug>

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

void MainWindow::on_getBalanceButton_clicked()
{
    const char *unit = "NEW";
    auto address = ui->addressLineEdit->text().trimmed();

    auto cstr_address = address.toStdString().c_str();

    GoGetBalance_return ret = GoGetBalance((char *)cstr_address,(char *)unit);
    qDebug() << ret.r0;
    qDebug() << ret.r1;

    QString balance = QString(ret.r1);
    free(ret.r1);
    ui->balanceLineEdit->setText(balance);

}
