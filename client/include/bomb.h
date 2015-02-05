#ifndef INCLUDED_BAKUDAN_H
#define INCLUDED_BAKUDAN_H
#define DEFAULT_PLAYER_NUM 3
#define DROP_OUT 1
#define NOTHING -1
#define NOT_PRESSED 0
#define PRESSED 1
#define EXPLODED 2
#define NAME_LENGTH 10

typedef struct bakudan {
  int bomb_loc;
  int bomb_status[DEFAULT_PLAYER_NUM+1];
  int dropout[DEFAULT_PLAYER_NUM-1];
  int order[DEFAULT_PLAYER_NUM];
  int player_num;
  char name[DEFAULT_PLAYER_NUM][NAME_LENGTH+1];
  int my_player_num;
} bakudan;

int bakudan_main();
int check_input(bakudan game, int input);
void disp_bomb(bakudan game);
void disp_guide_message(bakudan game, int order);
void disp_input_guide(bakudan game);
void disp_safe(bakudan game, int order);
void disp_winner(int winner);
int drop_out(bakudan* game, int order);
int explode_bomb(bakudan* game, int loc);
void init_bakudan(bakudan* game);
int input_data(bakudan game, int player);
void make_bakudan(bakudan* game);
int press_switch(bakudan* game);

int get_current_player(bakudan* game);
void get_data(unsigned char data[]);
int get_input(bakudan* game);
void get_init_data(bakudan* game);
void get_is_dropped(bakudan* game);
void get_name(bakudan* game);
void get_player_num(bakudan* game);
int get_winner(bakudan* game);
void send_data(unsigned char data[]);
void send_input(bakudan game, unsigned char input);
void send_name(bakudan game, unsigned char name[]);

#endif

