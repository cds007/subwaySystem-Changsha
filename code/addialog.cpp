#include "addialog.h"
#include "ui_addialog.h"
#include<QIcon>
#include<QDebug>

AdDialog::AdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("长沙地铁换乘系统"));
    setWindowIcon(QIcon(":/Images/Images/mainwindowIcon.png"));
    resize(955,755);



    QImage image;
    image.load(":/Images/Images/adImage.png");
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->resize(QSize(image.width(),image.height()));

    ui->label->setText(tr("<a href = 'http://www.pochanls.com/'><img src=:/Images/Images/adImage.png width =926 height=726></a>"));
    ui->label->setOpenExternalLinks( true );

    qDebug()<<image.width();
    qDebug()<<image.height();

}

AdDialog::~AdDialog()
{
    delete ui;
}
