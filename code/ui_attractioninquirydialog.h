/********************************************************************************
** Form generated from reading UI file 'attractioninquirydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTRACTIONINQUIRYDIALOG_H
#define UI_ATTRACTIONINQUIRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_AttractionInquiryDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *attpushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AttractionInquiryDialog)
    {
        if (AttractionInquiryDialog->objectName().isEmpty())
            AttractionInquiryDialog->setObjectName(QString::fromUtf8("AttractionInquiryDialog"));
        AttractionInquiryDialog->resize(719, 519);
        horizontalLayout_2 = new QHBoxLayout(AttractionInquiryDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(AttractionInquiryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(300, 300));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 271, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        attpushButton = new QPushButton(gridLayoutWidget);
        attpushButton->setObjectName(QString::fromUtf8("attpushButton"));

        gridLayout->addWidget(attpushButton, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(AttractionInquiryDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(label_2);

        textBrowser = new QTextBrowser(AttractionInquiryDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AttractionInquiryDialog);

        QMetaObject::connectSlotsByName(AttractionInquiryDialog);
    } // setupUi

    void retranslateUi(QDialog *AttractionInquiryDialog)
    {
        AttractionInquiryDialog->setWindowTitle(QApplication::translate("AttractionInquiryDialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("AttractionInquiryDialog", "\350\257\267\350\276\223\345\205\245\347\253\231\347\202\271\345\220\215\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("AttractionInquiryDialog", "\344\270\255\345\215\227\345\244\247\345\255\246", nullptr));
        attpushButton->setText(QApplication::translate("AttractionInquiryDialog", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QApplication::translate("AttractionInquiryDialog", "\351\231\204\344\273\266\347\232\204\346\231\257\347\202\271\346\234\211\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttractionInquiryDialog: public Ui_AttractionInquiryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRACTIONINQUIRYDIALOG_H
