#define PIN_LIGHT 12

void setup() {
  pinMode(PIN_LIGHT, OUTPUT);
  digitalWrite(PIN_LIGHT, HIGH);
}

void loop() {
  digitalWrite(PIN_LIGHT, HIGH);
  delay(200);
  digitalWrite(PIN_LIGHT, LOW);
  delay(1800);
}
