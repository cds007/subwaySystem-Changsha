#include "attractioninquirydialog.h"
#include "ui_attractioninquirydialog.h"

AttractionInquiryDialog::AttractionInquiryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttractionInquiryDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("景点查询"));
    setWindowIcon(QIcon(":/Images/Images/attractionInquiryIcon-modified"));
}

AttractionInquiryDialog::~AttractionInquiryDialog()
{
    delete ui;
}
