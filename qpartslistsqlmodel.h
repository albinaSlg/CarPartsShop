#ifndef QPARTSLISTSQLMODEL_H
#define QPARTSLISTSQLMODEL_H

#include "qpartslistmodel.h"
#include "qpartssqlmodel.h"

class QPartsListSqlModel
{
public:
    QPartsListSqlModel() = delete;

    static void getAllQPartsModelFromDb(QPartsListModel& listModel, const QPartsSqlModel& sqlModel);
    static QVector<QString> getListOfSuitableRows(const QString &query);

private:
    inline static QVector<QString> dbCache_;
};

#endif // QPARTSLISTSQLMODEL_H
