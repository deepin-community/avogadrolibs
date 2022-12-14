find_package(Eigen3 REQUIRED)
# Add as "system headers" to avoid warnings generated by them with
# compilers that support that notion.
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Provide some simple API to find the plugins, scripts, etc.
if(APPLE)
  # It is a special case, the app bundle logic breaks the relative pathing.
  add_definitions(-DAvogadroLibs_LIB_DIR=\"lib\")
  add_definitions(-DAvogadroLibs_DATA_DIR=\"share\")
else()
  add_definitions(-DAvogadroLibs_LIB_DIR=\"${INSTALL_LIBRARY_DIR}\")
  add_definitions(-DAvogadroLibs_DATA_DIR=\"${INSTALL_DATA_DIR}\")
endif()

if(USE_SPGLIB)
  add_definitions(-DUSE_SPGLIB)
endif()

# Find python for input generator scripts:
find_package(PythonInterp 3)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/avogadropython.h.in"
"namespace Avogadro {
static const char *pythonInterpreterPath = \"${PYTHON_EXECUTABLE}\";
}
")
configure_file("${CMAKE_CURRENT_BINARY_DIR}/avogadropython.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/avogadropython.h")

set(HEADERS
  backgroundfileformat.h
  colorbutton.h
  containerwidget.h
  customelementdialog.h
  elementtranslator.h
  extensionplugin.h
  filebrowsewidget.h
  fileformatdialog.h
  generichighlighter.h
  hydrogentools.h
  interfacescript.h
  interfacewidget.h
  jsonwidget.h
  layermodel.h
  rwlayermanager.h
  meshgenerator.h
  molecule.h
  moleculemodel.h
  multiviewwidget.h
  periodictableview.h
  persistentatom.h
  persistentbond.h
  pluginlayermanager.h
  pythonscript.h
  rwmolecule.h
  sceneplugin.h
  scenepluginmodel.h
  scriptloader.h
  toolplugin.h
  utilities.h
  viewfactory.h
)

set(SOURCES
  backgroundfileformat.cpp
  colorbutton.cpp
  containerwidget.cpp
  customelementdialog.cpp
  elementdetail_p.cpp
  elementitem_p.cpp
  elementtranslator.cpp
  extensionplugin.cpp
  filebrowsewidget.cpp
  fileformatdialog.cpp
  generichighlighter.cpp
  hydrogentools.cpp
  interfacescript.cpp
  interfacewidget.cpp
  jsonwidget.cpp
  layermodel.cpp
  rwlayermanager.cpp
  meshgenerator.cpp
  molecule.cpp
  moleculemodel.cpp
  multiviewwidget.cpp
  periodictablescene_p.cpp
  periodictableview.cpp
  pluginlayermanager.cpp
  pythonscript.cpp
  rwmolecule.cpp
  sceneplugin.cpp
  scenepluginmodel.cpp
  scriptloader.cpp
  toolplugin.cpp
  utilities.cpp
  viewfactory.cpp
)

set(UIS
  customelementdialog.ui
)
qt5_wrap_ui(UI_SOURCES ${UIS})
list(APPEND SOURCES ${UI_SOURCES})

set(RCS
  qtgui.qrc
)
qt5_add_resources(RC_SOURCES ${RCS})
list(APPEND SOURCES ${RC_SOURCES})

avogadro_add_library(AvogadroQtGui ${HEADERS} ${SOURCES})
target_link_libraries(AvogadroQtGui AvogadroIO Qt5::Widgets)
