// CONFIG

int SWITCH1 = 2;
int LIGHT1 = 10;

int SWITCH2 = 3;
int LIGHT2 = 11;

int SWITCH3 = 4;
int LIGHT3 = 12;

// SETUP AND MAIN LOOP

void setup() {
  setupLightCircuit(SWITCH1, LIGHT1);
  setupLightCircuit(SWITCH2, LIGHT2);
  setupLightCircuit(SWITCH3, LIGHT3);
}

void loop() {
  setLight(LIGHT1, SWITCH1);
  setLight(LIGHT2, SWITCH2);
  setLight(LIGHT3, SWITCH3);
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
