/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *calculateTab;
    QTextEdit *numberTextEdit1;
    QTextEdit *numberTextEdit2;
    QLabel *numberLabel1;
    QLabel *numberLabel2;
    QPushButton *calculateButton;
    QLabel *addLabel;
    QLabel *subLabel;
    QLabel *mulLabel;
    QLabel *divLabel;
    QLabel *addResultLabel;
    QLabel *subResultLabel;
    QLabel *mulResultLabel;
    QLabel *divResultLabel;
    QWidget *licenseTab;
    QPushButton *licenseButton;
    QTextEdit *licenseTextEdit;
    QLabel *licenseLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 381, 241));
        calculateTab = new QWidget();
        calculateTab->setObjectName(QStringLiteral("calculateTab"));
        numberTextEdit1 = new QTextEdit(calculateTab);
        numberTextEdit1->setObjectName(QStringLiteral("numberTextEdit1"));
        numberTextEdit1->setGeometry(QRect(20, 40, 91, 31));
        numberTextEdit2 = new QTextEdit(calculateTab);
        numberTextEdit2->setObjectName(QStringLiteral("numberTextEdit2"));
        numberTextEdit2->setGeometry(QRect(140, 40, 91, 31));
        numberLabel1 = new QLabel(calculateTab);
        numberLabel1->setObjectName(QStringLiteral("numberLabel1"));
        numberLabel1->setGeometry(QRect(30, 10, 67, 17));
        numberLabel2 = new QLabel(calculateTab);
        numberLabel2->setObjectName(QStringLiteral("numberLabel2"));
        numberLabel2->setGeometry(QRect(150, 10, 67, 17));
        calculateButton = new QPushButton(calculateTab);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));
        calculateButton->setGeometry(QRect(270, 40, 89, 31));
        addLabel = new QLabel(calculateTab);
        addLabel->setObjectName(QStringLiteral("addLabel"));
        addLabel->setGeometry(QRect(20, 90, 111, 17));
        subLabel = new QLabel(calculateTab);
        subLabel->setObjectName(QStringLiteral("subLabel"));
        subLabel->setGeometry(QRect(20, 120, 111, 17));
        mulLabel = new QLabel(calculateTab);
        mulLabel->setObjectName(QStringLiteral("mulLabel"));
        mulLabel->setGeometry(QRect(20, 150, 111, 17));
        divLabel = new QLabel(calculateTab);
        divLabel->setObjectName(QStringLiteral("divLabel"));
        divLabel->setGeometry(QRect(20, 180, 111, 17));
        addResultLabel = new QLabel(calculateTab);
        addResultLabel->setObjectName(QStringLiteral("addResultLabel"));
        addResultLabel->setGeometry(QRect(150, 90, 81, 17));
        addResultLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        subResultLabel = new QLabel(calculateTab);
        subResultLabel->setObjectName(QStringLiteral("subResultLabel"));
        subResultLabel->setGeometry(QRect(150, 120, 81, 17));
        subResultLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mulResultLabel = new QLabel(calculateTab);
        mulResultLabel->setObjectName(QStringLiteral("mulResultLabel"));
        mulResultLabel->setGeometry(QRect(150, 150, 81, 16));
        mulResultLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        divResultLabel = new QLabel(calculateTab);
        divResultLabel->setObjectName(QStringLiteral("divResultLabel"));
        divResultLabel->setGeometry(QRect(150, 180, 81, 16));
        divResultLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(calculateTab, QString());
        licenseTab = new QWidget();
        licenseTab->setObjectName(QStringLiteral("licenseTab"));
        licenseButton = new QPushButton(licenseTab);
        licenseButton->setObjectName(QStringLiteral("licenseButton"));
        licenseButton->setGeometry(QRect(140, 120, 89, 25));
        licenseTextEdit = new QTextEdit(licenseTab);
        licenseTextEdit->setObjectName(QStringLiteral("licenseTextEdit"));
        licenseTextEdit->setGeometry(QRect(20, 60, 341, 31));
        licenseLabel = new QLabel(licenseTab);
        licenseLabel->setObjectName(QStringLiteral("licenseLabel"));
        licenseLabel->setGeometry(QRect(20, 30, 171, 17));
        tabWidget->addTab(licenseTab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        numberLabel1->setText(QApplication::translate("MainWindow", "Number 1", Q_NULLPTR));
        numberLabel2->setText(QApplication::translate("MainWindow", "Number 2", Q_NULLPTR));
        calculateButton->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        addLabel->setText(QApplication::translate("MainWindow", "Addition: ", Q_NULLPTR));
        subLabel->setText(QApplication::translate("MainWindow", "Subtraction: ", Q_NULLPTR));
        mulLabel->setText(QApplication::translate("MainWindow", "Multiplication:", Q_NULLPTR));
        divLabel->setText(QApplication::translate("MainWindow", "Division:", Q_NULLPTR));
        addResultLabel->setText(QString());
        subResultLabel->setText(QString());
        mulResultLabel->setText(QString());
        divResultLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(calculateTab), QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        licenseButton->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        licenseLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Enter License Key:</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(licenseTab), QApplication::translate("MainWindow", "License", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
