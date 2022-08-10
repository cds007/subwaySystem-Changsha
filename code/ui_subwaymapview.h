/********************************************************************************
** Form generated from reading UI file 'subwaymapview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWAYMAPVIEW_H
#define UI_SUBWAYMAPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubwayMapView
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lineLabel;
    QSpacerItem *verticalSpacer;
    QLabel *line1;
    QSpacerItem *verticalSpacer_2;
    QLabel *line2;
    QSpacerItem *verticalSpacer_3;
    QLabel *line3;
    QSpacerItem *verticalSpacer_4;
    QLabel *line4;
    QSpacerItem *verticalSpacer_5;
    QLabel *line5;
    QSpacerItem *verticalSpacer_6;
    QLabel *line6;
    QSpacerItem *verticalSpacer_7;
    QLabel *line7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SubwayMapView)
    {
        if (SubwayMapView->objectName().isEmpty())
            SubwayMapView->setObjectName(QString::fromUtf8("SubwayMapView"));
        SubwayMapView->resize(1072, 671);
        centralwidget = new QWidget(SubwayMapView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(1050, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1027, 1600));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1600));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineLabel = new QLabel(scrollAreaWidgetContents);
        lineLabel->setObjectName(QString::fromUtf8("lineLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineLabel->sizePolicy().hasHeightForWidth());
        lineLabel->setSizePolicy(sizePolicy1);
        lineLabel->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        lineLabel->setFont(font);
        lineLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        line1 = new QLabel(scrollAreaWidgetContents);
        line1->setObjectName(QString::fromUtf8("line1"));
        sizePolicy1.setHeightForWidth(line1->sizePolicy().hasHeightForWidth());
        line1->setSizePolicy(sizePolicy1);
        line1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        line2 = new QLabel(scrollAreaWidgetContents);
        line2->setObjectName(QString::fromUtf8("line2"));
        sizePolicy1.setHeightForWidth(line2->sizePolicy().hasHeightForWidth());
        line2->setSizePolicy(sizePolicy1);
        line2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        line3 = new QLabel(scrollAreaWidgetContents);
        line3->setObjectName(QString::fromUtf8("line3"));
        sizePolicy1.setHeightForWidth(line3->sizePolicy().hasHeightForWidth());
        line3->setSizePolicy(sizePolicy1);
        line3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        line4 = new QLabel(scrollAreaWidgetContents);
        line4->setObjectName(QString::fromUtf8("line4"));
        sizePolicy1.setHeightForWidth(line4->sizePolicy().hasHeightForWidth());
        line4->setSizePolicy(sizePolicy1);
        line4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        line5 = new QLabel(scrollAreaWidgetContents);
        line5->setObjectName(QString::fromUtf8("line5"));
        sizePolicy1.setHeightForWidth(line5->sizePolicy().hasHeightForWidth());
        line5->setSizePolicy(sizePolicy1);
        line5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        line6 = new QLabel(scrollAreaWidgetContents);
        line6->setObjectName(QString::fromUtf8("line6"));
        sizePolicy1.setHeightForWidth(line6->sizePolicy().hasHeightForWidth());
        line6->setSizePolicy(sizePolicy1);
        line6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        line7 = new QLabel(scrollAreaWidgetContents);
        line7->setObjectName(QString::fromUtf8("line7"));
        sizePolicy1.setHeightForWidth(line7->sizePolicy().hasHeightForWidth());
        line7->setSizePolicy(sizePolicy1);
        line7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(line7);


        verticalLayout_2->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        SubwayMapView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SubwayMapView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1072, 26));
        SubwayMapView->setMenuBar(menubar);
        statusbar = new QStatusBar(SubwayMapView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SubwayMapView->setStatusBar(statusbar);

        retranslateUi(SubwayMapView);

        QMetaObject::connectSlotsByName(SubwayMapView);
    } // setupUi

    void retranslateUi(QMainWindow *SubwayMapView)
    {
        SubwayMapView->setWindowTitle(QApplication::translate("SubwayMapView", "MainWindow", nullptr));
        lineLabel->setText(QApplication::translate("SubwayMapView", "\351\225\277\346\262\231\345\234\260\351\223\201\347\272\277\350\267\257\345\233\276", nullptr));
        line1->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line2->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line3->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line4->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line5->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line6->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
        line7->setText(QApplication::translate("SubwayMapView", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubwayMapView: public Ui_SubwayMapView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWAYMAPVIEW_H
