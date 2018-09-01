
#include <Wire.h>
#include <Keyboard.h>

// 6 x 5 keyboard

// columns
const int O_1 = A4;
const int O_2 = A1;
const int O_3 = A0;
const int O_4 = 7;
const int O_5 = 10;
const int O_6 = 12;

// rows
const int I_A = A3;
const int I_B = A5;
const int I_C = 8;
const int I_D = 11;
const int I_E = 9;

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
int S_E1 = HIGH;
int S_E2 = HIGH;
int S_E3 = HIGH;

void setup() {
  pinMode(O_1, OUTPUT);
  pinMode(O_2, OUTPUT);
  pinMode(O_3, OUTPUT);
  pinMode(O_4, OUTPUT);
  pinMode(O_5, OUTPUT);
  pinMode(O_6, OUTPUT);

  // LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  pinMode(I_A, INPUT_PULLUP);
  pinMode(I_B, INPUT_PULLUP);
  pinMode(I_C, INPUT_PULLUP);
  pinMode(I_D, INPUT_PULLUP);
  pinMode(I_E, INPUT_PULLUP);

  Keyboard.begin();
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
  const int VAL_E = digitalRead(I_E);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (i == 0 && VAL_A == LOW && S_A1 != LOW) { Keyboard.press('6'); S_A1 = LOW; }
  else if (i == 0 && VAL_A == HIGH && S_A1 != HIGH) { Keyboard.release('6'); S_A1 = HIGH; }
  if (i == 0 && VAL_B == LOW && S_B1 != LOW) { Keyboard.press('z'); S_B1 = LOW; }
  else if (i == 0 && VAL_B == HIGH && S_B1 != HIGH) { Keyboard.release('z'); S_B1 = HIGH; }
  if (i == 0 && VAL_C == LOW && S_C1 != LOW) { Keyboard.press('h'); S_C1 = LOW; }
  else if (i == 0 && VAL_C == HIGH && S_C1 != HIGH) { Keyboard.release('h'); S_C1 = HIGH; }
  if (i == 0 && VAL_D == LOW && S_D1 != LOW) { Keyboard.press('n'); S_D1 = LOW; }
  else if (i == 0 && VAL_D == HIGH && S_D1 != HIGH) { Keyboard.release('n'); S_D1 = HIGH; }
  if (i == 0 && VAL_E == LOW && S_E1 != LOW) { Keyboard.press(KEY_LEFT_CTRL); S_E1 = LOW; }
  else if (i == 0 && VAL_E == HIGH && S_E1 != HIGH) { Keyboard.release(KEY_LEFT_CTRL); S_E1 = HIGH; }

  if (i == 1 && VAL_A == LOW && S_A2 != LOW) { Keyboard.press('7'); S_A2 = LOW; }
  else if (i == 1 && VAL_A == HIGH && S_A2 != HIGH) { Keyboard.release('7'); S_A2 = HIGH; }
  if (i == 1 && VAL_B == LOW && S_B2 != LOW) { Keyboard.press('u'); S_B2 = LOW; }
  else if (i == 1 && VAL_B == HIGH && S_B2 != HIGH) { Keyboard.release('u'); S_B2 = HIGH; }
  if (i == 1 && VAL_C == LOW && S_C2 != LOW) { Keyboard.press('j'); S_C2 = LOW; }
  else if (i == 1 && VAL_C == HIGH && S_C2 != HIGH) { Keyboard.release('j'); S_C2 = HIGH; }
  if (i == 1 && VAL_D == LOW && S_D2 != LOW) { Keyboard.press('m'); S_D2 = LOW; }
  else if (i == 1 && VAL_D == HIGH && S_D2 != HIGH) { Keyboard.release('m'); S_D2 = HIGH; }
  if (i == 1 && VAL_E == LOW && S_E2 != LOW) { Keyboard.press(KEY_LEFT_SHIFT); S_E2 = LOW; }
  else if (i == 1 && VAL_E == HIGH && S_E2 != HIGH) { Keyboard.release(KEY_LEFT_SHIFT); S_E2 = HIGH; }

  if (i == 2 && VAL_A == LOW && S_A3 != LOW) { Keyboard.press('8'); S_A3 = LOW; }
  else if (i == 2 && VAL_A == HIGH && S_A3 != HIGH) { Keyboard.release('8'); S_A3 = HIGH; }
  if (i == 2 && VAL_B == LOW && S_B3 != LOW) { Keyboard.press('i'); S_B3 = LOW; }
  else if (i == 2 && VAL_B == HIGH && S_B3 != HIGH) { Keyboard.release('i'); S_B3 = HIGH; }
  if (i == 2 && VAL_C == LOW && S_C3 != LOW) { Keyboard.press('k'); S_C3 = LOW; }
  else if (i == 2 && VAL_C == HIGH && S_C3 != HIGH) { Keyboard.release('k'); S_C3 = HIGH; }
  if (i == 2 && VAL_D == LOW && S_D3 != LOW) { Keyboard.press(','); S_D3 = LOW; }
  else if (i == 2 && VAL_D == HIGH && S_D3 != HIGH) { Keyboard.release(','); S_D3 = HIGH; }
  if (i == 2 && VAL_E == LOW && S_E3 != LOW) { Keyboard.press(KEY_LEFT_GUI); S_E3 = LOW; }
  else if (i == 2 && VAL_E == HIGH && S_E3 != HIGH) { Keyboard.release(KEY_LEFT_GUI); S_E3 = HIGH; }

  if (i == 3 && VAL_A == LOW && S_A4 != LOW) { Keyboard.press('9'); S_A4 = LOW; }
  else if (i == 3 && VAL_A == HIGH && S_A4 != HIGH) { Keyboard.release('9'); S_A4 = HIGH; }
  if (i == 3 && VAL_B == LOW && S_B4 != LOW) { Keyboard.press('o'); S_B4 = LOW; }
  else if (i == 3 && VAL_B == HIGH && S_B4 != HIGH) { Keyboard.release('o'); S_B4 = HIGH; }
  if (i == 3 && VAL_C == LOW && S_C4 != LOW) { Keyboard.press('l'); S_C4 = LOW; }
  else if (i == 3 && VAL_C == HIGH && S_C4 != HIGH) { Keyboard.release('l'); S_C4 = HIGH; }
  if (i == 3 && VAL_D == LOW && S_D4 != LOW) { Keyboard.press('.'); S_D4 = LOW; }
  else if (i == 3 && VAL_D == HIGH && S_D4 != HIGH) { Keyboard.release('.'); S_D4 = HIGH; }

  if (i == 4 && VAL_A == LOW && S_A5 != LOW) { Keyboard.press('0'); S_A5 = LOW; }
  else if (i == 4 && VAL_A == HIGH && S_A5 != HIGH) { Keyboard.release('0'); S_A5 = HIGH; }
  if (i == 4 && VAL_B == LOW && S_B5 != LOW) { Keyboard.press('p'); S_B5 = LOW; }
  else if (i == 4 && VAL_B == HIGH && S_B5 != HIGH) { Keyboard.release('p'); S_B5 = HIGH; }
  if (i == 4 && VAL_C == LOW && S_C5 != LOW) { Keyboard.press(';'); S_C5 = LOW; }
  else if (i == 4 && VAL_C == HIGH && S_C5 != HIGH) { Keyboard.release(';'); S_C5 = HIGH; }
  if (i == 4 && VAL_D == LOW && S_D5 != LOW) { Keyboard.press('/'); S_D5 = LOW; }
  else if (i == 4 && VAL_D == HIGH && S_D5 != HIGH) { Keyboard.release('/'); S_D5 = HIGH; }

  if (i == 5 && VAL_A == LOW && S_A6 != LOW) { Keyboard.press('-'); S_A6 = LOW; }
  else if (i == 5 && VAL_A == HIGH && S_A6 != HIGH) { Keyboard.release('-'); S_A6 = HIGH; }
  if (i == 5 && VAL_B == LOW && S_B6 != LOW) { Keyboard.press('['); S_B6 = LOW; }
  else if (i == 5 && VAL_B == HIGH && S_B6 != HIGH) { Keyboard.release('['); S_B6 = HIGH; }
  if (i == 5 && VAL_C == LOW && S_C6 != LOW) { Keyboard.press(KEY_RETURN); S_C6 = LOW; }
  else if (i == 5 && VAL_C == HIGH && S_C6 != HIGH) { Keyboard.release(KEY_RETURN); S_C6 = HIGH; }
  if (i == 5 && VAL_D == LOW && S_D6 != LOW) { Keyboard.press(']'); S_D6 = LOW; }
  else if (i == 5 && VAL_D == HIGH && S_D6 != HIGH) { Keyboard.release(']'); S_D6 = HIGH; }

  i = (i + 1) % 6; 
  delay(10);
}
