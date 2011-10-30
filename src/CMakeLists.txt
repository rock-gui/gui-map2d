
find_package(Qt4 REQUIRED QtCore QtSvg QtGui QtOpengl QtDesigner QtNetwork QtSql)
include_directories(${QT_INCLUDE_DIR})
include_directories(${QT_QTCORE_INCLUDE_DIR})
include_directories(${QT_QTGUI_INCLUDE_DIR})
include_directories(${QT_QTSVG_INCLUDE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Make ui files from the designer to header files
set(UIS 
    mapwidget/mapripform.ui)

QT4_WRAP_UI(SOURCES_UIS_H ${UIS})

FILE(GLOB COLLECTION_MOC_HDRS 
    core/*.h
    internals/*.h 
    internals/projections/*.h
    plugin/*.h
    mapwidget/*.h)

FILE(GLOB COLLECTION_HDRS 
    core/*.h
    internals/*.h 
    internals/projections/*.h
    plugin/*.h
    mapwidget/*.h)

FILE(GLOB COLLECTION_SOURCES 
    core/*.cpp 
    internals/*.cpp 
    plugin/*.cpp
    internals/projections/*.cpp 
    mapwidget/*.cpp)

SET(QtApp_RCCS mapwidget/mapresources.qrc)
QT4_ADD_RESOURCES(QtApp_RCC_SRCS ${QtApp_RCCS})

rock_vizkit_widget(map2d_widget
  SOURCES ${COLLECTION_SOURCES} ${QtApp_RCC_SRCS} ${SOURCES_UIS_H}
    HEADERS ${COLLECTION_HDRS}
    MOC ${COLLECTION_MOC_HDRS}
    DEPS_PKGCONFIG QtNetwork QtSql QtCore QtGui
    LIBS ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTSVG_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTDESIGNER_LIBRARY}
    )
