/*
    SPDX-FileCopyrightText: 2005 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINGMO5SUPPORT_DEFS_H
#define LINGMO5SUPPORT_DEFS_H

/** @header lingmo5support/lingmo5support.h <Lingmo5Support/Lingmo5Support> */

#include <QObject>

#include <lingmo5support/lingmo5support_export.h>

class QAction;

/**
 * Namespace for everything in liblingmo
 */
namespace Lingmo5Support
{
/**
 * @class Types lingmo5support/lingmo5support.h <Lingmo5Support/Lingmo5Support>
 * @short Enums and constants used in Lingmo
 *
 */
class LINGMO5SUPPORT_EXPORT Types : public QObject
{
    Q_OBJECT

public:
    ~Types();


    /**
     * Possible timing alignments
     **/
    enum IntervalAlignment {
        NoAlignment = 0, /**< No alignment **/
        AlignToMinute, /**< Align to the minute **/
        AlignToHour, /**< Align to the hour **/
    };
    Q_ENUM(IntervalAlignment)

private:
    Types(QObject *parent = nullptr);
};

} // Lingmo5Support namespace

#endif // multiple inclusion guard
