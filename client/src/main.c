#include "character.h"
#include "status.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  status player;
  int action=0;

  while(1)
  {
  }

  setting(&player);

  srand((unsigned)time(NULL));

  while(1){
    printf("sinka=%d\n",player->sinka);
    print_menu(player,&action);
    if(action==2){
      print_action(player);
    }else if(action==0 || action==1){
      player.turn++;
      first_judge(player);
      if(player.turn>11){
        final_judge(player);
        break;
      }
    }
  } 
  return 0;
}

int print_title(void)
{
  int action;

  printf("KosenWatch!\n");
  printf("0:新しく始める\n");
  printf("1:続きから始める\n");

  scanf("%d", &action);

  return action;
}

int print_turn_menu(void)
{
  int action;

  printf("\n------------------------------\n");
  printf("MENU\n");
  printf("0: ババ抜き, 1: 爆弾ゲーム, 2:コミュニケーション\n");
  printf("------------------------------\n");
  printf("Input number: ");

  scanf("%d", &action);

  return action;
}
