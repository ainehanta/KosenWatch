#include "character.h"
#include "status.h"
#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  status player;

  int action = 0;
  int user_select = 0;
  char string_buffer[80];

  // メインループ
  while(1)
  {

title:
    // タイトル
    print_title();
    user_select = get_input(TITLE_LIST, TITLE_LIST_LENGTH);

    if(user_select == TITLE_LOAD)
    {
      goto title;
      printf("セーブデータを確認しています\n");
      // TODOロードする奴
      /*
      data_status = data_ok?(filename);
      if(data_status == true)
      {
        load_data(&player, filename);
      }
      else
      {
        printf("ファイルが存在しません\n");
        printf("タイトル画面へ戻ります\n");
        goto title;
      }
      */
    }
    else if(user_select == TITLE_NEW)
    {
      printf("新しくゲームを始めますか\n");
      if(get_input_yes_no() == SELECT_YES)
      {
        while(1)
        {
          printf("名前を入力してください: ");
          scanf("%s", string_buffer);

          printf("\"%s\"でよろしいですか？\n", string_buffer);
          if(get_input_yes_no() == SELECT_YES)
          {
            break;
          }
        }
        setting(&player, string_buffer);
        // TODO
        // セーブデータ作成
      }
      else
      {
        goto title;
      }
    }

    while(1){
      printf("sinka=%d\n",player.sinka);
      action = print_menu();
      if(action==0 || action==1){
        player.turn++;
        judge(&player);
        if(player.turn>11){
          judge(&player);
          break;
        }else{
          player.turn = player.turn;
        }
      }
    }
  }
  return 0;
}
