/*
    Copyright 2019 Jan Grulich <jgrulich@redhat.com>

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

#ifndef NETWORKMANAGERQT_WIREGUARD_SETTING_H
#define NETWORKMANAGERQT_WIREGUARD_SETTING_H

#include <networkmanagerqt/networkmanagerqt_export.h>
#include "setting.h"

#include <QString>

namespace NetworkManager
{

class WireGuardSettingPrivate;

/**
 * Represents generic setting
 */
class NETWORKMANAGERQT_EXPORT WireGuardSetting : public Setting
{
public:
    typedef QSharedPointer<WireGuardSetting> Ptr;
    typedef QList<Ptr> List;
    WireGuardSetting();
    explicit WireGuardSetting(const Ptr &other);
    ~WireGuardSetting() override;

    QString name() const override;

    quint32 fwmark() const;
    void setFwmark(quint32 fwmark);

    quint32 listenPort() const;
    void setListenPort(quint32 port);

    quint32 mtu() const;
    void setMtu(quint32 mtu);

    bool peerRoutes() const;
    void setPeerRoutes(bool peerRoutes);

    NMVariantMapList peers() const;
    void setPeers(const NMVariantMapList &peers);

    QString privateKey() const;
    void setPrivateKey(const QString &key);

    SecretFlags privateKeyFlags() const;
    void setPrivateKeyFlags(SecretFlags flags);

    void secretsFromMap(const QVariantMap &secrets) override;

    QVariantMap secretsToMap() const override;

    void secretsFromStringMap(const NMStringMap &map) override;

    NMStringMap secretsToStringMap() const override;

    /*
     * Required "preshared-key" properties from "peers" property will be returned
     * as strings in format "peers.public-key.preshared-key".
     */
    QStringList needSecrets(bool requestNew = false) const override;

    void fromMap(const QVariantMap &setting) override;

    QVariantMap toMap() const override;

protected:
    WireGuardSettingPrivate *d_ptr;

private:
    Q_DECLARE_PRIVATE(WireGuardSetting)
};

NETWORKMANAGERQT_EXPORT QDebug operator<<(QDebug dbg, const WireGuardSetting &setting);

}

#endif // NETWORKMANAGERQT_WIREGUARD_SETTING_H

