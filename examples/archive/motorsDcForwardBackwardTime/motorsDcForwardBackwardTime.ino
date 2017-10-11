////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// dcMotorsForwardBackwardTime.ino
// das hier sollte passieren:
// 2 gleichstrommotoren fahren abwechselnd vor und zurück

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Motoren initialisieren

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

// Motorparameter

  // Variablen zum Speichern der Motorgeschwindigkeiten
  
  int speed1 = 100;
  int speed2 = 200;

// Variable zum Speichern der Richtung
// 'true' bedeutet vorwärts, 'false' bedeutet rückwärts
// wir setzen als anfangswert einfach mal 'vorwärts' ein

boolean direction1 = false;
boolean direction2 = false;

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

  // Motor 1 laufen lassen
  
  if (direction1) {                       // wenn der motor letztes mal vorwärts gefahren ist, fahre rückwärts
    Serial.println("motor1 - back");      // feedback an rechner geben
    direction1 = false;                   // speichern der neuen richtung
    motor1.run(BACKWARD);                 // 'fahre rückwärts'
    delay(runTime);                       // warte 1000ms
    motor1.run(RELEASE);                  // stoppe den motor
  }

  
  else {                                  // wenn der motor letztes mal rückwärts gefahren ist, fahre vorwärts
    Serial.println("motor1 - forward");   // feedback an rechner geben
    direction1 = true;                    // speichern der neuen richtung
    motor1.run(FORWARD);                // siehe oben
    delay(runTime);                          // siehe oben
    motor1.run(RELEASE);                  // siehe oben
  }

  

  delay(waitTime);                            // warte 1000 ms

  // Motor 2 nach dem gleichen prinzip laufen lassen
  
  if (direction2) {
    Serial.println("motor2 - back");
    direction2 = false;
    motor2.run(BACKWARD);
    delay(runTime);
    motor2.run(RELEASE);
  }
  else {
    Serial.println("motor2 - forward");
    direction2 = true;
    motor2.run(FORWARD);
    delay(runTime);
    motor2.run(RELEASE);
  }

  delay(waitTime);

}

////////////////////////////////////////////////////////////////////////
