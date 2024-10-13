/*
 * Entrées de l'Arduino, analogiques.
 */

const int broche_analogique = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int valeur_analogique = analogRead(broche_analogique);
    float U = valeur_analogique / 1024.0 * 5.0;  // en volts
    Serial.print("tension mesurée : ");
    Serial.println(U);
    delay(1000);
}
