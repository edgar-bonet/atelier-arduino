/*
 * Optionnellement, on peut communication avec un ordinateur.
 */

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("Le résultat est : ");
    Serial.println(42);
    delay(1000);
}
