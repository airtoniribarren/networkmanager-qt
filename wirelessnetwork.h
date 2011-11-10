/*
Copyright 2009,2011 Will Stephenson <wstephenson@kde.org>

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

#ifndef NM_WIRELESSNETWORK_H
#define NM_WIRELESSNETWORK_H

#include "nmqt-export.h"

#include <QtCore/QObject>
#include "accesspoint.h"

namespace NetworkManager {

class WirelessNetworkPrivate;
class NMQT_EXPORT WirelessNetwork : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(WirelessNetwork)
    friend class WirelessNetworkInterfaceEnvironment;
    public:
    ~WirelessNetwork();
    /**
     * ESSID of the network
     */
    QString ssid() const;

    /**
     * Signal strength of the network.  Syntactic sugar around tracking the reference access
     * point and watching its signal strength
     */
    int signalStrength() const;

    /**
     * The uni of the current 'best' (strongest) Access Point.  Note that this may change or disappear over time.
     * Get the Access Point object using @ref * WirelessDevice::findAccessPoint() on the NetworkInterface this network was obtained from.
     * Use @ref WirelessDevice::accessPointDisappeared() or
     * WirelessNetwork::referenceAccessPointChanged() to detect this.
     */
    QString referenceAccessPoint() const;

    /**
     * List of access points
     * Subject to change, do not store!
     */
    AccessPointList accessPoints() const;

Q_SIGNALS:
    /**
     * Indicate that the signal strength changed
     * @param strength strength as a percentage.
     */
    void signalStrengthChanged(int strength);
    /**
     * Indicate that the reference access point changed
     * @param apUni new access point or empty string if none
     */
    void referenceAccessPointChanged(const QString &apUni);
    /**
     * Indicate that this network has no more access points
     * (meaning the network has disappeared from view of the network interface)
     * @param ssid the SSID of this network
     */
    void disappeared(const QString & ssid);
private Q_SLOTS:
    void accessPointAppeared(const QString &);
    void accessPointDisappeared(const QString &);
    void updateStrength();
private:
    WirelessNetwork(AccessPoint *, WirelessDevice *network, QObject * parent);
    void addAccessPointInternal(AccessPoint *ap);
    WirelessNetworkPrivate * d_ptr;
};

}
#endif // NM_WIRELESSNETWORK_H