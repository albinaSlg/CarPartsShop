#include "qpart.h"


QPart::QPart(QString name, QString code, float weight, QVector3D sizes, QString country, QString description, QString imagePath)
    : name_(name), code_(code), weight_(weight), sizes_(sizes), country_(country), description_(description), imagePath_(imagePath)
{

}

QString QPart::GenerateInsertSql() const
{

}

int QPart::GetId() const
{

}

QString QPart::name() const
{
    return name_;
}

void QPart::setName(const QString &newName)
{
    name_ = newName;
}

QString QPart::code() const
{
    return code_;
}

void QPart::setCode(const QString &newCode)
{
    code_ = newCode;
}

float QPart::weight() const
{
    return weight_;
}

void QPart::setWeight(float newWeight)
{
    weight_ = newWeight;
}

QString QPart::country() const
{
    return country_;
}

void QPart::setCountry(const QString &newCountry)
{
    country_ = newCountry;
}

QString QPart::description() const
{
    return description_;
}

void QPart::setDescription(const QString &newDescription)
{
    description_ = newDescription;
}

QVector3D QPart::sizes() const
{
    return sizes_;
}

void QPart::setSizes(const QVector3D &newSizes)
{
    sizes_ = newSizes;
}

QString QPart::imagePath() const
{
    return imagePath_;
}

void QPart::setImagePath(const QString &newImagePath)
{
    imagePath_ = newImagePath;
}

