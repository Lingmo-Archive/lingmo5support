
ecm_add_qml_module(lingmo5supportplugin URI "org.kde.lingmo.lingmo5support" VERSION 2.0 DEPENDENCIES QtCore QtQuick GENERATE_PLUGIN_SOURCE)

target_sources(lingmo5supportplugin PRIVATE
    datamodel.cpp
    datasource.cpp
    serviceoperationstatus.cpp
    types.h
    )


target_link_libraries(lingmo5supportplugin PRIVATE
        Qt::Quick
        Qt::Qml
        KF6::ConfigCore
        KF6::I18n
        Lingmo::Lingmo5Support
        KF6::CoreAddons
)

ecm_finalize_qml_module(lingmo5supportplugin DESTINATION ${KDE_INSTALL_QMLDIR})
