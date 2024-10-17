/*
 * Quand on appuie sur un bouton, le moteur tourne trois secondes.
 */

const int broche_bouton = 2;
const int broche_moteur = 4;

void setup() {
    pinMode(broche_bouton, INPUT);
    pinMode(broche_moteur, OUTPUT);
}

void loop() {
    static bool moteur_tourne = false;   // le moteur tourne-t-il ?
    static uint32_t temps_allumage = 0;  // quand a-t-il été allumé ?

    // Quand on appuie sur le bouton, allumer le moteur.
    if (!moteur_tourne && digitalRead(broche_bouton) == HIGH) {
        digitalWrite(broche_moteur, HIGH);
        moteur_tourne = true;
        temps_allumage = millis();
    }

    // Quand il a tourné trois secondes, éteindre le moteur.
    if (moteur_tourne && millis() - temps_allumage >= 3000) {
        digitalWrite(broche_moteur, LOW);
        moteur_tourne = false;
    }
}
