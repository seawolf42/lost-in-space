#include <Key.h>
#include <Keypad.h>

// CONFIG

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // 1st row
  {'4', '5', '6', 'B'},  // 2nd row
  {'7', '8', '9', 'C'},  // 3rd row
  {'*', '0', '#', 'D'}   // 4th row
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

// DATA

Keypad keypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int tones[ROWS][COLS] = {
  {31, 93, 147, 208},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 4978}
};

int BUZZER = 10;

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
}
 
void loop() {
  int toneFreq = 0;

  char result = keypad.getKey();

  if (result) {
    for (byte r=0; r < ROWS; ++r) {
      for (byte c=0; c < COLS; ++c) {
        if (result == buttons[r][c]) {
          toneFreq = tones[r][c];
        }
      }
    }

    Serial.print("key: ");
    Serial.print(result);
    Serial.print(", frequency: ");
    Serial.println(toneFreq);

    tone(BUZZER, toneFreq, 500);
    delay(500);
    noTone(BUZZER);
  }
}
