#include "bomb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// メインループ
int bakudan_main() {
  bakudan game;
  int winner;

  init_bakudan(&game);
  send_name(game, "testkun");
  get_player_num(&game);
  get_name(&game);

  for(; game.player_num > 1;) {
    int player_num = game.player_num;
    int i;
    get_init_data(&game);
    make_bakudan(&game);
    // スイッチを押すための入力
    for(i = 0; i < game.player_num; i++) {
      disp_bomb(game);
      if(get_current_player(&game) == game.my_player_num) {
        disp_guide_message(game, i);
        input_data(game, game.order[i]);
      }
      press_switch(&game);
    }
    // 爆破
    get_is_dropped(&game);
  }

  // 勝者をorder配列の最初の要素に移動する
  winner = get_winner(&game);
  disp_winner(winner);

  return game.order[0];
}

// 全部の爆弾を表示
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

// 操作説明などのガイド表示
void disp_guide_message(bakudan game, int order) {
  printf("Please input bomb_num of you want to press.\n");
  printf("player number is %d\n", game.order[order]);
}

// 入力する時のガイド表示
void disp_input_guide(bakudan game) {
  int i;
  printf("input ");

  for(i = 0; i < game.player_num + 1; i++) {
    if(game.bomb_status[i] == NOT_PRESSED)
      printf("%d ", i);
  }
  puts("");
}

// 脱落じゃない時の表示
void disp_safe(bakudan game, int order) {
  printf("Player%d is safe!\n", game.order[order]);
}

// 勝者表示
void disp_winner(int winner) {
  printf("Winner is Player%d\n", winner);
}

// 脱落者追加
int drop_out(bakudan* game, int order) {
  puts("Bang!!!!!!!!!!!!!!!!!");
  printf("Player%d is dropped out.\n", game->order[order]);
  game->dropout[game->order[order]] = DROP_OUT;
  game->player_num--;
}

// 爆弾を爆破
int explode_bomb(bakudan* game, int loc) {
  if(game->bomb_loc == loc) {
    game->bomb_status[loc] = EXPLODED;
    return 1;
  }
  return 0;
}

// 爆弾ゲームを初期化
void init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

// 押すスイッチの場所を入力
int input_data(bakudan game, int player) {
  int data;
  int input_check;

  do {
    disp_input_guide(game);
    data = getchar();
    getchar();
    input_check = check_input(game, data - '0');
  } while(input_check);

  send_input(game, data);

  data -= '0';

  return data;
}

// 入力が正しいか判定
int check_input(bakudan game, int input) {
  int i;

  if(input < 0 || input > game.player_num) {
    printf("%d input 0 ~ %d\n", input, game.player_num);
    return 1;
  }

  if(game.bomb_status[input] != NOT_PRESSED) {
    printf("input not pressed switch\n");
    return 1;
  }

  return 0;
}

// 爆弾を初期化
void make_bakudan(bakudan* game) {
  int i;

  //game->bomb_loc = rand() % game->player_num;
/*
  // スイッチを押す順番の初期化
  for(i = 0; i < game->player_num; i++)
    game->order[i] = i;
  for(i = 0; i < game->player_num; i++) {
    int tmp;
    int random = rand() % game->player_num;
    tmp = game->order[random];
    game->order[random] = game->order[i];
    game->order[i] = tmp;
  }

  // 爆弾の状態の初期化
  for(i = 0; i < game->player_num+1; i++)
    game->bomb_status[i] = NOT_PRESSED;

  // 脱落者の初期化
  for(i = 0; i < game->player_num-1; i++) {
    game->dropout[i] = -1;
  }*/
  // 爆弾の状態の初期化
  for(i = 0; i < game->player_num+1; i++)
    game->bomb_status[i] = NOT_PRESSED;

  // 脱落者の初期化
  for(i = 0; i < game->player_num-1; i++) {
    game->dropout[i] = -1;
  }
}

// スイッチを押す処理
int press_switch(bakudan* game) {
  int loc = get_input(game);
  game->bomb_status[loc] = PRESSED;
  return 0;
}

// 今爆弾スイッチを押すプレイヤーナンバーを返す
int get_current_player(bakudan* game) {
  int i;
  unsigned char data[1024];

  get_data(data);

  for(i = 0; i < game->player_num+1; i++) {
    game->bomb_status[i] = data[i+2] - '0';
  }

  return data[1] - '0';
}

void get_data(unsigned char data[]) {
  puts("GETTING");
  scanf("%s", data);
  getchar();
}

int get_input(bakudan* game) {
  unsigned char data[1024];

  get_data(data);
  return data[1] - '0';
}

void get_init_data(bakudan* game) {
  int i, j, p_num = 0;
  unsigned char data[1024];

  get_data(data);
  game->player_num = data[1] - '0';

  for(i = 0; i < game->player_num; i++) {
    game->order[i] = data[i+2] - '0';
  }
}

// 脱落したか
void get_is_dropped(bakudan* game) {
  int i;
  unsigned char data[1024];

  get_data(data);

  if(data[1] - '0' == 1) {
    drop_out(game, game->order[game->my_player_num]);
  }
  if(data[2] != '0'-1) {
    explode_bomb(game, data[2] - '0');
  }
}

void get_name(bakudan* game) {
  int i, j, p_num = 0;
  unsigned char data[1024];

  get_data(data);

  for(i = 1; p_num < DEFAULT_PLAYER_NUM && i < (NAME_LENGTH + 1)*3 + 1 && data[i] != '\0'; i++) {
    for(j = 0; data[i+j] != ',' && data[i+j] != '\0'; j++) {
      game->name[p_num][j] = data[i+j];
    }
    i += j;
    game->name[p_num][j] = '\0';
    p_num++;
  }
}

void get_player_num(bakudan* game) {
  unsigned char data[1024];

  get_data(data);
  game->my_player_num = data[1] - '0';
}

int get_winner(bakudan* game) {
  unsigned char data[1024];

  get_data(data);

  return data[1] - '0';
}

void send_data(unsigned char data[]) {
  printf("sending %s.\n", data);
}

void send_input(bakudan game, unsigned char input) {
  unsigned char data[3];
  data[0] = '2';
  data[1] = input + '0';
  data[2] = '\0';
  send_data(data);
}

void send_name(bakudan game, unsigned char name[]) {
  unsigned char data[NAME_LENGTH + 2];
  data[0] = '1';
  strcat(&data[1], name);

  send_data(name);
}
