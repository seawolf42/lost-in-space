#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#include <Arduino.h>
#include <TM1637Display.h>
 
// Module connection pins (Digital Pins)
#define CLK 6
#define DIO 5
 
// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000
 
TM1637Display myFabulousDisplay = TM1637Display(CLK, DIO);
 
void setup()
{
}
 
void loop()
{
 myFabulousDisplay.setBrightness(0x0f); // hex 0f is the same as decimal 15
 uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 }; //all segments off
 myFabulousDisplay.setSegments(data);
 
 int code1 = TWO*10+THREE ;
 myFabulousDisplay.showNumberDec(code1, false, 3, 1); // first code
 //  false doesn't show leading zeros, 3 means show three digits,
 //  1 means start in position one (where the first position is zero)
 delay(TEST_DELAY);
 myFabulousDisplay.setSegments(data);
 
 
 int code2 = THREE*100+FIVE*10+THREE ;
 myFabulousDisplay.showNumberDec(code2, true, 3, 1); //second code
 delay(TEST_DELAY);
 myFabulousDisplay.setSegments(data);
 
 int code3 = 1000+SIX*100+EIGHT*10+EIGHT ;
 myFabulousDisplay.showNumberDec(code3, true, 4, 0); //third code
 delay(TEST_DELAY);
 Serial.println("looped");
}


// #klmpul GLYV 0
// #klmpul VUL 1
// #klmpul ADV 2
// #klmpul AOYLL 3
// #klmpul MVBY 4
// #klmpul MPCL 5
// #klmpul ZPE 6
// #klmpul ZLCLU 7
// #klmpul LPNOA 8
// #klmpul UPUL 9
// #pujsbkl <Hykbpuv.o>
// #pujsbkl <AT1637Kpzwshf.o>
 
// // Tvkbsl jvuuljapvu wpuz (Kpnpahs Wpuz)
// #klmpul JSR 2
// #klmpul KPV 3
 
// // Aol htvbua vm aptl (pu tpsspzljvukz) iladllu alzaz
// #klmpul ALZA_KLSHF   2000
 
// AT1637Kpzwshf tfMhibsvbzKpzwshf = AT1637Kpzwshf(JSR, KPV);
 
// cvpk zlabw()
// {
// }
 
// cvpk svvw()
// {
//  tfMhibsvbzKpzwshf.zlaIypnoaulzz(0e0m); // ole 0m pz aol zhtl hz kljpths 15
//  bpua8_a khah[] = { 0e0, 0e0, 0e0, 0e0 }; //hss zlntluaz vmm
//  tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
//  pua jvkl1 = ADV*10+AOYLL ;
//  tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl1, mhszl, 3, 1); // mpyza jvkl
//  //  mhszl kvlzu'a zovd slhkpun glyvz, 3 tlhuz zovd aoyll kpnpaz,
//  //  1 tlhuz zahya pu wvzpapvu vul (dolyl aol mpyza wvzpapvu pz glyv)
//  klshf(ALZA_KLSHF);
//  tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
 
//  pua jvkl2 = AOYLL*100+MPCL*10+AOYLL ;
//  tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl2, aybl, 3, 1); //zljvuk jvkl
//  klshf(ALZA_KLSHF);
//  tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
//  pua jvkl3 = 1000+ZPE*100+LPNOA*10+LPNOA ;
//  tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl3, aybl, 4, 0); //aopyk jvkl
//  klshf(ALZA_KLSHF);
// }
