/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(660, 525);
        login->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-e1d81057284e59759ad21a11d1eabb80_hd[1].jpg);"));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 280, 93, 28));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/image/v2-eacf4afd16a1fe25e000eef3689749bd_hd[1].jpg);\n"
"font: 9pt \"Bahnschrift\";\n"
"color: rgb(161, 130, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 150, 51, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 210, 45, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 150, 151, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(250, 210, 151, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 280, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("border-image: url(:/image/v2-eacf4afd16a1fe25e000eef3689749bd_hd[1].jpg);\n"
"color: rgb(187, 131, 255);\n"
"font: 75 9pt \"Arial\";"));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 660, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        login->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", 0));
        pushButton->setText(QApplication::translate("login", "\347\231\273\345\205\245", 0));
        label->setText(QApplication::translate("login", "\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("login", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit->setText(QApplication::translate("login", "\346\235\216\345\206\233", 0));
        lineEdit_2->setText(QApplication::translate("login", "123456", 0));
        pushButton_2->setText(QApplication::translate("login", "\346\263\250\345\206\214", 0));
        menu->setTitle(QApplication::translate("login", "\347\231\273\345\205\245\347\225\214\351\235\242", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
