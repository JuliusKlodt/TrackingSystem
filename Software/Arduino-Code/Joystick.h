#ifndef Joystick
#define Joystick

#define pin_joystick_x A6
#define pin_joystick_y A7
#define pin_joystick_button A0

void joystick_setup() {
  pinMode(pin_joystick_x, INPUT);
  pinMode(pin_joystick_y, INPUT);
  pinMode(pin_joystick_button, INPUT_PULLUP);
}

int joystick_raw_status_x() {
  return analogRead(pin_joystick_x);
}

int joystick_raw_status_y() {
  return analogRead(pin_joystick_y);
}

int joystick_status_button() {
  return digitalRead(pin_joystick_button);
}

int joystick_status_x() {
  int val = analogRead(pin_joystick_x);

  if (val < 200) {
    return -1;
  } else if (val < 800) {
    return 0;
  } else {
    return 1;
  }
}

int joystick_status_y() {
  int val = analogRead(pin_joystick_y);

  if (val < 200) {
    return -1;
  } else if (val < 800) {
    return 0;
  } else {
    return 1;
  }
}

#endif
