/********************************************************************************
** Form generated from reading UI file 'cwidgeta.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWIDGETA_H
#define UI_CWIDGETA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWidgetA
{
public:
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *CWidgetA)
    {
        if (CWidgetA->objectName().isEmpty())
            CWidgetA->setObjectName(QStringLiteral("CWidgetA"));
        CWidgetA->resize(302, 242);
        label = new QLabel(CWidgetA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 81, 16));
        lineEdit = new QLineEdit(CWidgetA);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 113, 20));

        retranslateUi(CWidgetA);

        QMetaObject::connectSlotsByName(CWidgetA);
    } // setupUi

    void retranslateUi(QWidget *CWidgetA)
    {
        CWidgetA->setWindowTitle(QApplication::translate("CWidgetA", "Form", 0));
        label->setText(QApplication::translate("CWidgetA", "iuput msg", 0));
    } // retranslateUi

};

namespace Ui {
    class CWidgetA: public Ui_CWidgetA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWIDGETA_H
