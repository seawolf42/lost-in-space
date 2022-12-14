#include <Key.h>
#include <Keypad.h>

// CONFIG

const byte ROWS = 4;
const byte COLS = 4;

char BUTTONS[ROWS][COLS] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}
};

byte ROW_PINS[ROWS] = {5, 4, 3, 2};
byte COL_PINS[COLS] = {6, 7, 8, 9};

// DATA

Keypad keypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

struct KeyInfo {
  char symbol;
  int tone;
};

const KeyInfo keys[ROWS * COLS] = {
  KeyInfo{'1', 31},
  KeyInfo{'2', 93},
  KeyInfo{'3', 147},
  KeyInfo{'A', 208},
  KeyInfo{'4', 247},
  KeyInfo{'5', 311},
  KeyInfo{'6', 370},
  KeyInfo{'B', 440},
  KeyInfo{'7', 523},
  KeyInfo{'8', 587},
  KeyInfo{'9', 698},
  KeyInfo{'C', 880},
  KeyInfo{'*', 1397},
  KeyInfo{'0', 2637},
  KeyInfo{'#', 3729},
  KeyInfo{'D', 4978},
};

int PIN_BUZZER = 10;

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
}

void loop() {
  char result = keypad.getKey();

  if (result) {
    --result;
    KeyInfo* key = &keys[result];

    Serial.print("key: ");
    Serial.print(key->symbol);
    Serial.print(", frequency: ");
    Serial.println(key->tone);

    tone(PIN_BUZZER, key->tone, 500);
    delay(500);
    noTone(PIN_BUZZER);
  }
}
