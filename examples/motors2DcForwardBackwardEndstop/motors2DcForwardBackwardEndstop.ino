////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// das hier sollte passieren:
// 2 gleichstrommotoren fährt zwischen ihren endstops hin und her

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Endschalter deklarieren

#define ENDSTOP1  A0
#define ENDSTOP2  A1
#define POTI1     A2

#define ENDSTOP3  A3
#define ENDSTOP4  A4
#define POTI2     A5

// Motoren initialisieren

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

// Motorparameter

// Variablen zum Speichern der Motorgeschwindigkeiten
int speed1 = 100;
int speed2 = 100;

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);               // Kommunikation mit dem Rechner starten
  motor1.setSpeed(speed1);    // Variable mit der Geschwindigkeit in Motoren schreiben
  motor1.run(FORWARD);
  Serial.println("motor1 - forward");   // feedback an rechner geben
  Serial.println("motor2 - forward");   // feedback an rechner geben
}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {

  // int speed1 = map(analogRead(POTI1),0,1023,0,255);
  // motor1.setSpeed(speed1);

  // int speed2 = map(analogRead(POTI2),0,1023,0,255);
  // motor1.setSpeed(speed2);

  // Motor 1
  if (ENDSTOP1 == HIGH) {
    motor1.run(BACKWARD);
    Serial.println("motor1 - backward");   // feedback an rechner geben
  }

  if (ENDSTOP2 == HIGH) {
    motor1.run(FORWARD);
    Serial.println("motor1 - forward");   // feedback an rechner geben
  }

  // Motor 2
  if (ENDSTOP3 == HIGH) {
    motor2.run(BACKWARD);
    Serial.println("motor2 - backward");   // feedback an rechner geben
  }

  if (ENDSTOP4 == HIGH) {
    motor2.run(FORWARD);
    Serial.println("motor2 - forward");   // feedback an rechner geben
  }

}

////////////////////////////////////////////////////////////////////////
