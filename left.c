
#include <pitchToFrequency.h>
#include <pitchToNote.h>
#include <frequencyToNote.h>
#include <MIDIUSB.h>

#include <Wire.h>

////////////
// CONFIG //
////////////

// how often we poll state from other keyboard 
const int SYNC_INTERVAL_MS = 30;
const int RIGHT_DEV_ID = 11; // i2c right keyboard device id

// values to represent key pressed/released
// during communication between two keyboards
const unsigned char PROT_PRESSED = 0xaa;
const unsigned char PROT_RELEASED = 0x55;

const int LEFT_KEY_COUNT = 24; // 4 x 6
const int RIGHT_KEY_COUNT = 27; // 4 x 6 + 3 thumb keys

// PINOUT ON LEFT KEYBOARD
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

///////////
// STATE //
///////////

unsigned long last_sync_t = 0;
int i = 0;
unsigned char state[LEFT_KEY_COUNT + RIGHT_KEY_COUNT] = { HIGH }; // tracks which keys were pressed during the last scan

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

  Wire.begin();
}


int mappings[] = {

  ///////////////
  // LEFT HAND //
  ///////////////
 
  // left A
  pitchC1,
  pitchD1,
  pitchE1,
  pitchF1,
  pitchG1,
  pitchA1,
  // left B
  pitchC2,
  pitchD2,
  pitchE2,
  pitchF2,
  pitchG2,
  pitchA2,
  // left C
  pitchC3,
  pitchD3,
  pitchE3,
  pitchF3,
  pitchG3,
  pitchA3,
  // left D
  pitchC4,
  pitchD4,
  pitchE4,
  pitchF4,
  pitchG4,
  pitchA4,

  ////////////////
  // RIGHT HAND //
  ////////////////
 
  // right A
  // right A
  pitchC1,
  pitchD1,
  pitchE1,
  pitchF1,
  pitchG1,
  pitchA1,
  // right B
  pitchC2,
  pitchD2,
  pitchE2,
  pitchF2,
  pitchG2,
  pitchA2,
  // right C
  pitchC3,
  pitchD3,
  pitchE3,
  pitchF3,
  pitchG3,
  pitchA3,
  // right D
  pitchC4,
  pitchD4,
  pitchE4,
  pitchF4,
  pitchG4,
  pitchA4,
  // right E
  pitchF4,
  pitchG4,
  pitchA4,
};


void sync() {
  unsigned char right_current[RIGHT_KEY_COUNT];

  last_sync_t = millis();
  Wire.requestFrom(RIGHT_DEV_ID, RIGHT_KEY_COUNT);

  if (Wire.available() >= RIGHT_KEY_COUNT) {

    for (int n = 0; n < RIGHT_KEY_COUNT; n++) {
      unsigned char val = Wire.read();
      right_current[n] = val;
    }

    for (int n = 0; n < RIGHT_KEY_COUNT; n++) {
      unsigned char old_val = state[LEFT_KEY_COUNT + n];
      int val = (right_current[n] == PROT_PRESSED) ? LOW : HIGH;
      if (old_val != val) {
        if (val == LOW) { keyDown(LEFT_KEY_COUNT + n); }
        else if (val == HIGH) { keyUp(LEFT_KEY_COUNT + n); }
      }
      state[LEFT_KEY_COUNT + n] = val;
    }

  }
}

void keyUp(int i) {
  noteOff(mappings[i]);
}

void keyDown(int i) {
  noteOn(mappings[i]);
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

  if (i == 0) {
    if (VAL_A == LOW && state[0] != LOW) { keyDown(0); state[0] = LOW; }
    else if (VAL_A == HIGH && state[0] != HIGH) { keyUp(0); state[0] = HIGH; }
    if (VAL_B == LOW && state[6] != LOW) { keyDown(6); state[6] = LOW; }
    else if (VAL_B == HIGH && state[6] != HIGH) { keyUp(6); state[6] = HIGH; }
    if (VAL_C == LOW && state[12] != LOW) { keyDown(12); state[12] = LOW; }
    else if (VAL_C == HIGH && state[12] != HIGH) { keyUp(12); state[12] = HIGH; }
    if (VAL_D == LOW && state[18] != LOW) { keyDown(18); state[18] = LOW; }
    else if (VAL_D == HIGH && state[18] != HIGH) { keyUp(18); state[18] = HIGH; }
  }

  if (i == 1) {
    if (VAL_A == LOW && state[1] != LOW) { keyDown(1); state[1] = LOW; }
    else if (VAL_A == HIGH && state[1] != HIGH) { keyUp(1); state[1] = HIGH; }
    if (VAL_B == LOW && state[7] != LOW) { keyDown(7); state[7] = LOW; }
    else if (VAL_B == HIGH && state[7] != HIGH) { keyUp(7); state[7] = HIGH; }
    if (VAL_C == LOW && state[13] != LOW) { keyDown(13); state[13] = LOW; }
    else if (VAL_C == HIGH && state[13] != HIGH) { keyUp(13); state[13] = HIGH; }
    if (VAL_D == LOW && state[19] != LOW) { keyDown(19); state[19] = LOW; }
    else if (VAL_D == HIGH && state[19] != HIGH) { keyUp(19); state[19] = HIGH; }
  }

  if (i == 2) {
    if (VAL_A == LOW && state[2] != LOW) { keyDown(2); state[2] = LOW; }
    else if (VAL_A == HIGH && state[2] != HIGH) { keyUp(2); state[2] = HIGH; }
    if (VAL_B == LOW && state[8] != LOW) { keyDown(8); state[8] = LOW; }
    else if (VAL_B == HIGH && state[8] != HIGH) { keyUp(8); state[8] = HIGH; }
    if (VAL_C == LOW && state[14] != LOW) { keyDown(14); state[14] = LOW; }
    else if (VAL_C == HIGH && state[14] != HIGH) { keyUp(14); state[14] = HIGH; }
    if (VAL_D == LOW && state[20] != LOW) { keyDown(20); state[20] = LOW; }
    else if (VAL_D == HIGH && state[20] != HIGH) { keyUp(20); state[20] = HIGH; }
  }

  if (i == 3) {
    if (VAL_A == LOW && state[3] != LOW) { keyDown(3); state[3] = LOW; }
    else if (VAL_A == HIGH && state[3] != HIGH) { keyUp(3); state[3] = HIGH; }
    if (VAL_B == LOW && state[9] != LOW) { keyDown(9); state[9] = LOW; }
    else if (VAL_B == HIGH && state[9] != HIGH) { keyUp(9); state[9] = HIGH; }
    if (VAL_C == LOW && state[15] != LOW) { keyDown(15); state[15] = LOW; }
    else if (VAL_C == HIGH && state[15] != HIGH) { keyUp(15); state[15] = HIGH; }
    if (VAL_D == LOW && state[21] != LOW) { keyDown(21); state[21] = LOW; }
    else if (VAL_D == HIGH && state[21] != HIGH) { keyUp(21); state[21] = HIGH; }
  }

  if (i == 4) {
    if (VAL_A == LOW && state[4] != LOW) { keyDown(4); state[4] = LOW; }
    else if (VAL_A == HIGH && state[4] != HIGH) { keyUp(4); state[4] = HIGH; }
    if (VAL_B == LOW && state[10] != LOW) { keyDown(10); state[10] = LOW; }
    else if (VAL_B == HIGH && state[10] != HIGH) { keyUp(10); state[10] = HIGH; }
    if (VAL_C == LOW && state[16] != LOW) { keyDown(16); state[16] = LOW; }
    else if (VAL_C == HIGH && state[16] != HIGH) { keyUp(16); state[16] = HIGH; }
    if (VAL_D == LOW && state[22] != LOW) { keyDown(22); state[22] = LOW; }
    else if (VAL_D == HIGH && state[22] != HIGH) { keyUp(22); state[22] = HIGH; }
  }

  if (i == 5) {
    if (VAL_A == LOW && state[5] != LOW) { keyDown(5); state[5] = LOW; }
    else if (VAL_A == HIGH && state[5] != HIGH) { keyUp(5); state[5] = HIGH; }
    if (VAL_B == LOW && state[11] != LOW) { keyDown(11); state[11] = LOW; }
    else if (VAL_B == HIGH && state[11] != HIGH) { keyUp(11); state[11] = HIGH; }
    if (VAL_C == LOW && state[17] != LOW) { keyDown(17); state[17] = LOW; }
    else if (VAL_C == HIGH && state[17] != HIGH) { keyUp(17); state[17] = HIGH; }
    if (VAL_D == LOW && state[23] != LOW) { keyDown(23); state[23] = LOW; }
    else if (VAL_D == HIGH && state[23] != HIGH) { keyUp(23); state[23] = HIGH; }
  }

  if ((millis() - last_sync_t) >= SYNC_INTERVAL_MS) {
    sync();
  }

  i = (i + 1) % 6; 
  delay(10);
}

// MIDI SPECIFIC 

void noteOn(unsigned char pitch) {
  midiEventPacket_t noteOn = {0x09, 0x90 | 0, pitch, 120};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

void noteOff(unsigned char pitch) {
  midiEventPacket_t noteOff = {0x08, 0x80 | 0, pitch, 0};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}

