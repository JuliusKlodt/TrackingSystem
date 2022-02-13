#ifndef Motors
#define Motors

#include<math.h>





#define pin_motor_en 12

// index definition:
//  pan = 0; tilt = 1; slider = 2

int pin_motors_dir[3] = {4, 6, 16};
int pin_motors_step[3] = {5, 7, 15};


int min_pos[3] = { -3400, -210, 0};
int max_pos[3] = {3400, 420, 6100};

int current_pos[3];
int dir_motors[3];
int step_status_motors[3];


int set_direction(int, int);
void single_motor_step(int);

void motor_setup() {
  pinMode(pin_motor_en, OUTPUT);
  digitalWrite(pin_motor_en, LOW);

  for (int i = 0; i < 3; i++) {
    pinMode(pin_motors_step[i], OUTPUT);
    pinMode(pin_motors_dir[i], OUTPUT);
    dir_motors[i] = 1;
    digitalWrite(pin_motors_dir[i], HIGH);
  }
}




void move_single_motor(int akt_motor, int akt_speed, int steps) {
  steps = set_direction(akt_motor, steps);

  for (int i = 0; i < steps; i++) {
    single_motor_step(akt_motor);
    delayMicroseconds(akt_speed);
  }
}


int set_direction(int akt_motor, int steps) {
  if (steps < 0) {
    digitalWrite(pin_motors_dir[akt_motor], LOW);
    dir_motors[akt_motor] = 0;
    if (current_pos[akt_motor] + steps < min_pos[akt_motor]) {
      steps = min_pos[akt_motor] - current_pos[akt_motor];
    }
  } else {
    digitalWrite(pin_motors_dir[akt_motor], HIGH);
    dir_motors[akt_motor] = 1;
    if (current_pos[akt_motor] + steps > max_pos[akt_motor]) {
      steps = max_pos[akt_motor] - current_pos[akt_motor];
    }
  }
  return fabs(steps);
}


/* This method makes one step with given motor
    int akt_motor => pan=0, tilt=1, slider=2
*/
void single_motor_step(int akt_motor) {
  if (step_status_motors[akt_motor]) {
    digitalWrite(pin_motors_step[akt_motor], LOW);
    step_status_motors[akt_motor] = 0;
  } else
  {
    digitalWrite(pin_motors_step[akt_motor], HIGH);
    step_status_motors[akt_motor] = 1;
  }

  if (dir_motors[akt_motor]) {
    current_pos[akt_motor]++;
  } else {
    current_pos[akt_motor]--;
  }
}



void  motorControlWithJoystick(int x, int y) {

  int num_step_x = 1;
  int num_step_y = 1;

  int akt_speed = 10000;


  if (x < 120) {
    move_single_motor(1, akt_speed, num_step_x);
  } else if (x > 750) {
    move_single_motor(1, akt_speed, -num_step_x);
  }

  if (y < 120) {
    move_single_motor(2, akt_speed, num_step_y);
  } else if (y > 750) {
    move_single_motor(2, akt_speed, -num_step_y);
  }


}



void switchmotors(int b)
{

}





void moveall (int steps_per_motor[], long time_per_motor[])
{
  int dir[3] = {6, 4, 16};
  int motor[3] = {7, 5, 15};

  int steps_done[3] = {0, 0, 0};
  int akt_step_status[3] = {0, 0, 0};







  // set all directions in order to algebraic sign
  for (int i = 0; i < 3; i++) {
    steps_per_motor[i] = set_direction(i, steps_per_motor[i]);
  }
  
  int delay_time[3] = {time_per_motor[0]/steps_per_motor[0], time_per_motor[1]/steps_per_motor[1], time_per_motor[2]/steps_per_motor[2]};
  for(int i = 0; i < 3;i++){
    if(delay_time[i] == 0){
      delay_time[i] = 1;
    }
  }



  long last_millis = 0;
  // motor movement
  while (steps_done[0] != steps_per_motor[0] || steps_done[1] != steps_per_motor[1] || steps_done[2] != steps_per_motor[2] ) {
    long akt_millis = millis();
    while (last_millis == akt_millis)
    {
      akt_millis = millis();
    }
    last_millis = akt_millis;

    for (int i = 0; i < 3; i++) {
      if (steps_done[i] < steps_per_motor[i])
        if (last_millis % delay_time[i] == 0) {
          single_motor_step(i);
          steps_done[i]++;
        }
    }
  }

}







#endif
