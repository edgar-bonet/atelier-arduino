/*
 * What happens if a non-atomic variable is not protected?
 */
#define NO_ATOMIC

#ifdef NO_ATOMIC
# undef noInterrupts
# define noInterrupts()
# undef interrupts
# define interrupts()
#endif

volatile uint32_t counter;

ISR(TIMER0_COMPA_vect) {
    if (counter == 0xffffffff)
        counter =  0x00000000;
    else
        counter += 0x01010101;
}

void setup() {
    TIMSK0 |= bit(OCIE0A);
    Serial.begin(9600);
    Serial.println("Ready");
}

void loop() {
    union {
        uint32_t value;
        uint8_t bytes[4];
    } data;
    noInterrupts();
    data.value = counter;
    interrupts();
    for (int i = 1; i < 4; i++) {
        if (data.bytes[i] != data.bytes[0]) {
            Serial.println(data.value, HEX);
            break;
        }
    }
    delayMicroseconds(500);
}
