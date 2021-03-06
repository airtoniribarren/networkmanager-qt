/*
    Copyright 2012-2013  Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NETWORKMANAGERQT_IPV6_SETTING_P_H
#define NETWORKMANAGERQT_IPV6_SETTING_P_H

#include "../ipconfig.h"

#include <QStringList>
#include <QtNetwork/QHostAddress>

namespace NetworkManager
{

class Ipv6SettingPrivate
{
public:
    Ipv6SettingPrivate();

    QString name;
    NetworkManager::Ipv6Setting::ConfigMethod method;
    QList<QHostAddress> dns;
    QStringList dnsSearch;
    QList<NetworkManager::IpAddress> addresses;
    QList<NetworkManager::IpRoute> routes;
    int routeMetric;
    bool ignoreAutoRoutes;
    bool ignoreAutoDns;
    bool neverDefault;
    bool mayFail;
    NetworkManager::Ipv6Setting::IPv6Privacy privacy;
    qint32 dadTimeout;
    NetworkManager::Ipv6Setting::IPv6AddressGenMode addressGenMode;
    qint32 dhcpTimeout;
    QString dhcpHostname;
    QString dhcpDuid;
    QString token;
    QStringList dnsOptions;
    NMVariantMapList addressData;
    NMVariantMapList routeData;
    qint32 routeTable;
};

}
#endif // NETWORKMANAGERQT_IPV6_SETTING_P_H
