difficulty getDifficulty() {
  return DIFF;
}

void setDifficulty(difficulty dif) {
  DIFF = dif;
}

void readDifficulty() {
  if (getSwState(1)) {
    setDifficulty(HARD);
  } else if (getSwState(0)) {
    setDifficulty(NORMAL);
  } else {
    setDifficulty(EASY);
  }
  switch (DIFF) {
        case EASY:
          ROTATE_SPEED = 300;
        break;
        case NORMAL:
          ROTATE_SPEED = 100;
        break;
        case HARD:
          ROTATE_SPEED = 50;
        break;
      }
}

int calcScore(char *results) {
  char align_three_result = 1;
  char align_four_result = 1;
  char is_seven = 1;

  char abs_diff = abs(results[3] - results[2]);

  for (int i = 1; i < 4; i++) {
    if (results[i - 1] != results[i]) {
      if (i < 3) {
        align_three_result = 0;
      }
      if (i < 4) {
        align_four_result = 0;
      }
    }
  }
  if (results[0] != 7) {
    is_seven = 0;
  }

  if (align_four_result) {
    if (is_seven) {
      return 40;
    }
    return 30;
  }
  if (align_three_result) {
    if (is_seven) {
      return 30;
    } else if (abs_diff == 1) {
      return 20;
    } else if (abs_diff == 2) {
      return 10;
    }
  }
  return 0;
}

void resetSegNums() {
  for (int i = 0; i < 4; i++ ) {
    SEG_NUMS[i] = 0;    
  }
  writeAll7seg(0);
}

void setSegState(int seg_num, segState state) {
  SEG_STATE[seg_num] = state;
}

void setSegStateAll(segState state) {
  for (int i = 0; i < 4; i++ ) {
    SEG_STATE[i] = state;    
  }
}

void randomSetSegNums() {
  randomSeed(millis());
  for (int i = 0; i < 4; i++) {
    SEG_NUMS[i] = random(10);
  }  
}
