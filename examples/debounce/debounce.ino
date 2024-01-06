/*
 * Exemple d'utilisation de la bibliothèque Bounce2.
 */

#include <Bounce2.h>

const int button_pin = 2;
const int led_pin = 8;

Bounce button;

void setup() {
    button.attach(button_pin, INPUT);
    pinMode(led_pin, OUTPUT);
}

void loop() {
    static int led_state = LOW;

    button.update();
    if (button.rose()) {
        led_state = led_state==HIGH ? LOW : HIGH;
        digitalWrite(led_pin, led_state);
    }
}
