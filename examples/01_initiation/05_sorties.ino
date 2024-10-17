/*
 * Sorties de l'Arduino.
 */

const int numero_de_broche = 6;

void setup() {
    pinMode(numero_de_broche, OUTPUT);
}

void loop() {
    digitalWrite(numero_de_broche, LOW);   // LOW = 0
    delay(1000);
    digitalWrite(numero_de_broche, HIGH);  // HIGH = 1
    delay(1000);
    analogWrite(numero_de_broche, 123);  // valeur = 0 à 255
    delay(1000);
}
