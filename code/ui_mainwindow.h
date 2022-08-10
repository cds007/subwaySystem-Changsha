/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPushButton *transferInquiryBtn;
    QPushButton *addCircuitBtn;
    QPushButton *addStationsBtn;
    QLabel *adLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1103, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1030, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(700, 580));
        graphicsView->setInteractive(true);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        transferInquiryBtn = new QPushButton(centralWidget);
        transferInquiryBtn->setObjectName(QString::fromUtf8("transferInquiryBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(transferInquiryBtn->sizePolicy().hasHeightForWidth());
        transferInquiryBtn->setSizePolicy(sizePolicy1);
        transferInquiryBtn->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        transferInquiryBtn->setFont(font);
        transferInquiryBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:#C0C0C0;\n"
"     boder:1px solid greay;\n"
"     padding:5px;\n"
"}\n"
""));

        verticalLayout->addWidget(transferInquiryBtn);

        addCircuitBtn = new QPushButton(centralWidget);
        addCircuitBtn->setObjectName(QString::fromUtf8("addCircuitBtn"));
        addCircuitBtn->setMinimumSize(QSize(0, 100));
        addCircuitBtn->setFont(font);
        addCircuitBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:#C0C0C0;\n"
"     boder:1px solid greay;\n"
"     padding:5px;\n"
"}"));

        verticalLayout->addWidget(addCircuitBtn);

        addStationsBtn = new QPushButton(centralWidget);
        addStationsBtn->setObjectName(QString::fromUtf8("addStationsBtn"));
        addStationsBtn->setMinimumSize(QSize(0, 100));
        addStationsBtn->setFont(font);
        addStationsBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:#C0C0C0;\n"
"     boder:1px solid greay;\n"
"     padding:5px;\n"
"}"));

        verticalLayout->addWidget(addStationsBtn);

        adLabel = new QLabel(centralWidget);
        adLabel->setObjectName(QString::fromUtf8("adLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(adLabel->sizePolicy().hasHeightForWidth());
        adLabel->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        adLabel->setFont(font1);

        verticalLayout->addWidget(adLabel);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 5);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1103, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        transferInquiryBtn->setText(QApplication::translate("MainWindow", "\345\234\260\351\223\201\346\215\242\344\271\230\346\237\245\350\257\242", nullptr));
        addCircuitBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\272\277\350\267\257", nullptr));
        addStationsBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\253\231\347\202\271", nullptr));
        adLabel->setText(QApplication::translate("MainWindow", "\345\271\277\345\255\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
