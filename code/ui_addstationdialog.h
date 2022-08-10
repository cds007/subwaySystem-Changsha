/********************************************************************************
** Form generated from reading UI file 'addstationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTATIONDIALOG_H
#define UI_ADDSTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addStationDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QLineEdit *stationNamelineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *longidoubleSpinBox;
    QDoubleSpinBox *latidoubleSpinBox_2;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_8;
    QTextBrowser *textBrowser;
    QLabel *label_9;
    QTextBrowser *textBrowser_2;
    QPushButton *addpushButton;

    void setupUi(QDialog *addStationDialog)
    {
        if (addStationDialog->objectName().isEmpty())
            addStationDialog->setObjectName(QString::fromUtf8("addStationDialog"));
        addStationDialog->resize(837, 600);
        horizontalLayout_2 = new QHBoxLayout(addStationDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(addStationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        stationNamelineEdit = new QLineEdit(addStationDialog);
        stationNamelineEdit->setObjectName(QString::fromUtf8("stationNamelineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stationNamelineEdit->sizePolicy().hasHeightForWidth());
        stationNamelineEdit->setSizePolicy(sizePolicy1);
        stationNamelineEdit->setMinimumSize(QSize(50, 0));

        verticalLayout->addWidget(stationNamelineEdit);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(addStationDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 241, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        longidoubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        longidoubleSpinBox->setObjectName(QString::fromUtf8("longidoubleSpinBox"));
        longidoubleSpinBox->setDecimals(6);
        longidoubleSpinBox->setMinimum(112.799999999999997);
        longidoubleSpinBox->setMaximum(113.299999999999997);
        longidoubleSpinBox->setSingleStep(0.010000000000000);

        gridLayout->addWidget(longidoubleSpinBox, 0, 1, 1, 1);

        latidoubleSpinBox_2 = new QDoubleSpinBox(gridLayoutWidget);
        latidoubleSpinBox_2->setObjectName(QString::fromUtf8("latidoubleSpinBox_2"));
        latidoubleSpinBox_2->setDecimals(6);
        latidoubleSpinBox_2->setMinimum(28.000000000000000);
        latidoubleSpinBox_2->setMaximum(28.300000000000001);
        latidoubleSpinBox_2->setSingleStep(0.010000000000000);

        gridLayout->addWidget(latidoubleSpinBox_2, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_2 = new QGroupBox(addStationDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(19, 19, 191, 171));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_7 = new QLabel(addStationDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        listWidget = new QListWidget(addStationDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_6);

        label_8 = new QLabel(addStationDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        textBrowser = new QTextBrowser(addStationDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(textBrowser);

        label_9 = new QLabel(addStationDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        textBrowser_2 = new QTextBrowser(addStationDialog);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(10);
        sizePolicy3.setHeightForWidth(textBrowser_2->sizePolicy().hasHeightForWidth());
        textBrowser_2->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(textBrowser_2);

        addpushButton = new QPushButton(addStationDialog);
        addpushButton->setObjectName(QString::fromUtf8("addpushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addpushButton->sizePolicy().hasHeightForWidth());
        addpushButton->setSizePolicy(sizePolicy4);
        addpushButton->setMinimumSize(QSize(10, 0));

        verticalLayout_3->addWidget(addpushButton);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(addStationDialog);

        QMetaObject::connectSlotsByName(addStationDialog);
    } // setupUi

    void retranslateUi(QDialog *addStationDialog)
    {
        addStationDialog->setWindowTitle(QApplication::translate("addStationDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("addStationDialog", "\347\253\231\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        stationNamelineEdit->setText(QString());
        stationNamelineEdit->setPlaceholderText(QApplication::translate("addStationDialog", "\344\270\255\345\215\227\345\244\247\345\255\246", nullptr));
        groupBox->setTitle(QApplication::translate("addStationDialog", "\347\253\231\347\202\271\345\234\260\347\220\206\344\277\241\346\201\257\357\274\232", nullptr));
        label_3->setText(QApplication::translate("addStationDialog", "\347\253\231\347\202\271\347\272\254\345\272\246(\345\214\227\347\272\254)", nullptr));
        label_2->setText(QApplication::translate("addStationDialog", "\347\253\231\347\202\271\347\273\217\345\272\246(\344\270\234\347\273\217)", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("addStationDialog", "\346\234\211\346\225\210\350\214\203\345\233\264\357\274\232", nullptr));
        label_6->setText(QApplication::translate("addStationDialog", "\347\273\217\345\272\246:[112.8-113.3]", nullptr));
        label_5->setText(QApplication::translate("addStationDialog", "\347\272\254\345\272\246:[28.0-28.3]", nullptr));
        label_7->setText(QApplication::translate("addStationDialog", "\346\267\273\345\212\240\347\253\231\347\202\271\346\211\200\345\261\236\347\272\277\350\267\257\357\274\232", nullptr));
        label_8->setText(QApplication::translate("addStationDialog", "\345\267\262\351\200\211\346\213\251\357\274\232", nullptr));
        label_9->setText(QApplication::translate("addStationDialog", "\346\267\273\345\212\240\344\277\241\346\201\257\357\274\232", nullptr));
        addpushButton->setText(QApplication::translate("addStationDialog", "\346\267\273\345\212\240\347\253\231\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addStationDialog: public Ui_addStationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTATIONDIALOG_H
