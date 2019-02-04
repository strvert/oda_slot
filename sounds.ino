//noteNum: MIDIのノート番号
//length:length×0.5秒だけ音が鳴る
//ms: 周期の半分(μs)
//temp: 型変換のための一時変数
void se(double noteNum, int length) {
  int ms;
  double f, temp;

  f = pow(2, ( (noteNum - 69) / 12 )) * 440; //MIDI Tuning Standardの式より周波数を計算
  temp = ( 1 / f * pow(10, 6) / 2);
  ms = (int)temp;

  if (noteNum == 145) {
    for (long i = 0; i < 200000 * length; i += ms * 2) {
      digitalWrite(signal, LOW);
      delayMicroseconds(ms);
      delayMicroseconds(ms);
    }
  } else {
    for (long i = 0; i < 200000 * length; i += ms * 2) {
      digitalWrite(signal, HIGH);
      delayMicroseconds(ms);
      digitalWrite(signal, LOW);
      delayMicroseconds(ms);
    }
  }
}

int pitch_normal_arr[30] = {60, 62, 64, 65, 67, 69, 71, 72, 74, 76, 77, 79, 81, 83, 84, 86, 88, 89, 91, 93, 95, 96}; //do,re,mi,fa,so,ra,si,do,re,mi,fa,so,ra,si
int pitch_half_arr[20] = {61, 63, 66, 68, 70, 73, 75, 78, 80, 82}; //do#,re#,fa#,so#,ra#,do#,re#,fa#,so#,ra#
int pitch_rest = 145;

//普通のドレミの数値の割り当て
typedef enum {
  do_1,//60
  re_1,//62
  mi_1,//64
  fa_1,//65
  so_1,//67
  ra_1,//69
  si_1,//71
  do_2,//72
  re_2,//74
  mi_2,//76
  fa_2,//77
  so_2,//79
  ra_2,//81
  si_2,//83
  do_3,
  re_3,
  mi_3,
  fa_3,
  so_3,
  ra_3,
  si_3,
  do_4
  
} pitch_normal;

//#のドレミの数値の割り当て
typedef enum {
  do_1_sharp,//61
  re_1_sharp,//63
  fa_1_sharp,//66
  so_1_sharp,//68
  ra_1_sharp,//70
  do_2_sharp,//73
  re_2_sharp,//75
  fa_2_sharp,//78
  so_2_sharp,//80
  ra_2_sharp//82
} pitch_harf;

//--------------------------------------------------------------------------------------------------
//元ネタ:となりのトトロ(トトロ)
void glad() {
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[mi_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[re_2], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[fa_2], 3);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[re_2], 2);
  se(pitch_normal_arr[do_2], 2);

  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[re_2], 4);
  se(pitch_rest, 4);

  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[so_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[fa_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[mi_2], 4);
  se(pitch_rest, 3);

  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[so_2], 6);
  se(pitch_rest, 3);
  
//-------------------------------------
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);

  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_rest, 4);

  se(pitch_normal_arr[fa_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);

  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[do_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[do_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 3);
  se(pitch_rest, 2);

  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[so_2], 1);
  //----------------------------------------
  
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);

  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_rest, 3);

  se(pitch_normal_arr[fa_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);

  se(pitch_normal_arr[fa_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[do_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[ra_2], 2);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[so_2], 3);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_rest, 1);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[fa_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[do_1], 1);
  se(pitch_normal_arr[fa_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[do_1], 1);
  se(pitch_normal_arr[ra_2], 1);
  se(pitch_normal_arr[so_2], 6);
  se(pitch_rest, 2);

  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[fa_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[re_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[do_1], 4);
  STATE = STOP;
}

//------------------------------------------------------------------------------------------
//元ネタ:さんぽ(トトロ)
void littleGlad() {
  se(pitch_normal_arr[mi_1], 3);
  se(pitch_normal_arr[so_1], 3);
  se(pitch_normal_arr[do_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[so_1], 3);
  se(pitch_normal_arr[ra_1], 3);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[do_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[ra_1], 3);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[ra_1], 2);
  
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[so_1], 3);
  se(pitch_rest, 3);

  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[re_1], 3);
  se(pitch_normal_arr[mi_1], 3);
  se(pitch_normal_arr[do_1], 4);
  se(pitch_rest, 4);

  se(pitch_half_arr[so_1_sharp], 2);
  se(pitch_half_arr[so_1_sharp], 1);
  se(pitch_half_arr[so_1_sharp], 2);
  se(pitch_half_arr[so_1_sharp], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[so_1], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[so_1], 2);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[fa_1], 2);
  se(pitch_normal_arr[fa_1], 2);
  se(pitch_normal_arr[fa_1], 2);
  se(pitch_normal_arr[re_1], 1);
  se(pitch_normal_arr[mi_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[do_1], 2);
  se(pitch_normal_arr[do_1], 1);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[ra_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[re_2], 2);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[ra_1], 2);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[mi_1], 3);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[si_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[so_1], 2);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[do_2], 4);
  STATE = STOP;
}

//--------------------------------------------------------------------------------------------------------

//ボギー大佐
void sad() {
  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[mi_3], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_3], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[do_3], 3);
  se(pitch_rest, 1);

  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[fa_2], 3);
  se(pitch_rest, 1);
  
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[fa_2], 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_half_arr[fa_2_sharp], 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[so_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_half_arr[fa_2_sharp], 1);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[ra_2],1);
  se(pitch_normal_arr[so_2],4);
  STATE = STOP;
}


//-----------------------------------------------------------------------------------------------------------------
//元ネタ:君をのせて
void littleSad() {
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[mi_2], 2);
  se(pitch_normal_arr[si_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[so_1], 3);
  se(pitch_normal_arr[ra_1], 3);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[fa_1], 3);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[fa_1], 2);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[mi_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[si_1], 3);
  se(pitch_half_arr[fa_1_sharp], 1);
  se(pitch_half_arr[fa_1_sharp], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[si_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[mi_2], 3);
  se(pitch_normal_arr[si_1], 4);
  se(pitch_rest, 2);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[ra_1], 3);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[ra_1], 3);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[so_1], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_normal_arr[fa_1], 2);
  se(pitch_rest, 1);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[si_1], 3);
  se(pitch_normal_arr[do_2], 3);
  se(pitch_normal_arr[re_2], 1);
  se(pitch_normal_arr[re_2], 3);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_normal_arr[do_2], 4);
  se(pitch_rest, 1);

  se(pitch_normal_arr[do_2], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 3);
  se(pitch_half_arr[so_1_sharp], 3);
  se(pitch_normal_arr[ra_1], 4);
  STATE = STOP;
}

//---------------------------------------

void verySad(){
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_rest, 2);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_rest, 3);

  se(pitch_normal_arr[ra_1], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_half_arr[so_1_sharp], 1);
  se(pitch_rest, 4);

  se(pitch_normal_arr[mi_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_rest, 3);
  se(pitch_normal_arr[do_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_2], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_rest, 1);
  se(pitch_normal_arr[mi_1], 1);
  se(pitch_rest, 1);
  
  se(pitch_normal_arr[fa_1], 1);
  se(pitch_normal_arr[so_1], 1);
  se(pitch_normal_arr[ra_1], 1);
  se(pitch_normal_arr[si_1], 1);
  se(pitch_normal_arr[do_2], 2);
  se(pitch_normal_arr[si_1], 2);
  se(pitch_normal_arr[ra_1], 4);
  STATE = STOP;
}
