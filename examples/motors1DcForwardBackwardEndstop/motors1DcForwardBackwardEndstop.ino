////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// das hier sollte passieren:
// 1 gleichstrommotor fährt zwischen den endstops hin und her

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Wenn nötig Endschalter deklarieren

#define ENDSTOP1  A0
#define ENDSTOP2  A1
#define POTI1     A2

// Motoren initialisieren

AF_DCMotor motor1(1);

// Motorparameter

// Variablen zum Speichern der Motorgeschwindigkeiten
int speed1 = 100;

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);               // Kommunikation mit dem Rechner starten
  motor1.setSpeed(speed1);    // Variable mit der Geschwindigkeit in Motoren schreiben
  motor1.run(FORWARD);
  Serial.println("motor1 - forward");   // feedback an rechner geben
}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {

  // speed1 = map(analogRead(POTI),0,1023,0,255);
  // motor1.setSpeed(speed1);

  if (ENDSTOP1 == HIGH) {
    motor1.run(BACKWARD);
  }

  if (ENDSTOP2 == HIGH) {
    motor1.run(FORWARD);
  }

}

////////////////////////////////////////////////////////////////////////
