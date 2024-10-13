/*
 * Capteur résistif.
 */

const int numero_de_broche = A0;
const float R0 = 1000.0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int lecture = analogRead(numero_de_broche);
    float R = lecture / (1024.0 - lecture) * R0;
    Serial.print("résistance : ");
    Serial.println(R);
    delay(1000);
}
