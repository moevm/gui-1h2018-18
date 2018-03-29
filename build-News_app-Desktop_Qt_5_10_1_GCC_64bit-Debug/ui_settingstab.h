/********************************************************************************
** Form generated from reading UI file 'settingstab.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSTAB_H
#define UI_SETTINGSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsTab
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *changePasswordLabel;
    QFrame *line;
    QLabel *oldPaswordLabel;
    QLineEdit *oldPasswordInput;
    QLabel *newPasswordLabel;
    QLineEdit *newPasswordInput;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *meduzaCheckBox;
    QCheckBox *lentaCheckBox;
    QFrame *line_3;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *SettingsTab)
    {
        if (SettingsTab->objectName().isEmpty())
            SettingsTab->setObjectName(QStringLiteral("SettingsTab"));
        SettingsTab->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(SettingsTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        changePasswordLabel = new QLabel(SettingsTab);
        changePasswordLabel->setObjectName(QStringLiteral("changePasswordLabel"));

        verticalLayout->addWidget(changePasswordLabel);

        line = new QFrame(SettingsTab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        oldPaswordLabel = new QLabel(SettingsTab);
        oldPaswordLabel->setObjectName(QStringLiteral("oldPaswordLabel"));

        verticalLayout->addWidget(oldPaswordLabel);

        oldPasswordInput = new QLineEdit(SettingsTab);
        oldPasswordInput->setObjectName(QStringLiteral("oldPasswordInput"));

        verticalLayout->addWidget(oldPasswordInput);

        newPasswordLabel = new QLabel(SettingsTab);
        newPasswordLabel->setObjectName(QStringLiteral("newPasswordLabel"));

        verticalLayout->addWidget(newPasswordLabel);

        newPasswordInput = new QLineEdit(SettingsTab);
        newPasswordInput->setObjectName(QStringLiteral("newPasswordInput"));

        verticalLayout->addWidget(newPasswordInput);

        pushButton = new QPushButton(SettingsTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(SettingsTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        line_2 = new QFrame(SettingsTab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        meduzaCheckBox = new QCheckBox(SettingsTab);
        meduzaCheckBox->setObjectName(QStringLiteral("meduzaCheckBox"));

        horizontalLayout->addWidget(meduzaCheckBox);

        lentaCheckBox = new QCheckBox(SettingsTab);
        lentaCheckBox->setObjectName(QStringLiteral("lentaCheckBox"));

        horizontalLayout->addWidget(lentaCheckBox);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout_3);

        line_3 = new QFrame(SettingsTab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        logoutButton = new QPushButton(SettingsTab);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        verticalLayout_2->addWidget(logoutButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(SettingsTab);

        QMetaObject::connectSlotsByName(SettingsTab);
    } // setupUi

    void retranslateUi(QWidget *SettingsTab)
    {
        SettingsTab->setWindowTitle(QApplication::translate("SettingsTab", "Form", nullptr));
        changePasswordLabel->setText(QApplication::translate("SettingsTab", "Change password", nullptr));
        oldPaswordLabel->setText(QApplication::translate("SettingsTab", "Old password", nullptr));
        newPasswordLabel->setText(QApplication::translate("SettingsTab", "New password", nullptr));
        pushButton->setText(QApplication::translate("SettingsTab", "Save new password", nullptr));
        label_4->setText(QApplication::translate("SettingsTab", "News API", nullptr));
        meduzaCheckBox->setText(QApplication::translate("SettingsTab", "Meduza", nullptr));
        lentaCheckBox->setText(QApplication::translate("SettingsTab", "Lenta.ru", nullptr));
        logoutButton->setText(QApplication::translate("SettingsTab", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsTab: public Ui_SettingsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSTAB_H
