bool detect_push(int pin){
  if(digitalRead(pin)){
    delay(100);
    return true;
  }
  return false;
}

bool push_start(){
  return detect_push(A0);
}

bool push_set(){
  return detect_push(A1);;
}

bool get_sw_state(int pin){
  int cw_list[] = {13, 12, 9, 8};
  return digitalRead(cw_list[pin]);  
}
