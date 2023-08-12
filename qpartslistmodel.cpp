#include "qpartslistmodel.h"

QPartsListModel::QPartsListModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int QPartsListModel::rowCount(const QModelIndex &parent) const
{
    return qParts_.size();
}

int QPartsListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

bool QPartsListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i = 0; i < count; i++)
    {
        qParts_.insert(row, {});
    }
    endInsertRows();
}

QVariant QPartsListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        return qParts_[index.row()];
    }

    return QVariant();
}

bool QPartsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        if(!checkIndex(index))
            return false;

        qParts_[index.row()] = value.toString();
        emit dataChanged(index, index, {role});

        return true;
    }
}

void QPartsListModel::clear()
{
    int i = qParts_.size();
    qParts_.clear();

    emit dataChanged(this->index(0), this->index(i), {Qt::DisplayRole});
}

void QPartsListModel::addPart(const QString &partName)
{
    int rowIndex = this->rowCount();

    insertRows(rowIndex);
    QVariant variant;
    variant.setValue(partName);
    setData(index(rowIndex), variant);
}
