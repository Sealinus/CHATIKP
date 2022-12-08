#define KP_ROWS 4
#define KP_COLS 4
#define txp 2
#define rxp 12
#define sone 5
#define stwo 6
#define keyp 7

#include <SimpleKeypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleKeypad.h>
#include <Gyver433.h>
#include <EncButton2.h>


static byte colPins[KP_COLS] = { 11, 10, 9, 8 };
static byte rowPins[KP_ROWS] = { A0, A1, A2, A3 };
static char keys[KP_ROWS][KP_COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
SimpleKeypad pad((char*)keys, rowPins, colPins, KP_ROWS, KP_COLS);

Gyver433_TX<txp> tx;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

EncButton2<EB_ENCBTN> enc(INPUT, sone, stwo, keyp);  // энкодер с кнопкой

String msg = "";


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  static int channel = 0;
  static char key = pad.getKey();
  static char NextChar = "";
  static int RadioChan = 0;
  static String TextOnScreen = "";
  static String NumOnScreen = "";
  key = keyboard();
  if (pad.getKey() == 'A') tx.sendData(key);
  

 
}


char keyboard() {
  char key = pad.getKey();
  if (key) {
    Serial.write(key);
    if (key != 'A' && key != 'B' && key != 'C' && key != 'D'){
      lcd.print(key);
    return key;
    }

  }
}