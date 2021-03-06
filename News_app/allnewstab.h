#ifndef ALLNEWSTAB_H
#define ALLNEWSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"
#include <QList>
#include <QtNetwork>


namespace Ui {
class AllNewsTab;
}

class AllNewsTab : public QWidget
{
    Q_OBJECT



public:
    explicit AllNewsTab(QWidget *parent = 0);
    ~AllNewsTab();
    QListWidgetItem *getCurrentItem();
    QWidget * getCurrentItemWidget();
    QWidget * getCurrentW2();
    void addItemToList(QListWidgetItem* item, NewsItem* news);
    void onFinishXMLParse();
    QWidget * transformToWidget(NewsItem *);
    void loadNewsFromLenta();
    void loadNewsFromMeduza();
    void clearList();
    void clearAllNews();
    void setUser(const QString &value);
    void checkFavorites(NewsItem* news);

private:
    Ui::AllNewsTab *ui;
    NewsItem *itemWidget;
    QList<NewsItem> *allNews;
    QPixmap tempPixmap;
    QString user;
    QSettings *settings;
    void downloadImage(QString url);

private slots:
    void getParsedNews(QNetworkReply* reply);
    void convertReplyToImage(QNetworkReply *reply);
    void readNews (QString link);
    void addFavoriteNews(NewsItem *news);

signals:
    void readNewsSignal(QString link);
    void updateFavorites();

};

#endif // ALLNEWSTAB_H
