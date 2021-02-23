/********************************************************************************
** Form generated from reading UI file 'lFilterForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LFILTERFORM_H
#define UI_LFILTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_LFilterForm
{
public:
    QPushButton *okButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *addedVBox;
    QTableWidget *kernelWidget;

    void setupUi(QDialog *LFilterForm)
    {
        if (LFilterForm->objectName().isEmpty())
            LFilterForm->setObjectName(QString::fromUtf8("LFilterForm"));
        LFilterForm->resize(384, 272);
        okButton = new QPushButton(LFilterForm);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(150, 220, 91, 31));
        label = new QLabel(LFilterForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 20, 57, 15));
        label_2 = new QLabel(LFilterForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 60, 91, 16));
        addedVBox = new QSpinBox(LFilterForm);
        addedVBox->setObjectName(QString::fromUtf8("addedVBox"));
        addedVBox->setGeometry(QRect(280, 90, 61, 41));
        addedVBox->setMaximum(255);
        kernelWidget = new QTableWidget(LFilterForm);
        if (kernelWidget->columnCount() < 3)
            kernelWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (kernelWidget->rowCount() < 3)
            kernelWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        kernelWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        kernelWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        kernelWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        kernelWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(1, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(2, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        kernelWidget->setItem(2, 2, __qtablewidgetitem14);
        kernelWidget->setObjectName(QString::fromUtf8("kernelWidget"));
        kernelWidget->setGeometry(QRect(30, 40, 211, 151));
        kernelWidget->setFrameShape(QFrame::WinPanel);
        kernelWidget->setFrameShadow(QFrame::Sunken);
        kernelWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        kernelWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        kernelWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        kernelWidget->setAutoScroll(true);
        kernelWidget->setAutoScrollMargin(16);
        kernelWidget->setShowGrid(true);
        kernelWidget->setGridStyle(Qt::SolidLine);
        kernelWidget->horizontalHeader()->setVisible(false);
        kernelWidget->horizontalHeader()->setMinimumSectionSize(30);
        kernelWidget->horizontalHeader()->setDefaultSectionSize(70);
        kernelWidget->horizontalHeader()->setHighlightSections(true);
        kernelWidget->verticalHeader()->setVisible(false);
        kernelWidget->verticalHeader()->setMinimumSectionSize(30);
        kernelWidget->verticalHeader()->setDefaultSectionSize(50);
        QWidget::setTabOrder(addedVBox, okButton);

        retranslateUi(LFilterForm);

        QMetaObject::connectSlotsByName(LFilterForm);
    } // setupUi

    void retranslateUi(QDialog *LFilterForm)
    {
        LFilterForm->setWindowTitle(QApplication::translate("LFilterForm", "Set kernel", nullptr));
        okButton->setText(QApplication::translate("LFilterForm", "Ok", nullptr));
        label->setText(QApplication::translate("LFilterForm", "<html><head/><body><p><span style=\" font-weight:600;\">Kernel</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("LFilterForm", "<html><head/><body><p><span style=\" font-weight:600;\">Added value</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = kernelWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = kernelWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LFilterForm", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = kernelWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LFilterForm", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = kernelWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = kernelWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("LFilterForm", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = kernelWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("LFilterForm", "2", nullptr));

        const bool __sortingEnabled = kernelWidget->isSortingEnabled();
        kernelWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = kernelWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = kernelWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = kernelWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = kernelWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = kernelWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("LFilterForm", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = kernelWidget->item(1, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = kernelWidget->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = kernelWidget->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("LFilterForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = kernelWidget->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("LFilterForm", "0", nullptr));
        kernelWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class LFilterForm: public Ui_LFilterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LFILTERFORM_H
