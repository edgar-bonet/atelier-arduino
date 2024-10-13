/*
 * Bouton avec pull-up interne.
 */

const int numero_de_broche = 4;

void setup() {
    Serial.begin(9600);
    pinMode(numero_de_broche, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(numero_de_broche) == LOW) {
        Serial.println("Le bouton est pressé");
    } else {
        Serial.println("Le bouton est relâché");
    }
    delay(1000);
}
