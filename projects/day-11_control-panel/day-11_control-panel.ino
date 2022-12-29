#include <Key.h>
#include <Keypad.h>

// CONFIG

const byte ROWS = 4;
const byte COLS = 4;

const char BUTTONS[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte ROW_PINS[ROWS] = {5, 4, 3, 2};
byte COL_PINS[COLS] = {6, 7, 8, 9};

// DATA

Keypad keypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
}

void loop() {
  char result = keypad.getKey();
  if (result) {
    Serial.println(result);
  }
}
