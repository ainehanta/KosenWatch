#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bakudan_main() {
  bakudan game;

  init_bakudan(&game);
  make_bakudan(&game);

  for(; game.player_num > 1;) {
    int press_num = -1;
    int i;
    disp_guide_message(game);
    for(i = 0; i < game.player_num; i++) {
      disp_bomb(game);
      scanf("%d", &press_num);
      // スイッチを押す処理
    }
  }
}

void disp_bomb(bakudan game) {
  int i;

  for(i = 0; i < game.player_num + 1; i++) {
    switch(game.bomb_status[i]) {
    case NOT_PRESSED:
      printf("凸");
      break;
    case PRESSED:
      printf("凹");
      break;
    }
  }
  puts("");
}

void disp_guide_message(bakudan game) {
  puts("Please input bomb_num of you want to press.");
}

void init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

void make_bakudan(bakudan* game) {
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

  // 脱落者の初期化
  for(i = 0; i < game->player_num-1; i++) {
    game->dropout[i] = -1;
  }
}
