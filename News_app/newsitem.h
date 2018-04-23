#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>
#include <QUrl>
#include <QDataStream>
namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    explicit NewsItem(QString name, QString text, QWidget *parent = 0);
    NewsItem(const NewsItem&, QWidget *parent = 0);
    NewsItem operator=(const NewsItem& other) const;
    void setName(QString);
    void setText(QString);
    QString getName();
    QString getText();
    ~NewsItem();

    QUrl getLink() const;
    void setLink(const QUrl &value);


    QPixmap *getImg() const;
    void setImg(QPixmap *value);
    Ui::NewsItem *ui;
    QString text;
    QString name;
    QUrl link;
    QPixmap *img;


private slots:
    void on_readButton_clicked();

    void on_addToFavButton_clicked();

signals:
    void readItemNews(QUrl newsLink);
    void addItemToFavorite(NewsItem newsItem);
private:

};

QDataStream& operator<<(QDataStream& out, const NewsItem& v);
QDataStream& operator>>(QDataStream& in, NewsItem& v);

Q_DECLARE_METATYPE(NewsItem)

#endif // NEWSITEM_H
