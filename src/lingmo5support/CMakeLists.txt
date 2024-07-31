
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config-lingmo5support.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-lingmo5support.h)

add_library(Lingmo5Support)
add_library(Lingmo::Lingmo5Support ALIAS Lingmo5Support)

qt_extract_metatypes(Lingmo5Support)

set_target_properties(Lingmo5Support PROPERTIES
    VERSION     ${LINGMO5SUPPORT_VERSION}
    SOVERSION   ${LINGMO5SUPPORT_SOVERSION}
    EXPORT_NAME Lingmo5Support
)

########### next target ###############
target_sources(Lingmo5Support PRIVATE
#global
    lingmo5support.cpp
    pluginloader.cpp
    version.cpp

#Dataengines, services
    datacontainer.cpp
    dataengine.cpp
    dataengineconsumer.cpp
    service.cpp
    servicejob.cpp
    private/datacontainer_p.cpp
    private/dataenginemanager.cpp
    private/storage.cpp
    private/storagethread.cpp
)

ecm_qt_declare_logging_category(Lingmo5Support
    HEADER debug_p.h
    IDENTIFIER LOG_LINGMO5SUPPORT
    CATEGORY_NAME kf.lingmo5support.core
    OLD_CATEGORY_NAMES org.kde.lingmo5support
    DESCRIPTION "Lingmo5Support Core lib"
    EXPORT LINGMO5SUPPORT
)

ecm_generate_export_header(Lingmo5Support
    EXPORT_FILE_NAME lingmo5support/lingmo5support_export.h
    BASE_NAME Lingmo5Support
    GROUP_BASE_NAME KF
    VERSION ${PROJECT_VERSION}
    DEPRECATED_BASE_VERSION 0
    DEPRECATION_VERSIONS 5.6 5.19 5.28 5.30 5.36 5.46 5.67 5.77 5.78 5.81
)

target_link_libraries(Lingmo5Support
PUBLIC
    KF6::ConfigCore #KConfigGroup
    KF6::CoreAddons
PRIVATE
    Qt::Gui
    Qt::Sql
    Qt::Widgets
    KF6::I18n
    KF6::ConfigGui
    KF6::CoreAddons
)

set(Lingmo5Support_BUILD_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/Lingmo5Support
)
target_include_directories(Lingmo5Support PUBLIC
  "$<BUILD_INTERFACE:${Lingmo5Support_BUILD_INCLUDE_DIRS}>"
)
target_include_directories(Lingmo5Support INTERFACE
  "$<INSTALL_INTERFACE:${KDE_INSTALL_INCLUDEDIR};${KDE_INSTALL_INCLUDEDIR}/Lingmo5Support>"
)

set_target_properties(Lingmo5Support PROPERTIES
                                VERSION ${LINGMO5SUPPORT_VERSION}
                                SOVERSION ${LINGMO5SUPPORT_SOVERSION}
                                EXPORT_NAME Lingmo5Support
                      )

########### install files ###############
ecm_generate_headers(Lingmo5Support_CamelCase_HEADERS
    HEADER_NAMES
        DataContainer
        DataEngine
        DataEngineConsumer
        PluginLoader
        Service
        ServiceJob
        Lingmo5Support
    REQUIRED_HEADERS Lingmo5Support_HEADERS
    PREFIX Lingmo5Support
)

set(Lingmo5Support_HEADERS
    ${Lingmo5Support_HEADERS}
    version.h
)

install(FILES
        ${Lingmo5Support_HEADERS}
        ${CMAKE_CURRENT_BINARY_DIR}/lingmo5support/lingmo5support_export.h
        DESTINATION ${KDE_INSTALL_INCLUDEDIR}/Lingmo5Support/lingmo5support COMPONENT Devel)

install(FILES ${Lingmo5Support_CamelCase_HEADERS}
        DESTINATION ${KDE_INSTALL_INCLUDEDIR}/Lingmo5Support/Lingmo5Support COMPONENT Devel)

install(FILES data/operations/dataengineservice.operations DESTINATION ${LINGMO5SUPPORT_DATA_INSTALL_DIR}/services)
install(FILES data/operations/plasmoidservice.operations DESTINATION ${LINGMO5SUPPORT_DATA_INSTALL_DIR}/services)
install(FILES data/operations/storage.operations DESTINATION ${LINGMO5SUPPORT_DATA_INSTALL_DIR}/services)

install(TARGETS Lingmo5Support EXPORT Lingmo5SupportTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

if(BUILD_QCH)
    ecm_add_qch(
        Lingmo5Support_QCH
        NAME Lingmo5Support
        BASE_NAME Lingmo5Support
        VERSION ${PROJECT_VERSION}
        ORG_DOMAIN org.kde
        SOURCES # using only public headers, to cover only public API
            ${Lingmo5Support_HEADERS}
            ${LingmoScripting_HEADERS}
            Mainpage.dox
        MD_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md"
        LINK_QCHS
            Qt6Gui_QCH
            KF6Service_QCH
            KF6Package_QCH
        INCLUDE_DIRS
            ${Lingmo5Support_BUILD_INCLUDE_DIRS}
        BLANK_MACROS
            LINGMO5SUPPORT_EXPORT
            LINGMO5SUPPORT_DEPRECATED
            LINGMO5SUPPORT_DEPRECATED_EXPORT
            "LINGMO5SUPPORT_DEPRECATED_VERSION(x, y, t)"
        TAGFILE_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        QCH_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        COMPONENT Devel
    )
endif()
