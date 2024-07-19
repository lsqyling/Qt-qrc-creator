/********************************************************************************
** Form generated from reading UI file 'qrc_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRC_DIALOG_H
#define UI_QRC_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_qrc_dialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditRccPrefix;
    QLabel *label;
    QLineEdit *lineEditFileName;
    QLabel *label_2;
    QLineEdit *lineEditFileSuffixName;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *qrc_dialog)
    {
        if (qrc_dialog->objectName().isEmpty())
            qrc_dialog->setObjectName(QString::fromUtf8("qrc_dialog"));
        qrc_dialog->resize(491, 279);
        gridLayout_2 = new QGridLayout(qrc_dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(qrc_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditRccPrefix = new QLineEdit(groupBox);
        lineEditRccPrefix->setObjectName(QString::fromUtf8("lineEditRccPrefix"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditRccPrefix->sizePolicy().hasHeightForWidth());
        lineEditRccPrefix->setSizePolicy(sizePolicy1);
        lineEditRccPrefix->setReadOnly(false);

        gridLayout->addWidget(lineEditRccPrefix, 0, 1, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditFileName = new QLineEdit(groupBox);
        lineEditFileName->setObjectName(QString::fromUtf8("lineEditFileName"));
        sizePolicy1.setHeightForWidth(lineEditFileName->sizePolicy().hasHeightForWidth());
        lineEditFileName->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditFileName, 1, 1, 1, 3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditFileSuffixName = new QLineEdit(groupBox);
        lineEditFileSuffixName->setObjectName(QString::fromUtf8("lineEditFileSuffixName"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditFileSuffixName->sizePolicy().hasHeightForWidth());
        lineEditFileSuffixName->setSizePolicy(sizePolicy3);
        lineEditFileSuffixName->setReadOnly(true);

        gridLayout->addWidget(lineEditFileSuffixName, 2, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButtonCancel = new QPushButton(groupBox);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon/no.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon);
        pushButtonCancel->setAutoDefault(true);

        gridLayout->addWidget(pushButtonCancel, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        pushButtonOk = new QPushButton(groupBox);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icon/yes.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon1);

        gridLayout->addWidget(pushButtonOk, 3, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(qrc_dialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), qrc_dialog, SLOT(reject()));

        pushButtonOk->setDefault(true);


        QMetaObject::connectSlotsByName(qrc_dialog);
    } // setupUi

    void retranslateUi(QDialog *qrc_dialog)
    {
        qrc_dialog->setWindowTitle(QCoreApplication::translate("qrc_dialog", "qrc_dialog", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("qrc_dialog", "RCC\345\211\215\347\274\200\357\274\232", nullptr));
        lineEditRccPrefix->setText(QCoreApplication::translate("qrc_dialog", "/", nullptr));
        label->setText(QCoreApplication::translate("qrc_dialog", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("qrc_dialog", "\345\220\216\347\274\200\345\220\215\357\274\232", nullptr));
        lineEditFileSuffixName->setText(QCoreApplication::translate("qrc_dialog", ".qrc", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("qrc_dialog", "\345\217\226\346\266\210", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("qrc_dialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qrc_dialog: public Ui_qrc_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRC_DIALOG_H
