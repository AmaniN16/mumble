// Copyright 2021-2022 The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#include "Connection.h"
#include "MainWindow.h"
#include "NetworkConfig.h"
#include "SSL.h"
#include "ServerHandler.h"
#include "ViewLogs.h"
#include "UserModel.h"
#include "Version.h"
#include "ViewCert.h"
#include "Global.h"

#include <QTableWidgetItem>

#include <boost/accumulators/accumulators.hpp>

#include <cmath>

QString ViewLogs::m_unknownStr = tr("Unknown");

ViewLogs::ViewLogs(QWidget *parent) : QDialog(parent) {
	setupUi(this);

	updateFields();

	qbaDigest          = Global::get().sh->qbaDigest;
	QStringList logs = Global::get().db->getLogs(qbaDigest);
	tokens.sort();
	foreach (const QString &qs, tokens) {
		QListWidgetItem *qlwi = new QListWidgetItem(qs); 
	}

void ViewLogs::ViewLogs() {
	/*updateLogs();
	updateTimeSpan();*/
}

void ViewLogs::on_okButton_clicked() {
	accept();
}

void ViewLogs::on_viewCertButton_clicked() {
	hide();

	ViewCert certViewer(Global::get().sh->qscCert, this);
	certViewer.exec();

	accept();
}
