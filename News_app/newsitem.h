#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>
#include <QString>
#include <QDataStream>
namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    explicit NewsItem(QString name, QString text, QString link, QString settingsLink, QWidget *parent = 0);
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
    QPixmap *getImg() const;
    void setImg(QPixmap *value);

private slots:
    void on_readButton_clicked();
    void on_addToFavButton_clicked();

signals:
    void readItemNews(QString newsLink);
    void addItemToFavorite(NewsItem newsItem);
private:
    Ui::NewsItem *ui;
    QString text;
    QString name;
    QString link;
    QString settngsLink;
    QPixmap *img;


};
#endif // NEWSITEM_H
