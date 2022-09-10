/*
  S-O-S

  Blinks the morse code for "S-O-S" repeatedly on the built-in LED.

  This example code is in the public domain: https://github.com/seawolf42/lost-in-space/blob/main/LICENSE
*/

// CONFIG

const int LIGHT = LED_BUILTIN; // or use a pin number to use an external LED such as from lesson 2

const int DELAY_SHORT = 100;
const int DELAY_DOT = DELAY_SHORT;
const int DELAY_DASH = DELAY_DOT * 2.5;
const int DELAY_CHARACTER_BREAK = DELAY_DASH * 2;
const int DELAY_WORD_BREAK = DELAY_DASH * 3;
const int DELAY_UNKNOWN_CHARACTER = DELAY_DASH * 4;

// SETUP AND MAIN LOOP

void setup() {
  pinMode(LIGHT, OUTPUT);
}

void loop() {
  emit('s');
  emit('o');
  emit('s');

  wordBreak();
}

// HELPERS

void emit(char ch) {
  switch (ch) {
    case 'a':
      dot();
      dash();
      break;
    case 'b':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'o':
      dash();
      dash();
      dash();
      break;
    case 's':
      dot();
      dot();
      dot();
      break;
    default:
      blink(DELAY_UNKNOWN_CHARACTER);
      break;
  }
  characterBreak();
}

void dot() {
  blink(DELAY_DOT);
}

void dash() {
  blink(DELAY_DASH);
}

void characterBreak() {
  delay(DELAY_CHARACTER_BREAK);
}

void wordBreak() {
  delay(DELAY_WORD_BREAK - DELAY_CHARACTER_BREAK);
}

void blink(int duration) {
  digitalWrite(LIGHT, HIGH);
  delay(duration);
  digitalWrite(LIGHT, LOW);
  delay(DELAY_SHORT);
}
