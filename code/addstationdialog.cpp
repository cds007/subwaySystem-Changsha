#include "addstationdialog.h"
#include "ui_addstationdialog.h"


addStationDialog::addStationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStationDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("添加站点"));
    setWindowIcon(QIcon(":/Images/Images/stationIcon-modified"));

    longitude = 112.800000;
    latitude = 28.000000;

}

addStationDialog::~addStationDialog()
{
    delete ui;
}

void addStationDialog::on_stationNamelineEdit_textChanged(const QString &arg1)
{
    stationName=arg1;
    ui->textBrowser_2->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void addStationDialog::on_longidoubleSpinBox_valueChanged(double arg1)
{
    longitude = arg1;
    ui->textBrowser_2->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void addStationDialog::on_latidoubleSpinBox_2_valueChanged(double arg1)
{
    latitude = arg1;
    ui->textBrowser_2->setText(tr("站名：")+stationName+"\n"+
                                       tr("经度：")+QString::number(longitude, 'f', 7)+"\n"+
                                       tr("纬度：")+QString::number(latitude, 'f', 7));
}

void addStationDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    QString str;
    linesSelected.clear();   //linesSelected是已选择的线路

    for (int i=0; i<ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item=ui->listWidget->item(i);   //遍历item
        if(item->checkState()==Qt::Checked)
        {
            linesSelected.push_back(item->text());
            str+=item->text();
            str+="\n";
        }
    }
    ui->textBrowser_2->setText(str);
}

void addStationDialog::updateLinesListWidget(){
    QListWidget* listWidget=ui->listWidget;  //listWidget就是选择 添加到线路 那个列表：
    for(int i=0; i<linesNameList.size(); ++i)  //linesNameList是保存选择线路名表
    {
        QListWidgetItem *item =listWidget->takeItem(i);  //一个QListWidgetItem是QListWidget中的一项（一行）
        delete item;
    }
    listWidget->clear();
    linesSelected.clear();
    ui->textBrowser_2->clear();   //全部清空

    for(int i=0; i<linesNameList.size(); ++i)
    {
        QListWidgetItem *item=new QListWidgetItem(linesNameList[i]);
        item->setFlags(item->flags()|Qt::ItemIsUserCheckable);    //如果用户勾选了这个item，那么listwidget会添加这个item
        item->setCheckState(Qt::Unchecked);    //把item设置为未选中
        listWidget->addItem(item);
    }
}
