/********************************************************************************
** Form generated from reading UI file 'infaboutlesson.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFABOUTLESSON_H
#define UI_INFABOUTLESSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfAboutLesson
{
public:

    void setupUi(QWidget *InfAboutLesson)
    {
        if (InfAboutLesson->objectName().isEmpty())
            InfAboutLesson->setObjectName(QString::fromUtf8("InfAboutLesson"));
        InfAboutLesson->resize(400, 300);

        retranslateUi(InfAboutLesson);

        QMetaObject::connectSlotsByName(InfAboutLesson);
    } // setupUi

    void retranslateUi(QWidget *InfAboutLesson)
    {
        InfAboutLesson->setWindowTitle(QCoreApplication::translate("InfAboutLesson", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfAboutLesson: public Ui_InfAboutLesson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFABOUTLESSON_H
