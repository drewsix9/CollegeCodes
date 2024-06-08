#include <Servo.h>

Servo claw, baseRight;

int joyX = 0;
int joyY = 1;
int joyVal;

void setup() {
  claw.attach(6);
  baseRight.attach(5);
}

void loop() {
  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  claw.write(joyVal);
  delay(15);

  joyVal = analogRead(joyY);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  baseRight.write(joyVal);
  delay(15);
}
