// CONFIG

int PIN_RED = 11;
int PIN_GREEN = 10;
int PIN_BLUE = 9;

// DATA

struct PWMColor {
  byte red;
  byte green;
  byte blue;
};

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

void displayColor(const PWMColor* color) {
  char buffer[25];
  sprintf(buffer, "color: { %3d, %3d, %3d }", color->red, color->green, color->blue);
  Serial.println(buffer);
  analogWrite(PIN_RED, color->red);
  analogWrite(PIN_GREEN, color->green);
  analogWrite(PIN_BLUE, color->blue);
}

// TEST PATTERN

void testPattern() {
  testPatternStep(&(PWMColor{125, 0, 0}));
  testPatternStep(&(PWMColor{0, 125, 0}));
  testPatternStep(&(PWMColor{0, 0, 125}));
  testPatternStep(&(PWMColor{64, 32, 0}));
  testPatternStep(&(PWMColor{125, 0, 125}));
  testPatternStep(&(PWMColor{125, 125, 125}));
}

void testPatternStep(const PWMColor* color) {
  displayColor(color);
  delay(500);
}

// SWIRL

void swirl() {
  PWMColor color = { 25, 0, 0 };

  int wait = 25;

  int step = 0;
  while (true) {
    displayColor(&color);
    step = advanceSwirl(step, &color);
    delay(wait);
  }
}

int advanceSwirl(int step, PWMColor* color) {
  switch (step) {
    case 0:
      --color->red;
      ++color->green;
      if (color->red == 0) {
        ++step;
      }
      break;
    case 1:
      --color->green;
      ++color->blue;
      if (color->green == 0) {
        ++step;
      }
      break;
    case 2:
      --color->blue;
      ++color->red;
      if (color->blue == 0) {
        ++step;
      }
      break;
    default:
      step %= 3;
      break;
  }
  return step;
}
