#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bakudan_main() {
  bakudan game;

  init_bakudan(&game);
  make_bakudan(&game);
}

int init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

int make_bakudan(bakudan* game) {
  int i;

  game->bomb_loc = rand() % game->player_num;

  // スイッチを押す順番の初期化
  for(i = 0; i < game->player_num; i++) game->order[i] = i;
  for(i = 0; i < game->player_num; i++) {
    int temp;
    int random = rand() % game->player_num;
    temp = game->order[random];
    game->order[random] = game->order[i];
    game->order[i] = temp;
  }
}
