/*
    SPDX-FileCopyrightText: 2013 Marco Martin <mart@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef SERVICEOPERATIONSTATUS_P
#define SERVICEOPERATIONSTATUS_P

#include <QObject>
#include <QPointer>
#include <QQmlEngine>

#include "lingmo5support/service.h"

namespace Lingmo5Support
{
class Service;
}

/**
 * @class ServiceOperationStatus
 * @short Monitors services
 */
class ServiceOperationStatus : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    /**
     * The service instance we want to monitor
     */
    Q_PROPERTY(Lingmo5Support::Service *service READ service WRITE setService NOTIFY serviceChanged)

    /**
     * the service operation we want to monitor for enabled or disabled status
     */
    Q_PROPERTY(QString operation READ operation WRITE setOperation NOTIFY operationChanged)

    /**
     * true if the service operation is enabled
     */
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

public:
    explicit ServiceOperationStatus(QObject *parent = nullptr);
    ~ServiceOperationStatus() override;

    void setService(Lingmo5Support::Service *service);
    Lingmo5Support::Service *service() const;

    void setOperation(const QString &operation);
    QString operation() const;

    void setEnabled(bool enabled);
    bool isEnabled() const;

Q_SIGNALS:
    void serviceChanged();
    void operationChanged();
    void enabledChanged();

private Q_SLOTS:
    void updateStatus();

private:
    QPointer<Lingmo5Support::Service> m_service;
    QString m_operation;
    bool m_enabled;
};

#endif
