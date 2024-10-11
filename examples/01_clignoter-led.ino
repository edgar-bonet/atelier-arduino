/*
 * Faire clignoter la LED.
 */

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);     // configurer la broche 13 en sortie
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // allumer
    delay(1000);                      // attendre
    digitalWrite(LED_BUILTIN, LOW);   // éteindre
    delay(1000);                      // attendre
}
