/*
    storage.h
    SPDX-FileCopyrightText: 2010 Brian Pritchett <batenkaitos@gmail.com>
    SPDX-FileCopyrightText: 2010 Marco Martin <mart@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINGMO_STORAGE_P_H
#define LINGMO_STORAGE_P_H

#include <QSqlDatabase>

#include <lingmo5support/service.h>
#include <lingmo5support/servicejob.h>

// Begin StorageJob
class StorageJob : public Lingmo5Support::ServiceJob
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap data READ data WRITE setData)

public:
    StorageJob(const QString &destination, const QString &operation, const QVariantMap &parameters, QObject *parent = nullptr);
    ~StorageJob() override;
    void setData(const QVariantMap &data);
    QVariantMap data() const;
    void start() override;
    QString clientName() const;

protected Q_SLOTS:
    void resultSlot(StorageJob *job, const QVariant &result);

private:
    QString m_clientName;
    QVariantMap m_data;
};
// End StorageJob

class Storage : public Lingmo5Support::Service
{
    Q_OBJECT

public:
    explicit Storage(QObject *parent = nullptr);
    ~Storage() override;

protected:
    Lingmo5Support::ServiceJob *createJob(const QString &operation, QVariantMap &parameters) override;

private:
    QString m_clientName;
};

#endif // LINGMO_STORAGE_P_H
