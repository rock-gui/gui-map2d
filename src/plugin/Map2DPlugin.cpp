#include "Map2DPlugin.h"
#include "Map2D.h"

Q_EXPORT_PLUGIN2(OPMapWidgetPluign, Map2DPlugin)

 Map2DPlugin::Map2DPlugin(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

 Map2DPlugin::~Map2DPlugin()
 {
 }

 void Map2DPlugin::initialize(QDesignerFormEditorInterface *formEditor)
 {
     if (initialized)
         return;
     initialized = true;
 }

 bool Map2DPlugin::isInitialized() const
 {
     return initialized;
 }

 QWidget *Map2DPlugin::createWidget(QWidget *parent)
 {
     return new Map2D(parent);
 }

 QString Map2DPlugin::name() const
 {
     return "Map2D";
 }

 QString Map2DPlugin::group() const
 {
     return "Rock-Robotics";
 }

 QIcon Map2DPlugin::icon() const
 {
     return QIcon(":/image_view/icon.png");
 }

 QString Map2DPlugin::toolTip() const
 {
     return "Widget for displaying maps";
 }

 QString Map2DPlugin::whatsThis() const
 {
     return "widgte for displaying maps";
 }

 bool Map2DPlugin::isContainer() const
 {
     return false;
 }

 QString Map2DPlugin::domXml() const
 {
     return "<widget class=\"Map2D\" name=\"map2d\">\n"
            " <property name=\"geometry\">\n"
            "  <rect>\n"
            "   <x>0</x>\n"
            "   <y>0</y>\n"
            "   <width>320</width>\n"
            "   <height>240</height>\n"
            "  </rect>\n"
            " </property>\n"
            " <property name=\"toolTip\" >\n"
            "  <string>ImageView</string>\n"
            " </property>\n"
            " <property name=\"whatsThis\" >\n"
            "  <string>Widget for displaying frames.</string>\n"
            " </property>\n"
            "</widget>\n";
 }

 QString Map2DPlugin::includeFile() const
 {
     return "";
 }

