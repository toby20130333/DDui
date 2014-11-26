// Copyright 2011 Thomas Kamps anubis1@linux-ecke.de
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef COOKIEJAR_H
#define COOKIEJAR_H

#include <QNetworkCookieJar>
#include <QStringList>
#include <QDebug>
#include "../settings/settings.h"

class CookieJar : public QNetworkCookieJar {
	Q_OBJECT

	public:
		explicit CookieJar(QObject *parent = 0);
		void saveCookies();
		void saveWhiteList();

		void addToWhiteList(QString domain);
		void removeFromWhiteList(QString domain);
		bool isOnWhiteList(QString domain);
		QStringList knownDomains();

		bool savesAllCookies() { return saveAll; }
		void setSaveAll(bool saveAll);

        static CookieJar* jar;

	private:
		QStringList allowedCookieDomains;
		bool saveAll;
};

#endif // COOKIEJAR_H
