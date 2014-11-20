#ifndef INCLUDED_BAKUDAN_H
#define INCLUDED_BAKUDAN_H
#define DEFAULT_PLAYER_NUM 3

typedef struct bakudan {
  int player_num;
  int bomb_loc;
} bakudan;

int bakudan_main();
int init_bakudan(bakudan* game);
int make_bakudan(bakudan* game);

#endif

