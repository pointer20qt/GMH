/********************************************************************************
** Form generated from reading UI file 'logon.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGON_H
#define UI_LOGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logon
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QWidget *widget;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *logon)
    {
        if (logon->objectName().isEmpty())
            logon->setObjectName(QStringLiteral("logon"));
        logon->resize(498, 358);
        logon->setStyleSheet(QStringLiteral(""));
        label = new QLabel(logon);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 130, 72, 15));
        label->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-599005f48cede2164b52c421a9bc9380_hd[1].jpg);"));
        label_2 = new QLabel(logon);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 72, 15));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-599005f48cede2164b52c421a9bc9380_hd[1].jpg);"));
        lineEdit_4 = new QLineEdit(logon);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 90, 111, 21));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);"));
        label_4 = new QLabel(logon);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 90, 72, 15));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-e1d81057284e59759ad21a11d1eabb80_hd[1].jpg);"));
        widget = new QWidget(logon);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 501, 361));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-d6f3d0eeccb398d6e7adc20f34c41498.jpg);"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 50, 72, 15));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-e1d81057284e59759ad21a11d1eabb80_hd[1].jpg);"));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 50, 113, 21));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 130, 111, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("border-color: rgb(134, 160, 255);\n"
"border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);\n"
"border-top-color: rgb(149, 151, 255);"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 180, 111, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-color: rgb(199, 176, 255);\n"
"border-image: url(:/image/\350\241\250\346\203\205\345\214\205/v2-4651fb0ed8be538882b2d4482fb21e08.jpg);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 240, 93, 28));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/image/v2-0adeec4d603571488924e7ab3b99b524_hd[1].jpg);"));
        widget->raise();
        label->raise();
        label_2->raise();
        lineEdit_4->raise();
        label_4->raise();

        retranslateUi(logon);

        QMetaObject::connectSlotsByName(logon);
    } // setupUi

    void retranslateUi(QWidget *logon)
    {
        logon->setWindowTitle(QApplication::translate("logon", "Form", 0));
        label->setText(QApplication::translate("logon", "\347\224\250\346\210\267\345\220\215", 0));
        label_2->setText(QApplication::translate("logon", "\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("logon", "\347\217\255\347\272\247", 0));
        label_3->setText(QApplication::translate("logon", "\345\255\246\345\217\267", 0));
        pushButton->setText(QApplication::translate("logon", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class logon: public Ui_logon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGON_H
