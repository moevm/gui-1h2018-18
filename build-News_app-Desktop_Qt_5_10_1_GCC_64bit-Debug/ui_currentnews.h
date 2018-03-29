/********************************************************************************
** Form generated from reading UI file 'currentnews.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTNEWS_H
#define UI_CURRENTNEWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentNews
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CurrentNews)
    {
        if (CurrentNews->objectName().isEmpty())
            CurrentNews->setObjectName(QStringLiteral("CurrentNews"));
        CurrentNews->resize(400, 300);
        verticalLayout = new QVBoxLayout(CurrentNews);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_2 = new QSplitter(CurrentNews);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter_2->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        splitter_2->addWidget(pushButton_2);

        verticalLayout->addWidget(splitter_2);

        groupBox = new QGroupBox(CurrentNews);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        splitter->addWidget(graphicsView);

        verticalLayout_2->addWidget(splitter);

        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        verticalLayout->addWidget(groupBox);


        retranslateUi(CurrentNews);

        QMetaObject::connectSlotsByName(CurrentNews);
    } // setupUi

    void retranslateUi(QWidget *CurrentNews)
    {
        CurrentNews->setWindowTitle(QApplication::translate("CurrentNews", "Form", nullptr));
        pushButton->setText(QApplication::translate("CurrentNews", "Back to list", nullptr));
        pushButton_2->setText(QApplication::translate("CurrentNews", "Add to Favorites", nullptr));
        groupBox->setTitle(QApplication::translate("CurrentNews", "\320\247\321\202\320\276 \321\202\320\260\320\272\320\276\320\265 Lorem Ipsum?", nullptr));
        textBrowser->setHtml(QApplication::translate("CurrentNews", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Open Sans,Arial,sans-serif'; font-size:8pt; font-weight:600; color:#000000; background-color:#ffffff;\">Lorem Ipsum</span><span style=\" font-family:'Open Sans,Arial,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">\302\240- \321\215\321\202\320\276 \321\202\320\265\320\272\321\201\321\202-&quot;\321\200\321\213\320\261\320\260&quot;, \321\207\320\260\321\201\321\202\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\271 \320\262 \320\277\320\265\321\207\320"
                        "\260\321\202\320\270 \320\270 \320\262\321\215\320\261-\320\264\320\270\320\267\320\260\320\271\320\275\320\265. Lorem Ipsum \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\320\276\320\271 &quot;\321\200\321\213\320\261\320\276\320\271&quot; \320\264\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\276\320\262 \320\275\320\260 \320\273\320\260\321\202\320\270\320\275\320\270\321\206\320\265 \321\201 \320\275\320\260\321\207\320\260\320\273\320\260 XVI \320\262\320\265\320\272\320\260. \320\222 \321\202\320\276 \320\262\321\200\320\265\320\274\321\217 \320\275\320\265\320\272\320\270\320\271 \320\261\320\265\320\267\321\213\320\274\321\217\320\275\320\275\321\213\320\271 \320\277\320\265\321\207\320\260\321\202\320\275\320\270\320\272 \321\201\320\276\320\267\320\264\320\260\320\273 \320\261\320\276\320\273\321\214\321\210\321\203\321\216 \320\272\320\276\320\273\320\273\320\265\320\272\321\206\320\270\321\216 "
                        "\321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\262 \320\270 \321\204\320\276\321\200\320\274 \321\210\321\200\320\270\321\204\321\202\320\276\320\262, \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\321\217 Lorem Ipsum \320\264\320\273\321\217 \321\200\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\272\320\270 \320\276\320\261\321\200\320\260\320\267\321\206\320\276\320\262. Lorem Ipsum \320\275\320\265 \321\202\320\276\320\273\321\214\320\272\320\276 \321\203\321\201\320\277\320\265\321\210\320\275\320\276 \320\277\320\265\321\200\320\265\320\266\320\270\320\273 \320\261\320\265\320\267 \320\267\320\260\320\274\320\265\321\202\320\275\321\213\321\205 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271 \320\277\321\217\321\202\321\214 \320\262\320\265\320\272\320\276\320\262, \320\275\320\276 \320\270 \320\277\320\265\321\200\320\265\321\210\320\260\320\263\320\275\321\203\320\273 \320\262 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320"
                        "\275\320\275\321\213\320\271 \320\264\320\270\320\267\320\260\320\271\320\275. \320\225\320\263\320\276 \320\277\320\276\320\277\321\203\320\273\321\217\321\200\320\270\320\267\320\260\321\206\320\270\320\270 \320\262 \320\275\320\276\320\262\320\276\320\265 \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\321\201\320\273\321\203\320\266\320\270\320\273\320\270 \320\277\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\321\217 \320\273\320\270\321\201\321\202\320\276\320\262 Letraset \321\201 \320\276\320\261\321\200\320\260\320\267\321\206\320\260\320\274\320\270 Lorem Ipsum \320\262 60-\321\205 \320\263\320\276\320\264\320\260\321\205 \320\270, \320\262 \320\261\320\276\320\273\320\265\320\265 \320\275\320\265\320\264\320\260\320\262\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217, \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\262\321\221\321\200\321"
                        "\201\321\202\320\272\320\270 \321\202\320\270\320\277\320\260 Aldus PageMaker, \320\262 \321\210\320\260\320\261\320\273\320\276\320\275\320\260\321\205 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217 Lorem Ipsum.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentNews: public Ui_CurrentNews {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTNEWS_H
