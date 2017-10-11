////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// motorsDC1Motor.ino
// das hier sollte passieren:
// 1 Gleichstrommotor läuft abwechselnd vor und zurück

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Motoren initialisieren

AF_DCMotor motor1(1);


// Motorparameter

  // Variablen zum Speichern der Motorgeschwindigkeiten
  
  int speed1 = 100;



unsigned int runTime = 200;               // Laufzeit der Motoren in ms
unsigned int waitTime = 10;               // Wartezeit in ms

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);                     // Kommunikation mit dem Rechner starten

  // Variable mit der Geschwindigkeit in Motoren schreiben
  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);
}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {

  motor1.run(FORWARD);
  Serial.println("forward");
  delay(runTime);
  motor1.run(RELEASE);
  Serial.println("stop");
  delay(waitTime);
  motor1.run(BACKWARD);
  Serial.println("backward");
  delay(runTime);
  motor1.run(RELEASE);
  Serial.println("stop");
  delay(waitTime);

}

////////////////////////////////////////////////////////////////////////
