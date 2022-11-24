// размеры клавиатуры
#define KP_ROWS 4
#define KP_COLS 4
// пины подключения (по порядку штекера)
byte colPins[KP_COLS] = {42, 44, 46, 48};
byte rowPins[KP_ROWS] = {34, 36, 38, 40};
// массив имён кнопок
char keys[KP_ROWS][KP_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// подключаем либу
#include <SimpleKeypad.h>
// создаём клавиатуру
SimpleKeypad pad((char*)keys, rowPins, colPins, KP_ROWS, KP_COLS);
void setup() {
  Serial.begin(9600);
}
void loop() {
  // получить текущую нажатую клавишу
  // вернёт 0 символ если ничего не нажато
  char key = pad.getKey();
  // если кнопка нажата (не 0 символ)
  if (key) {
    // выводим в порт
    Serial.println(key);
    // можно разобрать через
    // switch (key) {
    // case '1':
    // ...
  }
}


void keyboard (){
  char key = pad.getKey();
  if (key) {
    Serial.println(key);
  }
}