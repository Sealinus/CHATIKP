#define KP_ROWS 4
#define KP_COLS 4
#define txp 12
#define rxp 2
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
Gyver433_TX<rxp> rx;

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
  static char PadBut = "";
  static int RadioChan = 0;
  keyboard();
 
}


void keyboard() {
  char key = pad.getKey();
  if (key) {
    Serial.print(key);
    tx.sendData(key);
  }
}

char decode(int code) {
  switch (code) {
    case 0: return (" "); break;
    case 1: return ("a"); break;
    case 2: return ("b"); break;
    case 3: return ("c"); break;
    case 4: return ("d"); break;
    case 5: return ("e"); break;
    case 6: return ("f"); break;
    case 7: return ("g"); break;
    case 8: return ("h"); break;
    case 9: return ("i"); break;
    case 10: return ("j"); break;
    case 11: return ("k"); break;
    case 12: return ("l"); break;
    case 13: return ("m"); break;
    case 14: return ("n"); break;
    case 15: return ("o"); break;
    case 16: return ("p"); break;
    case 17: return ("q"); break;
    case 18: return ("r"); break;
    case 19: return ("s"); break;
    case 20: return ("t"); break;
    case 21: return ("u"); break;
    case 22: return ("v"); break;
    case 23: return ("w"); break;
    case 24: return ("x"); break;
    case 25: return ("y"); break;
    case 26: return ("z"); break;
    case 27: return ("A"); break;
    case 28: return ("B"); break;
    case 29: return ("C"); break;
    case 30: return ("D"); break;
    case 31: return ("E"); break;
    case 32: return ("F"); break;
    case 33: return ("G"); break;
    case 34: return ("H"); break;
    case 35: return ("I"); break;
    case 36: return ("J"); break;
    case 37: return ("K"); break;
    case 38: return ("L"); break;
    case 39: return ("M"); break;
    case 40: return ("N"); break;
    case 41: return ("O"); break;
    case 42: return ("P"); break;
    case 43: return ("Q"); break;
    case 44: return ("R"); break;
    case 45: return ("S"); break;
    case 46: return ("T"); break;
    case 47: return ("U"); break;
    case 48: return ("V"); break;
    case 49: return ("W"); break;
    case 50: return ("X"); break;
    case 51: return ("Y"); break;
    case 52: return ("Z"); break;
    case 53: return ("0"); break;
    case 54: return ("1"); break;
    case 55: return ("2"); break;
    case 56: return ("3"); break;
    case 57: return ("4"); break;
    case 58: return ("5"); break;
    case 59: return ("6"); break;
    case 60: return ("7"); break;
    case 61: return ("8"); break;
    case 62: return ("9"); break;
    case 63: return ("."); break;
    case 64: return (","); break;
    case 65: return ("!"); break;
    case 66: return ("?"); break;
    case 67: return ("/"); break;
    case 68: return ("@"); break;
    case 69: return ("'"); break;
    case 70: return ("&"); break;
    case 71: return ("("); break;
    case 72: return (")"); break;
  }
}

String newSim(String text, char a) {
  lcd.clear();
  lcd.print(text);
  lcd.print(a);
  text = text + a;
  return (text);
}

int ChannelChange(int channel) {
  while (enc.click()) {
    //lcd.clear();
    lcd.home();
    lcd.print("Your channel is:");
    lcd.setCursor(0, 1);
    lcd.print(channel);
    enc.tick();
    if (enc.right()){channel = ++channel % 20; Serial.println("right");}
    if (enc.left()){channel = abs(--channel) % 20; Serial.println("left");}
  }
  lcd.clear();
  return channel; 
}