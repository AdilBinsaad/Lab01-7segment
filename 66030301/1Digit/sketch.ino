// ลำดับขา GPIO ตาม A-G: A=19, B=18, C=5, D=17, E=16, F=4, G=0
const int segmentPins[7] = {19, 18, 5, 17, 16, 4, 0};

// รูปแบบ segment สำหรับเลข 0-9 (Common Cathode)
// ลำดับคือ A, B, C, D, E, F, G
const byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void setup() {
  // ตั้ง GPIO เป็น OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int digit) {
  // แสดงเลขบน 7-segment
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[digit][i]);
  }
}

void loop() {
  for (int num = 0; num <= 9; num++) {
    displayDigit(num);  // แสดงตัวเลข
    delay(1000);        // หน่วงเวลา 1 วินาที
  }
}

