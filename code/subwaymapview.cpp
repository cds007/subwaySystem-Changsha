#include "subwaymapview.h"
#include "ui_subwaymapview.h"
#include<QMessageBox>

SubwayMapView::SubwayMapView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubwayMapView)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Images/Images/subwayMapViewIcon-modified"));
    setWindowTitle(tr("长沙地铁线路图"));



    ui->line1->setGeometry(0,0,1041,729);
    QPixmap *pixmap1 = new QPixmap("Images/line1");
    pixmap1->scaled(ui->line1->size(), Qt::KeepAspectRatio);
    ui->line1->setScaledContents(true);
    ui->line1->setPixmap(*pixmap1);

    ui->line2->setGeometry(0,0,1041,729);
    QPixmap *pixmap2 = new QPixmap("Images/line2");
    pixmap2->scaled(ui->line2->size(), Qt::KeepAspectRatio);
    ui->line2->setScaledContents(true);
    ui->line2->setPixmap(*pixmap2);

    ui->line3->setGeometry(0,0,1041,729);
    QPixmap *pixmap3 = new QPixmap("Images/line3");
    pixmap3->scaled(ui->line3->size(), Qt::KeepAspectRatio);
    ui->line3->setScaledContents(true);
    ui->line3->setPixmap(*pixmap3);

    ui->line4->setGeometry(0,0,1041,729);
    QPixmap *pixmap4 = new QPixmap("Images/line4");
    pixmap4->scaled(ui->line4->size(), Qt::KeepAspectRatio);
    ui->line4->setScaledContents(true);
    ui->line4->setPixmap(*pixmap4);

    ui->line5->setGeometry(0,0,1041,729);
    QPixmap *pixmap5 = new QPixmap("Images/line5");
    pixmap5->scaled(ui->line5->size(), Qt::KeepAspectRatio);
    ui->line5->setScaledContents(true);
    ui->line5->setPixmap(*pixmap5);

    ui->line6->setGeometry(0,0,1041,729);
    QPixmap *pixmap6 = new QPixmap("Images/line6");
    pixmap6->scaled(ui->line6->size(), Qt::KeepAspectRatio);
    ui->line6->setScaledContents(true);
    ui->line6->setPixmap(*pixmap6);

    ui->line7->setGeometry(0,0,1041,729);
    QPixmap *pixmap7 = new QPixmap("Images/line7");
    pixmap1->scaled(ui->line7->size(), Qt::KeepAspectRatio);
    ui->line7->setScaledContents(true);
    ui->line7->setPixmap(*pixmap7);


}

SubwayMapView::~SubwayMapView()
{
    delete ui;
}



