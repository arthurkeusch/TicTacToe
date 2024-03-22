#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_stats_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_settings_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}




