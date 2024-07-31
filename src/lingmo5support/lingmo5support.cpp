/*
    SPDX-FileCopyrightText: 2005 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <lingmo5support/lingmo5support.h>

#include <QAction>
#include <QMenu>

namespace Lingmo5Support
{
Types::Types(QObject *parent)
    : QObject(parent)
{
}

Types::~Types()
{
}

} // Lingmo5Support namespace

#include "moc_lingmo5support.cpp"
