/*
 * Exemple d'utilisation de la bibliothèque Bounce2.
 */

#include <Bounce2.h>

const int broche_bouton = 2;
const int broche_led = 8;

Bounce bouton;  // création de l'objet Bounce représentant le bouton

void setup() {
    bouton.attach(broche_bouton, INPUT);
    pinMode(broche_led, OUTPUT);
}

void loop() {
    static int led_state = LOW;

    bouton.update();  // toujours appeler ça régulièrement

    // Quand on appuie sur le bouton, changer l'état de la LED.
    if (bouton.rose()) {
        led_state = led_state==HIGH ? LOW : HIGH;
        digitalWrite(broche_led, led_state);
    }
}
