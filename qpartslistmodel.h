#ifndef QPARTSLISTMODEL_H
#define QPARTSLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>

class QPartsListModel : public QAbstractListModel
{
public:
    explicit QPartsListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool insertRows(int row, int count = 1, const QModelIndex &parent = QModelIndex()) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void clear();

    void addPart(const QString& partName);

private:
    QVector<QString> qParts_;
};

#endif // QPARTSLISTMODEL_H
