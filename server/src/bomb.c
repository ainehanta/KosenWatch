#include "bomb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// �ᥤ��롼��
int bakudan_main() {
  bakudan game;
  int press[DEFAULT_PLAYER_NUM];

  wait_add_player(&game);
  init_bakudan(&game);
  send_player_num(game);
  send_player_name(game);

  for(; game.player_num > 1;) {
    int player_num = game.player_num;
    int i;
    make_bakudan(&game);
    send_init_data(game);
    // �����å��򲡤����������
    for(i = 0; i < game.player_num; i++) {
      // disp_guide_message(game, i);
      disp_bomb(game);
      printf("player %d %s's turn!\n", i, game.name[i]);
      press[i] = input_data(game, i);
      press_switch(&game, press[i]);
    }
    // ����
    for(i = 0; i < player_num; i++) {
      // �����å��򲡤�����
      if(explode_bomb(&game, press[i])) {
        drop_out(&game, i);
      } else {
        disp_safe(game, i);
      }
    }
    send_is_dropped(game);
  }

  // ���Ԥ�order����κǽ�����Ǥ˰�ư����
  make_bakudan(&game);
  disp_winner(game);
  send_winner(game);

  return game.order[0];
}

// ���Ϥ���������Ƚ��
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

// æ���ʤ�����ɽ��
void disp_safe(bakudan game, int order) {
  printf("Player%d is safe!\n", game.order[order]);
}

// ����ɽ��
void disp_winner(bakudan game) {
  printf("Winner is Player%d\n", game.order[0]);
}

// æ����ɲ�
int drop_out(bakudan* game, int order) {
  puts("Bang!!!!!!!!!!!!!!!!!");
  printf("Player%d is dropped out.\n", game->order[order]);
  // game->order[order] = �ץ쥤�䡼�ʥ�С�
  game->dropout[game->order[order]] = DROP_OUT;
  game->player_num--;
}

// ���Ƥ�����
int explode_bomb(bakudan* game, int loc) {
  if(game->bomb_loc == loc) {
    game->bomb_status[loc] = EXPLODED;
    return 1;
  }
  return 0;
}

void get_data(char data[], int num) {
  int i;
  data[0] = '0';
  scanf("%s", &data[1]);
  printf("[GET ] get data %s from net_num %d\n", data, num);
}

int get_input_data(int num) {
  char data[3];
  get_data(data, num);
  return (int)(data[1] - '0');
}

// �ץ쥤�䡼̾�򥲥å�
// �ץ쥤�䡼̾�κǸ��'\0'�����äƤʤ���¿ʬ��Ф�
void get_name(bakudan* game, int num) {
  unsigned char data[DEFAULT_PLAYER_NUM+2];
  get_data(data, num);
  strcpy(game->name[num], &data[1]);
}

// ���ƥ����������
void init_bakudan(bakudan* game) {
  int i;
  game->player_num = DEFAULT_PLAYER_NUM;
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++)
    game->dropout[i] = 0;
}

// ���������å��ξ�������
int input_data(bakudan game, int num) {
  int data;
  int input_check;

  do {
    disp_input_guide(game);
    //data = getchar();
    data = get_input_data(num);
    getchar();
    printf("input is %d\n", data);
    input_check = check_input(game, data);
  } while(input_check);

  return data;
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
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    game->dropout[i] = 0;
  }
}

// �����å��򲡤�����
int press_switch(bakudan* game, int loc) {
  game->bomb_status[loc] = PRESSED;
  return 0;
}

int send_data(unsigned char* data, int player) {
  printf("[SEND] sending \"%s\"\n", data);
  return 0;
}

int send_init_data(bakudan game) {
  // ���ƽ�����ι��[2]��
  // æ��Ƥʤ��Ϳ��ȥץ쥤�䡼�ν��֤�
  // �Ǹ��[\0]��
  // �Ĥʤ�������
  // prefix = 2

  unsigned char data[2+DEFAULT_PLAYER_NUM];
  int i;

  data[0] = '2';
  data[1] = game.player_num + '0';
  for(i = 0; i < game.player_num; i++) {
    data[2+i] = game.order[i] + '0';
  }
  data[2+i] = '\0';

  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] sending init data to player %d %s\n", i, game.name[i]);
    send_data(data, i);
  }
}

void send_is_dropped(bakudan game) {
  // prefix 6 ��
  // æ�������
  // ��ȯ��������
  // �Ĥʤ�������
  unsigned char data[2+DEFAULT_PLAYER_NUM];
  int i;

  data[0] = '6';
  for(i = 0; i < game.player_num + 1 && game.bomb_status[i] != EXPLODED; i++);
  // ��ȯ�������
  data[2] = i + '0';
  data[3] = '\0';

  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] is_dropped and exploded place to player %d %s\n", i, game.name[i]);
    printf("=============%d\n", game.dropout[i]);
    data[1] = game.dropout[i] + '0';
    send_data(data, i);
  }

}

// �ץ쥤�䡼��̾������������
void send_player_name(bakudan game) {
  // prefix = 1
  int i = 1;
  unsigned char data[2+3+NAME_LENGTH*DEFAULT_PLAYER_NUM];
  unsigned char camma[2] = ",";
  data[0] = '1';
  data[1] = '\0';
  strcat(data, game.name[0]);
  strcat(data, camma);
  strcat(data, game.name[1]);
  strcat(data, camma);
  strcat(data, game.name[2]);
  strcat(data, camma);
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] sending all player name to player %d %s\n", i, game.name[i]);
    send_data(data, i);
  }
}

int send_player_num(bakudan game) {
  // ���ƥ����೫�Ϥι��[0]��
  // �ץ쥤�䡼�Υʥ�С���
  // �Ĥʤ�������
  int i;
  unsigned char data[4];

  data[0] = '0';

  data[1] = game.player_num + '0';
  data[2] = '\0';
  // �ץ쥤�䡼�����˥ǡ���������
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] sending player_num to player %d %s\n", i, game.name[i]);
    data[1] = i + '0';
    send_data(data, i);
  }
}

// ��Ȼ����ѹ�
// ���Ԥ�������
void send_winner(bakudan game) {
  // prefix is 7
  int i;
  unsigned char data[4];

  data[0] = '7';
  data[1] = game.order[0] + '0';
  data[2] = '\0';
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] sending winner to player %d %s n", i, game.name[i]);
    send_data(data, i);
  }
}

// ���ʤ����֤��Ȥ������Ȥ�����
void send_your_order(bakudan game, int num) {
  int i;
  unsigned char data[7];

  data[0] = '3';
  data[1] = game.order[num] + '0';

  for(i = 0; i < game.player_num+1; i++) {
    data[i+2] = game.bomb_status[i];
  }
  data[6] = '\0';
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    printf("[SEND] sending \"now your turn\" to player %d %s\n", i, game.name[i]);
    send_data(data, i);
  }
}

void wait_add_player(bakudan* game) {
  puts("[MSG ] waiting add player");
  int i;
  for(i = 0; i < DEFAULT_PLAYER_NUM; i++) {
    get_name(game, i);
    printf("[GET ] %s joined bakudan game\n", game->name[i]);
  }
}
