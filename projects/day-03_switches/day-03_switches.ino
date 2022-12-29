// CONFIG

#define PIN_LED 12
#define PIN_SWITCH1 2

// SETUP AND MAIN LOOP

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SWITCH1, INPUT);
  digitalWrite(PIN_LED, HIGH);
}

void loop() {
  if (digitalRead(PIN_SWITCH1) == HIGH) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}
