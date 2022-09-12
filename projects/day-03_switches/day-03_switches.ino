int LED = 12;
int SWITCH1 = 2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SWITCH1, INPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  if (digitalRead(SWITCH1) == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(100);
}
