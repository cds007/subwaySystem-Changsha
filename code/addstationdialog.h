#ifndef ADDSTATIONDIALOG_H
#define ADDSTATIONDIALOG_H

#include <QDialog>
#include<QListWidgetItem>
#include <QVector>
#include <QTabWidget>
#include <QListWidget>
#include <QIcon>
#include <QString>


namespace Ui {
class addStationDialog;
}

class addStationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addStationDialog(QWidget *parent = nullptr);
    ~addStationDialog();

    //更新线路列表信息
    void updateLinesListWidget();

private slots:

    //站点名称改变
    void on_stationNamelineEdit_textChanged(const QString &arg1);
    //经度改变
    void on_longidoubleSpinBox_valueChanged(double arg1);
    //纬度改变
    void on_latidoubleSpinBox_2_valueChanged(double arg1);
    //列表选择项改变
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::addStationDialog *ui;

    QString stationName;                //保存输入站点名
    double longitude;                   //保存输入站点经度
    double latitude;                    //保存输入站点纬度
    QList<QString> linesNameList;       //保存选择线路名表
    QList<QString> linesSelected;       //保存选择的线路名
    //QList<QString> stationsNameList;    //保存选择站点名表

    friend class MainWindow;//让mainwindow能调用它的私有成员
};

#endif // ADDSTATIONDIALOG_H
