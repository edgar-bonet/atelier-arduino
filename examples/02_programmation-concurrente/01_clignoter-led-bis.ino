/*
 * Faire clignoter la LED sans bloquer le programme.
 *
 * Adapté de l'exemple Arduino « Blink without delay ».
 */

// Variable qui se souvient de l'état de la LED. LOW = éteinte.
int etat_LED = LOW;

// Variable qui se souvient du moment où la LED a changé d'état pour la
// dernière fois.
unsigned long temps_dernier_changement = 0;

void setup() {
    // La broche 13 (LED_BUILTIN), qui est connectée à la LED intégrée,
    // doit être configurée en sortie.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // L'heure actuelle, en millisecondes depuis le démarrage.
    unsigned long maintenant = millis();

    // Est-il temps de changer d'état ?
    if (maintenant - temps_dernier_changement >= 400) {
        temps_dernier_changement = maintenant;

        // Calculer le nouvel état.
        if (etat_LED == LOW) {
            etat_LED = HIGH;
        } else {
            etat_LED = LOW;
        }

        // Appliquer cet état.
        digitalWrite(LED_BUILTIN, etat_LED);
    }
}
