// CONFIG

#define PIN_SWITCH1 2
#define PIN_LIGHT1 10

#define PIN_SWITCH2 3
#define PIN_LIGHT2 11

#define PIN_SWITCH3 4
#define PIN_LIGHT3 12

// SETUP AND MAIN LOOP

void setup() {
  setupLightCircuit(PIN_SWITCH1, PIN_LIGHT1);
  setupLightCircuit(PIN_SWITCH2, PIN_LIGHT2);
  setupLightCircuit(PIN_SWITCH3, PIN_LIGHT3);
}

void loop() {
  setLight(PIN_LIGHT1, PIN_SWITCH1);
  setLight(PIN_LIGHT2, PIN_SWITCH2);
  setLight(PIN_LIGHT3, PIN_SWITCH3);
  delay(100);
}

// HELPERS

void setupLightCircuit(int swtch, int light) {
  pinMode(swtch, INPUT);
  pinMode(light, OUTPUT);
  digitalWrite(light, LOW);
}

void setLight(int light, int swtch) {
  digitalWrite(light, digitalRead(swtch));
}
