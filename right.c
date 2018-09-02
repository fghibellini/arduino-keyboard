
#include <Wire.h>

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

const int KEY_COUNT = 27;
char syncBuffer[KEY_COUNT] = { LOW };

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
 
  if (i == 0 && VAL_A == LOW && syncBuffer[0] != 0xaa) { syncBuffer[0] = 0xaa; }
  else if (i == 0 && VAL_A == HIGH && syncBuffer[0] != 0x55) { syncBuffer[0] = 0x55; }
  if (i == 0 && VAL_B == LOW && syncBuffer[1] != 0xaa) { syncBuffer[1] = 0xaa; }
  else if (i == 0 && VAL_B == HIGH && syncBuffer[1] != 0x55) { syncBuffer[1] = 0x55; }
  if (i == 0 && VAL_C == LOW && syncBuffer[2] != 0xaa) { syncBuffer[2] = 0xaa; }
  else if (i == 0 && VAL_C == HIGH && syncBuffer[2] != 0x55) { syncBuffer[2] = 0x55; }
  if (i == 0 && VAL_D == LOW && syncBuffer[3] != 0xaa) { syncBuffer[3] = 0xaa; }
  else if (i == 0 && VAL_D == HIGH && syncBuffer[3] != 0x55) { syncBuffer[3] = 0x55; }
  if (i == 0 && VAL_E == LOW && syncBuffer[4] != 0xaa) { syncBuffer[4] = 0xaa; }
  else if (i == 0 && VAL_E == HIGH && syncBuffer[4] != 0x55) { syncBuffer[4] = 0x55; }

  if (i == 1 && VAL_A == LOW && syncBuffer[5] != 0xaa) { syncBuffer[5] = 0xaa; }
  else if (i == 1 && VAL_A == HIGH && syncBuffer[5] != 0x55) { syncBuffer[5] = 0x55; }
  if (i == 1 && VAL_B == LOW && syncBuffer[6] != 0xaa) { syncBuffer[6] = 0xaa; }
  else if (i == 1 && VAL_B == HIGH && syncBuffer[6] != 0x55) { syncBuffer[6] = 0x55; }
  if (i == 1 && VAL_C == LOW && syncBuffer[7] != 0xaa) { syncBuffer[7] = 0xaa; }
  else if (i == 1 && VAL_C == HIGH && syncBuffer[7] != 0x55) { syncBuffer[7] = 0x55; }
  if (i == 1 && VAL_D == LOW && syncBuffer[8] != 0xaa) { syncBuffer[8] = 0xaa; }
  else if (i == 1 && VAL_D == HIGH && syncBuffer[8] != 0x55) { syncBuffer[8] = 0x55; }
  if (i == 1 && VAL_E == LOW && syncBuffer[9] != 0xaa) { syncBuffer[9] = 0xaa; }
  else if (i == 1 && VAL_E == HIGH && syncBuffer[9] != 0x55) { syncBuffer[9] = 0x55; }

  if (i == 2 && VAL_A == LOW && syncBuffer[10] != 0xaa) { syncBuffer[10] = 0xaa; }
  else if (i == 2 && VAL_A == HIGH && syncBuffer[10] != 0x55) { syncBuffer[10] = 0x55; }
  if (i == 2 && VAL_B == LOW && syncBuffer[11] != 0xaa) { syncBuffer[11] = 0xaa; }
  else if (i == 2 && VAL_B == HIGH && syncBuffer[11] != 0x55) { syncBuffer[11] = 0x55; }
  if (i == 2 && VAL_C == LOW && syncBuffer[12] != 0xaa) { syncBuffer[12] = 0xaa; }
  else if (i == 2 && VAL_C == HIGH && syncBuffer[12] != 0x55) { syncBuffer[12] = 0x55; }
  if (i == 2 && VAL_D == LOW && syncBuffer[13] != 0xaa) { syncBuffer[13] = 0xaa; }
  else if (i == 2 && VAL_D == HIGH && syncBuffer[13] != 0x55) { syncBuffer[13] = 0x55; }
  if (i == 2 && VAL_E == LOW && syncBuffer[14] != 0xaa) { syncBuffer[14] = 0xaa; }
  else if (i == 2 && VAL_E == HIGH && syncBuffer[14] != 0x55) { syncBuffer[14] = 0x55; }

  if (i == 3 && VAL_A == LOW && syncBuffer[15] != 0xaa) { syncBuffer[15] = 0xaa; }
  else if (i == 3 && VAL_A == HIGH && syncBuffer[15] != 0x55) { syncBuffer[15] = 0x55; }
  if (i == 3 && VAL_B == LOW && syncBuffer[16] != 0xaa) { syncBuffer[16] = 0xaa; }
  else if (i == 3 && VAL_B == HIGH && syncBuffer[16] != 0x55) { syncBuffer[16] = 0x55; }
  if (i == 3 && VAL_C == LOW && syncBuffer[17] != 0xaa) { syncBuffer[17] = 0xaa; }
  else if (i == 3 && VAL_C == HIGH && syncBuffer[17] != 0x55) { syncBuffer[17] = 0x55; }
  if (i == 3 && VAL_D == LOW && syncBuffer[18] != 0xaa) { syncBuffer[18] = 0xaa; }
  else if (i == 3 && VAL_D == HIGH && syncBuffer[18] != 0x55) { syncBuffer[18] = 0x55; }

  if (i == 4 && VAL_A == LOW && syncBuffer[19] != 0xaa) { syncBuffer[19] = 0xaa; }
  else if (i == 4 && VAL_A == HIGH && syncBuffer[19] != 0x55) { syncBuffer[19] = 0x55; }
  if (i == 4 && VAL_B == LOW && syncBuffer[20] != 0xaa) { syncBuffer[20] = 0xaa; }
  else if (i == 4 && VAL_B == HIGH && syncBuffer[20] != 0x55) { syncBuffer[20] = 0x55; }
  if (i == 4 && VAL_C == LOW && syncBuffer[21] != 0xaa) { syncBuffer[21] = 0xaa; }
  else if (i == 4 && VAL_C == HIGH && syncBuffer[21] != 0x55) { syncBuffer[21] = 0x55; }
  if (i == 4 && VAL_D == LOW && syncBuffer[22] != 0xaa) { syncBuffer[22] = 0xaa; }
  else if (i == 4 && VAL_D == HIGH && syncBuffer[22] != 0x55) { syncBuffer[22] = 0x55; }

  if (i == 5 && VAL_A == LOW && syncBuffer[23] != 0xaa) { syncBuffer[23] = 0xaa; }
  else if (i == 5 && VAL_A == HIGH && syncBuffer[23] != 0x55) { syncBuffer[23] = 0x55; }
  if (i == 5 && VAL_B == LOW && syncBuffer[24] != 0xaa) { syncBuffer[24] = 0xaa; }
  else if (i == 5 && VAL_B == HIGH && syncBuffer[24] != 0x55) { syncBuffer[24] = 0x55; }
  if (i == 5 && VAL_C == LOW && syncBuffer[25] != 0xaa) { syncBuffer[25] = 0xaa; }
  else if (i == 5 && VAL_C == HIGH && syncBuffer[25] != 0x55) { syncBuffer[25] = 0x55; }
  if (i == 5 && VAL_D == LOW && syncBuffer[26] != 0xaa) { syncBuffer[26] = 0xaa; }
  else if (i == 5 && VAL_D == HIGH && syncBuffer[26] != 0x55) { syncBuffer[26] = 0x55; }

  i = (i + 1) % 6; 
}
