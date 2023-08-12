#include "qpartslistsqlmodel.h"
#include "qpartslistmodel.h"
#include "qpartssqlmodel.h"


void QPartsListSqlModel::getAllQPartsModelFromDb(QPartsListModel& listModel, const QPartsSqlModel &sqlModel)
{
    QVector<QPart> parts = sqlModel.Select();
    foreach (auto& part, parts)
    {
        listModel.addPart(part.name());
        dbCache_.emplaceBack(part.name());
    }
}

QVector<QString> QPartsListSqlModel::getListOfSuitableRows(const QString &query)
{
    QVector<QString> temp;
    for(const auto& qPartName : dbCache_)
    {
        if (qPartName.indexOf(query) != -1)
            temp.emplaceBack(qPartName);
    }
    return temp;
}
