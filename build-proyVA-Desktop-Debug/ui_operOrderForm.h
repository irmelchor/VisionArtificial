/********************************************************************************
** Form generated from reading UI file 'operOrderForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERORDERFORM_H
#define UI_OPERORDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OperOrderForm
{
public:
    QComboBox *operationComboBox1;
    QComboBox *operationComboBox2;
    QComboBox *operationComboBox3;
    QComboBox *operationComboBox4;
    QCheckBox *firstOperCheckBox;
    QPushButton *okButton;
    QCheckBox *secondOperCheckBox;
    QCheckBox *thirdOperCheckBox;
    QCheckBox *fourthOperCheckBox;

    void setupUi(QDialog *OperOrderForm)
    {
        if (OperOrderForm->objectName().isEmpty())
            OperOrderForm->setObjectName(QString::fromUtf8("OperOrderForm"));
        OperOrderForm->resize(400, 289);
        operationComboBox1 = new QComboBox(OperOrderForm);
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->addItem(QString());
        operationComboBox1->setObjectName(QString::fromUtf8("operationComboBox1"));
        operationComboBox1->setEnabled(true);
        operationComboBox1->setGeometry(QRect(20, 30, 161, 27));
        operationComboBox2 = new QComboBox(OperOrderForm);
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->addItem(QString());
        operationComboBox2->setObjectName(QString::fromUtf8("operationComboBox2"));
        operationComboBox2->setEnabled(false);
        operationComboBox2->setGeometry(QRect(20, 80, 161, 27));
        operationComboBox3 = new QComboBox(OperOrderForm);
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->addItem(QString());
        operationComboBox3->setObjectName(QString::fromUtf8("operationComboBox3"));
        operationComboBox3->setEnabled(false);
        operationComboBox3->setGeometry(QRect(20, 130, 161, 27));
        operationComboBox4 = new QComboBox(OperOrderForm);
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->addItem(QString());
        operationComboBox4->setObjectName(QString::fromUtf8("operationComboBox4"));
        operationComboBox4->setEnabled(false);
        operationComboBox4->setGeometry(QRect(20, 180, 161, 27));
        firstOperCheckBox = new QCheckBox(OperOrderForm);
        firstOperCheckBox->setObjectName(QString::fromUtf8("firstOperCheckBox"));
        firstOperCheckBox->setGeometry(QRect(220, 30, 131, 22));
        firstOperCheckBox->setChecked(true);
        okButton = new QPushButton(OperOrderForm);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(140, 240, 98, 27));
        secondOperCheckBox = new QCheckBox(OperOrderForm);
        secondOperCheckBox->setObjectName(QString::fromUtf8("secondOperCheckBox"));
        secondOperCheckBox->setGeometry(QRect(220, 80, 151, 22));
        secondOperCheckBox->setChecked(false);
        thirdOperCheckBox = new QCheckBox(OperOrderForm);
        thirdOperCheckBox->setObjectName(QString::fromUtf8("thirdOperCheckBox"));
        thirdOperCheckBox->setGeometry(QRect(220, 130, 131, 22));
        thirdOperCheckBox->setChecked(false);
        fourthOperCheckBox = new QCheckBox(OperOrderForm);
        fourthOperCheckBox->setObjectName(QString::fromUtf8("fourthOperCheckBox"));
        fourthOperCheckBox->setGeometry(QRect(220, 180, 151, 22));
        fourthOperCheckBox->setChecked(false);
        QWidget::setTabOrder(operationComboBox1, firstOperCheckBox);
        QWidget::setTabOrder(firstOperCheckBox, operationComboBox2);
        QWidget::setTabOrder(operationComboBox2, secondOperCheckBox);
        QWidget::setTabOrder(secondOperCheckBox, operationComboBox3);
        QWidget::setTabOrder(operationComboBox3, thirdOperCheckBox);
        QWidget::setTabOrder(thirdOperCheckBox, operationComboBox4);
        QWidget::setTabOrder(operationComboBox4, fourthOperCheckBox);
        QWidget::setTabOrder(fourthOperCheckBox, okButton);

        retranslateUi(OperOrderForm);
        QObject::connect(firstOperCheckBox, SIGNAL(clicked(bool)), operationComboBox1, SLOT(setEnabled(bool)));
        QObject::connect(secondOperCheckBox, SIGNAL(clicked(bool)), operationComboBox2, SLOT(setEnabled(bool)));
        QObject::connect(thirdOperCheckBox, SIGNAL(clicked(bool)), operationComboBox3, SLOT(setEnabled(bool)));
        QObject::connect(fourthOperCheckBox, SIGNAL(clicked(bool)), operationComboBox4, SLOT(setEnabled(bool)));

        operationComboBox1->setCurrentIndex(0);
        operationComboBox2->setCurrentIndex(0);
        operationComboBox3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OperOrderForm);
    } // setupUi

    void retranslateUi(QDialog *OperOrderForm)
    {
        OperOrderForm->setWindowTitle(QApplication::translate("OperOrderForm", "Set operation order", nullptr));
        operationComboBox1->setItemText(0, QApplication::translate("OperOrderForm", "Transform pixel", nullptr));
        operationComboBox1->setItemText(1, QApplication::translate("OperOrderForm", "Thresholding", nullptr));
        operationComboBox1->setItemText(2, QApplication::translate("OperOrderForm", "Equalize", nullptr));
        operationComboBox1->setItemText(3, QApplication::translate("OperOrderForm", "Gaussian Blur", nullptr));
        operationComboBox1->setItemText(4, QApplication::translate("OperOrderForm", "Median Blur", nullptr));
        operationComboBox1->setItemText(5, QApplication::translate("OperOrderForm", "Linear Filter", nullptr));
        operationComboBox1->setItemText(6, QApplication::translate("OperOrderForm", "Dilate", nullptr));
        operationComboBox1->setItemText(7, QApplication::translate("OperOrderForm", "Erode", nullptr));

        operationComboBox2->setItemText(0, QApplication::translate("OperOrderForm", "Transform pixel", nullptr));
        operationComboBox2->setItemText(1, QApplication::translate("OperOrderForm", "Thresholding", nullptr));
        operationComboBox2->setItemText(2, QApplication::translate("OperOrderForm", "Equalize", nullptr));
        operationComboBox2->setItemText(3, QApplication::translate("OperOrderForm", "Gaussian Blur", nullptr));
        operationComboBox2->setItemText(4, QApplication::translate("OperOrderForm", "Median Blur", nullptr));
        operationComboBox2->setItemText(5, QApplication::translate("OperOrderForm", "Linear Filter", nullptr));
        operationComboBox2->setItemText(6, QApplication::translate("OperOrderForm", "Dilate", nullptr));
        operationComboBox2->setItemText(7, QApplication::translate("OperOrderForm", "Erode", nullptr));

        operationComboBox3->setItemText(0, QApplication::translate("OperOrderForm", "Transform pixel", nullptr));
        operationComboBox3->setItemText(1, QApplication::translate("OperOrderForm", "Thresholding", nullptr));
        operationComboBox3->setItemText(2, QApplication::translate("OperOrderForm", "Equalize", nullptr));
        operationComboBox3->setItemText(3, QApplication::translate("OperOrderForm", "Gaussian Blur", nullptr));
        operationComboBox3->setItemText(4, QApplication::translate("OperOrderForm", "Median Blur", nullptr));
        operationComboBox3->setItemText(5, QApplication::translate("OperOrderForm", "Linear Filter", nullptr));
        operationComboBox3->setItemText(6, QApplication::translate("OperOrderForm", "Dilate", nullptr));
        operationComboBox3->setItemText(7, QApplication::translate("OperOrderForm", "Erode", nullptr));

        operationComboBox4->setItemText(0, QApplication::translate("OperOrderForm", "Transform pixel", nullptr));
        operationComboBox4->setItemText(1, QApplication::translate("OperOrderForm", "Thresholding", nullptr));
        operationComboBox4->setItemText(2, QApplication::translate("OperOrderForm", "Equalize", nullptr));
        operationComboBox4->setItemText(3, QApplication::translate("OperOrderForm", "Gaussian Blur", nullptr));
        operationComboBox4->setItemText(4, QApplication::translate("OperOrderForm", "Median Blur", nullptr));
        operationComboBox4->setItemText(5, QApplication::translate("OperOrderForm", "Linear Filter", nullptr));
        operationComboBox4->setItemText(6, QApplication::translate("OperOrderForm", "Dilate", nullptr));
        operationComboBox4->setItemText(7, QApplication::translate("OperOrderForm", "Erode", nullptr));

        firstOperCheckBox->setText(QApplication::translate("OperOrderForm", "First operation", nullptr));
        okButton->setText(QApplication::translate("OperOrderForm", "OK", nullptr));
        secondOperCheckBox->setText(QApplication::translate("OperOrderForm", "Second operation", nullptr));
        thirdOperCheckBox->setText(QApplication::translate("OperOrderForm", "Third operation", nullptr));
        fourthOperCheckBox->setText(QApplication::translate("OperOrderForm", "Fourth operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperOrderForm: public Ui_OperOrderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERORDERFORM_H
