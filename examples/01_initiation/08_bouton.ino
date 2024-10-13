/*
 * Bouton.
 */

const int numero_de_broche = 4;

void setup() {
    Serial.begin(9600);
    pinMode(numero_de_broche, INPUT);
}

void loop() {
    if (digitalRead(numero_de_broche) == HIGH) {  // LOW avec un pull-up
        Serial.println("Le bouton est pressé");
    } else {
        Serial.println("Le bouton est relâché");
    }
    delay(1000);
}
