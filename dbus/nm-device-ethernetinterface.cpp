/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -m -p nm-device-ethernetinterface /home/ilia/libnm-qt/libnm-qt/dbus/introspection/nm-device-ethernet.xml
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "nm-device-ethernetinterface.h"

/*
 * Implementation of interface class OrgFreedesktopNetworkManagerDeviceWiredInterface
 */

OrgFreedesktopNetworkManagerDeviceWiredInterface::OrgFreedesktopNetworkManagerDeviceWiredInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

OrgFreedesktopNetworkManagerDeviceWiredInterface::~OrgFreedesktopNetworkManagerDeviceWiredInterface()
{
}


#include "nm-device-ethernetinterface.moc"