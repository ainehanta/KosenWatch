#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �ᥤ��롼��
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
      // ��ʬ�Υ�����λ�
      if(now_player == bakudan.my_num){
        disp_guide_message(game, i);
        disp_bomb(game);
        // �����å��򲡤��������
        do {
          press_num = input_data(game, game.order[i]);
        } while(send_input(press_num));
        check_result(&bakudan);
      } else {
        check_result(&bakudan);
      }
    } while(/*���ƥ������1�󤬽���äƤʤ��ä���*/);
  }

  // ����ɽ��
  disp_winner(get_winner());
}

int check_result(bakudan* game, int now_player) {
  game_status = get_bakudan_status();
  if(game_status == DROP_OUT) {
    drop_out(&game, get_dropout());
  } else {
    // �����դ�ɽ��
    // now_player��Ȥäơ�bomb_status��񤭴���
  }
}

// ���������Ƥ�ɽ��
void disp_bomb(bakudan game) {
  int i;

  printf("");
  for(i = 0; i < game.player_num + 1; i++) {
    switch(game.bomb_status[i]) {
    case NOT_PRESSED:
      printf("��");
      break;
    case PRESSED:
      printf("��");
      break;
    }
  }
  puts("");
}

void disp_game(bakudan game, int player) {
  printf("Player%d's turn!");
}

// ��������ʤɤΥ�����ɽ��
void disp_guide_message(bakudan game, int order) {
  printf("Your turn!!");
  printf("Please input bomb_num of you want to press.\n");
  printf("player number is %d\n", game.order[order]);
}

// ���Ϥ�����Υ�����ɽ��
void disp_input_guide(bakudan game) {
  int i;
  printf("input ");

  for(i = 0; i < game.player_num + 1; i++) {
    if(game.bomb_status[i] == NOT_PRESSED)
      printf("%d ", i);
  }
  puts("");
}

// ����ɽ��
void disp_winner(bakudan game) {
  printf("Winner is Player%d\n", game.order[0]);
}

// æ����ɲ�
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

// �����С��������ƥ�������������������������
int get_bakudan(bakudan* game) {
  // player_num���������
}

// æ��Ԥ򥵡��С�����������
int get_dropout() {
  return 0;
}

// ���ƥ����������
void init_bakudan(bakudan* game) {
  game->player_num = DEFAULT_PLAYER_NUM;
}

// ���������å��ξ�������
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

// �����ब��λ�����������С�����������
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

// ���Ƥ�����
void make_bakudan(bakudan* game) {
  int i;

  // ���Ƥξ��֤ν����
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

// �����������å��ξ��򥵡��С�������
int send_input(int loc) {
}
