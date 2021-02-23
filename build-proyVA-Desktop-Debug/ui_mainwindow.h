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
#include <QtWidgets/QSpinBox>
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
    QFrame *processingFrame;
    QComboBox *operationComboBox;
    QLabel *operationLabel;
    QLabel *gaussianLabel;
    QSpinBox *thresholdSpinBox;
    QLabel *gaussianLabel_2;
    QPushButton *kernelButton;
    QPushButton *operOrderButton;
    QPushButton *pixelTButton;
    QSpinBox *gaussWidthBox;
    QLabel *label;
    QPushButton *saveButton;
    QFrame *histoFrameS;
    QFrame *histoFrameD;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 563);
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
        captureButton->setGeometry(QRect(740, 30, 101, 31));
        captureButton->setCheckable(true);
        captureButton->setChecked(true);
        colorButton = new QPushButton(MainWindow);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setGeometry(QRect(740, 80, 101, 31));
        colorButton->setCheckable(true);
        colorButton->setChecked(false);
        loadButton = new QPushButton(MainWindow);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(740, 130, 101, 31));
        loadButton->setCheckable(false);
        loadButton->setChecked(false);
        processingFrame = new QFrame(MainWindow);
        processingFrame->setObjectName(QString::fromUtf8("processingFrame"));
        processingFrame->setGeometry(QRect(20, 460, 831, 91));
        processingFrame->setFrameShape(QFrame::StyledPanel);
        processingFrame->setFrameShadow(QFrame::Raised);
        operationComboBox = new QComboBox(processingFrame);
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->addItem(QString());
        operationComboBox->setObjectName(QString::fromUtf8("operationComboBox"));
        operationComboBox->setGeometry(QRect(10, 50, 161, 27));
        operationLabel = new QLabel(processingFrame);
        operationLabel->setObjectName(QString::fromUtf8("operationLabel"));
        operationLabel->setGeometry(QRect(30, 30, 121, 17));
        gaussianLabel = new QLabel(processingFrame);
        gaussianLabel->setObjectName(QString::fromUtf8("gaussianLabel"));
        gaussianLabel->setGeometry(QRect(170, 30, 111, 17));
        thresholdSpinBox = new QSpinBox(processingFrame);
        thresholdSpinBox->setObjectName(QString::fromUtf8("thresholdSpinBox"));
        thresholdSpinBox->setGeometry(QRect(290, 50, 60, 27));
        thresholdSpinBox->setMaximum(255);
        thresholdSpinBox->setValue(120);
        gaussianLabel_2 = new QLabel(processingFrame);
        gaussianLabel_2->setObjectName(QString::fromUtf8("gaussianLabel_2"));
        gaussianLabel_2->setGeometry(QRect(280, 30, 81, 17));
        kernelButton = new QPushButton(processingFrame);
        kernelButton->setObjectName(QString::fromUtf8("kernelButton"));
        kernelButton->setGeometry(QRect(550, 40, 111, 41));
        operOrderButton = new QPushButton(processingFrame);
        operOrderButton->setObjectName(QString::fromUtf8("operOrderButton"));
        operOrderButton->setGeometry(QRect(660, 40, 161, 41));
        pixelTButton = new QPushButton(processingFrame);
        pixelTButton->setObjectName(QString::fromUtf8("pixelTButton"));
        pixelTButton->setGeometry(QRect(370, 40, 181, 41));
        gaussWidthBox = new QSpinBox(processingFrame);
        gaussWidthBox->setObjectName(QString::fromUtf8("gaussWidthBox"));
        gaussWidthBox->setGeometry(QRect(200, 50, 60, 27));
        gaussWidthBox->setMinimum(3);
        gaussWidthBox->setMaximum(19);
        gaussWidthBox->setSingleStep(2);
        gaussWidthBox->setValue(3);
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 440, 221, 31));
        label->setAutoFillBackground(true);
        label->setTextFormat(Qt::RichText);
        saveButton = new QPushButton(MainWindow);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(740, 180, 101, 31));
        saveButton->setCheckable(false);
        saveButton->setChecked(false);
        histoFrameS = new QFrame(MainWindow);
        histoFrameS->setObjectName(QString::fromUtf8("histoFrameS"));
        histoFrameS->setGeometry(QRect(50, 280, 260, 150));
        histoFrameS->setFrameShape(QFrame::StyledPanel);
        histoFrameS->setFrameShadow(QFrame::Raised);
        histoFrameS->setLineWidth(4);
        histoFrameD = new QFrame(MainWindow);
        histoFrameD->setObjectName(QString::fromUtf8("histoFrameD"));
        histoFrameD->setGeometry(QRect(420, 280, 260, 150));
        histoFrameD->setFrameShape(QFrame::StyledPanel);
        histoFrameD->setFrameShadow(QFrame::Raised);
        histoFrameD->setLineWidth(4);
        QWidget::setTabOrder(captureButton, colorButton);
        QWidget::setTabOrder(colorButton, loadButton);
        QWidget::setTabOrder(loadButton, saveButton);
        QWidget::setTabOrder(saveButton, operationComboBox);
        QWidget::setTabOrder(operationComboBox, gaussWidthBox);
        QWidget::setTabOrder(gaussWidthBox, thresholdSpinBox);
        QWidget::setTabOrder(thresholdSpinBox, pixelTButton);
        QWidget::setTabOrder(pixelTButton, kernelButton);
        QWidget::setTabOrder(kernelButton, operOrderButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Proyecto de Visi\303\263n Artificial", nullptr));
        captureButton->setText(QApplication::translate("MainWindow", "Stop Capture", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Color Image", nullptr));
        loadButton->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        operationComboBox->setItemText(0, QApplication::translate("MainWindow", "Transform pixel", nullptr));
        operationComboBox->setItemText(1, QApplication::translate("MainWindow", "Thresholding", nullptr));
        operationComboBox->setItemText(2, QApplication::translate("MainWindow", "Equalize", nullptr));
        operationComboBox->setItemText(3, QApplication::translate("MainWindow", "Gaussian Blur", nullptr));
        operationComboBox->setItemText(4, QApplication::translate("MainWindow", "Median Blur", nullptr));
        operationComboBox->setItemText(5, QApplication::translate("MainWindow", "Linear Filter", nullptr));
        operationComboBox->setItemText(6, QApplication::translate("MainWindow", "Dilate", nullptr));
        operationComboBox->setItemText(7, QApplication::translate("MainWindow", "Erode", nullptr));
        operationComboBox->setItemText(8, QApplication::translate("MainWindow", "Apply several...", nullptr));

        operationLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Select operation</span></p></body></html>", nullptr));
        gaussianLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Gaussian width</span></p></body></html>", nullptr));
        gaussianLabel_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Threshold</span></p></body></html>", nullptr));
        kernelButton->setText(QApplication::translate("MainWindow", "Set Kernel", nullptr));
        operOrderButton->setText(QApplication::translate("MainWindow", "Set Operation Order", nullptr));
        pixelTButton->setText(QApplication::translate("MainWindow", "Set Pixel Transformation", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">Image Processing</span></p></body></html>", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "Save Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
