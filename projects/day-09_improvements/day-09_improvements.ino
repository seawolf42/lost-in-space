// CONFIG

int PIN_SENSOR = A0;

int PIN_RED = 11;
int PIN_GREEN = 10;
int PIN_BLUE = 9;

unsigned int BATTERY_CAPACITY = 50000;

unsigned int WAIT = 100;

// DATA

struct PWMColor {
  byte red;
  byte green;
  byte blue;
};

// STATE

unsigned int batteryLevel = 0;
unsigned int tics = 0;

char buffer[100];

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  testPattern();
}

void loop() {
  delay(1000);
  showBatteryPercentage();
  int sensorValue = analogRead(PIN_SENSOR);
  tics += WAIT;
  delay(WAIT);
  batteryLevel += analogRead(PIN_SENSOR);
  if (batteryLevel > BATTERY_CAPACITY) {
    batteryLevel = BATTERY_CAPACITY;
  }
}

// HELPERS

void displayColor(const PWMColor* color) {
  sprintf(buffer, "color: { %3d, %3d, %3d }", color->red, color->green, color->blue);
  Serial.println(buffer);
  analogWrite(PIN_RED, color->red);
  analogWrite(PIN_GREEN, color->green);
  analogWrite(PIN_BLUE, color->blue);
}

// TEST PATTERN

const struct PWMColor testRed = PWMColor{125, 0, 0};
const struct PWMColor testGreen = PWMColor{0, 125, 0};
const struct PWMColor testBlue = PWMColor{0, 0, 125};

void testPattern() {
  testPatternStep(&testRed);
  testPatternStep(&testGreen);
  testPatternStep(&testBlue);
}

void testPatternStep(const PWMColor* color) {
  displayColor(color);
  delay(500);
}

// BATTERY MONITOR

void showBatteryPercentage() {
  double percentFull = 100 * ((double) batteryLevel / (double) BATTERY_CAPACITY);

  sprintf(buffer, "%d ms | charge at %s -> ", tics, String(percentFull).c_str());
  Serial.print(buffer);

  PWMColor color;
  color.red = percentFull < 5 ? 25 : 0;
  color.green = percentFull > 99 ? 25 : 0;
  color.blue = color.red == 0 && color.green == 0 ? 5 : 0;

  displayColor(&color);
}
