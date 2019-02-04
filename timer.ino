void timer() {
  unsigned long crrtime = millis();
  bool rotate;

  if (getSwState(3)) {
    if (! (crrtime % 5000)) {
      Serial.print("起動から");
      Serial.print(crrtime / 1000);
      Serial.println("秒！！ワイ生きとるで！！");  
    }
  }
  switch (STATE) {
    case STOP:
    break;
    
    case ACTIVE:
      rotate = !(crrtime % ROTATE_SPEED);
      if (rotate) {
        for (int i = 0; i < 4; i++){
          if (SEG_STATE[i] == SEG_ACTIVE) {
            SEG_NUMS[i] = SEG_NUMS[i]+1 < 10 ? SEG_NUMS[i]+1 : 0;
          }
        }
      }
    break;
  }

  if (detectPush(A1)) {
    resetFunc();  //再起動
  }

  
}
