#include "basesqlmodel.h"

#include <QSqlQuery>
#include <memory>
#include <QSqlError>

BaseSqlModel::BaseSqlModel()
{
    Connect();
}

BaseSqlModel::~BaseSqlModel()
{
    Disconnect();
}

void BaseSqlModel::Connect()
{
    Database = QSqlDatabase::addDatabase(sqlDriver);
    Database.setDatabaseName(dbPath);

    if (!Database.open())
    {
        Messages.append({QMessage::QType::Error, "Database can not be opened"});
        return;
    }
}

void BaseSqlModel::Disconnect()
{
    Database.close();
}

QSqlQuery BaseSqlModel::ExecQuery(const QString& Query)
{
    QSqlQuery SqlQuery(Database);
    if (!SqlQuery.exec(Query))
    {
        Messages.append({QMessage::QType::Error, "Invalid SQL query: " + Query});
        return QSqlQuery(nullptr);
    }
    return SqlQuery;
}

QSqlQuery BaseSqlModel::ExecQuery(QSqlQuery &Query)
{
    if (!Query.exec())
    {
        Messages.append({QMessage::QType::Error, "Invalid SQL query: " + Query.lastQuery()});
        qDebug() << Query.lastError();
        return QSqlQuery(nullptr);
    }
    return Query;
}

QSqlDatabase& BaseSqlModel::getDB()
{
    return Database;
}

QSqlQuery BaseSqlModel::MakeQuery()
{
    return QSqlQuery(Database);
}

const QVector<QMessage> &BaseSqlModel::GetMessages() const
{
    return Messages;
}
