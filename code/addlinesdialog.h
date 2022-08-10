#ifndef ADDLINESDIALOG_H
#define ADDLINESDIALOG_H

#include <QDialog>

namespace Ui {
class addlinesDialog;
}

class addlinesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addlinesDialog(QWidget *parent = nullptr);
    ~addlinesDialog();

    //更新选择部件
    void updateComboBox();

private slots:
    //线路编辑内容改变
    void on_lineEdit_textChanged(const QString &arg1);
    //点击选择颜色按钮
    void on_ColorpushButton_clicked();

private:
    Ui::addlinesDialog *ui;

    QString lineName;                   //保存输入线路名
    QColor lineColor;                   //保存输入线路颜色

    friend class MainWindow;
};

#endif // ADDLINESDIALOG_H
