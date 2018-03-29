/********************************************************************************
** Form generated from reading UI file 'newsitem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSITEM_H
#define UI_NEWSITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewsItem
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QGraphicsView *graphicsView;
    QSplitter *splitter;
    QLabel *newsTitle;
    QTextBrowser *textBrowser;
    QSplitter *splitter_2;
    QPushButton *readButton;
    QPushButton *addToFavButton;

    void setupUi(QWidget *NewsItem)
    {
        if (NewsItem->objectName().isEmpty())
            NewsItem->setObjectName(QStringLiteral("NewsItem"));
        NewsItem->resize(454, 107);
        verticalLayout = new QVBoxLayout(NewsItem);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_3 = new QSplitter(NewsItem);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(splitter_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMaximumSize(QSize(64, 64));
        graphicsView->setBaseSize(QSize(64, 64));
        splitter_3->addWidget(graphicsView);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        newsTitle = new QLabel(splitter);
        newsTitle->setObjectName(QStringLiteral("newsTitle"));
        splitter->addWidget(newsTitle);
        textBrowser = new QTextBrowser(splitter);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        splitter->addWidget(textBrowser);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        readButton = new QPushButton(splitter_2);
        readButton->setObjectName(QStringLiteral("readButton"));
        splitter_2->addWidget(readButton);
        addToFavButton = new QPushButton(splitter_2);
        addToFavButton->setObjectName(QStringLiteral("addToFavButton"));
        splitter_2->addWidget(addToFavButton);
        splitter_3->addWidget(splitter_2);

        verticalLayout->addWidget(splitter_3);


        retranslateUi(NewsItem);

        QMetaObject::connectSlotsByName(NewsItem);
    } // setupUi

    void retranslateUi(QWidget *NewsItem)
    {
        NewsItem->setWindowTitle(QApplication::translate("NewsItem", "Form", nullptr));
        newsTitle->setText(QApplication::translate("NewsItem", "\320\247\321\202\320\276 \321\202\320\260\320\272\320\276\320\265 Lorem Ipsum?", nullptr));
        textBrowser->setHtml(QApplication::translate("NewsItem", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Open Sans,Arial,sans-serif'; font-size:8pt; font-weight:600; color:#000000; background-color:#ffffff;\">Lorem Ipsum</span><span style=\" font-family:'Open Sans,Arial,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">\302\240- \321\215\321\202\320\276 \321\202\320\265\320\272\321\201\321\202-&quot;\321\200\321\213\320\261\320\260&quot;, \321\207\320\260\321\201\321\202\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\271 \320\262 \320\277\320\265\321\207\320"
                        "\260\321\202\320\270 \320\270 \320\262\321\215\320\261-\320\264\320\270\320\267\320\260\320\271\320\275\320\265. Lorem Ipsum \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\320\276\320\271 &quot;\321\200\321\213\320\261\320\276\320\271&quot; \320\264\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\276\320\262 \320\275\320\260 \320\273\320\260\321\202\320\270\320\275\320\270\321\206\320\265 \321\201 \320\275\320\260\321\207\320\260\320\273\320\260 XVI \320\262\320\265\320\272\320\260...</span></p></body></html>", nullptr));
        readButton->setText(QApplication::translate("NewsItem", "Read", nullptr));
        addToFavButton->setText(QApplication::translate("NewsItem", "Add to Favorites", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewsItem: public Ui_NewsItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSITEM_H
