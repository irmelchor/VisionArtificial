/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QFrame *imageFrameS;
    QFrame *imageFrameD;
    QPushButton *captureButton;
    QPushButton *colorButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *copyChannelsButton;
    QFrame *frameCheck;
    QCheckBox *rCheck;
    QCheckBox *gCheck;
    QCheckBox *bCheck;
    QPushButton *copyWindowButton;
    QPushButton *resizeButton;
    QPushButton *enlargeButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 390);
        imageFrameS = new QFrame(MainWindow);
        imageFrameS->setObjectName(QString::fromUtf8("imageFrameS"));
        imageFrameS->setGeometry(QRect(20, 20, 320, 240));
        imageFrameS->setFrameShape(QFrame::StyledPanel);
        imageFrameS->setFrameShadow(QFrame::Raised);
        imageFrameD = new QFrame(MainWindow);
        imageFrameD->setObjectName(QString::fromUtf8("imageFrameD"));
        imageFrameD->setGeometry(QRect(390, 20, 320, 240));
        imageFrameD->setFrameShape(QFrame::StyledPanel);
        imageFrameD->setFrameShadow(QFrame::Raised);
        captureButton = new QPushButton(MainWindow);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(730, 20, 111, 31));
        captureButton->setCheckable(true);
        captureButton->setChecked(true);
        colorButton = new QPushButton(MainWindow);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setGeometry(QRect(730, 60, 111, 31));
        colorButton->setCheckable(true);
        colorButton->setChecked(false);
        loadButton = new QPushButton(MainWindow);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(730, 100, 111, 31));
        loadButton->setCheckable(false);
        saveButton = new QPushButton(MainWindow);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(730, 140, 111, 31));
        saveButton->setCheckable(false);
        copyChannelsButton = new QPushButton(MainWindow);
        copyChannelsButton->setObjectName(QString::fromUtf8("copyChannelsButton"));
        copyChannelsButton->setGeometry(QRect(730, 180, 111, 31));
        copyChannelsButton->setCheckable(false);
        frameCheck = new QFrame(MainWindow);
        frameCheck->setObjectName(QString::fromUtf8("frameCheck"));
        frameCheck->setGeometry(QRect(720, 220, 121, 41));
        frameCheck->setFrameShape(QFrame::StyledPanel);
        frameCheck->setFrameShadow(QFrame::Raised);
        rCheck = new QCheckBox(frameCheck);
        rCheck->setObjectName(QString::fromUtf8("rCheck"));
        rCheck->setGeometry(QRect(10, 10, 31, 21));
        gCheck = new QCheckBox(frameCheck);
        gCheck->setObjectName(QString::fromUtf8("gCheck"));
        gCheck->setGeometry(QRect(50, 10, 31, 21));
        bCheck = new QCheckBox(frameCheck);
        bCheck->setObjectName(QString::fromUtf8("bCheck"));
        bCheck->setGeometry(QRect(90, 10, 31, 21));
        copyWindowButton = new QPushButton(MainWindow);
        copyWindowButton->setObjectName(QString::fromUtf8("copyWindowButton"));
        copyWindowButton->setGeometry(QRect(728, 270, 111, 31));
        copyWindowButton->setCheckable(false);
        resizeButton = new QPushButton(MainWindow);
        resizeButton->setObjectName(QString::fromUtf8("resizeButton"));
        resizeButton->setGeometry(QRect(728, 310, 111, 31));
        resizeButton->setCheckable(false);
        enlargeButton = new QPushButton(MainWindow);
        enlargeButton->setObjectName(QString::fromUtf8("enlargeButton"));
        enlargeButton->setGeometry(QRect(728, 350, 111, 31));
        enlargeButton->setCheckable(false);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Proyecto de Visi\303\263n Artificial", nullptr));
        captureButton->setText(QApplication::translate("MainWindow", "Stop Capture", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Color Image", nullptr));
        loadButton->setText(QApplication::translate("MainWindow", "Load from File", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "Save to File", nullptr));
        copyChannelsButton->setText(QApplication::translate("MainWindow", "Copy channels", nullptr));
        rCheck->setText(QApplication::translate("MainWindow", "R", nullptr));
        gCheck->setText(QApplication::translate("MainWindow", "G", nullptr));
        bCheck->setText(QApplication::translate("MainWindow", "B", nullptr));
        copyWindowButton->setText(QApplication::translate("MainWindow", "Copy window", nullptr));
        resizeButton->setText(QApplication::translate("MainWindow", "Resize window", nullptr));
        enlargeButton->setText(QApplication::translate("MainWindow", "Enlarge window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
