#include <Key.h>
#include <Keypad.h>

// CONFIG

const int PIN_BUZZER = 8;
const int PIN_RED = 11;
const int PIN_GREEN = 10;
const int PIN_BLUE = 9;

const byte ROWS = 4;
const byte COLS = 4;

const byte PASSWORD_LENGTH = 4;

const char BUTTONS[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte ROW_PINS[ROWS] = {5, 4, 3, 2};
byte COL_PINS[COLS] = {6, 7, 12, 13};

// DATA

Keypad keypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

char currentPassword[PASSWORD_LENGTH] = {'0', '0', '0', '0'};

struct PWMColor {
  byte red;
  byte green;
  byte blue;
};

const PWMColor OFF = {0, 0, 0};
const PWMColor WHITE = {125, 125, 125};
const PWMColor RED = {125, 0, 0};
const PWMColor GREEN = {0, 125, 0};
const PWMColor BLUE = {0, 0, 125};

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
  displayColor(&BLUE);
  delay(1000);
  displayColor(&WHITE);
  Serial.println("*: set password");
  Serial.println("#: unlock");
}

void loop() {
  char result = keypad.getKey();

  switch(result) {
    case '*':
      trySet();
      break;
    case '#':
      tryUnlock();
      break;
    default:
      break;
  };
}

// HELPERS

void tryUnlock() {
  Serial.print("enter current password: ");
  char attempted[PASSWORD_LENGTH] = {0, 0, 0, 0};
  readPassword(attempted);
  int result = compare(attempted, currentPassword);
  if (result == 0) {
    onSuccess("UNLOCKED");
  } else {
    onError("INCORRECT PASSWORD");
  }
  displayColor(&WHITE);
}

void trySet() {
  Serial.print("enter current password: ");

  char current[PASSWORD_LENGTH] = {0, 0, 0, 0};
  readPassword(current);
  int result = compare(current, currentPassword);
  if (result != 0) {
    onError("PASSWORD UNCHANGED");
    return;
  }

  Serial.print("enter new password: ");
  char new1[PASSWORD_LENGTH] = {0, 0, 0, 0};
  readPassword(new1);

  Serial.print("repeat: ");
  char new2[PASSWORD_LENGTH] = {0, 0, 0, 0};
  readPassword(new2);

  result = compare(new2, new1);
  if (result != 0) {
    onError("PASSWORD UNCHANGED");
    return;
  }

  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    currentPassword[i] = new1[i];
  }
  onSuccess("PASSWORD UPDATED");

  displayColor(&WHITE);
}

void readPassword(char* buffer) {
  displayColor(&OFF);
  char result = 0;
  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    while(!(result = keypad.getKey()));
    buffer[i] = result;
    onInput("*");
  }
  Serial.println(" OK");
}

int compare(char* test, char* expected) {
  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    if (test[i] != expected[i]) {
      return 1;
    }
  }
  return 0;
}

void onInput(const char* character) {
  toneAndBlink(880, &BLUE, 100);
  Serial.print(character);
}

void onSuccess(const char* message) {
  for (int i = 0; i < 5; ++i) {
    toneAndBlink(1500, &GREEN, 50);
  }
}

void onError(const char* message) {
  toneAndBlink(147, &RED, 500);
  Serial.println(message);
}

void toneAndBlink(const int frequency, const PWMColor* color, const int duration) {
  displayColor(color);
  tone(PIN_BUZZER, frequency);
  delay(duration);
  noTone(PIN_BUZZER);
  displayColor(&OFF);
  delay(50);
}

void displayColor(const PWMColor* color) {
  analogWrite(PIN_RED, color->red);
  analogWrite(PIN_GREEN, color->green);
  analogWrite(PIN_BLUE, color->blue);
}
