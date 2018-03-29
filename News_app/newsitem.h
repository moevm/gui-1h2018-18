#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>

namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    explicit NewsItem(QString name, QString text, QWidget *parent = 0);
    NewsItem(const NewsItem&);
    NewsItem operator=(const NewsItem& other) const;
    void setName(QString);
    void setText(QString);
    QString getName();
    QString getText();
    ~NewsItem();

private slots:
    void on_readButton_clicked();

signals:
    void readNews();
private:
    Ui::NewsItem *ui;
    QString text;
    QString name;
};

#endif // NEWSITEM_H
