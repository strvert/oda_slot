#define LDaddrs1 (0x70)

void write7segNum(char score) {
  int numList[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0x00};
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0x00);
  Wire.write(numList[0]); // Control Digit1
  Wire.write(0x00);
  Wire.write(numList[0]); // Control Digit2
  Wire.write(0x00);
  Wire.write(0x00); // Control D1,D2,D3
  Wire.write(0x00);
  Wire.write(numList[score / 10]); // Control Digit3
  Wire.write(0x00);
  Wire.write(numList[0]); // Control Digit4
  Wire.endTransmission();
}

void write7seg(char nums[]) {
  // Serial.println("WRITE SEGS");
  int numList[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0x00};
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0x00);
  Wire.write(numList[nums[0]]); // Control Digit1
  Wire.write(0x00);
  Wire.write(numList[nums[1]]); // Control Digit2
  Wire.write(0x00);
  Wire.write(0x00); // Control D1,D2,D3
  Wire.write(0x00);
  Wire.write(numList[nums[2]]); // Control Digit3
  Wire.write(0x00);
  Wire.write(numList[nums[3]]); // Control Digit4
  Wire.endTransmission();
}

void writeAll7seg(char num) {
  int numList[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0x00};
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0x00);
  Wire.write(numList[num]); // Control Digit1
  Wire.write(0x00);
  Wire.write(numList[num]); // Control Digit2
  Wire.write(0x00);
  Wire.write(0x00); // Control D1,D2,D3
  Wire.write(0x00);
  Wire.write(numList[num]); // Control Digit3
  Wire.write(0x00);
  Wire.write(numList[num]); // Control Digit4
  Wire.endTransmission();
}
