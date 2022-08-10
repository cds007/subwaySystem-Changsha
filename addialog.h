#ifndef ADDIALOG_H
#define ADDIALOG_H

#include <QDialog>

namespace Ui {
class AdDialog;
}

class AdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdDialog(QWidget *parent = nullptr);
    ~AdDialog();

private:
    Ui::AdDialog *ui;
};

#endif // ADDIALOG_H
