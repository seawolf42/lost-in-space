// CONFIG

int PIN_RED = 11;
int PIN_GREEN = 10;
int PIN_BLUE = 9;

// SETUP AND MAIN LOOP

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT); 
}

void loop() {
  testPattern();
  delay(500);
  swirl();
}

// HELPERS

void rgbColor(int red, int green, int blue) {
  analogWrite(PIN_RED, red);
  analogWrite(PIN_GREEN, green);
  analogWrite(PIN_BLUE, blue);
}

void testPattern() {
  rgbColor(125, 0, 0);
  delay(500);
  rgbColor(0, 125, 0);
  delay(500);
  rgbColor(0, 0, 125);
  delay(500);
  rgbColor(64, 32, 0);
  delay(500);
  rgbColor(125, 0, 125);
  delay(500);
  rgbColor(125, 125, 125);
  delay(500);
}

void swirl() {
  int red = 25;
  int green = 0;
  int blue = 0;

  int wait = 25;

  int step = 0;
  while (true) {
    rgbColor(red, green, blue);
    switch(step) {
      case 0:
        --red;
        ++green;
        if (red == 0) {
          ++step;
        }
        break;
      case 1:
        --green;
        ++blue;
        if (green == 0) {
          ++step;
        }
        break;
      case 2:
        --blue;
        ++red;
        if (blue == 0) {
          ++step;
        }
        break;
      default:
        step %= 3;
        break;
    }
    delay(wait);
  }
}
