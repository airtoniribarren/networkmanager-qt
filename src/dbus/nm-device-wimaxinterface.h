/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p nm-device-wimaxinterface /home/jgrulich/development/projects/libnm-qt/dbus/introspection/nm-device-wimax.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NETWORKMANAGERQT_DEVICE_WIMAXINTERFACE_H
#define NETWORKMANAGERQT_DEVICE_WIMAXINTERFACE_H

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
 * Proxy class for interface org.freedesktop.NetworkManager.Device.WiMax
 */
class OrgFreedesktopNetworkManagerDeviceWiMaxInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef NMQT_STATIC
    {
        return "org.kde.fakenetwork.Device.WiMax";
    }
#else
    {
        return "org.freedesktop.NetworkManager.Device.WiMax";
    }
#endif
public:
    OrgFreedesktopNetworkManagerDeviceWiMaxInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopNetworkManagerDeviceWiMaxInterface();

    Q_PROPERTY(QDBusObjectPath ActiveNsp READ activeNsp)
    inline QDBusObjectPath activeNsp() const
    {
        return qvariant_cast< QDBusObjectPath >(property("ActiveNsp"));
    }

    Q_PROPERTY(QString Bsid READ bsid)
    inline QString bsid() const
    {
        return qvariant_cast< QString >(property("Bsid"));
    }

    Q_PROPERTY(uint CenterFrequency READ centerFrequency)
    inline uint centerFrequency() const
    {
        return qvariant_cast< uint >(property("CenterFrequency"));
    }

    Q_PROPERTY(int Cinr READ cinr)
    inline int cinr() const
    {
        return qvariant_cast< int >(property("Cinr"));
    }

    Q_PROPERTY(QString HwAddress READ hwAddress)
    inline QString hwAddress() const
    {
        return qvariant_cast< QString >(property("HwAddress"));
    }

    Q_PROPERTY(QList<QDBusObjectPath> Nsps READ nsps)
    inline QList<QDBusObjectPath> nsps() const
    {
        return qvariant_cast< QList<QDBusObjectPath> >(property("Nsps"));
    }

    Q_PROPERTY(int Rssi READ rssi)
    inline int rssi() const
    {
        return qvariant_cast< int >(property("Rssi"));
    }

    Q_PROPERTY(int TxPower READ txPower)
    inline int txPower() const
    {
        return qvariant_cast< int >(property("TxPower"));
    }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QList<QDBusObjectPath> > GetNspList()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetNspList"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void NspAdded(const QDBusObjectPath &nsp);
    void NspRemoved(const QDBusObjectPath &nsp);
    void PropertiesChanged(const QVariantMap &properties);
};

#endif
