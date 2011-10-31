#include "Map2D.h"
#include <stdexcept>

Map2D::Map2D(QWidget *parent):
    QWidget(parent),
    op_map(this),
    context_menu(this)
{
    //setting up layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(&op_map);
    setLayout(layout);

    //setting up popup menue
    clear_trait = new QAction(tr("&Clear Vehicle Trail"),this);
    clear_trait->setStatusTip(tr("Deletes the vehicle trail."));
    connect(clear_trait,SIGNAL(triggered()),this,SLOT(clearVehicleTrail()));
    context_menu.addAction(clear_trait);
}

void Map2D::contextMenuEvent ( QContextMenuEvent * event )
{
    context_menu.exec(event->globalPos());
}

void Map2D::setVehiclePosition(double lat, double lng)
{
    if(!op_map.UAV)
        op_map.SetShowUAV(true);
    internals::PointLatLng value(lat,lng);
    op_map.UAV->SetUAVPos(value,0);
}

void Map2D::setMapType(QString type)
{
    if(type == "GoogleTerrain")
        op_map.SetMapType(MapType::GoogleTerrain);
    else if(type == "GoogleMap")
        op_map.SetMapType(MapType::GoogleMap);
    else
        throw std::runtime_error("Unknown map type: Supported types are GoogleTerrain, GoogleMap");
}

void Map2D::clearVehicleTrail()
{
    if(op_map.UAV)
        op_map.UAV->DeleteTrail();
}

void Map2D::setVehicleHeading(double rad)
{
    if(op_map.UAV)
        op_map.UAV->SetUAVHeading(rad*180.0/M_PI);
}

