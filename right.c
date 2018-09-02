
#include <Wire.h>

// 6 x 5 keyboard

const unsigned char PROT_PRESSED = 0xaa;
const unsigned char PROT_RELEASED = 0x55;

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

const int KEY_COUNT = 27;
unsigned char syncBuffer[KEY_COUNT] = { PROT_RELEASED };

void onReq() {
  Wire.write(syncBuffer, KEY_COUNT);
}

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
  pinMode(I_E, INPUT_PULLUP);

  Wire.begin(11);
  Wire.onRequest(onReq);
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
 
  if (i == 0 && VAL_A == LOW && syncBuffer[0] != PROT_PRESSED) { syncBuffer[0] = PROT_PRESSED; }
  else if (i == 0 && VAL_A == HIGH && syncBuffer[0] != PROT_RELEASED) { syncBuffer[0] = PROT_RELEASED; }
  if (i == 0 && VAL_B == LOW && syncBuffer[1] != PROT_PRESSED) { syncBuffer[1] = PROT_PRESSED; }
  else if (i == 0 && VAL_B == HIGH && syncBuffer[1] != PROT_RELEASED) { syncBuffer[1] = PROT_RELEASED; }
  if (i == 0 && VAL_C == LOW && syncBuffer[2] != PROT_PRESSED) { syncBuffer[2] = PROT_PRESSED; }
  else if (i == 0 && VAL_C == HIGH && syncBuffer[2] != PROT_RELEASED) { syncBuffer[2] = PROT_RELEASED; }
  if (i == 0 && VAL_D == LOW && syncBuffer[3] != PROT_PRESSED) { syncBuffer[3] = PROT_PRESSED; }
  else if (i == 0 && VAL_D == HIGH && syncBuffer[3] != PROT_RELEASED) { syncBuffer[3] = PROT_RELEASED; }
  if (i == 0 && VAL_E == LOW && syncBuffer[4] != PROT_PRESSED) { syncBuffer[4] = PROT_PRESSED; }
  else if (i == 0 && VAL_E == HIGH && syncBuffer[4] != PROT_RELEASED) { syncBuffer[4] = PROT_RELEASED; }

  if (i == 1 && VAL_A == LOW && syncBuffer[5] != PROT_PRESSED) { syncBuffer[5] = PROT_PRESSED; }
  else if (i == 1 && VAL_A == HIGH && syncBuffer[5] != PROT_RELEASED) { syncBuffer[5] = PROT_RELEASED; }
  if (i == 1 && VAL_B == LOW && syncBuffer[6] != PROT_PRESSED) { syncBuffer[6] = PROT_PRESSED; }
  else if (i == 1 && VAL_B == HIGH && syncBuffer[6] != PROT_RELEASED) { syncBuffer[6] = PROT_RELEASED; }
  if (i == 1 && VAL_C == LOW && syncBuffer[7] != PROT_PRESSED) { syncBuffer[7] = PROT_PRESSED; }
  else if (i == 1 && VAL_C == HIGH && syncBuffer[7] != PROT_RELEASED) { syncBuffer[7] = PROT_RELEASED; }
  if (i == 1 && VAL_D == LOW && syncBuffer[8] != PROT_PRESSED) { syncBuffer[8] = PROT_PRESSED; }
  else if (i == 1 && VAL_D == HIGH && syncBuffer[8] != PROT_RELEASED) { syncBuffer[8] = PROT_RELEASED; }
  if (i == 1 && VAL_E == LOW && syncBuffer[9] != PROT_PRESSED) { syncBuffer[9] = PROT_PRESSED; }
  else if (i == 1 && VAL_E == HIGH && syncBuffer[9] != PROT_RELEASED) { syncBuffer[9] = PROT_RELEASED; }

  if (i == 2 && VAL_A == LOW && syncBuffer[10] != PROT_PRESSED) { syncBuffer[10] = PROT_PRESSED; }
  else if (i == 2 && VAL_A == HIGH && syncBuffer[10] != PROT_RELEASED) { syncBuffer[10] = PROT_RELEASED; }
  if (i == 2 && VAL_B == LOW && syncBuffer[11] != PROT_PRESSED) { syncBuffer[11] = PROT_PRESSED; }
  else if (i == 2 && VAL_B == HIGH && syncBuffer[11] != PROT_RELEASED) { syncBuffer[11] = PROT_RELEASED; }
  if (i == 2 && VAL_C == LOW && syncBuffer[12] != PROT_PRESSED) { syncBuffer[12] = PROT_PRESSED; }
  else if (i == 2 && VAL_C == HIGH && syncBuffer[12] != PROT_RELEASED) { syncBuffer[12] = PROT_RELEASED; }
  if (i == 2 && VAL_D == LOW && syncBuffer[13] != PROT_PRESSED) { syncBuffer[13] = PROT_PRESSED; }
  else if (i == 2 && VAL_D == HIGH && syncBuffer[13] != PROT_RELEASED) { syncBuffer[13] = PROT_RELEASED; }
  if (i == 2 && VAL_E == LOW && syncBuffer[14] != PROT_PRESSED) { syncBuffer[14] = PROT_PRESSED; }
  else if (i == 2 && VAL_E == HIGH && syncBuffer[14] != PROT_RELEASED) { syncBuffer[14] = PROT_RELEASED; }

  if (i == 3 && VAL_A == LOW && syncBuffer[15] != PROT_PRESSED) { syncBuffer[15] = PROT_PRESSED; }
  else if (i == 3 && VAL_A == HIGH && syncBuffer[15] != PROT_RELEASED) { syncBuffer[15] = PROT_RELEASED; }
  if (i == 3 && VAL_B == LOW && syncBuffer[16] != PROT_PRESSED) { syncBuffer[16] = PROT_PRESSED; }
  else if (i == 3 && VAL_B == HIGH && syncBuffer[16] != PROT_RELEASED) { syncBuffer[16] = PROT_RELEASED; }
  if (i == 3 && VAL_C == LOW && syncBuffer[17] != PROT_PRESSED) { syncBuffer[17] = PROT_PRESSED; }
  else if (i == 3 && VAL_C == HIGH && syncBuffer[17] != PROT_RELEASED) { syncBuffer[17] = PROT_RELEASED; }
  if (i == 3 && VAL_D == LOW && syncBuffer[18] != PROT_PRESSED) { syncBuffer[18] = PROT_PRESSED; }
  else if (i == 3 && VAL_D == HIGH && syncBuffer[18] != PROT_RELEASED) { syncBuffer[18] = PROT_RELEASED; }

  if (i == 4 && VAL_A == LOW && syncBuffer[19] != PROT_PRESSED) { syncBuffer[19] = PROT_PRESSED; }
  else if (i == 4 && VAL_A == HIGH && syncBuffer[19] != PROT_RELEASED) { syncBuffer[19] = PROT_RELEASED; }
  if (i == 4 && VAL_B == LOW && syncBuffer[20] != PROT_PRESSED) { syncBuffer[20] = PROT_PRESSED; }
  else if (i == 4 && VAL_B == HIGH && syncBuffer[20] != PROT_RELEASED) { syncBuffer[20] = PROT_RELEASED; }
  if (i == 4 && VAL_C == LOW && syncBuffer[21] != PROT_PRESSED) { syncBuffer[21] = PROT_PRESSED; }
  else if (i == 4 && VAL_C == HIGH && syncBuffer[21] != PROT_RELEASED) { syncBuffer[21] = PROT_RELEASED; }
  if (i == 4 && VAL_D == LOW && syncBuffer[22] != PROT_PRESSED) { syncBuffer[22] = PROT_PRESSED; }
  else if (i == 4 && VAL_D == HIGH && syncBuffer[22] != PROT_RELEASED) { syncBuffer[22] = PROT_RELEASED; }

  if (i == 5 && VAL_A == LOW && syncBuffer[23] != PROT_PRESSED) { syncBuffer[23] = PROT_PRESSED; }
  else if (i == 5 && VAL_A == HIGH && syncBuffer[23] != PROT_RELEASED) { syncBuffer[23] = PROT_RELEASED; }
  if (i == 5 && VAL_B == LOW && syncBuffer[24] != PROT_PRESSED) { syncBuffer[24] = PROT_PRESSED; }
  else if (i == 5 && VAL_B == HIGH && syncBuffer[24] != PROT_RELEASED) { syncBuffer[24] = PROT_RELEASED; }
  if (i == 5 && VAL_C == LOW && syncBuffer[25] != PROT_PRESSED) { syncBuffer[25] = PROT_PRESSED; }
  else if (i == 5 && VAL_C == HIGH && syncBuffer[25] != PROT_RELEASED) { syncBuffer[25] = PROT_RELEASED; }
  if (i == 5 && VAL_D == LOW && syncBuffer[26] != PROT_PRESSED) { syncBuffer[26] = PROT_PRESSED; }
  else if (i == 5 && VAL_D == HIGH && syncBuffer[26] != PROT_RELEASED) { syncBuffer[26] = PROT_RELEASED; }

  i = (i + 1) % 6; 
}
