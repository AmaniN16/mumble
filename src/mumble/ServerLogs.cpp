// Copyright 2021-2022 The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#include "MainWindow.h"
#include "NetworkConfig.h"
#include "SSL.h"
#include "ServerHandler.h"
#include "ServerLogs.h"
#include "UserModel.h"
#include "Version.h"
#include "Global.h"

#include <QTableWidgetItem>

#include <boost/accumulators/accumulators.hpp>

QString ServerLogs::m_unknownStr = tr("Unknown");

ServerLogs::ServerLogs(QWidget *parent) : QDialog(parent) {
	setupUi(this);

	updateFields();

	qbaDigest        = Global::get().sh->qbaDigest;
	QStringList logs = Global::get().db->getLogs(qbaDigest);
	logs.sort();
	foreach (const QString &qs, logs) { QListWidgetItem *qlwi = new QListWidgetItem(qs); }
}

void ServerLogs::ServerLogs() {
	/*updateLogs();
	updateTimeSpan();*/
}

void ServerLogs::on_okButton_clicked() {
	accept();
}
