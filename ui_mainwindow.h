/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QLabel *nameSoundLB;
    QSlider *soundSlider;
    QPushButton *stopStartBTN;
    QPushButton *predSoundBTN;
    QSlider *volumeSlider;
    QPushButton *nextSoundBTN;
    QLabel *totalTime;
    QLabel *currentTime;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menudsa;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 250);
        MainWindow->setMinimumSize(QSize(500, 250));
        MainWindow->setMaximumSize(QSize(500, 250));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        nameSoundLB = new QLabel(centralwidget);
        nameSoundLB->setObjectName("nameSoundLB");
        nameSoundLB->setGeometry(QRect(20, 10, 451, 101));
        QFont font;
        font.setPointSize(12);
        nameSoundLB->setFont(font);
        nameSoundLB->setStyleSheet(QString::fromUtf8("color: white;"));
        nameSoundLB->setAlignment(Qt::AlignCenter);
        soundSlider = new QSlider(centralwidget);
        soundSlider->setObjectName("soundSlider");
        soundSlider->setGeometry(QRect(59, 130, 371, 22));
        QFont font1;
        font1.setPointSize(9);
        soundSlider->setFont(font1);
        soundSlider->setMaximum(100);
        soundSlider->setPageStep(1);
        soundSlider->setOrientation(Qt::Horizontal);
        stopStartBTN = new QPushButton(centralwidget);
        stopStartBTN->setObjectName("stopStartBTN");
        stopStartBTN->setGeometry(QRect(230, 160, 40, 40));
        stopStartBTN->setFlat(false);
        predSoundBTN = new QPushButton(centralwidget);
        predSoundBTN->setObjectName("predSoundBTN");
        predSoundBTN->setGeometry(QRect(180, 160, 40, 40));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(370, 170, 100, 22));
        volumeSlider->setMaximum(100);
        volumeSlider->setSingleStep(0);
        volumeSlider->setPageStep(5);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Horizontal);
        nextSoundBTN = new QPushButton(centralwidget);
        nextSoundBTN->setObjectName("nextSoundBTN");
        nextSoundBTN->setGeometry(QRect(280, 160, 40, 40));
        totalTime = new QLabel(centralwidget);
        totalTime->setObjectName("totalTime");
        totalTime->setGeometry(QRect(390, 150, 71, 21));
        QFont font2;
        font2.setBold(false);
        totalTime->setFont(font2);
        totalTime->setStyleSheet(QString::fromUtf8("color: white;"));
        totalTime->setAlignment(Qt::AlignCenter);
        currentTime = new QLabel(centralwidget);
        currentTime->setObjectName("currentTime");
        currentTime->setGeometry(QRect(30, 150, 71, 21));
        currentTime->setFont(font2);
        currentTime->setStyleSheet(QString::fromUtf8("color: white;"));
        currentTime->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 500, 21));
        menudsa = new QMenu(menuBar);
        menudsa->setObjectName("menudsa");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menudsa->menuAction());
        menudsa->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MP3 Player #SK", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        nameSoundLB->setText(QString());
        stopStartBTN->setText(QString());
        predSoundBTN->setText(QString());
        nextSoundBTN->setText(QString());
        totalTime->setText(QString());
        currentTime->setText(QString());
        menudsa->setTitle(QCoreApplication::translate("MainWindow", "Open File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
