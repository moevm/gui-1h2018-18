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
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
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
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        verticalLayout->addWidget(emailLabel);

        emailInput = new QLineEdit(layoutWidget);
        emailInput->setObjectName(QStringLiteral("emailInput"));

        verticalLayout->addWidget(emailInput);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        verticalLayout->addWidget(passwordLabel);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

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

        horizontalLayout->addWidget(splitter_2);

        AuthWindow->setCentralWidget(centralwidget);

        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AuthWindow)
    {
        AuthWindow->setWindowTitle(QApplication::translate("AuthWindow", "Authorization", nullptr));
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
