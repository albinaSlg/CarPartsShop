#ifndef QPART_H
#define QPART_H

#include <QString>
#include <map>
#include <QVector3D>
#include "BaseTableObject.h"

struct Countries
{
    inline static std::map<QString, QString> names = {{"UA", "Ukraine"}, {"None", "None"}};
};

class QPart : public BaseTableObject
{
public:
    QPart() = default;
    QPart(QString name, QString code, float weight, QVector3D sizes, QString country, QString description, QString imagePath);

    ~QPart() = default;

    QString GenerateInsertSql() const override;
    int GetId() const override;

    QString name() const;
    void setName(const QString &newName);

    QString code() const;
    void setCode(const QString &newCode);

    float weight() const;
    void setWeight(float newWeight);

    QString country() const;
    void setCountry(const QString &newCountry);

    QString description() const;
    void setDescription(const QString &newDescription);

    QVector3D sizes() const;
    void setSizes(const QVector3D &newSizes);

    QString imagePath() const;
    void setImagePath(const QString &newImagePath);

public:
    inline static const char TableName[] = "Parts";
    inline static const char FieldName[] = "Name";
    inline static const char FieldCode[] = "Code";
    inline static const char FieldWeight[] = "Weight";
    inline static const char FieldHeight[] = "Height";
    inline static const char FieldLength[] = "Length";
    inline static const char FieldWidth[] = "Width";
    inline static const char FieldCountry[] = "Country";
    inline static const char FieldDescription[] = "Description";
    inline static const char FieldImage[] = "Img";

private:
    int id_ = 0;
    QString name_ = "None";
    QString code_ = "None";
    float weight_ = 0;
    QVector3D sizes_;
    QString country_ = Countries::names["None"];
    QString description_ = "None";
    QString imagePath_ = "blank.png";
};

#endif // QPART_H
