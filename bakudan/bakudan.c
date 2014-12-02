#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bakudan_main() {
  bakudan game;

  init_bakudan(&game);

  for(; game.player_num > 1;) {
    int press_num = -1;
    int i;
    make_bakudan(&game);
    for(i = 0; i < game.player_num; i++) {
      disp_guide_message(game, i);
      disp_bomb(game);
      press_num = input_data(game);
      // スイッチを押す処理
      if(press_switch(&game, press_num)) {
        drop_out(&game, press_num);
        break;
      }
    }
  }
  make_bakudan(&game);
  disp_winner(game);
}

void disp_bomb(bakudan game) {
  int i;

  printf("");
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

void disp_guide_message(bakudan game, int order) {
  printf("Please input bomb_num of you want to press.\n");
  printf("player number is %d\n", game.order[order]);
}

void disp_winner(bakudan game) {
  printf("Winner is Player%d", game.order[0]);
}

int drop_out(bakudan* game, int press_num) {
  puts("Bang!!!!!!!!!!!!!!!!!");
  printf("Player%d is dropped out.\n", game->order[press_num]);
  game->dropout[press_num] = DROP_OUT;
  game->player_num--;
}

void init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

int input_data(bakudan game) {
  int data;

  do {
    printf("input 0 ~ %d\n", game.player_num);
    scanf(" %c", &data);
  } while(!(data >= '0' && data <= game.player_num + '0'));

  data -= '0';

  return data;
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

int press_switch(bakudan* game, int loc) {
  if(game->bomb_loc == loc) {
    game->bomb_status[loc] = EXPLODED;
    return 1;
  } else {
    game->bomb_status[loc] = PRESSED;
    return 0;
  }
  return 0;
}
