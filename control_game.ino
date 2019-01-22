Difficulty getDifficulty() {
  return DIFF;
}

void setDifficulty(Difficulty dif) {
  DIFF = dif;
}

void readDifficulty() {
  if (get_sw_state(1))
    setDifficulty(HARD);
  else if (get_sw_state(0))
    setDifficulty(NORMAL);
  else
    setDifficulty(EASY);
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

void rotate_7seg() {
  static int seg0 = 0;
  static int seg1 = 0;
  static int seg2 = 0;
  static int seg3 = 0;

  static float delay_time = 1;

  static int push_TS_times = 0;
  static bool is_push_TS1 = false;

  int i[4] = {seg0, seg1, seg2, seg3};

  if (DIFF == EASY) {
    delay_time = 3;
  }
  else if (DIFF == NORMAL) {
    delay_time = 2;
  } else {
    delay_time = 1;
  }

  write_7seg(i);

  for (int j = 0; j < 100; j ++) {
    if (detect_push(A0)) {
      is_push_TS1 = false;
      push_TS_times++;
    }

    if (detect_push(A1)) {
      is_push_TS1 = true;
      seg0 = 0;
      seg1 = 0;
      seg2 = 0;
      seg3 = 0;
      push_TS_times = -1;
    }

    delay(delay_time);
  }

  if (is_push_TS1) {
    return;
  }

  switch (push_TS_times) {
    case 0:
      seg0 ++;

    case 1:
      seg1 ++;

    case 2:
      seg2 ++;

    case 3:
      seg3 ++;
      break;

    default:
      //calcScoreをよびだしてからステートを変える
      break;
  }

  if (seg0 == 10) {
    seg0 = 0;
  }
  if (seg1 == 10) {
    seg1 = 0;
  }
  if (seg2 == 10) {
    seg2 = 0;
  }
  if (seg3 == 10) {
    seg3 = 0;
  }
}
