#include "qpartssqlmodel.h"
#include <QSqlError>
#include <basesqlmodel.h>

QPartsSqlModel::QPartsSqlModel()
{
    CreateTable();
}

void QPartsSqlModel::Add(const QPart& qPart)
{
    QSqlQuery query = BaseSqlModel::Instance().MakeQuery();
    query.prepare(QString("INSERT INTO %1(%2, %3, %4, %5, %6, %7, %8, %9, %10)"
                              "VALUES(:partName, :partCode, :partWeight, :partWidth, :partHeight, :partLength, :partCountry, :partDescription, :partImage)").arg(
                          QPart::TableName, QPart::FieldName, QPart::FieldCode, QPart::FieldWeight, QPart::FieldWidth, QPart::FieldHeight,
                          QPart::FieldLength, QPart::FieldCountry, QPart::FieldDescription, QPart::FieldImage));

    query.bindValue(":partName", qPart.name());
    query.bindValue(":partCode", qPart.code());
    query.bindValue(":partWeight", qPart.weight());
    query.bindValue(":partWidth", qPart.sizes().x());
    query.bindValue(":partHeight", qPart.sizes().y());
    query.bindValue(":partLength", qPart.sizes().z());
    query.bindValue(":partCountry", qPart.country());
    query.bindValue(":partDescription", qPart.description());
    query.bindValue(":partImage", qPart.imagePath());

    BaseSqlModel::Instance().ExecQuery(query);
}

void QPartsSqlModel::Remove(const QPart& qPart)
{
    BaseSqlModel::Instance().ExecQuery(
        QString("DELETE FROM %1 (%2) WHERE %2 = '%3')").
        arg(QPart::TableName, QPart::FieldCode, qPart.code())
        );
}

QVector<QPart> QPartsSqlModel::Select(const QString &Fields, const QString &Where, const QString &Limit) const
{
    QSqlQuery Query;
    if(Where != "" && Limit != "")
        Query = BaseSqlModel::Instance().ExecQuery(
            QString("SELECT %1 FROM %2 WHERE %3 LIMIT %4").
            arg(Fields, QPart::TableName, Where, Limit)
            );
    else if (Where != "")
        Query = BaseSqlModel::Instance().ExecQuery(
            QString("SELECT %1 FROM %2 WHERE %3").
            arg(Fields, QPart::TableName, Where)
            );
    else if (Limit != "")
        Query = BaseSqlModel::Instance().ExecQuery(
            QString("SELECT %1 FROM %2 LIMIT %3").
            arg(Fields, QPart::TableName, Limit)
            );
    else
        Query = BaseSqlModel::Instance().ExecQuery(
            QString("SELECT %1 FROM %2").
            arg(Fields, QPart::TableName)
            );

    QVector<QPart> qParts;

    if(Query.exec())
    {
        while(Query.next())
        {
            qParts.append(sqlQueryToPart(Query));
        }
    }

    return qParts;
}

int QPartsSqlModel::Count()
{
    QSqlQuery Query = BaseSqlModel::Instance().ExecQuery(
        QString("SELECT COUNT(%1) FROM %2").
        arg(QPart::FieldName, QPart::TableName)
    );

    if(Query.exec())
    {
        if (Query.next())
        {
            return Query.value(0).toInt();
        }
    }

    return 0;
}

QPart QPartsSqlModel::sqlQueryToPart(const QSqlQuery &query) const
{
    QPart part;
    part.setName(query.value("Name").toString());
    part.setCode(query.value("Code").toString());
    part.setWeight(query.value("Weight").toFloat());
    part.setSizes({query.value("Width").toFloat(), query.value("Height").toFloat(), query.value("Length").toFloat()});
    part.setCountry(query.value("Country").toString());
    part.setDescription(query.value("Description").toString());
    part.setImagePath(query.value("Img").toString());

    return part;
}

void QPartsSqlModel::CreateTable()
{
    BaseSqlModel::Instance().ExecQuery(
        QString("CREATE TABLE IF NOT EXISTS %1(Name NVARCHAR(60), Code NVARCHAR(64), Weight FLOAT, Height FLOAT, Length FLOAT, Width FLOAT, Country NVARCHAR(60), Description TEXT, Img NVARCHAR(512))").
        arg(QPart::TableName)
        );
}

