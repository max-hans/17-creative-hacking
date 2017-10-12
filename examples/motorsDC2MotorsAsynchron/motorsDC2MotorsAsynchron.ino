////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// das hier sollte passieren:
// 2 gleichstrommotoren fahren unabhängig voneinander in verschiedenen
// Intervallen hin und her.

////////////////////////////////////////////////////////////////////////

// Libraries importieren

#include <AFMotor.h>      // Motor Shield Library

////////////////////////////////////////////////////////////////////////

// Motoren initialisieren

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

// Die verschiedenen Frequenzen / Laufzeiten in getrennte Variablen speichern

int deltaTime1 = 400;
int deltaTime2 = 600;

// Für jeden Motor brauchen wir eine Variable um zu speichern, zu welchem
// Zeitpunkt er umdrehen soll.
// "unsigned long" ist eine spezielle Art von Ganzzahl, die kein Vorzeichen
// besitzt und größere Werte speichern kann, da die Laufzeit in Millisekunden
// gespeichert wird und die Werte schnell sehr groß werden.

unsigned long timeStamp1;
unsigned long timeStamp2;

// Ausserdem müssen wir uns die aktuelle Laufrichtung der Motoren speichern.

boolean direction1 = true;
boolean direction2 = true;

void setup() {

  motor1.setSpeed(200);
  motor2.setSpeed(200);

  // Beide Motoren starten in Vorwärtsrichtung

  motor1.run(FORWARD);
  motor2.run(FORWARD);

  // Speichern des Zeitpunkts in der Zukunft an dem umgedreht wird.

  timeStamp1 = millis() + deltaTime1;
  timeStamp2 = millis() + deltaTime2;
}

void loop() {
  // Aktuelle Zeit in Variable speichern
  // Das ist schneller, als sie jedes Mal neu anzufordern.

  unsigned long timeNow = millis();

  // Wenn die aktuelle Zeit größer ist als das gesetzte Ziel

  if (timeNow > timeStamp1) {
    // Wenn der Motor bis zu diesem Punkt vorwärts gefahren ist...

    if (direction1) {

      // Speichere die neue Richtung...

      direction1 = false;

      // ... und drehe die Motorrichtung in "rückwärts" um

      motor1.run(BACKWARD);
    }

    //Wenn der Motor bis zu diesem Punkt NICHT vorwärts gefahren ist...

    else {

      // Speichere die neue Richtung...

      direction1 = true;

      // ...und lass den Motor vorwärts fahren.

      motor1.run(FORWARD);
    }
    // Speichere die neue Zeit in die Variable.

    timeStamp1 = timeNow + deltaTime1;
  }

  // ... das gleiche Spiel für Motor 2
  if (timeNow > timeStamp2) {
    if (direction2) {
      direction2 = false;
      motor2.run(BACKWARD);
    }
    else {
      direction2 = true;
      motor2.run(FORWARD);
    }
    timeStamp2 = timeNow + deltaTime2;
  }

}
