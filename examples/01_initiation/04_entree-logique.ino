/*
 * Entrées de l'Arduino, logiques.
 */

const int broche_logique = 6;

void setup() {
    Serial.begin(9600);
    pinMode(broche_logique, INPUT);
}

void loop() {
    int valeur_logique = digitalRead(broche_logique);
    Serial.print("entrée logique : ");
    Serial.println(valeur_logique);
    delay(1000);
}
