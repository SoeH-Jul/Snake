/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snake
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Snake)
    {
        if (Snake->objectName().isEmpty())
            Snake->setObjectName("Snake");
        Snake->resize(800, 600);
        centralwidget = new QWidget(Snake);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("image: url(:/myimage/Desktop/download.jpg);\n"
"background-color: rgb(175, 214, 255);"));
        Snake->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Snake);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Snake->setMenuBar(menubar);
        statusbar = new QStatusBar(Snake);
        statusbar->setObjectName("statusbar");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font.setBold(true);
        statusbar->setFont(font);
        Snake->setStatusBar(statusbar);

        retranslateUi(Snake);

        QMetaObject::connectSlotsByName(Snake);
    } // setupUi

    void retranslateUi(QMainWindow *Snake)
    {
        Snake->setWindowTitle(QCoreApplication::translate("Snake", "Snake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snake: public Ui_Snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
