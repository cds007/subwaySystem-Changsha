/********************************************************************************
** Form generated from reading UI file 'addialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDIALOG_H
#define UI_ADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AdDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *AdDialog)
    {
        if (AdDialog->objectName().isEmpty())
            AdDialog->setObjectName(QString::fromUtf8("AdDialog"));
        AdDialog->resize(754, 579);
        label = new QLabel(AdDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 14, 731, 541));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        retranslateUi(AdDialog);

        QMetaObject::connectSlotsByName(AdDialog);
    } // setupUi

    void retranslateUi(QDialog *AdDialog)
    {
        AdDialog->setWindowTitle(QApplication::translate("AdDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AdDialog", "\345\271\277\345\221\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdDialog: public Ui_AdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDIALOG_H
