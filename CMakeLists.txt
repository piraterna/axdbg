cmake_minimum_required(VERSION 3.19)
project(AxDbg LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

add_subdirectory(lib/ads)

qt_standard_project_setup()

qt_add_executable(AxDbg
    WIN32 MACOSX_BUNDLE
    main.cpp
    widgets/mainwindow.cpp widgets/mainwindow.h widgets/ui/mainwindow.ui
    widgets/logswidget.h widgets/logswidget.cpp widgets/ui/logswidget.ui
    widgets/commandswidget.h widgets/commandswidget.cpp widgets/ui/commandswidget.ui
    widgets/preferencesdialog.h widgets/preferencesdialog.cpp widgets/ui/preferencesdialog.ui
)

qt_add_translations(AxDbg TS_FILES translation/cs_CZ.ts)

qt_add_translations(
    TARGETS AxDbg
    TS_FILES translation/en_US.ts translation/cs_CZ.ts
)

target_include_directories(AxDbg PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/ads/src")
target_link_libraries(AxDbg PRIVATE qtadvanceddocking-qt6)

target_link_libraries(AxDbg
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS AxDbg
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET AxDbg
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
