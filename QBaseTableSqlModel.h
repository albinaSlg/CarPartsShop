#ifndef QBASETABLESQLMODEL_H
#define QBASETABLESQLMODEL_H

#include <QString>
#include <unordered_set>
#include <utility>

template<class T, const char* _TableName, const char* ...Fields>
class QBaseTableSqlModel
{
public:
    QBaseTableSqlModel()
    {
        std::unordered_set<const char*>& F = const_cast<std::unordered_set<const char*>&>(Fields_);
        (F.emplace(Fields), ...);
    }

    virtual void Add(const T& Object)
    {
        QString Query = Object.GenerateInsertSql();
    }

    virtual void Remove(const T& Object)
    {
        QString Query("DELETE FROM %1 WHERE id = %2");
        Query.arg(TableName_, Object.GetId());
    }

    inline static const QString TableName_ = _TableName;
    inline static const std::unordered_set<const char*> Fields_{};
};

#endif // QBASETABLESQLMODEL_H
