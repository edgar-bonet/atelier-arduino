/*
 * Potentiomètre.
 */

const int numero_de_broche = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    float x = analogRead(numero_de_broche) / 1024.0;  // entre 0 et 1
    Serial.print("position du potentiomètre : ");
    Serial.println(x);
    delay(1000);
}
