
#include <Wire.h>
#include <Keyboard.h>

const int SYNC_INTERVAL_MS = 30;

const unsigned char PROT_PRESSED = 0xaa;
const unsigned char PROT_RELEASED = 0x55;

// 6 x 4 keyboard

// columns
const int O_1 = 11;
const int O_2 = 9;
const int O_3 = A4;
const int O_4 = A2;
const int O_5 = A0;
const int O_6 = A1;

// rows
const int I_A = 12;
const int I_B = 10;
const int I_C = 8;
const int I_D = A3;

unsigned long last_sync_t = 0;
int i = 0;

int S_A1 = HIGH;
int S_A2 = HIGH;
int S_A3 = HIGH;
int S_A4 = HIGH;
int S_A5 = HIGH;
int S_A6 = HIGH;
int S_B1 = HIGH;
int S_B2 = HIGH;
int S_B3 = HIGH;
int S_B4 = HIGH;
int S_B5 = HIGH;
int S_B6 = HIGH;
int S_C1 = HIGH;
int S_C2 = HIGH;
int S_C3 = HIGH;
int S_C4 = HIGH;
int S_C5 = HIGH;
int S_C6 = HIGH;
int S_D1 = HIGH;
int S_D2 = HIGH;
int S_D3 = HIGH;
int S_D4 = HIGH;
int S_D5 = HIGH;
int S_D6 = HIGH;

void setup() {
  pinMode(O_1, OUTPUT);
  pinMode(O_2, OUTPUT);
  pinMode(O_3, OUTPUT);
  pinMode(O_4, OUTPUT);
  pinMode(O_5, OUTPUT);
  pinMode(O_6, OUTPUT);

  pinMode(I_A, INPUT_PULLUP);
  pinMode(I_B, INPUT_PULLUP);
  pinMode(I_C, INPUT_PULLUP);
  pinMode(I_D, INPUT_PULLUP);

  Keyboard.begin();

  Wire.begin();
}

unsigned char right_old[27] = { PROT_RELEASED };
unsigned char right_current[27] = { PROT_RELEASED };

int right_map[] = {
  // col 1
  '6',
  'y',
  'h',
  'n',
  KEY_LEFT_SHIFT, //KEY_LEFT_CTRL,
  // col 2
  '7',
  'u',
  'j',
  'm',
  ' ',
  // col 3
  '8',
  'i',
  'k',
  ',',
  KEY_LEFT_GUI,
  // col 4
  '9',
  'o',
  'l',
  '.',
  // col 5
  '0',
  'p',
  ';',
  '/',
  // col 6
  KEY_BACKSPACE,
  '[',
  '\'',
  KEY_RETURN
};


const int LEFT_KEY_COUNT = 27;

void sync() {
  last_sync_t = millis();
  Wire.requestFrom(11, LEFT_KEY_COUNT);
  if (Wire.available() >= LEFT_KEY_COUNT) {
    for (int n = 0; n < LEFT_KEY_COUNT; n++) {
      unsigned char val = Wire.read();
      right_current[n] = val;
    }

    for (int n = 0; n < LEFT_KEY_COUNT; n++) {
      unsigned char old_val = right_old[n];
      unsigned char val = right_current[n];
      if (old_val != val) {
        if (val == PROT_PRESSED) { Keyboard.press(right_map[n]); }
        else if (val == PROT_RELEASED) { Keyboard.release(right_map[n]); }
      }
      right_old[n] = val;
    }
  }
}

void loop() {
  // select column
  digitalWrite(O_1, i == 0 ? LOW : HIGH);
  digitalWrite(O_2, i == 1 ? LOW : HIGH);
  digitalWrite(O_3, i == 2 ? LOW : HIGH);
  digitalWrite(O_4, i == 3 ? LOW : HIGH);
  digitalWrite(O_5, i == 4 ? LOW : HIGH);
  digitalWrite(O_6, i == 5 ? LOW : HIGH);

  // read keys (i.e. rows)
  const int VAL_A = digitalRead(I_A);
  const int VAL_B = digitalRead(I_B);
  const int VAL_C = digitalRead(I_C);
  const int VAL_D = digitalRead(I_D);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (i == 0 && VAL_A == LOW && S_A1 != LOW) { Keyboard.press(KEY_ESC); S_A1 = LOW; }
  else if (i == 0 && VAL_A == HIGH && S_A1 != HIGH) { Keyboard.release(KEY_ESC); S_A1 = HIGH; }
  if (i == 0 && VAL_B == LOW && S_B1 != LOW) { Keyboard.press('\t'); S_B1 = LOW; }
  else if (i == 0 && VAL_B == HIGH && S_B1 != HIGH) { Keyboard.release('\t'); S_B1 = HIGH; }
  if (i == 0 && VAL_C == LOW && S_C1 != LOW) { Keyboard.press(KEY_LEFT_SHIFT); S_C1 = LOW; }
  else if (i == 0 && VAL_C == HIGH && S_C1 != HIGH) { Keyboard.release(KEY_LEFT_SHIFT); S_C1 = HIGH; }
  if (i == 0 && VAL_D == LOW && S_D1 != LOW) { Keyboard.press(KEY_LEFT_GUI); S_D1 = LOW; }
  else if (i == 0 && VAL_D == HIGH && S_D1 != HIGH) { Keyboard.release(KEY_LEFT_GUI); S_D1 = HIGH; }

  if (i == 1 && VAL_A == LOW && S_A2 != LOW) { Keyboard.press('1'); S_A2 = LOW; }
  else if (i == 1 && VAL_A == HIGH && S_A2 != HIGH) { Keyboard.release('1'); S_A2 = HIGH; }
  if (i == 1 && VAL_B == LOW && S_B2 != LOW) { Keyboard.press('q'); S_B2 = LOW; }
  else if (i == 1 && VAL_B == HIGH && S_B2 != HIGH) { Keyboard.release('q'); S_B2 = HIGH; }
  if (i == 1 && VAL_C == LOW && S_C2 != LOW) { Keyboard.press('a'); S_C2 = LOW; }
  else if (i == 1 && VAL_C == HIGH && S_C2 != HIGH) { Keyboard.release('a'); S_C2 = HIGH; }
  if (i == 1 && VAL_D == LOW && S_D2 != LOW) { Keyboard.press('z'); S_D2 = LOW; }
  else if (i == 1 && VAL_D == HIGH && S_D2 != HIGH) { Keyboard.release('z'); S_D2 = HIGH; }

  if (i == 2 && VAL_A == LOW && S_A3 != LOW) { Keyboard.press('2'); S_A3 = LOW; }
  else if (i == 2 && VAL_A == HIGH && S_A3 != HIGH) { Keyboard.release('2'); S_A3 = HIGH; }
  if (i == 2 && VAL_B == LOW && S_B3 != LOW) { Keyboard.press('w'); S_B3 = LOW; }
  else if (i == 2 && VAL_B == HIGH && S_B3 != HIGH) { Keyboard.release('w'); S_B3 = HIGH; }
  if (i == 2 && VAL_C == LOW && S_C3 != LOW) { Keyboard.press('s'); S_C3 = LOW; }
  else if (i == 2 && VAL_C == HIGH && S_C3 != HIGH) { Keyboard.release('s'); S_C3 = HIGH; }
  if (i == 2 && VAL_D == LOW && S_D3 != LOW) { Keyboard.press('x'); S_D3 = LOW; }
  else if (i == 2 && VAL_D == HIGH && S_D3 != HIGH) { Keyboard.release('x'); S_D3 = HIGH; }

  if (i == 3 && VAL_A == LOW && S_A4 != LOW) { Keyboard.press('3'); S_A4 = LOW; }
  else if (i == 3 && VAL_A == HIGH && S_A4 != HIGH) { Keyboard.release('3'); S_A4 = HIGH; }
  if (i == 3 && VAL_B == LOW && S_B4 != LOW) { Keyboard.press('e'); S_B4 = LOW; }
  else if (i == 3 && VAL_B == HIGH && S_B4 != HIGH) { Keyboard.release('e'); S_B4 = HIGH; }
  if (i == 3 && VAL_C == LOW && S_C4 != LOW) { Keyboard.press('d'); S_C4 = LOW; }
  else if (i == 3 && VAL_C == HIGH && S_C4 != HIGH) { Keyboard.release('d'); S_C4 = HIGH; }
  if (i == 3 && VAL_D == LOW && S_D4 != LOW) { Keyboard.press('c'); S_D4 = LOW; }
  else if (i == 3 && VAL_D == HIGH && S_D4 != HIGH) { Keyboard.release('c'); S_D4 = HIGH; }

  if (i == 4 && VAL_A == LOW && S_A5 != LOW) { Keyboard.press('4'); S_A5 = LOW; }
  else if (i == 4 && VAL_A == HIGH && S_A5 != HIGH) { Keyboard.release('4'); S_A5 = HIGH; }
  if (i == 4 && VAL_B == LOW && S_B5 != LOW) { Keyboard.press('r'); S_B5 = LOW; }
  else if (i == 4 && VAL_B == HIGH && S_B5 != HIGH) { Keyboard.release('r'); S_B5 = HIGH; }
  if (i == 4 && VAL_C == LOW && S_C5 != LOW) { Keyboard.press('f'); S_C5 = LOW; }
  else if (i == 4 && VAL_C == HIGH && S_C5 != HIGH) { Keyboard.release('f'); S_C5 = HIGH; }
  if (i == 4 && VAL_D == LOW && S_D5 != LOW) { Keyboard.press('v'); S_D5 = LOW; }
  else if (i == 4 && VAL_D == HIGH && S_D5 != HIGH) { Keyboard.release('v'); S_D5 = HIGH; }

  if (i == 5 && VAL_A == LOW && S_A6 != LOW) { Keyboard.press('5'); S_A6 = LOW; }
  else if (i == 5 && VAL_A == HIGH && S_A6 != HIGH) { Keyboard.release('5'); S_A6 = HIGH; }
  if (i == 5 && VAL_B == LOW && S_B6 != LOW) { Keyboard.press('t'); S_B6 = LOW; }
  else if (i == 5 && VAL_B == HIGH && S_B6 != HIGH) { Keyboard.release('t'); S_B6 = HIGH; }
  if (i == 5 && VAL_C == LOW && S_C6 != LOW) { Keyboard.press('g'); S_C6 = LOW; }
  else if (i == 5 && VAL_C == HIGH && S_C6 != HIGH) { Keyboard.release('g'); S_C6 = HIGH; }
  if (i == 5 && VAL_D == LOW && S_D6 != LOW) { Keyboard.press('b'); S_D6 = LOW; }
  else if (i == 5 && VAL_D == HIGH && S_D6 != HIGH) { Keyboard.release('b'); S_D6 = HIGH; }

  if ((millis() - last_sync_t) >= SYNC_INTERVAL_MS) {
    sync();
  }

  i = (i + 1) % 6; 
  delay(10);
}
