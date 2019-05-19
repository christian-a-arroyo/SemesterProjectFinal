#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prerequisite.h"

int  choice =1;

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

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(choice == 2){
        frame = new prerequisite (this);
        frame -> show();
        this->hide();
    }
    if(choice == 1){
    ui->textBrowser->setText("Thank you for using our application. As more devices make their way into the home, we know it can get to be a bit overwhelming trying to keep track of everything. This program will help with that by leveraging the same tools that network security experts use to provide you with insight on the going on in your home network. From helping you recognize freeloading devices to giving warnings about potential risks, this program will try its best to empower you to take control of your home digitally. ");
    ui->label->setText("SETUP");
    choice = 2;
    }

}
