#ifndef INCLUDED_BAKUDAN_H
#define INCLUDED_BAKUDAN_H
#define DEFAULT_PLAYER_NUM 3
#define NAME_LENGTH 10
#define DROP_OUT 1
#define NOTHING -1
#define NOT_PRESSED 0
#define PRESSED 1
#define EXPLODED 2

typedef struct bakudan {
  int bomb_loc;
  int bomb_status[DEFAULT_PLAYER_NUM+1];
  int dropout[DEFAULT_PLAYER_NUM-1];
  int order[DEFAULT_PLAYER_NUM];
  int player_num;
  char name[DEFAULT_PLAYER_NUM][NAME_LENGTH+1];
} bakudan;

int bakudan_main();
int check_input(bakudan game, int input);
void disp_bomb(bakudan game);
void disp_guide_message(bakudan game, int order);
void disp_input_guide(bakudan game);
void disp_safe(bakudan game, int order);
void disp_winner(bakudan game);
int drop_out(bakudan* game, int order);
int explode_bomb(bakudan* game, int loc);
void get_data(char* data, int num);
int get_input_data(int num);
void get_name(bakudan* game, int num);
void init_bakudan(bakudan* game);
int input_data(bakudan game, int num);
void make_bakudan(bakudan* game);
int press_switch(bakudan* game, int loc);
int send_data(unsigned char* data, int player);
int send_player_num(bakudan game);
void send_player_name(bakudan game);
int send_init_data(bakudan game);
void send_your_order(bakudan game, int num);
void wait_add_player(bakudan* game);

#endif

