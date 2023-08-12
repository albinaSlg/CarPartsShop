#ifndef QPARTSSQLMODEL_H
#define QPARTSSQLMODEL_H

#include "qpart.h"

#include <QString>
#include <QVector>
#include <QSqlQuery>
#include "QBaseTableSqlModel.h"

class QPartSqlInterface
{
public:
    QPartSqlInterface() = delete;

};

class QPartsSqlModel : public QBaseTableSqlModel<QPart, QPart::TableName, QPart::FieldName, QPart::FieldCode, QPart::FieldWeight, QPart::FieldHeight,
                                                 QPart::FieldLength, QPart::FieldWidth, QPart::FieldCountry, QPart::FieldDescription, QPart::FieldImage>
{
public:
    QPartsSqlModel();
    void Add(const QPart& qPart);
    void Remove(const QPart& qPart);
    QVector<QPart> Select(const QString& Fields = "*",
                          const QString& Where = "",
                          const QString& Limit = "") const;

    int Count();

private:
    QPart sqlQueryToPart(const QSqlQuery& query) const;
    void CreateTable();

    // SELECT * FROM parts WHERE id > 10 LIMIT 5
};

#endif // QPARTSSQLMODEL_H
