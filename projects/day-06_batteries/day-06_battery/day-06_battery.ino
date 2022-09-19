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
  digitalWrite(pin, HIGH);
  delay(value * 15);
  digitalWrite(pin, LOW);
  delay(100);
}
