/*
 * Moteur, relais...
 */

const int numero_de_broche = 8;  // commande du moteur

void setup() {
    pinMode(numero_de_broche, OUTPUT);
}

void loop() {
    digitalWrite(numero_de_broche, HIGH);   // moteur allumé
    delay(1000);
    digitalWrite(numero_de_broche, LOW);    // moteur éteint
    delay(1000);
}
