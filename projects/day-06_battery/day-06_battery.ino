// CONFIG

#define PIN_SENSOR A0
#define PIN_LIGHT LED_BUILTIN

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LIGHT, OUTPUT);

}

void loop() {
  int sensorValue = analogRead(PIN_SENSOR);
  Serial.println(sensorValue);
  // lightAtThreshold(LIGHT, sensorValue, 30);
  lightForDuration(PIN_LIGHT, sensorValue);
  delay(100);
}

// HELPERS

void lightAtThreshold(int pin, int value, int threshold) {
  digitalWrite(pin, value >= threshold ? HIGH : LOW);
}

void lightForDuration(int pin, int value) {
  digitalWrite(pin, HIGH);
  delay(value * 15);
  digitalWrite(pin, LOW);
}
