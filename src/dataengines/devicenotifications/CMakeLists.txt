add_definitions(-DTRANSLATION_DOMAIN=\"lingmo_engine_devicenotifications\")

set(device_notifications_engine_SRCS
    devicenotificationsengine.cpp
    ksolidnotify.cpp
    devicenotificationsengine.h
    ksolidnotify.h
)

add_library(lingmo_engine_devicenotifications MODULE ${device_notifications_engine_SRCS})

target_link_libraries(lingmo_engine_devicenotifications
    KF6::I18n
    KF6::Notifications
    KF6::Solid
    KSysGuard::ProcessCore
    Lingmo::Lingmo5Support
)

install(TARGETS lingmo_engine_devicenotifications DESTINATION ${KDE_INSTALL_PLUGINDIR}/lingmo5support/dataengine)
