/*
    SPDX-FileCopyrightText: 2008 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "debug_p.h"
#include <QDebug>
#include <lingmo5support/version.h>

namespace Lingmo5Support
{
unsigned int version()
{
    return LINGMO5SUPPORT_VERSION;
}

unsigned int versionMajor()
{
    return LINGMO5SUPPORT_VERSION_MAJOR;
}

unsigned int versionMinor()
{
    return LINGMO5SUPPORT_VERSION_MINOR;
}

unsigned int versionRelease()
{
    return LINGMO5SUPPORT_VERSION_PATCH;
}

const char *versionString()
{
    return LINGMO5SUPPORT_VERSION_STRING;
}

bool isPluginVersionCompatible(unsigned int version)
{
    if (version == quint32(-1)) {
        // unversioned, just let it through
        qCWarning(LOG_LINGMO5SUPPORT) << "unversioned plugin detected, may result in instability";
        return true;
    }

    // we require LINGMO5SUPPORT_VERSION_MAJOR and LINGMO5SUPPORT_VERSION_MINOR
    const quint32 minVersion = LINGMO5SUPPORT_MAKE_VERSION(LINGMO5SUPPORT_VERSION_MAJOR, 0, 0);
    const quint32 maxVersion = LINGMO5SUPPORT_MAKE_VERSION(LINGMO5SUPPORT_VERSION_MAJOR, LINGMO5SUPPORT_VERSION_MINOR, 60);

    if (version < minVersion || version > maxVersion) {
#ifndef NDEBUG
        // qCDebug(LOG_LINGMO5SUPPORT) << "plugin is compiled against incompatible Lingmo version  " << version
        //         << "This build is compatible with" << LINGMO5SUPPORT_VERSION_MAJOR << ".0.0 (" << minVersion
        //         << ") to" << LINGMO5SUPPORT_VERSION_STRING << "(" << maxVersion << ")";
#endif
        return false;
    }

    return true;
}

} // Lingmo namespace
