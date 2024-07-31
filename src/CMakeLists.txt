add_subdirectory(lingmo5support)
add_subdirectory(declarativeimports)
add_subdirectory(dataengines)

ecm_qt_install_logging_categories(
    EXPORT LINGMO5SUPPORT
    FILE lingmo5support.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)
