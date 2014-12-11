#ifndef INCLUDED_BAKUDAN_H
#define INCLUDED_BAKUDAN_H
#define DEFAULT_PLAYER_NUM 3
#define DROP_OUT 1
#define NOTHING -1
#define NOT_PRESSED 0
#define PRESSED 1
#define EXPLODED 2

typedef struct bakudan {
  int bomb_loc;
  int bomb_status[DEFAULT_PLAYER_NUM+1];
  int dropout[DEFAULT_PLAYER_NUM-1];
  int order[DEFAULT_PLAYER_NUM];
  int player_num;
} bakudan;

int bakudan_main();
void disp_bomb(bakudan game);
void disp_guide_message(bakudan game, int order);
void disp_winner(bakudan game);
int drop_out(bakudan* game, int order);
void init_bakudan(bakudan* game);
int input_data(bakudan game, int player);
void make_bakudan(bakudan* game);
int press_switch(bakudan* game, int loc);

#endif

