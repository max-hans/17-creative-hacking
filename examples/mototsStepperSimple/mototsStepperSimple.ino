////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// motorsDC1Motor.ino
// das hier sollte passieren:
// 1 Gleichstrommotor läuft abwechselnd vor und zurück

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library
#include <AccelStepper.h>
////////////////////////////////////////////////////////////////////////

AF_Stepper motor1(200, 1);

/// Stepper Funktionen

void forwardstep() {
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep() {
  motor1.onestep(BACKWARD, SINGLE);
}

// Stepper initialisieren

AccelStepper stepper(forwardstep, backwardstep);

void setup() {
  
  Serial.begin(9600);
  stepper.setMaxSpeed(300);
  stepper.setAcceleration(500);
}

void loop() {
  Serial.println("running to position 500");
  stepper.runToPosition(500);
  delay(1000);
  Serial.println("running to position 0");
  stepper.runToPosition(0);
  delay(1000);
}



