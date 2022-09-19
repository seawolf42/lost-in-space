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
const int DELAY_UNKNOWN_CHARACTER = DELAY_DASH * 5;

// SETUP AND MAIN LOOP

void setup() {
  pinMode(LIGHT, OUTPUT);
}

void loop() {
  emit("the quick brown fox jumps over the lazy dog");
}

// HELPERS

void emit(char* s) {
  while (*s) {
    emitChar(*s);
    *s++;
  }

  wordBreak();
}

void emitChar(char c) {
  char* s = getSequence(c);
  emitSequence(s);
}

char* getSequence(char c) {
  switch (c) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case ' ': return " ";
    default: return "!";
  }
}

void emitSequence(char* s) {
  if (!s) {
    blink(DELAY_UNKNOWN_CHARACTER);
  }
  while (*s) {
    switch (*s) {
      case '.':
        dot();
        break;
      case '-':
        dash();
        break;
      case ' ':
        wordBreak();
        break;
      default:
        blink(DELAY_UNKNOWN_CHARACTER);
        break;
    }
    *s++;
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
