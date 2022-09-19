// CONFIG

int SENSOR = A0;
int LIGHT = LED_BUILTIN;

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT, OUTPUT);

}

void loop() {
  int sensorValue = analogRead(SENSOR);
  Serial.println(sensorValue);
  // lightAtThreshold(LIGHT, sensorValue, 30);
  lightForDuration(LIGHT, sensorValue);
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
