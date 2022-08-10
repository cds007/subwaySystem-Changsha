/********************************************************************************
** Form generated from reading UI file 'addlinesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLINESDIALOG_H
#define UI_ADDLINESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addlinesDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *ColorpushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *addpushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonconnect;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBoxline;
    QComboBox *comboBoxstation1;
    QComboBox *comboBoxstation2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QTextBrowser *textBrowser_2;

    void setupUi(QDialog *addlinesDialog)
    {
        if (addlinesDialog->objectName().isEmpty())
            addlinesDialog->setObjectName(QString::fromUtf8("addlinesDialog"));
        addlinesDialog->resize(878, 631);
        verticalLayout_3 = new QVBoxLayout(addlinesDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(addlinesDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 371, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        ColorpushButton = new QPushButton(gridLayoutWidget);
        ColorpushButton->setObjectName(QString::fromUtf8("ColorpushButton"));

        gridLayout->addWidget(ColorpushButton, 1, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_2 = new QGroupBox(addlinesDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(19, 29, 371, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        addpushButton = new QPushButton(verticalLayoutWidget_2);
        addpushButton->setObjectName(QString::fromUtf8("addpushButton"));

        verticalLayout_2->addWidget(addpushButton);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(addlinesDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 30, 341, 221));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonconnect = new QPushButton(gridLayoutWidget_2);
        pushButtonconnect->setObjectName(QString::fromUtf8("pushButtonconnect"));

        gridLayout_2->addWidget(pushButtonconnect, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        comboBoxline = new QComboBox(gridLayoutWidget_2);
        comboBoxline->setObjectName(QString::fromUtf8("comboBoxline"));

        gridLayout_2->addWidget(comboBoxline, 0, 1, 1, 1);

        comboBoxstation1 = new QComboBox(gridLayoutWidget_2);
        comboBoxstation1->setObjectName(QString::fromUtf8("comboBoxstation1"));

        gridLayout_2->addWidget(comboBoxstation1, 1, 1, 1, 1);

        comboBoxstation2 = new QComboBox(gridLayoutWidget_2);
        comboBoxstation2->setObjectName(QString::fromUtf8("comboBoxstation2"));

        gridLayout_2->addWidget(comboBoxstation2, 2, 1, 1, 1);


        horizontalLayout_2->addWidget(groupBox_3);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        groupBox_4 = new QGroupBox(addlinesDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        textBrowser_2 = new QTextBrowser(groupBox_4);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(20, 30, 331, 221));

        horizontalLayout_2->addWidget(groupBox_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(addlinesDialog);

        QMetaObject::connectSlotsByName(addlinesDialog);
    } // setupUi

    void retranslateUi(QDialog *addlinesDialog)
    {
        addlinesDialog->setWindowTitle(QApplication::translate("addlinesDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("addlinesDialog", "\346\226\260\345\242\236\347\272\277\350\267\257(\346\226\260\347\272\277\350\267\257\344\277\241\346\201\257):", nullptr));
        label->setText(QApplication::translate("addlinesDialog", "\347\272\277\350\267\257\345\220\215\347\247\260:", nullptr));
        label_2->setText(QApplication::translate("addlinesDialog", "\347\272\277\350\267\257\351\242\234\350\211\262:", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("addlinesDialog", "\350\257\267\350\276\223\345\205\245\347\272\277\350\267\257\345\220\215:", nullptr));
        ColorpushButton->setText(QApplication::translate("addlinesDialog", "\346\213\276\345\217\226\347\272\277\350\267\257\351\242\234\350\211\262", nullptr));
        groupBox_2->setTitle(QApplication::translate("addlinesDialog", "\346\267\273\345\212\240\344\277\241\346\201\257\357\274\232", nullptr));
        addpushButton->setText(QApplication::translate("addlinesDialog", "\346\267\273\345\212\240\347\272\277\350\267\257", nullptr));
        groupBox_3->setTitle(QApplication::translate("addlinesDialog", "\350\277\236\346\216\245\347\253\231\347\202\271:", nullptr));
        pushButtonconnect->setText(QApplication::translate("addlinesDialog", "\350\277\236\346\216\245", nullptr));
        label_5->setText(QApplication::translate("addlinesDialog", "\347\253\231\347\202\2712\357\274\232", nullptr));
        label_3->setText(QApplication::translate("addlinesDialog", "\346\211\200\345\261\236\347\272\277\350\267\257\357\274\232", nullptr));
        label_4->setText(QApplication::translate("addlinesDialog", "\347\253\231\347\202\2711\357\274\232", nullptr));
        groupBox_4->setTitle(QApplication::translate("addlinesDialog", "\346\217\220\347\244\272:", nullptr));
        textBrowser_2->setHtml(QApplication::translate("addlinesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\346\267\273\345\212\240\346\226\260\347\272\277\350\267\257\347\232\204\346\226\271\346\263\225\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">1.</span>\345\205\210\345\234\250\346\226\260\345\242\236\347\272\277\350\267\257\346\240\217\345\260\206\346\226\260\347\272\277\350\267\257\347\232\204\347\233\270\345\205\263\344\277\241\346\201\257\345\241\253\345\206\231\345\245\275\357"
                        "\274\214\347\202\271\345\207\273\346\267\273\345\212\240\347\272\277\350\267\257\346\214\211\351\222\256\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">2.</span>\347\202\271\345\274\200\344\270\273\347\225\214\351\235\242\347\232\204\346\267\273\345\212\240\347\253\231\347\202\271\346\214\211\351\222\256\357\274\214\347\204\266\345\220\216\346\226\260\346\267\273\345\212\240\345\261\236\344\272\216\350\277\231\346\235\241\346\226\260\347\272\277\350\267\257\347\232\204\345\207\240\344\270\252\347\253\231\347\202\271\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">3.</span>\347\204\266\345\220\216\345\233\236\345\210\260\346\255\244\347\225\214\351\235\242\357\274\214\345\234\250\350\277\236\346\216\245\347\253\231\347\202\271\346\240\217\345\260\206\346\203\263"
                        "\350\246\201\350\277\236\346\216\245\347\232\204\345\261\236\344\272\216\350\257\245\347\272\277\350\267\257\347\232\204\344\270\244\344\270\252\347\253\231\347\202\271\344\277\241\346\201\257\345\241\253\345\206\231\345\245\275\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273\350\277\236\346\216\245\346\214\211\351\222\256\345\215\263\345\217\257\357\274\214\346\216\245\344\270\213\346\235\245\344\270\273\347\225\214\351\235\242\347\232\204\345\234\260\345\233\276\344\270\212\345\260\206\346\230\276\347\244\272\346\226\260\347\272\277\350\267\257\343\200\202</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addlinesDialog: public Ui_addlinesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLINESDIALOG_H
