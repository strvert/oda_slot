#include<Wire.h>
#define LDaddrs1 (0x70)

#include <FlexiTimer2.h>
#include <Wire.h>

typedef enum {
    EASY,
    NORMAL,
    HARD
  } Difficulty;

// global val
char CW_LIST[] = {13, 12, 9, 8};
Difficulty DIFF = NORMAL;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setClock(400000L);

/* oscillatorが0でoff、1でon */
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0x21);
  Wire.endTransmission();

/* ROW/INT output is set to ROW driver output */
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0xA0);
  Wire.endTransmission();

/* Dimming Set　明るさの調整 */
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0xEF);
  Wire.endTransmission();

/* Display setup 上位2,3bit目が点滅の間隔、最下位bitがon/off*/
  Wire.beginTransmission(LDaddrs1);
  Wire.write(0x81);
  Wire.endTransmission();

  pinMode(13,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
}

void loop() {
  readDifficulty();
  Serial.println();
}
