#include "addlinesdialog.h"
#include "ui_addlinesdialog.h"
#include <QColorDialog>

addlinesDialog::addlinesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addlinesDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("添加线路"));
    setWindowIcon(QIcon(":/Images/Images/lineIcon-modified"));
}

addlinesDialog::~addlinesDialog()
{
    delete ui;
}

void addlinesDialog::on_lineEdit_textChanged(const QString &arg1)
{
    lineName=arg1;
    ui->textBrowser->setText(tr("线路：")+lineName+"\n"
                                    +tr("颜色：")+QString::number(lineColor.rgb()-0xff000000,16));
}



void addlinesDialog::on_ColorpushButton_clicked()
{
    QColorDialog colorDialog;
    colorDialog.setOptions(QColorDialog::ShowAlphaChannel);
    colorDialog.exec();
    lineColor=colorDialog.currentColor();
    ui->textBrowser->setText(tr("线路：")+lineName+"\n"
                                    +tr("颜色：")+QString::number(lineColor.rgb()-0xff000000,16));
    return ;
}


