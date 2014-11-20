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
  game->bomb_loc = rand() % game->player_num;
}
