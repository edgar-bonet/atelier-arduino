/*
 * Exemple de lecture non-bloquante d'un port série.
 */

const int led_pin = 8;

void setup() {
    pinMode(led_pin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Ready.");
}

/* Contrôler une LED avec les commandes "on" et "off". */
void interpret(const char *command) {
    if (strcmp(command, "on") == 0) {
        digitalWrite(led_pin, HIGH);
    } else if (strcmp(command, "off") == 0) {
        digitalWrite(led_pin, LOW);
    } else {
        Serial.println("Bad command.");
    }
}

void loop() {
    static char buffer[80];
    static size_t buffer_pos = 0;

    if (Serial.available()) {
        char c = Serial.read();
        if (c == '\n') {
            buffer[buffer_pos] = '\0';  // terminer la chaîne
            interpret(buffer);
            buffer_pos = 0;  // préparer la prochaine lecture
        } else if (buffer_pos < sizeof buffer - 1) {
            buffer[buffer_pos++] = c;
        }
    }
}
