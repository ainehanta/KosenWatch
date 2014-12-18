#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// メインループ
int bakudan_main() {
  bakudan game;

  init_bakudan(&game);

  for(; !is_game_finished();) {
    int press_num = -1;
    int now_player;
    make_bakudan(&game);
    do {
      int game_status;
      now_player = get_now_order();
      // 自分のターンの時
      if(now_player == bakudan.my_num){
        disp_guide_message(game, i);
        disp_bomb(game);
        // スイッチを押す場所入力
        do {
          press_num = input_data(game, game.order[i]);
        } while(send_input(press_num));
        check_result(&bakudan);
      } else {
        check_result(&bakudan);
      }
    } while(/*爆弾ゲームの1回が終わってなかったら*/);
  }

  // 勝者表示
  disp_winner(get_winner());
}

int check_result(bakudan* game, int now_player) {
  game_status = get_bakudan_status();
  if(game_status == DROP_OUT) {
    drop_out(&game, get_dropout());
  } else {
    // セーフと表示
    // now_playerを使って、bomb_statusを書き換え
  }
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

void disp_game(bakudan game, int player) {
  printf("Player%d's turn!");
}

// 操作説明などのガイド表示
void disp_guide_message(bakudan game, int order) {
  printf("Your turn!!");
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

// 勝者表示
void disp_winner(bakudan game) {
  printf("Winner is Player%d\n", game.order[0]);
}

// 脱落者追加
int drop_out(bakudan* game, int player) {
  puts("Bang!!!!!!!!!!!!!!!!!");
  if(game->my_num == player) {
    printf("You are dropped out.\n");
  } else {
    printf("Player%d is dropped out.\n", player);
  }
  game->dropout[player] = DROP_OUT;
  game->player_num--;
}

// サーバーから爆弾ゲーム初期化した情報を手に入れる
int get_bakudan(bakudan* game) {
  // player_numを手に入れる
}

// 脱落者をサーバーから受け取る
int get_dropout() {
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

  data -= '0';

  return data;
}

// ゲームが終了したかサーバーから受け取る
int is_game_finished() {
  return 0;
}

int check_input(bakudan game, int input) {
  int i;

  if(input < 0 || input > game.player_num)
    return 1;

  if(game.bomb_status[input] != NOT_PRESSED)
    return 1;

  return 0;
}

// 爆弾を初期化
void make_bakudan(bakudan* game) {
  int i;

  // 爆弾の状態の初期化
  for(i = 0; i < game->player_num+1; i++)
    game->bomb_status[i] = NOT_PRESSED;
}

int press_switch(bakudan* game, int loc) {
  /*
  if(game->bomb_loc == loc) {
    game->bomb_status[loc] = EXPLODED;
    return 1;
  } else {
    game->bomb_status[loc] = PRESSED;
    return 0;
  }*/
  return 0;
}

// 押したスイッチの場所をサーバーに送る
int send_input(int loc) {
}
