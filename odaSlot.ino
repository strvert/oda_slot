#include<Wire.h>
#include <FlexiTimer2.h>
#define LDaddrs1 (0x70)

typedef enum {
  EASY,
  NORMAL,
  HARD
} difficulty;

typedef enum {
  STOP,
  CHANGEDEF,
  ACTIVE,
  RESULT
} state;

typedef enum {
  SEG_ACTIVE,
  SEG_STOP
} segState;

// global vals
char CW_LIST[] = {13, 12, 9, 8};
difficulty DIFF = NORMAL;
state STATE = STOP;
segState SEG_STATE[] = {SEG_STOP, SEG_STOP, SEG_STOP, SEG_STOP};
bool DELAY_STOPPING = false;
int ROTATE_SPEED = 100;
char SEG_SELECTOR = 0;
int SCORE;
char SEG_NUMS[4] = {0, 0, 0, 0};
char LED_PINS[] = {5,6,10,11};
unsigned long LAST_BUTTON_TIME = millis();
const int signal = 7;

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

  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);

  //LEDのpin
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(signal,OUTPUT);


  FlexiTimer2::set(1, timer); // 10ms period
  FlexiTimer2::start();
}

//再起動用関数
void(* resetFunc)(void) = 0;

void loop() {

  switch (STATE) {
    case STOP:
      resetSegNums();
      SEG_SELECTOR = 0;
      writeAll7seg(0);
      //どんな状態からもリセットしたらここに戻る
      STATE = CHANGEDEF;
    break;

    case CHANGEDEF:
      //TS0を押したらACTIVEに状態遷移
      if (detectPush(A0)) {
        readDifficulty();
        STATE = ACTIVE;
        randomSetSegNums();
        setSegStateAll(SEG_ACTIVE);
      }
    break;

    case ACTIVE:
      // Serial.println("ACTIVE");
      if (detectPush(A0)) {
        setSegState(SEG_SELECTOR, SEG_STOP);
        if (SEG_SELECTOR < 3) {
          SEG_SELECTOR++;
        } else {
          STATE = RESULT;
        }
      }
    break;

    case RESULT:
      SCORE = calcScore(SEG_NUMS);
      flashLEDs(SCORE);

      //スコアに応じて音を変更
      switch(SCORE){
        case 40:
          glad();
        break;

        case 30:
          littleGlad();
        break;

        case 20:
          littleSad();
        break;
          
        case 10:
          sad();
        break;

        case 0:
          verySad();
        break;

        default :
          Serial.println("SCORE isn't set correct value.");  
      }
      
    break;

    default:
    break;
  }
  write7seg(SEG_NUMS);
}
