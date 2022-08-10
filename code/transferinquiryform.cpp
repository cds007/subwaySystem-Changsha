#include "transferinquiryform.h"
#include "ui_transferinquiryform.h"

#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

TransferInquiryForm::TransferInquiryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransferInquiryForm)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Images/Images/transferInquiryIcon-modified"));


 }
TransferInquiryForm::~TransferInquiryForm()
{
    delete ui;
}
