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

#include "cookiejar.h"
#include <QDir>
#include <QFile>
#include <QNetworkCookie>

#include <QDateTime>
#include <QDebug>

#include "../settings/settings.h"

CookieJar* CookieJar::jar = 0;

CookieJar::CookieJar(QObject *parent) : QNetworkCookieJar(parent) {
	//Read allowed cookiedomains
    QFile allowedDomains(QDir::homePath()+"/.ybdb/whitelistCookies");
	if (allowedDomains.exists()) {
		allowedDomains.open(QFile::ReadOnly);
		while (allowedDomains.bytesAvailable()) {
			QByteArray arr = allowedDomains.readLine();
			QString domain = QString::fromUtf8(arr);
			if (domain.endsWith("\n"))
				domain.chop(1);
			if (domain.size() < 1) continue;
			qDebug() << "Whitelisted cookiedomain: " << domain;
			allowedCookieDomains.append(domain);
		}
		allowedDomains.close();
	}
	allowedCookieDomains.removeDuplicates();

	//Read saved cookies
    QFile cookies(QDir::homePath()+"/.ybdb/cookies");
	if (cookies.exists()) {
		QList<QNetworkCookie> cookieList;
		cookies.open(QFile::ReadOnly);
		while (cookies.bytesAvailable()) {
			QByteArray arr = cookies.readLine();
			QString cookie = QString::fromUtf8(arr);
			if (cookie.endsWith("\n")) cookie.chop(1);
			cookieList.append(QNetworkCookie::parseCookies(cookie.toUtf8()));
		}
		cookies.close();
		setAllCookies(cookieList);
	}
    qDebug()<<"alfkjalsjkalgjaljskl";
    //saveAll = Settings::get("saveallcookies", QVariant(true)).toBool();
}

void CookieJar::saveCookies() {
    QFile cookieFile(QDir::homePath()+"/.ybdb/cookies");
	cookieFile.open(QFile::WriteOnly);

	qDebug() << "Saving all cookies: " << saveAll;
	//Save cookies, if there are in the allowesCookieDomains-list
	QList<QNetworkCookie> cookies = allCookies();

	for (int i = 0; i < cookies.size(); i++) {
		bool allowed = false;

		//Check if cookies may not be saved
		if (cookies.value(i).isSessionCookie()) continue;
		if (cookies.value(i).expirationDate() < QDateTime::currentDateTime()) continue;

		//Only save non session cookies and is not expirated
		foreach (QString d, allowedCookieDomains) {
			if (saveAll || cookies.value(i).domain().endsWith(d)) {
				allowed = true;
				break;
			}
		}

		if (allowed) {
			cookieFile.write(cookies.value(i).toRawForm()+"\n");
			qDebug() << "Saved cookie from: " << cookies.value(i).domain();
		} else {
			qDebug() << "Discarded cookie from: " << cookies.value(i).domain();
		}
	}
	cookieFile.flush();
	cookieFile.close();

	//Save the save all settings
	Settings::set("saveallcookies", QVariant(saveAll));
}

void CookieJar::saveWhiteList() {
    QFile allowedDomains(QDir::homePath()+"/.ybdb/whitelistCookies");
	allowedDomains.open(QFile::WriteOnly);
	foreach(QString domain, allowedCookieDomains) {
		allowedDomains.write((domain.toUtf8()+"\n"));
	}
	allowedDomains.flush();
	allowedDomains.close();

	qDebug() << "Cookie whitelist saved.";
}

void CookieJar::addToWhiteList(QString domain) {
	if (!allowedCookieDomains.contains(domain)) allowedCookieDomains.append(domain);
}

void CookieJar::removeFromWhiteList(QString domain) {
	allowedCookieDomains.removeAll(domain);
}

bool CookieJar::isOnWhiteList(QString domain) {
	return allowedCookieDomains.contains(domain);
}

QStringList CookieJar::knownDomains() {
	QStringList res;
	QList<QNetworkCookie> cookies = allCookies();

	foreach (QNetworkCookie cookie, cookies) {
		if (!res.contains(cookie.domain())) res.append(cookie.domain());
	}

	return res;
}

void CookieJar::setSaveAll(bool saveAll) {
	this->saveAll = saveAll;
}
