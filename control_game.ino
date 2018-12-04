Difficulty getGameDifficulty() {
  return diff;
}

void setDifficulty(Difficulty dif){
  diff = dif;
}

void readDifficulty(){
  if(get_sw_state(1))
    setDifficulty(HARD);
  else if(get_sw_state(0))
    setDifficulty(NORMAL);
  else
    setDifficulty(EASY);
}
