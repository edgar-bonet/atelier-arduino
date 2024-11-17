/*
 * What happens when an ISR takes too long.
 */

const uint32_t periode_de_commutation = 400;

// Gestionnaire d'interruption sur conversion ADC terminée.
ISR(ADC_vect) { delayMicroseconds(0); }

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    ADCSRA |= bit(ADIE);  // activer l'interruption ADC
}

void loop() {
    static uint32_t temps_dernier_changement = 0;
    static uint8_t etat_LED = LOW;
    if (millis() - temps_dernier_changement >= periode_de_commutation) {
        temps_dernier_changement += periode_de_commutation;
        if (etat_LED == LOW) {
            etat_LED = HIGH;
        } else {
            etat_LED = LOW;
        }
        digitalWrite(LED_BUILTIN, etat_LED);
    }

    analogRead(A0);  // provoque l'exécution de ISR(ADC_vect)
    delayMicroseconds(0);
}
