#ifndef MAP2D_H
#define MAP2D_H

#include <QtGui/QWidget>
#include "../mapwidget/opmapwidget.h"

class Map2D:public QWidget
{

  Q_OBJECT

    // Q_PROPERTY(int MaxZoom READ MaxZoom WRITE SetMaxZoom)
  public:
    Map2D(QWidget* parent = NULL);
    void contextMenuEvent ( QContextMenuEvent * event );

    public slots:
      void setMinZoom(int const& value){op_map.SetMinZoom(value);}
    void reloadMap(){op_map.ReloadMap();}

    void setShowDiagnostics(bool const& value){op_map.SetShowDiagnostics(value);};

    void setCurrentPosition(double lat, double lon){internals::PointLatLng value(lat,lon);op_map.SetCurrentPosition(value);}

    //    double ZoomReal(){return map->Zoom();}
    //    double ZoomDigi(){return map->ZoomDigi();}
    //    double ZoomTotal(){return map->ZoomTotal();}
    void setZoom(double const& value){op_map.SetZoom(value);}
    //
    //    bool UseOpenGL(){return useOpenGL;}
    void setUseOpenGL(bool const& value){op_map.SetUseOpenGL(value);}
    //    void SetShowCompass(bool const& value);
    //
    //    bool CanDragMap()const{return map->CanDragMap();}
    //    void SetCanDragMap(bool const& value){map->SetCanDragMap(value);}
    //
    //    bool isStarted(){return map->core->isStarted();}

    void setShowVehicle(bool const& value){op_map.SetShowUAV(value);}
    bool showVehicle()const{return op_map.ShowUAV();}
    void setVehiclePosition(double lat, double lon);
    void setVehicleHeading(double rad);
    void clearVehicleTrail();

    void setMapType(QString type);

  private:
    mapcontrol::OPMapWidget op_map;

    QMenu context_menu;
    QAction *clear_trait;

};
#endif 
