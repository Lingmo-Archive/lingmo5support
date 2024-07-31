/*
    SPDX-FileCopyrightText: 2010 Ryan Rix <ry@n.rix.si>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef PLUGIN_LOADER_H
#define PLUGIN_LOADER_H

#include <QString>
#include <lingmo5support/lingmo5support_export.h>

class KPluginMetaData;
namespace Lingmo5Support
{
class DataEngine;
class Service;

class PluginLoaderPrivate;

/**
 * @class PluginLoader lingmo/pluginloader.h <Lingmo/PluginLoader>
 *
 * This is an abstract base class which defines an interface to which Lingmo's
 * DataEngine and Service Loading logic can communicate with a parent application.
 * This is deprecated api in KF6, use C++ based QML imports instead
 */
class LINGMO5SUPPORT_EXPORT PluginLoader
{
public:
    /**
     * Load a Service plugin.
     *
     * @param name the plugin name of the service to load
     * @param args a list of arguments to supply to the service plugin when loading it
     * @param parent the parent object, if any, for the service
     *
     * @return a Service object, unlike Lingmo5Support::Service::loadService, this can return null.
     **/
    static Service *loadService(const QString &name, QObject *parent = nullptr);

    /**
     * Returns a list of all known dataengines.
     *
     * @param parentApp the application to filter dataengines on. Uses the
     *                  X-KDE-ParentApp entry (if any) in the plugin info.
     *                  The default value of QString() will result in a
     *                  list of all dataengines
     * @return list of dataengines
     **/
    static QList<KPluginMetaData> listDataEngineMetaData(const QString &parentApp = QString());

private:
    PluginLoader() = default;
    virtual ~PluginLoader();
    void *d;
};

}

#endif
