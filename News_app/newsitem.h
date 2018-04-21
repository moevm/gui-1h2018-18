#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>
#include <QUrl>

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

private slots:
    void on_readButton_clicked();

signals:
    void readItemNews(QUrl newsLink);
private:
    Ui::NewsItem *ui;
    QString text;
    QString name;
    QUrl link;
    QPixmap *img;
};

#endif // NEWSITEM_H
