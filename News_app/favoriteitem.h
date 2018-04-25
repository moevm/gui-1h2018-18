#ifndef FAVORITEITEM_H
#define FAVORITEITEM_H

#include <QWidget>

namespace Ui {
class FavoriteItem;
}

class FavoriteItem : public QWidget
{
    Q_OBJECT

public:
    explicit FavoriteItem(QWidget *parent = 0);
    explicit FavoriteItem(QString name, QString text, QString link, QString settingsLink, QWidget *parent = 0);
    FavoriteItem(const FavoriteItem&, QWidget *parent = 0);
    FavoriteItem operator=(const FavoriteItem& other) const;
    ~FavoriteItem();

    QString getText() const;
    void setText(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getLink() const;
    void setLink(const QString &value);

    QString getSettingsLink();
    void setSettingsLink(QString settingsLink);

private slots:
    void on_addToFavButton_clicked();

signals:
    void reoveItemFromFavorite(FavoriteItem newsItem);

private:
    Ui::FavoriteItem *ui;
    QString text;
    QString name;
    QString link;
    QString settngsLink;
};

#endif // FAVORITEITEM_H
