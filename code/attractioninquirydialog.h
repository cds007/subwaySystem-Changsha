#ifndef ATTRACTIONINQUIRYDIALOG_H
#define ATTRACTIONINQUIRYDIALOG_H

#include <QDialog>

namespace Ui {
class AttractionInquiryDialog;
}

class AttractionInquiryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AttractionInquiryDialog(QWidget *parent = nullptr);
    ~AttractionInquiryDialog();

private:
    Ui::AttractionInquiryDialog *ui;

    friend class MainWindow;
};

#endif // ATTRACTIONINQUIRYDIALOG_H
