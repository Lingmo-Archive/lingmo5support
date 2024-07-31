/*
    SPDX-FileCopyrightText: 2009 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#pragma once

#include <Lingmo5Support/Service>
#include <Lingmo5Support/ServiceJob>

class KModifierKeyInfo;

class KeyService : public Lingmo5Support::Service
{
    Q_OBJECT

public:
    KeyService(QObject *parent, KModifierKeyInfo *keyInfo, Qt::Key key);
    void lock(bool lock);
    void latch(bool lock);

protected:
    Lingmo5Support::ServiceJob *createJob(const QString &operation, QMap<QString, QVariant> &parameters) override;

private:
    KModifierKeyInfo *m_keyInfo;
    Qt::Key m_key;
};

class LockKeyJob : public Lingmo5Support::ServiceJob
{
    Q_OBJECT

public:
    LockKeyJob(KeyService *service, const QMap<QString, QVariant> &parameters);
    void start() override;

private:
    KeyService *m_service;
};

class LatchKeyJob : public Lingmo5Support::ServiceJob
{
    Q_OBJECT

public:
    LatchKeyJob(KeyService *service, const QMap<QString, QVariant> &parameters);
    void start() override;

private:
    KeyService *m_service;
};
