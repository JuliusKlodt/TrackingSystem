#ifndef Magnets
#define Magnets


#define pin_magnet_pan A5
#define pin_magnet_tilt A4
#define pin_magnet_slider A3

void magnet_setup(){
  pinMode(pin_magnet_pan, INPUT_PULLUP);
  pinMode(pin_magnet_tilt, INPUT_PULLUP);
  pinMode(pin_magnet_slider, INPUT_PULLUP);
  
}

int magnet_status_pan(){
  return digitalRead(pin_magnet_pan);
}

int magnet_status_tilt(){
  return digitalRead(pin_magnet_tilt);
}

int magnet_status_slider(){
  return digitalRead(pin_magnet_slider);
}


#endif
