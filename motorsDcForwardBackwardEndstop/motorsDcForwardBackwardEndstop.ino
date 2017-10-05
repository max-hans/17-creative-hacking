////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// das hier sollte passieren:
// 2 gleichstrommotoren fahren abwechselnd vor und zurück

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
AF_DCMotor motor2(2);

// Motorparameter

// Variablen zum Speichern der Motorgeschwindigkeiten
int maxSpeed1 = 100;
int maxSpeed2 = 100;

// Variable zum Speichern der Richtung
// 'true' bedeutet vorwärts, 'false' bedeutet rückwärts
// wir setzen als anfangswert einfach mal 'vorwärts' ein
boolean direction1 = true;
boolean direction2 = true;

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);               // Kommunikation mit dem Rechner starten

  // Variable mit der Geschwindigkeit in Motoren schreiben
  motor1.setMaxSpeed(maxSpeed1);
  motor2.setMaxSpeed(maxSpeed2);
}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {

  // Motor 1 laufen lassen
  if (direction1) {                       // wenn der motor letztes mal vorwärts gefahren ist, fahre rückwärts
    Serial.println("motor1 - back");      // feedback an rechner geben
    direction1 = false;                   // speichern der neuen richtung
    while (digitalRead(A0)) {             // 'solange der endschalter nicht betätigt wurde...'
      motor1.run(BACKWARD);               // 'fahre rückwärts'
    }                                     // danach (also wenn der schalter betätigt wurde)...
    motor1.run(RELEASE);                  // stoppe den motor
  }
  else {                                  // wenn der motor letztes mal rückwärts gefahren ist, fahre vorwärts
    Serial.println("motor1 - forward");   // feedback an rechner geben
    direction1 = true;                    // speichern der neuen richtung
    while (digitalRead(A1)) {             // siehe oben
      motor1.run(FORWARD);                // siehe oben
    }                                     // siehe oben
    motor1.run(RELEASE);                  // siehe oben
  }

  delay(1000);                            // warte 1000 ms

  // Motor 2 nach dem gleichen prinzip laufen lassen
  if (direction2) {
    Serial.println("motor2 - back");
    direction2 = false;
    while (digitalRead(A2)) {
      motor2.run(BACKWARD);
    }
    motor2.run(RELEASE);
  }
  else {
    Serial.println("motor2 - forward");
    direction2 = true;
    while (digitalRead(A3)) {
      motor2.run(FORWARD);
    }
    motor2.run(RELEASE);
  }

  delay(1000);

}

////////////////////////////////////////////////////////////////////////
