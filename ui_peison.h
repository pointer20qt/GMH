/********************************************************************************
** Form generated from reading UI file 'peison.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEISON_H
#define UI_PEISON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Peison
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCalendarWidget *calendarWidget;
    QLabel *label_4;
    QProgressBar *progressBar;
    QLabel *label_5;

    void setupUi(QWidget *Peison)
    {
        if (Peison->objectName().isEmpty())
            Peison->setObjectName(QStringLiteral("Peison"));
        Peison->resize(668, 394);
        label = new QLabel(Peison);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 101, 16));
        label_2 = new QLabel(Peison);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 101, 16));
        label_3 = new QLabel(Peison);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 50, 72, 15));
        calendarWidget = new QCalendarWidget(Peison);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 90, 611, 236));
        label_4 = new QLabel(Peison);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 350, 251, 16));
        progressBar = new QProgressBar(Peison);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(460, 350, 118, 23));
        progressBar->setValue(24);
        label_5 = new QLabel(Peison);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 350, 72, 15));

        retranslateUi(Peison);

        QMetaObject::connectSlotsByName(Peison);
    } // setupUi

    void retranslateUi(QWidget *Peison)
    {
        Peison->setWindowTitle(QApplication::translate("Peison", "Form", 0));
        label->setText(QApplication::translate("Peison", "\345\255\246\345\217\267               ", 0));
        label_2->setText(QApplication::translate("Peison", "\347\217\255\347\272\247", 0));
        label_3->setText(QApplication::translate("Peison", "\347\205\247\347\211\207", 0));
        label_4->setText(QApplication::translate("Peison", "\347\255\276\345\210\260\346\254\241\346\225\260", 0));
        label_5->setText(QApplication::translate("Peison", "\347\255\276\345\210\260\350\277\233\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class Peison: public Ui_Peison {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEISON_H
