/*
    SPDX-FileCopyrightText: 2006-2007 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINGMO_DATAENGINEMANAGER_P_H
#define LINGMO_DATAENGINEMANAGER_P_H

#include <lingmo5support/dataengine.h>

namespace Lingmo5Support
{
class DataEngineManagerPrivate;

/**
 * @class DataEngineManager lingmo/dataenginemanager.h <Lingmo/DataEngineManager>
 *
 * @short DataEngine loader and life time manager
 *
 * Lingmo5Support::DataEngineManager provides facilities for listing, loading and
 * according to reference count unloading of DataEngines.
 **/
class DataEngineManager : public QObject
{
    Q_OBJECT
public:
    /**
     * Singleton pattern accessor.
     */
    static DataEngineManager *self();

    /**
     * Returns a data engine object if one is loaded and available.
     * On failure, the fallback NullEngine (which does nothing and
     * !isValid()) is returned.
     *
     * @param name the name of the engine
     */
    Lingmo5Support::DataEngine *engine(const QString &name) const;

    /**
     * Loads a data engine and increases the reference count on it.
     * This should be called once per object (or set of objects) using the
     * DataEngine. Afterwards, dataEngine should be used or the return
     * value cached. Call unloadDataEngine when finished with the engine.
     *
     * @param name the name of the engine
     * @return the data engine that was loaded, or the NullEngine on failure.
     */
    Lingmo5Support::DataEngine *loadEngine(const QString &name);

    /**
     * Decreases the reference count on the engine. If the count reaches
     * zero, then the engine is deleted to save resources.
     */
    void unloadEngine(const QString &name);

protected:
    /**
     * Reimplemented from QObject
     **/
    void timerEvent(QTimerEvent *event) override;

private:
    /**
     * Default constructor. The singleton method self() is the
     * preferred access mechanism.
     */
    DataEngineManager();
    ~DataEngineManager() override;

    DataEngineManagerPrivate *const d;

    friend class DataEngineManagerSingleton;
};

} // namespace Lingmo5Support

#endif // multiple inclusion guard
