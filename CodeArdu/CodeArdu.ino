// размеры клавиатуры
#define KP_ROWS 4
#define KP_COLS 4
// пины подключения (по порядку штекера)

#include <SimpleKeypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

static byte colPins[KP_COLS] = {42, 44, 46, 48};
static byte rowPins[KP_ROWS] = {34, 36, 38, 40};
static char keys[KP_ROWS][KP_COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

SimpleKeypad pad((char*)keys, rowPins, colPins, KP_ROWS, KP_COLS);

LiquidCrystal_I2C lcd( 0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
   lcd.backlight();
   
}

void loop() {
  keyboard();
}


void keyboard (){


  char key = pad.getKey();
  if (key) {
    lcd.print("p");
    Serial.print(key);
  }
}