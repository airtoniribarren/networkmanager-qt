/*
    Copyright 2014 Jan Grulich <jgrulich@redhat.com>

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

#ifndef NETWORKMANAGERQT_FAKE_NETWORK_SETTINGS_CONNECTION_H
#define NETWORKMANAGERQT_FAKE_NETWORK_SETTINGS_CONNECTION_H

#include <QObject>

#include <QDBusObjectPath>

#include "../generictypes.h"

class Connection : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.fakenetwork.Settings.Connection")
public:
    explicit Connection(QObject *parent = nullptr, const NMVariantMapMap &settings = NMVariantMapMap());
    virtual ~Connection();

    Q_PROPERTY(bool Unsaved READ unsaved)

    bool unsaved() const;

    /* Not part of DBus interface */
    QString connectionPath() const;
    void setConnectionPath(const QString &path);

public Q_SLOTS: // METHODS
    Q_SCRIPTABLE void  Delete();
    Q_SCRIPTABLE NMVariantMapMap GetSecrets(const QString &setting_name);
    Q_SCRIPTABLE NMVariantMapMap GetSettings();
    Q_SCRIPTABLE void Save();
    Q_SCRIPTABLE void Update(const NMVariantMapMap &properties);
    Q_SCRIPTABLE void UpdateUnsaved(const NMVariantMapMap &properties);

Q_SIGNALS:
    void connectionRemoved(const QDBusObjectPath &path);
    Q_SCRIPTABLE void Removed();
    Q_SCRIPTABLE void Updated();
    Q_SCRIPTABLE void PropertiesChanged(const QVariantMap &properties);

private:
    bool m_unsaved;
    NMVariantMapMap m_settings;

    /* Not part of DBus interface */
    QString m_connectionPath;
};

#endif
