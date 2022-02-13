#ifndef Menu
#define Menu

char* menu_tree[7][7] = {{"Menu", "Tracking", "Joystick-Control", "Timelaps", "Play movement", "Define movement", "Settings"}, {"Tracking", "Start", "Sensitivity:    ", "Speed:    ", "Back", "", ""}, {"Joystick-Control", "Pan:         ", "Tilt:        ", "Slider:      ", "Speed:    ", "Reset", "Back"}, {"Timelaps", "Start position", "End position", "Time in sek", "Count of pics", "Start", "Back"}, {"Play movement", "Back", "", "", "", "", ""}, {"Define movement", "Name", "Pos1", "Pos2", "Save", "Back", ""}, {"Settings", "input_read_speed:    ", "Set origin", "Back", "", "", ""}};
int menu_current_numbers[7] = { -9999, -9999, -9999, -9999, -9999, -9999, -9999};
int menu_length[7] = {6, 4, 6, 6, 2, 5, 3};

int menu_current_menu = 0;
int menu_current_row = 1;
int menu_selected = 0;

int menu_joystick_control_speed = 2000;

int input_read_speed;




void process_button_pressed_tracking();
void process_button_pressed_joystick_control();
void process_button_pressed_timelaps();
void process_button_pressed_play_movement();
void process_button_pressed_define_movement();
void process_button_pressed_settings();

void move_motor_with_joystick(int);
void set_joystick_movement_speed();
void set_input_read_speed();

void disp_menu();




void menu_init() {
  input_read_speed = 100;
  disp_menu();
}

void process_joystick_values(int x, int y, int button) {
  delay(input_read_speed);
  if (!x && !y && button) {
    return;
  }


  if (!button || x > 0) {
    if (menu_current_menu == 0) {
      menu_current_menu = menu_current_row;
      menu_current_row = 1;
    } else if (menu_current_menu == 1) {
      process_button_pressed_tracking();
    } else if (menu_current_menu == 2) {
      process_button_pressed_joystick_control();
    } else if (menu_current_menu == 3) {
      process_button_pressed_timelaps();
    } else if (menu_current_menu == 4) {
      process_button_pressed_play_movement();
    } else if (menu_current_menu == 5) {
      process_button_pressed_define_movement();
    } else if (menu_current_menu == 6) {
      process_button_pressed_settings();
    }

    disp_menu();

  } else if (y < 0) {
    if (!menu_selected) {
      if (menu_current_row < menu_length[menu_current_menu]) {
        menu_current_row++;
        disp_menu();
      }
    }
  } else if (y > 0) {
    if (!menu_selected) {
      if (menu_current_row > 1) {
        menu_current_row--;
        disp_menu();
      }
    }
  }


}






void process_button_pressed_tracking() {
  if (menu_current_row == 4) {
    menu_current_menu = 0;
    menu_current_row = 1;
  }

}

void process_button_pressed_joystick_control() {
  if (menu_current_row == 6) {
    menu_current_menu = 0;
    menu_current_row = 2;
  } else if (menu_current_row == 1) {
    move_motor_with_joystick(0);
  } else if (menu_current_row == 2) {
    move_motor_with_joystick(1);
  } else if (menu_current_row == 3) {
    move_motor_with_joystick(2);
  } else if (menu_current_row == 4) {
    set_joystick_movement_speed();
  } else if (menu_current_row == 5) {
    menu_selected = 1;
    disp_menu();
    int steps[3] = { -current_pos[0], -current_pos[1], -current_pos[2]};
    long time_for_steps[3] = {4000, 4000, 4000};
    moveall(steps, time_for_steps);
    menu_selected = 0;
    disp_menu();
  }
}

void process_button_pressed_timelaps() {
  if (menu_current_row == 6) {
    menu_current_menu = 0;
    menu_current_row = 3;
  }
}

void process_button_pressed_play_movement() {
  if (menu_current_row == 1) {
    menu_current_menu = 0;
    menu_current_row = 4;
  }
}

void process_button_pressed_define_movement() {
  if (menu_current_row == 5) {
    menu_current_menu = 0;
    menu_current_row = 5;
  }
}

void process_button_pressed_settings() {
  if (menu_current_row == 3) {
    menu_current_menu = 0;
    menu_current_row = 6;
  } else if (menu_current_row == 2) {
    for (int i = 0; i < 3; i++) {
      current_pos[i] = 0;
    }
  } else if (menu_current_row == 1) {
    set_input_read_speed();

  }
}


void move_motor_with_joystick(int motor) {
  delay(200);
  menu_selected = 1;
  disp_menu();

  while (joystick_status_button() && !joystick_status_x())
  {
    int y = joystick_status_y();
    if (y) {
      move_single_motor(motor, menu_joystick_control_speed, y);
      //disp_menu();
    }
  }
  menu_selected = 0;
  disp_menu();
}

void set_joystick_movement_speed() {
  delay(200);
  menu_selected = 1;
  disp_menu();

  while (joystick_status_button() && !joystick_status_x())
  {
    int tmp = menu_joystick_control_speed;
    menu_joystick_control_speed += joystick_status_y() * 200;
    if (tmp != menu_joystick_control_speed) {
      disp_menu();
    }
    delay(50);
  }
  menu_selected = 0;
  disp_menu();
}

void set_input_read_speed() {
  delay(200);
  menu_selected = 1;
  disp_menu();

  while (joystick_status_button() && !joystick_status_x())
  {
    int tmp = input_read_speed;
    input_read_speed += joystick_status_y() * 20;
    if (input_read_speed < 0) {
      input_read_speed = tmp;
    }
    if (tmp != input_read_speed) {
      disp_menu();
    }
    delay(50);
  }
  menu_selected = 0;
  disp_menu();
}




void disp_menu() {
  if (menu_current_menu == 2) {
    menu_current_numbers[1] = current_pos[0];
    menu_current_numbers[2] = current_pos[1];
    menu_current_numbers[3] = current_pos[2];
    menu_current_numbers[4] = menu_joystick_control_speed;
  } else if (menu_current_menu == 6) {
    menu_current_numbers[1] = input_read_speed;
  } else {
    for (int i = 0; i < 7; i++) {
      menu_current_numbers[i] = -9999;
    }
  }


  oled_disp_show_text(menu_tree[menu_current_menu], menu_current_numbers, menu_current_row, menu_selected);
}


#endif
