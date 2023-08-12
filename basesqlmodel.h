#ifndef BASESQLMODEL_H
#define BASESQLMODEL_H

#include "singleton.h"
#include <QString>
#include <QSqlDatabase>
#include <QVector>

struct QMessage
{
    enum class QType
    {
        Info,
        Error
    };

    QType Type;
    QString Message;
};

class BaseSqlModel : public Singleton<BaseSqlModel>
{
public:
    void Connect();
    void Disconnect();
    QSqlQuery ExecQuery(const QString& Query);
    QSqlQuery ExecQuery(QSqlQuery& Query);
    QSqlDatabase& getDB();
    QSqlQuery MakeQuery();
    const QVector<QMessage>& GetMessages() const;
    // TODO: create a method to get the last error message
    // TODO: create a method to get the last info message

    ~BaseSqlModel();

public:
    inline static const QString sqlDriver = "QSQLITE";
    inline static const QString dbPath = "D:/visualStudio/Shop/Shop/database/PartsDB.db";

private:
    BaseSqlModel();
    friend class Singleton<BaseSqlModel>;

    QSqlDatabase Database;
    QVector<QMessage> Messages;
};

#endif // BASESQLMODEL_H
