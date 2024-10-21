/*
 * Exemple de lecture non-bloquante d'un port série.
 */

const int broche_led = 8;

void setup() {
    pinMode(broche_led, OUTPUT);
    Serial.begin(9600);
    Serial.println("Ready.");
}

/* Contrôler une LED avec les commandes "on" et "off". */
void interprete(const char *commande) {
    if (strcmp(commande, "on") == 0) {          // "on" = allumer
        digitalWrite(broche_led, HIGH);
    } else if (strcmp(commande, "off") == 0) {  // "off" = éteindre
        digitalWrite(broche_led, LOW);
    } else {
        Serial.println("Commande incorrecte.");
    }
}

void loop() {
    static char tampon[80];        // stockage des caractères reçus
    static size_t pos_tampon = 0;  // nombre de caractères reçus

    if (Serial.available()) {
        char c = Serial.read();         // nouveau caractère reçu
        if (c == '\n') {                // fin de ligne
            tampon[pos_tampon] = '\0';  // terminer la chaîne
            interprete(tampon);
            pos_tampon = 0;             // préparer la prochaine lecture
        } else if (pos_tampon < sizeof tampon - 1) {
            tampon[pos_tampon++] = c;   // ajouter au tampon
        }
    }
}
