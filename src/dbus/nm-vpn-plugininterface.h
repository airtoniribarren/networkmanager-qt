/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p nm-vpn-plugininterface /home/jgrulich/projects/libnm-qt/dbus/introspection/nm-vpn-plugin.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NETWORKMANAGERQT_VPN_PLUGININTERFACE_H
#define NETWORKMANAGERQT_VPN_PLUGININTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

#include "generictypes.h"

/*
 * Proxy class for interface org.freedesktop.NetworkManager.VPN.Plugin
 */
class OrgFreedesktopNetworkManagerVPNPluginInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef NMQT_STATIC
    {
        return "org.kde.fakenetwork.Settings.VPN.Plugin";
    }
#else
    {
        return "org.freedesktop.NetworkManager.VPN.Plugin";
    }
#endif
public:
    OrgFreedesktopNetworkManagerVPNPluginInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopNetworkManagerVPNPluginInterface();

    Q_PROPERTY(uint State READ state)
    inline uint state() const
    {
        return qvariant_cast< uint >(property("State"));
    }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Connect(const NMVariantMapMap &connection)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(connection);
        return asyncCallWithArgumentList(QLatin1String("Connect"), argumentList);
    }

    inline QDBusPendingReply<> Disconnect()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Disconnect"), argumentList);
    }

    inline QDBusPendingReply<QString> NeedSecrets(const NMVariantMapMap &settings)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(settings);
        return asyncCallWithArgumentList(QLatin1String("NeedSecrets"), argumentList);
    }

    inline QDBusPendingReply<> SetConfig(const QVariantMap &config)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(config);
        return asyncCallWithArgumentList(QLatin1String("SetConfig"), argumentList);
    }

    inline QDBusPendingReply<> SetFailure(const QString &reason)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(reason);
        return asyncCallWithArgumentList(QLatin1String("SetFailure"), argumentList);
    }

    inline QDBusPendingReply<> SetIp4Config(const QVariantMap &config)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(config);
        return asyncCallWithArgumentList(QLatin1String("SetIp4Config"), argumentList);
    }

    inline QDBusPendingReply<> SetIp6Config(const QVariantMap &config)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(config);
        return asyncCallWithArgumentList(QLatin1String("SetIp6Config"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Config(const QVariantMap &config);
    void Failure(uint reason);
    void Ip4Config(const QVariantMap &ip4config);
    void Ip6Config(const QVariantMap &ip6config);
    void LoginBanner(const QString &banner);
    void StateChanged(uint state);
};

#endif
