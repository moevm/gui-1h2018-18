/********************************************************************************
** Form generated from reading UI file 'allnewstab.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLNEWSTAB_H
#define UI_ALLNEWSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllNewsTab
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *newsListWidget;

    void setupUi(QWidget *AllNewsTab)
    {
        if (AllNewsTab->objectName().isEmpty())
            AllNewsTab->setObjectName(QStringLiteral("AllNewsTab"));
        AllNewsTab->resize(400, 300);
        horizontalLayout = new QHBoxLayout(AllNewsTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newsListWidget = new QListWidget(AllNewsTab);
        newsListWidget->setObjectName(QStringLiteral("newsListWidget"));

        horizontalLayout->addWidget(newsListWidget);


        retranslateUi(AllNewsTab);

        QMetaObject::connectSlotsByName(AllNewsTab);
    } // setupUi

    void retranslateUi(QWidget *AllNewsTab)
    {
        AllNewsTab->setWindowTitle(QApplication::translate("AllNewsTab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllNewsTab: public Ui_AllNewsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLNEWSTAB_H
