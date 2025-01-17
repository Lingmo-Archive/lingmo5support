/*
    SPDX-FileCopyrightText: 2012 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINGMO_DATAENGINECONSUMER_H
#define LINGMO_DATAENGINECONSUMER_H

#include <QUrl>

#include <lingmo5support/lingmo5support_export.h>

namespace Lingmo5Support
{
class DataEngine;
class DataEngineConsumerPrivate;

/**
 * @class DataEngineConsumer lingmo5support/dataengineconsumer.h <Lingmo/DataEngineConsumer>
 *
 * @brief A class that makes it safe and easy to use DataEngines
 *
 * DataEngineConsumer provides access to DataEngines, which are internally reference
 * counted and shared between all users of them. The only public method provided is
 * dataEngine which returns engines upon request.
 *
 * When the DataEngineConsumer class is deleted, all engines accessed using it are
 * de-referenced and possibly deleted (in the case that there are no other users of
 * the engine in question).
 *
 * DataEngineConsumer can be subclassed by other C++ classes to allow this simple
 * API to be used directly from these classes in a convenient manner.
 **/
class LINGMO5SUPPORT_EXPORT DataEngineConsumer
{
public:
    /**
     * Constructs a DataEngineConsumer
     **/
    DataEngineConsumer();
    ~DataEngineConsumer();

    /**
     * Returns a Lingmo5Support::DataEngine. It never returns a null pointer, and the
     * DataEngine returned should not be deleted. All DataEngines will be dereferenced
     * once this DataEngineConsumer instance is deleted.
     *
     * It is safe and fast to request the same engine more than once.
     *
     * @param name the name of the DataEngine. This corresponds to the plugin name
     *             of the DataEngine.
     */
    DataEngine *dataEngine(const QString &name);

private:
    DataEngineConsumerPrivate *const d;
};

} // namespace Lingmo5Support

#endif
