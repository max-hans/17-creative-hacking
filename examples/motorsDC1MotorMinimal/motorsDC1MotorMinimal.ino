#include <AFMotor.h>

AF_DCMotor motor1(1);

int runTime = 200;
int waitTime = 10;

void setup() {
  motor1.setSpeed(200);
  
}

void loop() {
  motor1.run(FORWARD);
  delay(runTime);
  motor1.run(RELEASE);
  delay(waitTime);
  motor1.run(BACKWARD);
  delay(runTime);
  motor1.run(RELEASE);
  delay(waitTime);
}
