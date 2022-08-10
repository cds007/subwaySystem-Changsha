#include "apphelpdialog.h"
#include "ui_apphelpdialog.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFile>

AppHelpDialog::AppHelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppHelpDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("使用说明"));
    setWindowIcon(QIcon(":/Images/Images/appHelpIcon-modified"));
    creatlistMainItem();

     connect(listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(listWidgetChanged(QListWidgetItem*)));

}

AppHelpDialog::~AppHelpDialog()
{
    delete ui;
}

void AppHelpDialog::creatlistMainItem(){
    QHBoxLayout *mainLayout = new QHBoxLayout;
    setLayout(mainLayout);

    listWidget = new QListWidget;
    listWidget->addItem(tr("网络图"));
    listWidget->addItem(tr("换乘指南"));
    listWidget->addItem(tr("添加线路"));
    listWidget->addItem(tr("添加站点"));
    listWidget->addItem(tr("查看地铁线路图"));
    listWidget->addItem(tr("景点查询"));
    listWidget->setFixedWidth(150);
    mainLayout->addWidget(listWidget);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    textBrowser = new QTextBrowser;
    textBrowser->setFont(QFont("consolas"));
    textBrowser->setOpenExternalLinks(true);
    textBrowser->setOpenLinks(true);
    rightLayout->addWidget(textBrowser);

    mainLayout->addLayout(rightLayout);
    listWidget->setCurrentItem(listWidget->item(0));
    listWidgetChanged(listWidget->item(0));
}

void AppHelpDialog::listWidgetChanged(QListWidgetItem * item){
    if (listWidget->item(0) == item) {
        QFile txtFile(":/html/html/helpWatch.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(1)==item)
    {
        QFile txtFile(":/html/html/helpTransfer.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(2)==item)
    {
        QFile txtFile(":/html/html/helpAddLine.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(3)==item)
    {
        QFile txtFile(":/html/html/helpAddStation.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(4)==item)
    {
        QFile txtFile(":/html/html/helpAddConnection.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(5)==item)
    {
        QFile txtFile(":/html/html/helpAddByText.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
}
