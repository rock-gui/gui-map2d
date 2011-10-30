require 'vizkit'

widget = Vizkit.default_loader.Map2D
widget.setUseOpenGL(true)
widget.setMapType("GoogleTerrain")
timer =  Qt::Timer.new
timer2 =  Qt::Timer.new
timer3 =  Qt::Timer.new
timer.connect(SIGNAL('timeout()')) do 
  widget.setCurrentPosition(54.66,10.02)
  widget.setZoom(10)
  timer.stop
  timer2.start(3000)
end

timer2.connect(SIGNAL('timeout()')) do 
  widget.setZoom(15)
  timer2.stop
  timer3.start(2000)
end

timer3.connect(SIGNAL('timeout()')) do 
  @counter ||= 0
  @counter += 0.02
  widget.setVehicleHeading(@counter)
  widget.setVehiclePosition(Math::cos(@counter)*0.01+54.66,10.02+Math::sin(@counter)*0.02)
end

timer.start(3000)
widget.show
Vizkit.exec
