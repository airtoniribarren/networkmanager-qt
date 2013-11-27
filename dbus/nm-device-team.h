/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-device-team introspection/nm-device-team.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NMQT_DEVICE_TEAMINTERFACE_H
#define NMQT_DEVICE_TEAMINTERFACE_H

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
 * Proxy class for interface org.freedesktop.NetworkManager.Device.Team
 */
class OrgFreedesktopNetworkManagerDeviceTeamInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.NetworkManager.Device.Team"; }

public:
    OrgFreedesktopNetworkManagerDeviceTeamInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNetworkManagerDeviceTeamInterface();

    Q_PROPERTY(bool Carrier READ carrier)
    inline bool carrier() const
    { return qvariant_cast< bool >(property("Carrier")); }

    Q_PROPERTY(QString HwAddress READ hwAddress)
    inline QString hwAddress() const
    { return qvariant_cast< QString >(property("HwAddress")); }

    Q_PROPERTY(QList<QDBusObjectPath> Slaves READ slaves)
    inline QList<QDBusObjectPath> slaves() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Slaves")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

#endif
