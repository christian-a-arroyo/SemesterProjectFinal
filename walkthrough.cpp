#include "walkthrough.h"
#include "ui_walkthrough.h"
#include "QDebug"
#include "QFile"

int walks =2;
QString image;
QString textW;

walkthrough::walkthrough(QWidget *parent,QString img, QString text) :
    QDialog(parent),
    ui(new Ui::walkthrough)
{
    ui->setupUi(this);
    ui->textBrowser->insertPlainText(text);
    image = img;
    ui->labelimg->setPixmap(image+ "1.PNG");
    textW = text;
    QFile file(textW+"1.txt");
    QString temp;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    temp = file.readAll();
    file.close();


    ui->textBrowser->setText(temp);
}

walkthrough::~walkthrough()
{
    delete ui;
}

void walkthrough::on_pushButton_2_clicked()
{
    this->close();
}

void walkthrough::on_pushButton_clicked()
{
    QString temp = image+QString::number(walks)+ ".PNG";
    //qDebug()  << temp;
    ui->labelimg->setPixmap(temp);

    QString temp2 = textW+QString::number(walks)+ ".txt";

    QString output;
    QFile file(temp2);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    output = file.readAll();
    file.close();
    ui->textBrowser->setText(output);
    walks += 1;


}
