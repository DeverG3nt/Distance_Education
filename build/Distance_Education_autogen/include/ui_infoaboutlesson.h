/********************************************************************************
** Form generated from reading UI file 'infoaboutlesson.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOABOUTLESSON_H
#define UI_INFOABOUTLESSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_InfoAboutLesson
{
public:

    void setupUi(QDialog *InfoAboutLesson)
    {
        if (InfoAboutLesson->objectName().isEmpty())
            InfoAboutLesson->setObjectName(QString::fromUtf8("InfoAboutLesson"));
        InfoAboutLesson->resize(400, 300);

        retranslateUi(InfoAboutLesson);

        QMetaObject::connectSlotsByName(InfoAboutLesson);
    } // setupUi

    void retranslateUi(QDialog *InfoAboutLesson)
    {
        InfoAboutLesson->setWindowTitle(QCoreApplication::translate("InfoAboutLesson", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoAboutLesson: public Ui_InfoAboutLesson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOABOUTLESSON_H
