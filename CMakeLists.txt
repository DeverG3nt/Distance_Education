cmake_minimum_required(VERSION 3.5)

project(Distance_Education LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED )
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED )
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Network Widgets )
find_package(Qt5Sql REQUIRED)
find_package(Qt5 5.12.0 REQUIRED COMPONENTS Core Gui WebEngineWidgets Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        secondwindow.cpp
        secondwindow.h
        secondwindow.ui
        resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Distance_Education
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Distance_Education STATIC
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Distance_Education
            ${PROJECT_SOURCES}
        )
    endif()
endif()



target_link_libraries(Distance_Education Qt${QT_VERSION_MAJOR}::Widgets Qt5::Core Qt5::Quick Qt5::Sql Qt5::WebEngineCore Qt5::WebEngineWidgets Qt5::Widgets)

