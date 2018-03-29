/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *emailLabel;
    QLineEdit *emailInput;
    QLabel *passwordLabel;
    QLineEdit *lineEdit_2;
    QSplitter *splitter;
    QPushButton *signInButton;
    QPushButton *signUpButton;

    void setupUi(QMainWindow *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName(QStringLiteral("AuthWindow"));
        AuthWindow->resize(341, 168);
        centralwidget = new QWidget(AuthWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, emailLabel);

        emailInput = new QLineEdit(layoutWidget);
        emailInput->setObjectName(QStringLiteral("emailInput"));

        formLayout->setWidget(1, QFormLayout::LabelRole, emailInput);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_2);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        signInButton = new QPushButton(splitter);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        splitter->addWidget(signInButton);
        signUpButton = new QPushButton(splitter);
        signUpButton->setObjectName(QStringLiteral("signUpButton"));
        splitter->addWidget(signUpButton);
        splitter_2->addWidget(splitter);

        verticalLayout->addWidget(splitter_2);

        AuthWindow->setCentralWidget(centralwidget);

        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AuthWindow)
    {
        AuthWindow->setWindowTitle(QApplication::translate("AuthWindow", "MainWindow", nullptr));
        emailLabel->setText(QApplication::translate("AuthWindow", "User e-mail", nullptr));
        passwordLabel->setText(QApplication::translate("AuthWindow", "Password", nullptr));
        signInButton->setText(QApplication::translate("AuthWindow", "Sing In", nullptr));
        signUpButton->setText(QApplication::translate("AuthWindow", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
