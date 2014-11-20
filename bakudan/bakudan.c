#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bakudan_main() {
  bakudan game;

  init_bakudan(&game);
  make_bakudan(&game);
  disp_guide_message(&game);
  disp_bomb(&game);
}

int disp_bomb(bakudan* game) {
  int i;

  for(i = 0; i < game->player_num + 1; i++)
    printf("%2d", game->bomb_status[i]);
  puts("");
}

int disp_guide_message(bakudan* game) {
  puts("Please input bomb_num of you want to press.");
}

int init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

int make_bakudan(bakudan* game) {
  int i;

  game->bomb_loc = rand() % game->player_num;

  // スイッチを押す順番の初期化
  for(i = 0; i < game->player_num; i++)
    game->order[i] = i;
  for(i = 0; i < game->player_num; i++) {
    int temp;
    int random = rand() % game->player_num;
    temp = game->order[random];
    game->order[random] = game->order[i];
    game->order[i] = temp;
  }

  // 爆弾の状態の初期化
  for(i = 0; i < game->player_num+1; i++)
    game->bomb_status[i] = NOT_PRESSED;
}
