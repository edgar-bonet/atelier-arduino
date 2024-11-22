/*
 * Contrôler une LED avec un bouton et des interruptions.
 */

const uint8_t broche_bouton = 2;
const uint8_t numero_interruption = digitalPinToInterrupt(broche_bouton);

// Gestionnaire d'interruption.
void mettre_a_jour_led() {
    digitalWrite(LED_BUILTIN, digitalRead(broche_bouton));
}

void setup() {
    pinMode(broche_bouton, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    attachInterrupt(numero_interruption, mettre_a_jour_led, CHANGE);
}

void loop() {}
