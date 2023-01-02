#include <TM1637Display.h>

// NOTE: requires external library: ../../assets/7SEG-TM1637-HERO.zip

// CONFIG

#define PIN_DISPLAY_CLOCK 6
#define PIN_DISPLAY_IO 5

#define PIN_ENCODER_CLOCK 2
#define PIN_ENCODER_IO 3

// DATA

const uint8_t CHAR_NONE = 0x00;
const uint8_t CHAR_ALL = 0xff;

const uint8_t CHAR_d = SEG_B | SEG_C | SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_o = SEG_C | SEG_D | SEG_E | SEG_G;
const uint8_t CHAR_n = SEG_C | SEG_E | SEG_G;
const uint8_t CHAR_E = SEG_A | SEG_D | SEG_E | SEG_F | SEG_G;

const uint8_t ALL_ON[] = {CHAR_ALL, CHAR_ALL, CHAR_ALL, CHAR_ALL};
const uint8_t BLANK[] = {CHAR_NONE, CHAR_NONE, CHAR_NONE, CHAR_NONE};
const uint8_t DONE[] = {CHAR_d, CHAR_o, CHAR_n, CHAR_E};

TM1637Display displayPad = TM1637Display(PIN_DISPLAY_CLOCK, PIN_DISPLAY_IO);

volatile int stepCounter = 0;
volatile bool clockLatch = true;

int lastStep = 0;

// SETUP AND MAIN LOOP

void setup()
{
    pinMode(PIN_ENCODER_CLOCK, INPUT);
    pinMode(PIN_ENCODER_IO, INPUT);

    displayPad.clear();
    delay(1000);
    displayPad.setBrightness(7);

    Serial.begin(115200);

    attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_CLOCK), updateEncoderClock, CHANGE);
    attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_IO), updateEncoderIO, CHANGE);

    Serial.println("setup complete");
}

void loop()
{
    displayPad.showNumberDec(stepCounter);
    delay(50);

    const int currentStep = stepCounter;
    const int delta = currentStep - lastStep;
    lastStep = currentStep;

    if (delta)
    {
        Serial.print("direction: ");
        Serial.print(delta > 0 ? "CW" : "CCW");
        Serial.print(", counter: ");
        Serial.println(lastStep);
    }

    switch (lastStep)
    {
    case 50:
    case 75:
        displayPad.setSegments(ALL_ON);
        delay(500);
        displayPad.showNumberDec(lastStep);
        delay(500);
        break;
    case 100:
        displayPad.setSegments(DONE);
        delay(500);
        displayPad.clear();
        delay(500);
        displayPad.setSegments(DONE);
        delay(500);
        displayPad.clear();
        delay(500);
        stepCounter = 0;
    default:
        break;
    }
}

void updateEncoderClock()
{
    if (clockLatch)
    {
        return;
    }
    clockLatch = true;
    if (digitalRead(PIN_ENCODER_CLOCK) == 0)
    {
        return;
    }
    const int step = digitalRead(PIN_ENCODER_IO);
    if (step == 0)
    {
        --stepCounter;
    }
    else
    {
        ++stepCounter;
    }
}

void updateEncoderIO()
{
    if (!clockLatch)
    {
        return;
    }
    clockLatch = false;
}
