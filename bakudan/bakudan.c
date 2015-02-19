#include "bakudan.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// �ᥤ��롼��
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
      press_num = input_data(game, game.order[i]);
      // �����å��򲡤�����
      if(press_switch(&game, press_num)) {
        drop_out(&game, i);
        break;
      }
    }
  }

  // ���Ԥ�order����κǽ�����Ǥ˰�ư����
  make_bakudan(&game);

  disp_winner(game);
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

// ��������ʤɤΥ�����ɽ��
void disp_guide_message(bakudan game, int order) {
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
int drop_out(bakudan* game, int order) {
  puts("Bang!!!!!!!!!!!!!!!!!");
  printf("Player%d is dropped out.\n", game->order[order]);
  game->dropout[game->order[order]] = DROP_OUT;
  game->player_num--;
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

  game->bomb_loc = rand() % game->player_num;

  // �����å��򲡤����֤ν����
  for(i = 0; i < game->player_num; i++)
    game->order[i] = i;
  for(i = 0; i < game->player_num; i++) {
    int tmp;
    int random = rand() % game->player_num;
    tmp = game->order[random];
    game->order[random] = game->order[i];
    game->order[i] = tmp;
  }

  // ���Ƥξ��֤ν����
  for(i = 0; i < game->player_num+1; i++)
    game->bomb_status[i] = NOT_PRESSED;

  // æ��Ԥν����
  for(i = 0; i < game->player_num-1; i++) {
    game->dropout[i] = -1;
  }
}

// �����å��򲡤�����
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
