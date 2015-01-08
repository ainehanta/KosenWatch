#include "character.h"
#include "status.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num;

int main()
{
  struct parameter player[4];
  int action=0;

  setting(player);

  while(1){
    printf("num=%d\n",num);
    print_menu(player,&action);
    if(action==0 || action==1){
      player[0].turn++;
      first_judge(player);
      if(player[0].turn>11){
        final_judge(player);
        break;
      }
    }
  }
  return 0;
}

void setting(struct parameter player[])
{

  player[0].inteli = 40;
  player[0].health = 80;
  player[0].turn = 0;

  num = 0;

  printf("What is your name?\n");
  scanf("%s",player[0].name);

}

void first_judge(struct parameter player[])
{
  srand((unsigned)time(NULL));

  int val = rand()%2;

  if(player[0].turn==6){

    if(player[0].inteli<player[0].health){
      num = 1;
      player[1].inteli = player[0].inteli;
      player[1].health = player[0].health;

      printf("進化しました！\n");


    } else if(player[0].inteli>player[0].health){
      num = 2;
      player[2].inteli = player[0].inteli;
      player[2].health = player[0].health;

      printf("進化しました！\n");

    } else if(player[0].inteli==player[0].health){
      if(val==0){
        num = 1;
        player[1].inteli = player[0].inteli;
        player[1].health = player[0].health;
        printf("進化しました！\n");
      }else if(val==1){
        num = 2;
        player[2].inteli = player[0].inteli;
        player[2].health = player[0].health;
        printf("進化しました！\n");
      }
    }
  }
}

void final_judge(struct parameter player[])
{
  if(player[0].turn>11){

    if(player[1].inteli<60 && player[1].health<60){
      printf("NHK(ニート・ヒッキー・警備員)END\n");

      printf(" ／⌒ヽ\n");
      printf("く/・   ⌒ヽ\n");
      printf(" | 3 (∪‾]\n");
      printf("く、・  (∩‾]\n");
      printf("-------------\n");
    }else if(player[2].inteli<60 && player[2].health<60){
      printf("NHK(ニート・ヒッキー・警備員)END\n");
      printf(" ／⌒ヽ\n");
      printf("く/・   ⌒ヽ\n");
      printf(" | 3 (∪‾]\n");
      printf("く、・  (∩‾]\n");
      printf("-------------\n");
    }else if(player[1].inteli<60 && player[1].health>=60){
      printf("アイツ，良いやつだったんだけどなEND\n");
      printf("　 | l|　ｌ || || l|\n");
      printf(" 　 | l|　| || || ｌ!\n");
      printf(" 　　　l 　 ｌ| .|　　　 ☆\n");
      printf(" 　　＿＿＿＿　／\n");
      printf(" 　 ゝ＿＿＿ノ　がーん！\n");
      printf(" 　　 (　　　 ）\n");
      printf(" 　　 と　 　 i\n");
      printf(" 　　　 しーJ\n");
    }else if(player[2].inteli>=60 && player[0].health<60){
      printf("あ，アイツ同窓会誘うの忘れてたEND\n");
      printf("      ハ,,ハ\n");
      printf("    （ ゜ω゜ ) お断りします\n");
      printf("   ／   ＼\n");
      printf("((⊂ ） ノ  ＼つ))\n");
      printf("    （＿⌒ヽ\n");
      printf("     ヽ ヘ  }\n");
      printf("ε≡Ξ ノノ ｀J\n");
    }else if(player[2].inteli>=60 && player[2].health>=60 && player[2].inteli<80 && player[2].health<80){
      printf("大学進学おめでとうEND\n");
      printf("          ∧__∧\n");
      printf("        （｀・ω・）\n");
      printf("       .ノ^ yヽ、\n");
      printf("      ヽ,,ノ==l ノ\n");
      printf("          / l |\n");
      printf("／／／／／／／／／／／／\n");
    }else if(player[1].inteli>=60 && player[1].health>=60 && player[1].inteli<80 && player[1].health<80){
      printf("就職決まっておめでとうEND\n");
      printf("　　　　　∧__∧∧∧∧∧∧\n");
      printf("　　　　 (・ω・` )┐┐┐┐┐┐\n");
      printf("　　　　　と´_,ノ゛ヾ.ヾヾ.ヾヾ.ヾヾ.ヾ\n");
      printf("　　　　 　 (´ ヽ、 ＼＼＼＼＼＼＼\n");
      printf("　　　 　 　 ｀ー'　＼__）__）__）_）__）_）__） \n");
    }else if(player[1].inteli>=80 && player[1].health>=80){
      printf("一時期は荒れて留年したが今では立派なベンチャー企業の社長END\n");
      printf("　　　　　　　　*'``・* 。\n");
      printf("　　　　　　　　|　　　　 `*。\n");
      printf("　　　　 　　,。∩　　　　 　* 　　　\n");
      printf("　　　　　　+　(´・ω・`)　*。+゜\n");
      printf("　　　　　　`*。 ヽ、　 つ *゜*\n");
      printf("　　　　　　　`・+。*・' ゜⊃ +゜\n");
      printf("　　　　　　　☆　　 ∪~ 。*゜\n");
      printf("　 　　　　　　`・+。*・ ゜\n");
    }else if(player[2].inteli>=80 || player[2].health>=80){
      printf("一時期は荒れて留年したが今では立派なベンチャー企業の社長END\n");
      printf("　　　　　　　　*'``・* 。\n");
      printf("　　　　　　　　|　　　　 `*。\n");
      printf("　　　　 　　,。∩　　　　 　* 　　　\n");
      printf("　　　　　　+　(´・ω・`)　*。+゜\n");
      printf("　　　　　　`*。 ヽ、　 つ *゜*\n");
      printf("　　　　　　　`・+。*・' ゜⊃ +゜\n");
      printf("　　　　　　　☆　　 ∪~ 。*゜\n");
      printf("　 　　　　　　`・+。*・ ゜\n");
    }
  }
}

void print_menu(struct parameter player[],int *action)
{
  int month;

  month = player[0].turn+4;
  if(month>12){
    month = month-12;
  }

  printf("\n");
  printf("%d月\n",month);
  printf("\n");
  printf("your name: %s\n",player[0].name);
  printf("your parameter: inteli %d  health %d\n",player[num].inteli,player[num].health);

  if(num==0){
    printf("your title: [留年生]\n");
    printf("status:\n");
    printf("        ∧∧\n");
    printf("     ヽ(・ω・)/ ズコー\n");
    printf("   ＼(.＼ ノ\n");
    printf(")、ハ,,、\n");

  }else if(num==1){
    printf("your title: [ストロング高専生]\n");
    printf("status:\n");
    printf(" ∧＿∧\n");
    printf("( ・ω・)=つ≡つ\n");
    printf("(っ ≡つ=つ\n");
    printf("/ ) ババババ\n");
    printf("( /‾∪\n");

  }else if(num==2){
    printf("your title: [インテリ高専生]\n");
    printf("status:\n");
    printf(" 〃∩ ∧＿∧\n");
    printf("⊂⌒（ ・ω・）\n");
    printf("  ｀ヽ_っ⌒/⌒ｃ\n");
    printf("       ⌒ ⌒\n");
  }

  printf("\n------------------------------\n");
  printf("MENU\n");
  printf("0: ババ抜き, 1: 爆弾ゲーム\n");
  printf("------------------------------\n");
  printf("Input number: ");
  scanf("%d", action);
}
