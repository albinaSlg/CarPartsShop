#ifndef BASETABLEOBJECT_H
#define BASETABLEOBJECT_H

#include "QBaseTableSqlModel.h"

struct BaseTableObject
{
    virtual QString GenerateInsertSql() const = 0;
    virtual int GetId() const = 0;
};

#endif // BASETABLEOBJECT_H
