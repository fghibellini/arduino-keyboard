
#include <Keyboard.h>

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
}

int i = 0;

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
  if (VAL_A == LOW) {
    Keyboard.write('4');
  }
  if (VAL_B == LOW) {
    Keyboard.write('r');
  }
  if (VAL_C == LOW) {
    Keyboard.write('f');
  }
  if (VAL_D == LOW) {
    Keyboard.write('v');
  }

  i = (i + 1) % 6; 
  delay(100);
}