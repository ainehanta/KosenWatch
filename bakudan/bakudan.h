#ifndef INCLUDED_BAKUDAN_H
#define INCLUDED_BAKUDAN_H
#define DEFAULT_PLAYER_NUM 3
#define NOTHING -1
#define NOT_PRESSED 0
#define PRESSED 1
#define EXPLODED 2

typedef struct bakudan {
  int bomb_loc;
  int bomb_status[DEFAULT_PLAYER_NUM+1];
  int order[DEFAULT_PLAYER_NUM];
  int player_num;
} bakudan;

int bakudan_main();
void disp_bomb(bakudan game);
void disp_guide_message(bakudan game);
void init_bakudan(bakudan* game);
void make_bakudan(bakudan* game);

#endif

