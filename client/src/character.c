#include "character.h"
#include "status.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初期パラメータ作成
void setting(status *player, char* name)
{
  player->inteli = 0;
  player->health = 0;
  player->turn = 0;
  player->sinka = 0;

  strcpy(player->name, name);
}

// 進化判定関数
// 戻り値がSINKA_FINALの時、ゲーム終了
int judge(status *player)
{
  if(player->sinka == 0)
  {
    first_judge(player);
    return SINKA_FIRST;
  }
  else
  {
    final_judge(player);
    return SINKA_FINAL;
  }

  return -1;
}
//キャラクターを表示
void print_action(status *player)
{
  int val;

  val = rand()%4;

  if(val==0){
    printf("ネコとたわむれた！\n");
    printf("　　　　　　　　　　  |\n");
    printf("　　　　　　　　　 　 |　彡⌒ミ\n");
    printf("　　　　　　　　　　　 ＼(･ω･`　):: \n");
    printf("　　　　　　　　　　　　　(|　　|)::::\n");
    printf("　　　　　　　　　　　　 　(γ　/:::::::\n");
    printf("　   ∧_∧ 　　　　　　　　 し ＼:::\n");
    printf("　. ﾐ・_・ﾐ　　　　　　　　　 　＼\n");
    printf(" ヾ(,_ｕｕﾉ\n");
  }else if(val==1){
    printf("ごはんを食べた！\n");
    printf("   ∧＿∧ \n");
    printf("　(´･ω･`）\n");
    printf("　(っ=川O\n");
    printf("￣￣ヽ二フ￣￣￣￣＼ \n");
  }else if(val==2){
    printf("こたつに吸い込まれた！\n");
    printf("   　∧_∧ \n");
    printf("　（ ´・ω・)\n"); 
    printf("　//＼￣￣旦＼ \n");
    printf("／/ ※ ＼＿＿＿＼ \n");
    printf("＼＼ 　※ 　※ ※ ヽ\n"); 
    printf("　 ＼ヽ-＿_＿--＿__ヽ\n"); 
  }else if(val==3){
    printf("運動した！\n");
    printf("  　　　 ∧,,∧ \n");
    printf("　　　　(´・ω・)　　　　　　　ｼｭｯ!!　　 ∧,,∧ \n");
    printf("　　　　（　っ(⌒）　　　◯三二≡＝─　　⊂(・ω・｀)、 \n");
    printf("　　　　 `ｕ-ｕ'　　　　　　　　　　　 ヽ　　と) \n");
    printf("　　　　　　　　　　　　　　　　　　　　 ｀ｕ-ｕ' \n");
  }
}

// キャラクター表示する
void print_character(status *player)
{
  int month;

  month = player->turn+4;
  if(month>12){
    month = month-12;
  }

  printf("\n");
  printf("%d月\n",month);
  printf("\n");
  printf("your name: %s\n",player->name);
  printf("your parameter: inteli %d  health %d sinka %d\n", player->inteli, player->health, player->sinka);

  if(player->sinka == 0){
    printf("your title: [留年生]\n");
    printf("status:\n");
    printf("        ∧∧\n");
    printf("     ヽ(・ω・)/ ズコー\n");
    printf("   ＼(.＼ ノ\n");
    printf(")、ハ,,、\n");

  }else if(player->sinka == 1){
    printf("your title: [ストロング高専生]\n");
    printf("status:\n");
    printf(" ∧＿∧\n");
    printf("( ・ω・)=つ≡つ\n");
    printf("(っ ≡つ=つ\n");
    printf("/ ) ババババ\n");
    printf("( /‾∪\n");

  }else if(player->sinka == 2){
    printf("your title: [インテリ高専生]\n");
    printf("status:\n");
    printf(" 〃∩ ∧＿∧\n");
    printf("⊂⌒（ ・ω・）\n");
    printf("  ｀ヽ_っ⌒/⌒ｃ\n");
    printf("       ⌒ ⌒\n");
  }
}


// PRIVATE
void _first_judge(status *player)
{
  int val = rand()%2;

  if(player->turn==6){

    if(player->inteli<player->health){
      player->sinka = 1;
      printf("進化しました！\n");
    } else if(player->inteli>player->health){
      player->sinka = 2;
      printf("進化しました！\n");
    } else if(player->inteli==player->health){
      if(val==0){
        player->shinka = 1;
        printf("進化しました！\n");
      }else if(val==1){
        player->sinka = 2;
        printf("進化しました！\n");
      }
    }
  }
}

// PRIVATE
void final_judge(status *player)
{
  if(player->turn>11){

    if(player->sinka == 1 && player->inteli<60 && player->health<60){
      printf("NHK(ニート・ヒッキー・警備員)END\n");

      printf(" ／⌒ヽ\n");
      printf("く/・   ⌒ヽ\n");
      printf(" | 3 (∪‾]\n");
      printf("く、・  (∩‾]\n");
      printf("-------------\n");
    }else if(player->sinka == 2 && player->inteli<60 && player->health<60){
      printf("NHK(ニート・ヒッキー・警備員)END\n");
      printf(" ／⌒ヽ\n");
      printf("く/・   ⌒ヽ\n");
      printf(" | 3 (∪‾]\n");
      printf("く、・  (∩‾]\n");
      printf("-------------\n");
    }else if(player->sinka == 1 && player->inteli<60 && player->health>=60){
      printf("アイツ，良いやつだったんだけどなEND\n");
      printf("　 | l|　ｌ || || l|\n");
      printf(" 　 | l|　| || || ｌ!\n");
      printf(" 　　　l 　 ｌ| .|　　　 ☆\n");
      printf(" 　　＿＿＿＿　／\n");
      printf(" 　 ゝ＿＿＿ノ　がーん！\n");
      printf(" 　　 (　　　 ）\n");
      printf(" 　　 と　 　 i\n");
      printf(" 　　　 しーJ\n");
    }else if(player->sinka == 2 && player->inteli>=60 && player->health<60){
      printf("あ，アイツ同窓会誘うの忘れてたEND\n");
      printf("      ハ,,ハ\n");
      printf("    （ ゜ω゜ ) お断りします\n");
      printf("   ／   ＼\n");
      printf("((⊂ ） ノ  ＼つ))\n");
      printf("    （＿⌒ヽ\n");
      printf("     ヽ ヘ  }\n");
      printf("ε≡Ξ ノノ ｀J\n");
    }else if(player->sinka == 2 && player->inteli>=60 && player->health>=60 && player->inteli<80 && player->health<80){
      printf("大学進学おめでとうEND\n");
      printf("          ∧__∧\n");
      printf("        （｀・ω・）\n");
      printf("       .ノ^ yヽ、\n");
      printf("      ヽ,,ノ==l ノ\n");
      printf("          / l |\n");
      printf("／／／／／／／／／／／／\n");
    }else if(player->sinka == 1 && player->inteli>=60 && player->health>=60 && player->inteli<80 && player->health<80){
      printf("就職決まっておめでとうEND\n");
      printf("　　　　　∧__∧∧∧∧∧∧\n");
      printf("　　　　 (・ω・` )┐┐┐┐┐┐\n");
      printf("　　　　　と´_,ノ゛ヾ.ヾヾ.ヾヾ.ヾヾ.ヾ\n");
      printf("　　　　 　 (´ ヽ、 ＼＼＼＼＼＼＼\n");
      printf("　　　 　 　 ｀ー'　＼__）__）__）_）__）_）__） \n");
    }else if(player->sinka == 1 && (player->inteli>=80 || player->health>=80)){
      printf("一時期は荒れて留年したが今では立派なベンチャー企業の社長END\n");
      printf("　　　　　　　　*'``・* 。\n");
      printf("　　　　　　　　|　　　　 `*。\n");
      printf("　　　　 　　,。∩　　　　 　* 　　　\n");
      printf("　　　　　　+　(´・ω・`)　*。+゜\n");
      printf("　　　　　　`*。 ヽ、　 つ *゜*\n");
      printf("　　　　　　　`・+。*・' ゜⊃ +゜\n");
      printf("　　　　　　　☆　　 ∪~ 。*゜\n");
      printf("　 　　　　　　`・+。*・ ゜\n");
    }else if(player-sinka == 2 && (player->inteli>=80 || player->health>=80)){
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
