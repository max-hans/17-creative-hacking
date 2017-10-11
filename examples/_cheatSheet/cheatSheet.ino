////////////////////////////////////////////////////////////////////////
////////////////////CREATIVE HACKING AKA 17/18 /////////////////////////
////////////////////////////////////////////////////////////////////////

// cheatSheet
// Sammlung von verschiedenen Syntax-Bausteinen

////////////////////////////////////////////////////////////////////////

// Variablenbezeichnungen

// Variablen müssen vor Benutzung deklariert werden und ihnen muss ein bestimmter Typ zugeordnet werden.
// Man kann zwischen Typen wechseln, das erfordert aber meinst eine explizite Umwandlung.

int a;                                    // Variablen müssen nicht zwangsläufig direkt einen Wert zugewiesen bekommen

int b = 5;                                // Integer: Ganze Zahlen (-32.768 bis 32.767)
long c = 120;                             // Long: Ganze Zahlen (-2,147,483,648 bis 2,147,483,647)

float d = 4.3245;                         // Fließkommazahl: 6-7 Nachkommastellen (ACHTUNG: '.' als Trennzeichen!)

char e = 'd';                             // Character: Buchstaben, Zahlen, Sonderzeichen

String f = "hallo";                       // Stringobjekt: hält mehrere Buchstaben und Zeichen

boolean x = true;                         // Boolsche Variable: Kann entweder "true" oder "false" sein
boolean y = false;

////////////////////////////////////////////////////////////////////////

// Arrays

// Mehrere Daten des gleichen Typs können in einem Array gebündelt werden. Dafür muss es erst einmal deklariert werden.
// Die Länge eines Arrays ist FIX! Im Nachhinein ist es nicht mehr so einfach möglich, eine andere Größe zuzuweisen.

int einArray[6];                          // In diesem Array sind 6 Plätze 'reserviert', aber noch nicht gefüllt
int zweitesArray[] = {2, 4, 8, 3, 6};     // In diesem Array wird die Größe automatisch an den Input angepasst
int drittesArray[6] = {2, 4, -8, 3, 2};   // Hier werden Inhalt und Größe direkt bestimmt. Der 5te Wert bleibt frei.
char viertesArray[6] = "hello";           // Bei Charactern kann man einfach eine Zeichenfolge hineinschreiben.

// Arrayzugriff

int beispielArray[6] = {2, 4, 8, 3, 6, 8}; // Schreiben der Werte in ein Array
int ersteZahl = einArray[0];              // Der erste Index in einem Array ist 0!
int letzte Zahl = beispielArray[5];       // Der letzte Index in einem Array ist (Länge des Arrays) - 1 !

beispielArray[3] = 5;                     // So schreibt man Daten in das Array.

////////////////////////////////////////////////////////////////////////

// Logik

// IF-Abfragen
// Eine If-Abfrage wird immer dann ausgeführt, wenn das, was in den Klammern 'true' ergibt.

if (true) {
  Serial.println("true");
}

if (!false) {                             // Ein '!' invertiert die folgende Variable
  Serial.println("true");                 // 'false' invertiert ergibt 'true'
}

boolean j = true;
boolean k = false;

// Boolsche Operationen

if (j) {                                  // Wenn j 'true ist
  Serial.println("true");                 // Wird das ausgeführt was in den Klammern ist
}

if (j == true) {
  Serial.println("true");
}

if (k == false) {                          // Wenn 'k' 'false' ist das Statement richtig und daher 'true'
  Serial.println("true");
}

if (j != false) {
  Serial.println("true");                  // Wenn die beiden Parameter nicht gleich sind, gibt das Statement 'true' aus
}

if (true && true) {                        // AND - true : Wenn beide Parameter true sind
  Serial.println("true");
}

if (true && false) {                       // AND - false : Wenn nur einer der beiden 'true' ist
  Serial.println("false");
}

if (true || false) {                       // OR - true : Wenn nur einer der beiden 'true' ist
  Serial.println("true");
}

if (false || true) {                       // OR - true : Die Reihenfolge ist bei allen egal.
  Serial.println("true");
}

if (true || true) {                        // OR - false : Wenn beide Paramter true sind,
  Serial.println("false");
}

// Diese Vergleiche kann man auch mit Zahlen machen

int g = 5;
int h = 9;

if (g < h) {                              // Hier wird überprüft ob g kleiner als h ist.
  Serial.println("kleiner");              // Falls ja, wird ausgeführt, was in den folgenden {}-Klammern ist.
}
else if (g > h) {                         // Sollte g nicht kleiner als h sein, wird geprüft ob g größer als h ist.
  Serial.println("größer");               // Falls ja, wird ausgeführt, was in den folgenden {}-Klammern ist.
}
else {                                    // Sollte keine der beiden vorherigen Bedingungen stimmen
  Serial.println("gleich");               // wird ausgeführt, was in den folgenden {}-Klammern ist.
}

int l = 5;

if (l == 5) {
  Serial.println("Das Ergebnis ist 5");
}
else {
  Serial.println("Das Ergebnis ist nicht 5");
}

////////////////////////////////////////////////////////////////////////

// Schleifen
// Schleifen sind sehr praktisch um Vorgänge mehrmals auszuführen
// Wichtig sind WHILE- und FOR-Schleifen


// WHILE-Schleife                         // While-Schleifen werden solange ausgeführt, wie der Parameter true ist. Das wird immer am Anfang getestet.
while(true){
  Serial.println("hallo");    
}

int m = 1;
while(m<10){
  m += 1;
  Serial.println(m);
}

// FOR Schleife                           // Diese Schleife wird eine definierte Anzahl an Wiederholungen ausgeführt.
for(int i = 0; i< 10;i++){                // Sie besteht aus ( Anfangsanweisung , Schleifenbedingung , Endanweisung )
  Serial.println(i);                      // Am Anfang definieren wir eine Variable i mit dem Wert 0, die Schleife wird ausgeführt wenn i kleiner als 10 ist.
}                                         // Am Ende wird i um 1 erhöht. Und dann geht es wieder von vorn los.

////////////////////////////////////////////////////////////////////////

// Rechenoperationen

int a = 10;
int b = 5;
int c = a + b;                            // Variablen des gleichen Typs können einfach addiert werden.

a = 4-3;                                  // Variablen können überschrieben werden.

a = a + 1;                                // Addieren von 1 a wird zum wert von (a+1)
a += 1;                                   // Kürzere Schreibweise
a++;                                      // Verkürzte Schreibweise wenn nur 1 addiert wird.

a -= 1;                                   // Das Gleiche bei der Substraktion
a--;

a = a * 2;                                // Multiplikation geht natütrlich auch.
a*=2;                                     // Kürzere Schreibweise

a = a / 3;                                // Divison ACHTUNG : Bei Ganzzahloperationen ist das Ergebnis auch eine Ganzzahl
                                          // Beispiel : 6 / 2 = 3 | 5 / 2 = 2 (Die Nachkommastellen gehen verloren)
a/=3;

////////////////////////////////////////////////////////////////////////

// Wichtige Funktionen

Serial.begin(9600);                       // Starten der Serial-Kommunikation zum Computer
Serial.println("hallo");                  // Schreiben einer Zeile an den Computer

delay(1000);                              // Warten (Zeit in ms) - Achtung BLOCKIERT!
millis();                                 // Gibt die aktuelle Zeit seit Start in ms aus.

random(100);                              // Gibt eine zufällige Zahl zwischen 0 und dem Eingabewert aus
random(30,100);                           // Gibt eine zufällige Zahl zwischen Input 1 und Input 2 aus

pinMode(13,INPUT);                        // Definiert Pin 13 als INPUT
pinMode(13,OUTPUT);                       // Definiert Pin 13 als OUTPUT

boolean a = digitalRead(13);              // Lese pin13 in eine Variable
digitalWrite(13,HIGH);                    // Setze pin13 HIGH
digitalWrite(13,LOW);                     // Setze pin13 LOW
analogWrite(13,200);                      // Schreibe einen PWM-Wert (0-255) auf Pin13

boolean b = digitalRead(A0);              // Lese AnalogPin 0 ein (HIGH oder LOW)
int c = analogRead(A0);                   // Lese AnalogPin 0 ein (0 - 1023);

////////////////////////////////////////////////////////////////////////
