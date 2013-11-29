/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-device-gre introspection/nm-device-gre.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NMQT_DEVICE_GREINTERFACE_H
#define NMQT_DEVICE_GREINTERFACE_H

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
 * Proxy class for interface org.freedesktop.NetworkManager.Device.Gre
 */
class OrgFreedesktopNetworkManagerDeviceGreInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.NetworkManager.Device.Gre"; }

public:
    OrgFreedesktopNetworkManagerDeviceGreInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNetworkManagerDeviceGreInterface();

    Q_PROPERTY(ushort InputFlags READ inputFlags)
    inline ushort inputFlags() const
    { return qvariant_cast< ushort >(property("InputFlags")); }

    Q_PROPERTY(uint InputKey READ inputKey)
    inline uint inputKey() const
    { return qvariant_cast< uint >(property("InputKey")); }

    Q_PROPERTY(QString Local READ local)
    inline QString local() const
    { return qvariant_cast< QString >(property("Local")); }

    Q_PROPERTY(ushort OutputFlags READ outputFlags)
    inline ushort outputFlags() const
    { return qvariant_cast< ushort >(property("OutputFlags")); }

    Q_PROPERTY(uint OutputKey READ outputKey)
    inline uint outputKey() const
    { return qvariant_cast< uint >(property("OutputKey")); }

    Q_PROPERTY(QDBusObjectPath Parent READ parent)
    inline QDBusObjectPath parent() const
    { return qvariant_cast< QDBusObjectPath >(property("Parent")); }

    Q_PROPERTY(bool PathMtuDiscovery READ pathMtuDiscovery)
    inline bool pathMtuDiscovery() const
    { return qvariant_cast< bool >(property("PathMtuDiscovery")); }

    Q_PROPERTY(QString Remote READ remote)
    inline QString remote() const
    { return qvariant_cast< QString >(property("Remote")); }

    Q_PROPERTY(uchar Tos READ tos)
    inline uchar tos() const
    { return qvariant_cast< uchar >(property("Tos")); }

    Q_PROPERTY(uchar Ttl READ ttl)
    inline uchar ttl() const
    { return qvariant_cast< uchar >(property("Ttl")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

#endif