/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-secret-agentinterface /space/kde/src/git/extragear/libs/libnm-qt/dbus/introspection/nm-secret-agent.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NM_SECRET_AGENTINTERFACE_H
#define NM_SECRET_AGENTINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generic-types.h"

/*
 * Proxy class for interface org.freedesktop.NetworkManager.SecretAgent
 */
class OrgFreedesktopNetworkManagerSecretAgentInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.NetworkManager.SecretAgent"; }

public:
    OrgFreedesktopNetworkManagerSecretAgentInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNetworkManagerSecretAgentInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> CancelGetSecrets(const QDBusObjectPath &connection_path, const QString &setting_name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(connection_path) << QVariant::fromValue(setting_name);
        return asyncCallWithArgumentList(QLatin1String("CancelGetSecrets"), argumentList);
    }

    inline QDBusPendingReply<> DeleteSecrets(NMVariantMapMap connection, const QDBusObjectPath &connection_path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(connection) << QVariant::fromValue(connection_path);
        return asyncCallWithArgumentList(QLatin1String("DeleteSecrets"), argumentList);
    }

    inline QDBusPendingReply<NMVariantMapMap> GetSecrets(NMVariantMapMap connection, const QDBusObjectPath &connection_path, const QString &setting_name, const QStringList &hints, uint flags)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(connection) << QVariant::fromValue(connection_path) << QVariant::fromValue(setting_name) << QVariant::fromValue(hints) << QVariant::fromValue(flags);
        return asyncCallWithArgumentList(QLatin1String("GetSecrets"), argumentList);
    }

    inline QDBusPendingReply<> SaveSecrets(NMVariantMapMap connection, const QDBusObjectPath &connection_path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(connection) << QVariant::fromValue(connection_path);
        return asyncCallWithArgumentList(QLatin1String("SaveSecrets"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif