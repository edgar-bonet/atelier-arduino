/*
 * Faire scanner un servo.
 */

#include <Servo.h>

const uint8_t broche_servo = 4;
const int pas_servo = 2;          // pas de 2 degrés
const uint32_t duree_pause = 20;  // pause entre deux pas

Servo mon_servo;

void setup() {
    mon_servo.attach(broche_servo);
}

void loop() {
    static enum { AVANCE, RECULE } direction = AVANCE;
    static int position = 0;
    static uint32_t temps_dernier_pas = 0;

    switch (direction) {
        case AVANCE:
            if (millis() - temps_dernier_pas >= duree_pause) {
                temps_dernier_pas += duree_pause;
                position += pas_servo;
                mon_servo.write(position);
            }
            if (position >= 180) {
                direction = RECULE;
            }
            break;
        case RECULE:
            if (millis() - temps_dernier_pas >= duree_pause) {
                temps_dernier_pas += duree_pause;
                position -= pas_servo;
                mon_servo.write(position);
            }
            if (position <= 0) {
                direction = AVANCE;
            }
            break;
    }
}
