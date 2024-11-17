/*
 * Exemple d'interruption périodique générée par un timer.
 */

#include <TimerOne.h>

// Gestionnaire d'interruption.
void commuter_LED() {
    static uint8_t etat_LED = LOW;
    if (etat_LED == LOW) {
        etat_LED = HIGH;
    } else {
        etat_LED = LOW;
    }
    digitalWrite(LED_BUILTIN, etat_LED);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Timer1.initialize(400000);  // période = 400 000 µs = 0,4 s
    Timer1.attachInterrupt(commuter_LED);
}

void loop() {}
