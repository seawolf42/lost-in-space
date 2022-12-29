// CONFIG

int SENSOR = A0;

unsigned int BATTERY_CAPACITY = 50000;
unsigned int WAIT = 100;
unsigned int DEPLETION_RATE = 1350;

// STATE

unsigned int batteryLevel = 0;
unsigned int tics = 0;

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
  reset();
}

void loop() {
  if (batteryLevel >= BATTERY_CAPACITY) {
    handleBatteryCharged();
    reset();
  }
  printBatteryPercentage();

  wait(WAIT);

  int sensorValue = analogRead(SENSOR);
  batteryLevel += sensorValue;
}

// HELPERS

void wait(int duration) {
  delay(duration);
  tics += duration;
}

void printBatteryPercentage() {
  double percentFull = 100 * ((double) batteryLevel / (double) BATTERY_CAPACITY);

  Serial.print(tics);
  Serial.print(" ms | charge at ");
  Serial.print(percentFull);
  Serial.println("%");
}

void handleBatteryCharged() {
  Serial.print(tics);
  Serial.println(" ms | FULLY CHARGED");
  batteryLevel = BATTERY_CAPACITY;
  wait(1000);
}

void reset() {
  Serial.println("INITIATING BATTERY RESET");
  wait(300);
  Serial.println("BEGINNING RAPID DISCHARGE");
  while (batteryLevel > DEPLETION_RATE) {
    batteryLevel -= DEPLETION_RATE;
    printBatteryPercentage();
    wait(WAIT);
  }
  Serial.println("BATTERY DISCHARGED");

  delay(500);
  tics = 0;
  batteryLevel = 0;
  Serial.println("RESET COMPLETE");

  delay(750);
  Serial.println("BEGINNING CHARGE SEQUENCE");
}
