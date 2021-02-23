/********************************************************************************
** Form generated from reading UI file 'pixelTForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXELTFORM_H
#define UI_PIXELTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PixelTForm
{
public:
    QLabel *origLabel;
    QPushButton *okButton;
    QTableWidget *grayTransformW;

    void setupUi(QDialog *PixelTForm)
    {
        if (PixelTForm->objectName().isEmpty())
            PixelTForm->setObjectName(QString::fromUtf8("PixelTForm"));
        PixelTForm->resize(360, 325);
        origLabel = new QLabel(PixelTForm);
        origLabel->setObjectName(QString::fromUtf8("origLabel"));
        origLabel->setGeometry(QRect(130, 20, 101, 21));
        origLabel->setTextFormat(Qt::RichText);
        okButton = new QPushButton(PixelTForm);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(130, 270, 98, 27));
        grayTransformW = new QTableWidget(PixelTForm);
        if (grayTransformW->columnCount() < 2)
            grayTransformW->setColumnCount(2);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        grayTransformW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        grayTransformW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (grayTransformW->rowCount() < 4)
            grayTransformW->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        grayTransformW->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        grayTransformW->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        grayTransformW->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        grayTransformW->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem6->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(1, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem11->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(2, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(3, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        grayTransformW->setItem(3, 1, __qtablewidgetitem13);
        grayTransformW->setObjectName(QString::fromUtf8("grayTransformW"));
        grayTransformW->setGeometry(QRect(110, 50, 141, 191));
        grayTransformW->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grayTransformW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grayTransformW->horizontalHeader()->setVisible(true);
        grayTransformW->horizontalHeader()->setDefaultSectionSize(70);
        grayTransformW->verticalHeader()->setVisible(false);
        grayTransformW->verticalHeader()->setDefaultSectionSize(40);

        retranslateUi(PixelTForm);

        QMetaObject::connectSlotsByName(PixelTForm);
    } // setupUi

    void retranslateUi(QDialog *PixelTForm)
    {
        PixelTForm->setWindowTitle(QApplication::translate("PixelTForm", "Set pixel transformation", nullptr));
        origLabel->setText(QApplication::translate("PixelTForm", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">4 points LUT</span></p></body></html>", nullptr));
        okButton->setText(QApplication::translate("PixelTForm", "Ok", nullptr));
        QTableWidgetItem *___qtablewidgetitem = grayTransformW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PixelTForm", "s", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = grayTransformW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PixelTForm", "r", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = grayTransformW->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PixelTForm", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = grayTransformW->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("PixelTForm", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = grayTransformW->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("PixelTForm", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = grayTransformW->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("PixelTForm", "New Row", nullptr));

        const bool __sortingEnabled = grayTransformW->isSortingEnabled();
        grayTransformW->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = grayTransformW->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("PixelTForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = grayTransformW->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("PixelTForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = grayTransformW->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("PixelTForm", "85", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = grayTransformW->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("PixelTForm", "85", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = grayTransformW->item(2, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("PixelTForm", "170", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = grayTransformW->item(2, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("PixelTForm", "170", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = grayTransformW->item(3, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("PixelTForm", "255", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = grayTransformW->item(3, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("PixelTForm", "255", nullptr));
        grayTransformW->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class PixelTForm: public Ui_PixelTForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXELTFORM_H
