const byte digitsData[10] = {
  B01111110, B00010010,
  B10111100, B10110110,
  B11010010, B11100110,
  B11101110, B00110010,
  B11111110, B11110010};
  
const int dataPin = 11;
const int clockPin = 12;
const int latchPin = 8;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int digit = 9; digit >= 0; digit--){
    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, digitsData[digit]);
    myShiftOut(digitsData[digit]);
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}

void myShiftOut(byte data){
  for (byte mask = B10000000; mask > 0; mask >>=1) {
    digitalWrite(clockPin, LOW);
    if (data & mask) {
      digitalWrite(dataPin, HIGH);
    } else {
      digitalWrite(dataPin, LOW);
    }
    digitalWrite(clockPin, HIGH);
  }
}
