/*
 * Servo de modélisme.
 */

#include <Servo.h>

const int numero_de_broche = 12;
Servo servo;

void setup() {
    servo.attach(numero_de_broche);
}

void loop() {
    servo.write(0);    // positions extrêmes : 0°...
    delay(1000);
    servo.write(180);  // ...et 180°
    delay(1000);
}
