#include <TM1637Display.h>

// NOTE: requires external .zip download

// CONFIG

#define PIN_CLOCK 6
#define DISPLAY_IO 5

// DATA

const uint8_t CHAR_NONE = 0x00;
const uint8_t CHAR_ALL = 0xff;

const uint8_t CHAR_0 = SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F;
const uint8_t CHAR_1 = SEG_B | SEG_C;
const uint8_t CHAR_2 = SEG_A | SEG_B | SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_3 = SEG_A | SEG_B | SEG_C | SEG_D | SEG_G;
const uint8_t CHAR_4 = SEG_B | SEG_C | SEG_F | SEG_G;
const uint8_t CHAR_5 = SEG_A | SEG_C | SEG_D | SEG_F | SEG_G;
const uint8_t CHAR_6 = SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
const uint8_t CHAR_7 = SEG_A | SEG_B | SEG_C;
const uint8_t CHAR_8 = SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
const uint8_t CHAR_9 = SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G;
const uint8_t CHAR_A = SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
const uint8_t CHAR_b = SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
const uint8_t CHAR_c = SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_d = SEG_B | SEG_C | SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_E = SEG_A | SEG_D | SEG_E | SEG_F | SEG_G;
const uint8_t CHAR_F = SEG_A | SEG_E | SEG_F | SEG_G;

const uint8_t CHAR_o = SEG_C | SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_n = SEG_C | SEG_E | SEG_G;


const uint8_t ALL_ON[] = {CHAR_ALL, CHAR_ALL, CHAR_ALL, CHAR_ALL};
const uint8_t BLANK[] = {CHAR_NONE, CHAR_NONE, CHAR_NONE, CHAR_NONE};
const uint8_t DONE[] = {CHAR_d, CHAR_o, CHAR_n, CHAR_E};

TM1637Display displayPad = TM1637Display(PIN_CLOCK, DISPLAY_IO);

// SETUP AND MAIN LOOP

void setup() {
  Serial.begin(115200);
  displayPad.clear();
  delay(500);
  displayPad.setBrightness(7);
  displayPad.setSegments(ALL_ON);
  delay(500);
  displayPad.clear();
  delay(500);
  Serial.println("setup complete");
}

void loop() {
  Serial.println("starting count sequence");
  for (int i = 0; i < 10000; ++i) {
    displayPad.showNumberDec(i);
  }
  delay(500);
  displayPad.clear();
  delay(250);
  displayPad.setSegments(DONE);
  delay(2000);
}
