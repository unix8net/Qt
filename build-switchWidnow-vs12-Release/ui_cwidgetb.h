/********************************************************************************
** Form generated from reading UI file 'cwidgetb.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWIDGETB_H
#define UI_CWIDGETB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWidgetB
{
public:
    QLabel *label;

    void setupUi(QWidget *CWidgetB)
    {
        if (CWidgetB->objectName().isEmpty())
            CWidgetB->setObjectName(QStringLiteral("CWidgetB"));
        CWidgetB->resize(400, 300);
        label = new QLabel(CWidgetB);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 100, 161, 41));

        retranslateUi(CWidgetB);

        QMetaObject::connectSlotsByName(CWidgetB);
    } // setupUi

    void retranslateUi(QWidget *CWidgetB)
    {
        CWidgetB->setWindowTitle(QApplication::translate("CWidgetB", "Form", 0));
        label->setText(QApplication::translate("CWidgetB", "this is widget B", 0));
    } // retranslateUi

};

namespace Ui {
    class CWidgetB: public Ui_CWidgetB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWIDGETB_H
