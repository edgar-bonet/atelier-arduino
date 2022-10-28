/*
 * Machine à états de feu tricolore.
 */

// Brochage.
const int feu_vert = 2;
const int feu_orange = 3;
const int feu_rouge = 4;

// Durées.
const unsigned long duree_vert   = 4000;
const unsigned long duree_orange = 1000;
const unsigned long duree_rouge  = 5000;

enum { VERT, ORANGE, ROUGE } etat = VERT;
unsigned long dernier_changement;

void setup() {
    pinMode(feu_vert, OUTPUT);
    pinMode(feu_orange, OUTPUT);
    pinMode(feu_rouge, OUTPUT);
    digitalWrite(feu_vert, HIGH);
    digitalWrite(feu_orange, LOW);
    digitalWrite(feu_rouge, LOW);
    dernier_changement = millis();
}

void loop() {
    unsigned long maintenant = millis();
    unsigned long temps_ecoule = maintenant - dernier_changement;
    switch (etat) {
        case VERT:
            if (temps_ecoule >= duree_vert) {
                digitalWrite(feu_vert, LOW);
                digitalWrite(feu_orange, HIGH);
                etat = ORANGE;
                dernier_changement = maintenant;
            }
            break;
        case ORANGE:
            if (temps_ecoule >= duree_orange) {
                digitalWrite(feu_orange, LOW);
                digitalWrite(feu_rouge, HIGH);
                etat = ROUGE;
                dernier_changement = maintenant;
            }
            break;
        case ROUGE:
            if (temps_ecoule >= duree_rouge) {
                digitalWrite(feu_rouge, LOW);
                digitalWrite(feu_vert, HIGH);
                etat = VERT;
                dernier_changement = maintenant;
            }
            break;
    }
}
