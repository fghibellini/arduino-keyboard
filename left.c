
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

  digitalWrite(O_1, HIGH);
  digitalWrite(O_2, HIGH);
  digitalWrite(O_3, HIGH);
  digitalWrite(O_4, HIGH);
  digitalWrite(O_5, LOW);
  digitalWrite(O_6, HIGH);
}

void loop() {
  // read the state of the pushbutton value:
  const int buttonState = digitalRead(I_B);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(13, HIGH);
  } else {
    // turn LED off:
    digitalWrite(13, LOW);
  }
}
