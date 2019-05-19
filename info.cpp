#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent,QString img, QString text) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    ui->textBrowser->insertPlainText(text);
    ui->labelimg->setPixmap(img);
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    this->close();
}
