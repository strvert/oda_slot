Difficulty getDifficulty() {
  return DIFF;
}

void setDifficulty(Difficulty dif){
  DIFF = dif;
}

void readDifficulty(){
  if(get_sw_state(1))
    setDifficulty(HARD);
  else if(get_sw_state(0))
    setDifficulty(NORMAL);
  else
    setDifficulty(EASY);
}

int calcScore(char *results){
  char align_three_result = 1;
  char align_four_result = 1;
  char is_seven = 1;
  
  char abs_diff = abs(results[3] - results[2]);
  
  for(int i = 1; i < 4; i++){
    if(results[i-1] != results[i]){
      if(i < 3){
        align_three_result = 0;
      }
      if(i < 4){
        align_four_result = 0; 
      }
    }
  }
  if(results[0] != 7){
    is_seven = 0;
  }

  if(align_four_result){
    if(is_seven){
      return 40;  
    }
    return 30;
  }
  if(align_three_result){
    if(is_seven){
      return 30; 
    }else if(abs_diff == 1){
      return 20;  
    }else if(abs_diff == 2){
      return 10;  
    }
  }
  return 0;
}
