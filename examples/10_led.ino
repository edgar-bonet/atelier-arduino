/*
 * LED.
 */

const int numero_de_broche = 8;  // LED externe

void setup() {
    pinMode(numero_de_broche, OUTPUT);
}

void loop() {
    digitalWrite(numero_de_broche, HIGH);   // allume la LED
    delay(1000);
    digitalWrite(numero_de_broche, LOW);    // éteint la LED
    delay(1000);
}
