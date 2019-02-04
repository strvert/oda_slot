bool detectPush(int pin) {
  if (digitalRead(pin)) {
    if (millis()-LAST_BUTTON_TIME > 210){
      LAST_BUTTON_TIME = millis();     
      return true;
    }
  }
  return false;
}

bool getSwState(int pin) {
  return digitalRead(CW_LIST[pin]);
}

void flashLEDs(char score){
  char index = 0;
  for(score/=10; index<score ; index++){
    digitalWrite(LED_PINS[index],HIGH);
  }
}

void turnOLEDs(){
  for(char index = 0;index < 4;index ++){
    digitalWrite(LED_PINS[index],LOW);
  }
}
