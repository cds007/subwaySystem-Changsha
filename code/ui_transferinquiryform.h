/********************************************************************************
** Form generated from reading UI file 'transferinquiryform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERINQUIRYFORM_H
#define UI_TRANSFERINQUIRYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferInquiryForm
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *FPlabel;
    QLabel *SPlabel;
    QLineEdit *SPlineEdit;
    QLineEdit *FPlineEdit;
    QLabel *label_3;
    QRadioButton *transferradioButton;
    QRadioButton *timeradioButton;
    QPushButton *inquirypushButton;
    QPushButton *restorepushButton;
    QLabel *label_4;
    QTextBrowser *textBrowserRoute;

    void setupUi(QWidget *TransferInquiryForm)
    {
        if (TransferInquiryForm->objectName().isEmpty())
            TransferInquiryForm->setObjectName(QString::fromUtf8("TransferInquiryForm"));
        TransferInquiryForm->resize(1008, 661);
        horizontalLayout = new QHBoxLayout(TransferInquiryForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(TransferInquiryForm);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FPlabel = new QLabel(TransferInquiryForm);
        FPlabel->setObjectName(QString::fromUtf8("FPlabel"));

        gridLayout->addWidget(FPlabel, 1, 0, 1, 1);

        SPlabel = new QLabel(TransferInquiryForm);
        SPlabel->setObjectName(QString::fromUtf8("SPlabel"));

        gridLayout->addWidget(SPlabel, 0, 0, 1, 1);

        SPlineEdit = new QLineEdit(TransferInquiryForm);
        SPlineEdit->setObjectName(QString::fromUtf8("SPlineEdit"));

        gridLayout->addWidget(SPlineEdit, 0, 1, 1, 1);

        FPlineEdit = new QLineEdit(TransferInquiryForm);
        FPlineEdit->setObjectName(QString::fromUtf8("FPlineEdit"));

        gridLayout->addWidget(FPlineEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_3 = new QLabel(TransferInquiryForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        transferradioButton = new QRadioButton(TransferInquiryForm);
        transferradioButton->setObjectName(QString::fromUtf8("transferradioButton"));

        verticalLayout->addWidget(transferradioButton);

        timeradioButton = new QRadioButton(TransferInquiryForm);
        timeradioButton->setObjectName(QString::fromUtf8("timeradioButton"));

        verticalLayout->addWidget(timeradioButton);

        inquirypushButton = new QPushButton(TransferInquiryForm);
        inquirypushButton->setObjectName(QString::fromUtf8("inquirypushButton"));

        verticalLayout->addWidget(inquirypushButton);

        restorepushButton = new QPushButton(TransferInquiryForm);
        restorepushButton->setObjectName(QString::fromUtf8("restorepushButton"));

        verticalLayout->addWidget(restorepushButton);

        label_4 = new QLabel(TransferInquiryForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        textBrowserRoute = new QTextBrowser(TransferInquiryForm);
        textBrowserRoute->setObjectName(QString::fromUtf8("textBrowserRoute"));

        verticalLayout->addWidget(textBrowserRoute);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 3);

        retranslateUi(TransferInquiryForm);

        QMetaObject::connectSlotsByName(TransferInquiryForm);
    } // setupUi

    void retranslateUi(QWidget *TransferInquiryForm)
    {
        TransferInquiryForm->setWindowTitle(QApplication::translate("TransferInquiryForm", "\345\234\260\351\223\201\346\215\242\344\271\230\346\237\245\350\257\242", nullptr));
        FPlabel->setText(QApplication::translate("TransferInquiryForm", "\347\273\210\347\202\271\347\253\231\357\274\232", nullptr));
        SPlabel->setText(QApplication::translate("TransferInquiryForm", "\350\265\267\347\202\271\347\253\231\357\274\232", nullptr));
        SPlineEdit->setText(QString());
        SPlineEdit->setPlaceholderText(QApplication::translate("TransferInquiryForm", "\344\270\255\345\215\227\345\244\247\345\255\246", nullptr));
        FPlineEdit->setText(QString());
        FPlineEdit->setPlaceholderText(QApplication::translate("TransferInquiryForm", "\351\223\201\351\201\223\345\255\246\351\231\242", nullptr));
        label_3->setText(QApplication::translate("TransferInquiryForm", "\346\215\242\344\271\230\347\255\226\347\225\245\357\274\232", nullptr));
        transferradioButton->setText(QApplication::translate("TransferInquiryForm", "\345\260\221\346\215\242\344\271\230", nullptr));
        timeradioButton->setText(QApplication::translate("TransferInquiryForm", "\350\276\203\345\277\253\346\215\267", nullptr));
        inquirypushButton->setText(QApplication::translate("TransferInquiryForm", "\346\237\245\350\257\242", nullptr));
        restorepushButton->setText(QApplication::translate("TransferInquiryForm", "\351\207\215\347\275\256", nullptr));
        label_4->setText(QApplication::translate("TransferInquiryForm", "\346\215\242\344\271\230\350\267\257\347\272\277\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferInquiryForm: public Ui_TransferInquiryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERINQUIRYFORM_H
