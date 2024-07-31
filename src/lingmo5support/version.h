/*
    SPDX-FileCopyrightText: 2008 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINGMO5SUPPORTVERSION_H
#define LINGMO5SUPPORTVERSION_H

/** @file lingmo5support/version.h <Lingmo5Support/Version> */

#include <lingmo5support/lingmo5support_export.h>
#include <lingmo5support_version.h>

#define LINGMO5SUPPORT_MAKE_VERSION(a, b, c) (((a) << 16) | ((b) << 8) | (c))

/**
 * Compile-time macro for checking the lingmo version. Not useful for
 * detecting the version of liblingmo at runtime.
 */
#define LINGMO5SUPPORT_IS_VERSION(a, b, c) (LINGMO5SUPPORT_VERSION >= LINGMO5SUPPORT_MAKE_VERSION(a, b, c))

/**
 * Namespace for everything in liblingmo
 */
namespace Lingmo5Support
{
/**
 * The runtime version of liblingmo
 */
LINGMO5SUPPORT_EXPORT unsigned int version();

/**
 * The runtime major version of liblingmo
 */
LINGMO5SUPPORT_EXPORT unsigned int versionMajor();

/**
 * The runtime major version of liblingmo
 */
LINGMO5SUPPORT_EXPORT unsigned int versionMinor();

/**
 * The runtime major version of liblingmo
 */
LINGMO5SUPPORT_EXPORT unsigned int versionRelease();

/**
 * The runtime version string of liblingmo
 */
LINGMO5SUPPORT_EXPORT const char *versionString();

/**
 * Verifies that a plugin is compatible with lingmo
 */
LINGMO5SUPPORT_EXPORT bool isPluginVersionCompatible(unsigned int version);

} // Lingmo5Support namespace

#endif // multiple inclusion guard
