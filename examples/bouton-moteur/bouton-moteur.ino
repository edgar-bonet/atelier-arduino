/*
 * Exemple : Quand on appuie sur un bouton, le moteur tourne trois
 * secondes.
 */

const int button_pin = 2;
const int motor_pin = 4;

void setup() {
    pinMode(button_pin, INPUT);
    pinMode(motor_pin, OUTPUT);
}

void loop() {
    static bool motor_is_running = false;
    static uint32_t time_turned_on = 0;
    if (!motor_is_running && digitalRead(button_pin) == HIGH) {
        digitalWrite(motor_pin, HIGH);
        motor_is_running = true;
        time_turned_on = millis();
    }
    if (motor_is_running && millis() - time_turned_on >= 3000) {
        digitalWrite(motor_pin, LOW);
        motor_is_running = false;
    }
}
