#include <Arduino.h>
#include <Servo.h>

Servo servoZAxis;
Servo servoXAxis;
Servo servoYAxis;
Servo servoClamp;

int potPinX = A0;
int potPinY = A1;
int potPinZ = A2;
int potPinClamp = A3;
int valX;
int valY;
int valZ;
int valClamp;

void setup() {
  Serial.begin(9600);
  servoClamp.attach(5);
  servoZAxis.attach(11);
  servoXAxis.attach(9);
  servoYAxis.attach(10);
}
void loop() {
  valX = analogRead(potPinX);
  valX = map(valX, 0, 1023, 0, 180);
  servoXAxis.write(valX);

  valY = analogRead(potPinY);
  valY = map(valY, 0, 1023, 0, 180);
  servoYAxis.write(valY);

  valZ = analogRead(potPinZ);
  valZ = map(valZ, 0, 1023, 0, 180);
  servoZAxis.write(valZ);

  valClamp = analogRead(potPinClamp);
  valClamp = map(valClamp, 0, 1023, 0, 180);
  servoClamp.write(valClamp);
}