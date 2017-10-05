////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// dcMotorsParallel
// das hier sollte passieren:
// 2 gleichstrommotoren fahren gleichzeitig zwischen ihren Endstopschaltern hin und her

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Wenn nötig Endschalter deklarieren

#define ENDSTOP11 A0
#define ENDSTOP12 A1
#define ENDSTOP21 A2
#define ENDSTOP22 A3

// Motoren initialisieren

AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

// Motorparameter

// Variablen zum Speichern der Motorgeschwindigkeiten
int maxSpeed1 = 100;
int maxSpeed2 = 200;

unsigned int runTime = 200;               // Laufzeit der Motoren in ms
unsigned int waitTime = 10;               // Wartezeit in ms

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);                     // Kommunikation mit dem Rechner starten

  // Variable mit der Geschwindigkeit in Motoren schreiben
  motor1.setSpeed(maxSpeed1);
  motor2.setSpeed(maxSpeed2);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {

  if(!digitalRead(ENDSTOP11)){
    motor1.run(FORWARD);
    Serial.println("Motor1: FORWARD");
  }
  if(!digitalRead(ENDSTOP12)){
    motor1.run(BACKWARD);
    Serial.println("Motor1: BACKWARD");
  }

  if(!digitalRead(ENDSTOP21)){
    motor2.run(FORWARD);
    Serial.println("Motor2: FORWARD");
  }
  if(!digitalRead(ENDSTOP22)){
    motor2.run(BACKWARD);
    Serial.println("Motor2: BACKWARD");
  }

}

////////////////////////////////////////////////////////////////////////
