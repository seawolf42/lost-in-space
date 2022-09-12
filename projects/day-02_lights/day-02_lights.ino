const int LIGHT = 12;

void setup() {
  pinMode(LIGHT, OUTPUT);
  digitalWrite(LIGHT, HIGH);
}

void loop() {
  digitalWrite(LIGHT, HIGH);
  delay(200);
  digitalWrite(LIGHT, LOW);
  delay(1800);
}
