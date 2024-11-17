/*
 * What happens if we forget `volatile`?
 */

bool fini = false;  // est-ce que l'attente est finie ?

// Gestionnaire d'interruption appelé toutes les 1,024 ms.
ISR(TIMER0_COMPA_vect) { fini = true; }

void setup() {
    Serial.begin(9600);
    Serial.println("En attente...");
    TIMSK0 |= bit(OCIE0A);  // activer l'interruption TIMER0_COMPA
    while (!fini) {
        /* attendre... */
    }
    Serial.println(" fini!");
}

void loop() {}
