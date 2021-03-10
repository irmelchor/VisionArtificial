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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
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
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 314);
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
        comboBox = new QComboBox(MainWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(730, 140, 111, 25));
        comboBox->setEditable(true);
        comboBox->setMaxVisibleItems(3);
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(740, 120, 101, 17));
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(720, 200, 131, 31));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(720, 240, 131, 31));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Proyecto de Visi\303\263n Artificial", nullptr));
        captureButton->setText(QApplication::translate("MainWindow", "Stop Capture", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Color Image", nullptr));
        label->setText(QApplication::translate("MainWindow", "Select Object", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Add Object Image", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Del Object Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
