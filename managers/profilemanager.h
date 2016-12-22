#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class ProfileManager : public QObject
{
    Q_OBJECT
public:
    explicit ProfileManager(QObject *parent = 0);

    void setUsername(QString username);
    QJsonArray loadProfile();
    void dumpProfile(QJsonArray json);

private:
    QString username;
    QFile *ob_file_profile;
};

#endif // PROFILEMANAGER_H
