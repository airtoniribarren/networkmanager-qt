/*
Copyright 2011 Ilia Kats <ilia-kats@gmx.net>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "wimaxnsp.h"
#include "dbus/nm-wimax-nspinterface.h"
#include "manager_p.h"
#include "wimaxdevice.h"

#include "nmdebug.h"

namespace NetworkManager {

class WimaxNspPrivate
{
public:
    WimaxNspPrivate( const QString & path ) : iface( NetworkManagerPrivate::DBUS_SERVICE, path, QDBusConnection::systemBus()), networkType(WimaxNsp::Unknown), signalQuality(0)
    {
    }
    OrgFreedesktopNetworkManagerWiMaxNspInterface iface;
    QString uni;
    WimaxNsp::NetworkType networkType;
    QString name;
    uint signalQuality;
};
}

NetworkManager::WimaxNsp::WimaxNsp( const QString& path, QObject * parent ) : QObject(parent), d_ptr(new WimaxNspPrivate( path ))
{
    Q_D(WimaxNsp);
    d->uni = path;
    if (d->iface.isValid()) {
        d->networkType = convertNetworkType( d->iface.networkType() );
        d->name = d->iface.name();
        d->signalQuality = d->iface.signalQuality();
        connect( &d->iface, SIGNAL(PropertiesChanged(const QVariantMap &)),
                 this, SLOT(propertiesChanged(const QVariantMap &)));
    }
}

NetworkManager::WimaxNsp::~WimaxNsp()
{
    Q_D(WimaxNsp);
    delete d;
}

QString NetworkManager::WimaxNsp::uni() const
{
    Q_D(const WimaxNsp);
    return d->uni;
}

NetworkManager::WimaxNsp::NetworkType NetworkManager::WimaxNsp::networkType() const
{
    Q_D(const WimaxNsp);
    return d->networkType;
}

QString NetworkManager::WimaxNsp::name() const
{
    Q_D(const WimaxNsp);
    return d->name;
}

uint NetworkManager::WimaxNsp::signalQuality() const
{
    Q_D(const WimaxNsp);
    return d->signalQuality;
}

void NetworkManager::WimaxNsp::propertiesChanged(const QVariantMap &properties)
{
    Q_D(WimaxNsp);
    QStringList propKeys = properties.keys();
    //nmDebug() << propKeys;
    QLatin1String nameKey("Name"),
                  networkTypeKey("NetworkType"),
                  signalQualityKey("SignalQuality");
    QVariantMap::const_iterator it = properties.find(networkTypeKey);
    if (it != properties.end()) {
        d->networkType = convertNetworkType(it->toUInt());
        emit networkTypeChanged(d->networkType);
        propKeys.removeOne(networkTypeKey);
    }
    it = properties.find(nameKey);
    if (it != properties.end()) {
        d->name = it->toString();
        emit nameChanged(d->name);
        propKeys.removeOne(nameKey);
    }
    it = properties.find(signalQualityKey);
    if (it != properties.end()) {
        d->signalQuality = it->toUInt();
        emit signalQualityChanged(d->signalQuality);
        propKeys.removeOne(signalQualityKey);
    }
    if (propKeys.count()) {
        nmDebug() << "Unhandled properties: " << propKeys;
    }
}

NetworkManager::WimaxNsp::NetworkType NetworkManager::WimaxNsp::convertNetworkType(uint type)
{
    switch (type) {
        case 0:
            return NetworkManager::WimaxNsp::Unknown;
        case 1:
            return NetworkManager::WimaxNsp::Home;
        case 2:
            return NetworkManager::WimaxNsp::Partner;
        case 3:
            return NetworkManager::WimaxNsp::RoamingPartner;
    }
    return NetworkManager::WimaxNsp::Unknown;
}