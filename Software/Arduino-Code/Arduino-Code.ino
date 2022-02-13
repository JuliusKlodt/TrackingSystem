#include<stdio.h>
#include"Joystick.h"
#include"Magnets.h"
#include"Motors.h"
#include"OLED_display.h"
#include"Menu.h"





void setup() {
  Serial.begin(250000);
  Serial.setTimeout(1);

  joystick_setup();
  magnet_setup();
  motor_setup();
  oled_display_setup();
  menu_init();


  int steps[3] = {200, 200, 200};
  long step_time[3] = {1500, 1500, 1500};
  moveall(steps, step_time);
  int stepsr[3] = { -200, -200, -200};
  moveall(stepsr, step_time);
  /*
    int steps_l[3] = {8000, 8000, 8000};
    int steps_r[3] = { -8000, -8000, -8000};
    long time_in_sek[3] = {10000, 10000, 10500};
    moveall(steps_l, time_in_sek);
    moveall(steps_r, time_in_sek);*/

}





void loop() {
  String command_raw;
  if (Serial.available()) {
    command_raw = Serial.readStringUntil("E");
    int steps_x = command_raw.substring(0, 5).toInt();
    int steps_y = command_raw.substring(5, 10).toInt();
    int speed_x = command_raw.substring(10, 15).toInt();
    int speed_y = command_raw.substring(15, 20).toInt();

    Serial.println("Move");
    int steps[3] = {steps_x,steps_y, 0};
    long step_time[3] = {speed_x, speed_y, 0};
    moveall(steps, step_time);
  }

  process_joystick_values(joystick_status_x(), joystick_status_y(), joystick_status_button());

}

void showCurrentSensors() {
  char *row_names[] = {"Menu", "Magnet Pan: ", "Magnet Tilt: ", "Magnet Slider: ", "Joystick x: ", "Joystick y: "};
  int row_numbers[6] = {0, magnet_status_pan(), magnet_status_tilt(), magnet_status_slider(), joystick_status_x(), joystick_status_y()};
  //oled_disp_show_text(row_names, row_numbers);
}
