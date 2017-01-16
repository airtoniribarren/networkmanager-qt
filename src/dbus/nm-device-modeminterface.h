/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p nm-device-modeminterface /home/jgrulich/development/projects/libnm-qt/dbus/introspection/nm-device-modem.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NETWORKMANAGERQT_DEVICE_MODEMINTERFACE_H
#define NETWORKMANAGERQT_DEVICE_MODEMINTERFACE_H

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
 * Proxy class for interface org.freedesktop.NetworkManager.Device.Modem
 */
class OrgFreedesktopNetworkManagerDeviceModemInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef NMQT_STATIC
    {
        return "org.kde.fakenetwork.Device.Modem";
    }
#else
    {
        return "org.freedesktop.NetworkManager.Device.Modem";
    }
#endif
public:
    OrgFreedesktopNetworkManagerDeviceModemInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopNetworkManagerDeviceModemInterface();

    Q_PROPERTY(uint CurrentCapabilities READ currentCapabilities)
    inline uint currentCapabilities() const
    {
        return qvariant_cast< uint >(property("CurrentCapabilities"));
    }

    Q_PROPERTY(uint ModemCapabilities READ modemCapabilities)
    inline uint modemCapabilities() const
    {
        return qvariant_cast< uint >(property("ModemCapabilities"));
    }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

#endif
