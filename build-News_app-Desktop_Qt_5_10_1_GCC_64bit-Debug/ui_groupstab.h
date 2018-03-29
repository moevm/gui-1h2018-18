/********************************************************************************
** Form generated from reading UI file 'groupstab.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSTAB_H
#define UI_GROUPSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupsTab
{
public:

    void setupUi(QWidget *GroupsTab)
    {
        if (GroupsTab->objectName().isEmpty())
            GroupsTab->setObjectName(QStringLiteral("GroupsTab"));
        GroupsTab->resize(400, 300);

        retranslateUi(GroupsTab);

        QMetaObject::connectSlotsByName(GroupsTab);
    } // setupUi

    void retranslateUi(QWidget *GroupsTab)
    {
        GroupsTab->setWindowTitle(QApplication::translate("GroupsTab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupsTab: public Ui_GroupsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSTAB_H
