#ifndef APPHELPDIALOG_H
#define APPHELPDIALOG_H

#include <QDialog>
#include<QListWidget>
#include<QTextBrowser>

namespace Ui {
class AppHelpDialog;
}

class AppHelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppHelpDialog(QWidget *parent = nullptr);
    ~AppHelpDialog();

    void creatlistMainItem();
private slots:
    //当前列表项变化
    void listWidgetChanged(QListWidgetItem*);

private:
    Ui::AppHelpDialog *ui;

    QListWidget *listWidget;
    QTextBrowser *textBrowser;
};

#endif // APPHELPDIALOG_H
