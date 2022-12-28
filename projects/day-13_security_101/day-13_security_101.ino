#include <Key.h>
#include <Keypad.h>

// CONFIG

const byte ROWS = 4;
const byte COLS = 4;

const byte PASSWORD_LENGTH = 4;

const char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // 1st row
  {'4', '5', '6', 'B'},  // 2nd row
  {'7', '8', '9', 'C'},  // 3rd row
  {'*', '0', '#', 'D'}   // 4th row
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

// DATA

Keypad keypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

char currentPassword[PASSWORD_LENGTH] = {'0', '0', '0', '0'};

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
  delay(1000);
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
    Serial.println("UNLOCKED");
  }
}

void trySet() {
  Serial.print("enter current password: ");

  char current[PASSWORD_LENGTH] = {0, 0, 0, 0};
  readPassword(current);
  int result = compare(current, currentPassword);
  if (result != 0) {
    Serial.println("PASSWORD UNCHANGED");
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
    Serial.println("PASSWORD UNCHANGED");
    return;
  }

  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    currentPassword[i] = new1[i];
  }
  Serial.println("PASSWORD UPDATED");
}

void readPassword(char* buffer) {
  char result = 0;
  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    while(!(result = keypad.getKey()));
    buffer[i] = result;
    Serial.print(result);
  }
  Serial.println(" OK");
}

int compare(char* test, char* expected) {
  for (int i = 0; i < PASSWORD_LENGTH; ++i) {
    if (test[i] != expected[i]) {
      Serial.println("values mismatched");
      return 1;
    }
  }
  return 0;
}
