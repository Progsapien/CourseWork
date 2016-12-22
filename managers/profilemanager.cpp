#include "profilemanager.h"

ProfileManager::ProfileManager(QObject *parent) : QObject(parent)
{
    // create;
    ob_file_profile = new QFile;
}

QJsonArray ProfileManager::loadProfile() {
    QJsonArray json;
    ob_file_profile->open(QIODevice::ReadOnly);
    json =  QJsonDocument::fromBinaryData(ob_file_profile->readAll()).array();
    ob_file_profile->close();
    return json;
}

void ProfileManager::dumpProfile(QJsonArray json) {
    QJsonDocument doc;
    doc.setArray(json);

    ob_file_profile->open(QIODevice::WriteOnly);
    ob_file_profile->write(doc.toBinaryData());
    ob_file_profile->close();
}

void ProfileManager::setUsername(QString username) {
    this->username = !username.isEmpty() ? username : "";
    ob_file_profile->setFileName(this->username);
}
