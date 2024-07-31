add_definitions(-DTRANSLATION_DOMAIN=\"lingmo_engine_keystate\")

set(keystate_engine_SRCS
    keystate.cpp
    keyservice.cpp
    keystate.h
    keyservice.h
)

kcoreaddons_add_plugin(lingmo_engine_keystate SOURCES ${keystate_engine_SRCS} INSTALL_NAMESPACE lingmo5support/dataengine)

target_link_libraries(lingmo_engine_keystate
    KF6::GuiAddons
    Lingmo::Lingmo5Support
    KF6::I18n
)

install(FILES modifierkeystate.operations DESTINATION ${LINGMO5SUPPORT_DATA_INSTALL_DIR}/services)
