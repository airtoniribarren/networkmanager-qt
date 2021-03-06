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

#include "cdmasettingtest.h"

#include "settings/cdmasetting.h"

#include <libnm/NetworkManager.h>

#include <QTest>

void CdmaSettingTest::testSetting_data()
{
    QTest::addColumn<QString>("number");
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");
    QTest::addColumn<quint32>("passwordFlags");

    QTest::newRow("setting1")
            << QString("#123456789")    // number
            << QString("username")      // username
            << QString("password")      // password
            << (quint32) 2;             // passwordFlags
}

void CdmaSettingTest::testSetting()
{
    QFETCH(QString, number);
    QFETCH(QString, username);
    QFETCH(QString, password);
    QFETCH(quint32, passwordFlags);

    QVariantMap map;

    map.insert(QLatin1String(NM_SETTING_CDMA_NUMBER), number);
    map.insert(QLatin1String(NM_SETTING_CDMA_USERNAME), username);
    map.insert(QLatin1String(NM_SETTING_CDMA_PASSWORD), password);
    map.insert(QLatin1String(NM_SETTING_CDMA_PASSWORD_FLAGS), passwordFlags);

    NetworkManager::CdmaSetting setting;
    setting.fromMap(map);

    QVariantMap map1 = setting.toMap();
    QVariantMap::const_iterator it = map.constBegin();
    while (it != map.constEnd()) {
        QCOMPARE(it.value(), map1.value(it.key()));
        ++it;
    }
}

QTEST_MAIN(CdmaSettingTest)
