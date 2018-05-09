#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>
#include <QString>
#include <QDataStream>
#include <QtNetwork>
namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    explicit NewsItem(QString name, QString text, QString link, QString settingsLink, QString img, bool isInFavorites=false, QWidget *parent = 0);
    NewsItem(const NewsItem&, QWidget *parent = 0);
    NewsItem operator=(const NewsItem& other) const;
    void setName(QString);
    void setText(QString);
    QString getName();
    QString getText();
    QString getLink();
    QString getSettingsLink();
    void setSettingsLink(QString settingsLink);
    ~NewsItem();

    QString getLink() const;
    void setLink(const QString &value);
    QString getImg() const;
    void setImg(QString value);

    bool getIsInFavorites() const;
    void setIsInFavorites(bool value);

private slots:
    void on_readButton_clicked();
    void on_addToFavButton_clicked();
    void setupImage(QNetworkReply *reply);

signals:
    void readItemNews(QString newsLink);
    void addItemToFavorite(NewsItem *newsItem);
private:
    Ui::NewsItem *ui;
    QString text;
    QString name;
    QString link;
    QString settngsLink;
    QString img;
    bool isInFavorites;


};
#endif // NEWSITEM_H
