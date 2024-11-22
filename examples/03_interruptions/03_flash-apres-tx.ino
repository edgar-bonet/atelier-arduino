/*
 * Flasher la LED après une transmission série.
 */

const char message[] = "Lorem ipsum dolor sit amet, consectetur "
    "adipiscing elit. Pellentesque euismod, velit ut rutrum faucibus, "
    "ipsum lorem sodales magna, vitae feugiat est ac risus.";

// Gestionnaire de l'interruption « transmit complete ».
ISR(USART_TX_vect) {
    digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    UCSR0B |= bit(TXCIE0);  // activer interruption USART_TX
}

void loop() {
    Serial.println(message);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
}
