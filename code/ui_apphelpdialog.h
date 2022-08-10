/********************************************************************************
** Form generated from reading UI file 'apphelpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPHELPDIALOG_H
#define UI_APPHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AppHelpDialog
{
public:

    void setupUi(QDialog *AppHelpDialog)
    {
        if (AppHelpDialog->objectName().isEmpty())
            AppHelpDialog->setObjectName(QString::fromUtf8("AppHelpDialog"));
        AppHelpDialog->resize(806, 655);

        retranslateUi(AppHelpDialog);

        QMetaObject::connectSlotsByName(AppHelpDialog);
    } // setupUi

    void retranslateUi(QDialog *AppHelpDialog)
    {
        AppHelpDialog->setWindowTitle(QApplication::translate("AppHelpDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppHelpDialog: public Ui_AppHelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPHELPDIALOG_H
