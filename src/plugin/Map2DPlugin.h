
#ifndef MAP2DPLUGIN_H
#define MAP2DPLUGIN_H

#include <QtGui/QtGui>
#include <QtDesigner/QDesignerCustomWidgetInterface>

class Map2DPlugin : public QObject , public QDesignerCustomWidgetInterface
{
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetInterface)

 public:
   Map2DPlugin(QObject *parent = 0);
   virtual ~Map2DPlugin();

   bool isContainer() const;
   bool isInitialized() const;
   QIcon icon() const;
   QString domXml() const;
   QString group() const;
   QString includeFile() const;
   QString name() const;
   QString toolTip() const;
   QString whatsThis() const;
   QWidget *createWidget(QWidget *parent);
   void initialize(QDesignerFormEditorInterface *core);

 private:
   bool initialized; 
};
#endif
