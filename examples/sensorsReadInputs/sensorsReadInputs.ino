////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// readInputs
// das hier sollte passieren:
// Über den Serial Monitor werden die Werte der Sensoreingänge ausgegeben

////////////////////////////////////////////////////////////////////////

unsigned int frequency = 100;               // Messfrequenz

////////////////////////////////////////////////////////////////////////

// Setup

void setup() {

  Serial.begin(9600);                     // Kommunikation mit dem Rechner starten

}

////////////////////////////////////////////////////////////////////////

// Loop

void loop() {
  

  Serial.print('-');
  Serial.print(digitalRead(A0));
  Serial.print('-');
  Serial.print(!digitalRead(A1));         // Hall Sensor - Gibt normal '1' aus und bei Auslösen '0'. Das '!' invertiert den Wert, damit
  Serial.print('-');                      // der Sensor wie alle Alle anderen auslöst
  Serial.print(digitalRead(A2));
  Serial.print('-');
  Serial.print(digitalRead(A3));
  Serial.println('-');
  delay(frequency);
  
}

////////////////////////////////////////////////////////////////////////
