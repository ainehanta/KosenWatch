#include "ui.h"

#include <stdio.h>

void print_title(void)
{
  printf("KosenWatch!\n");
  printf("〜こうせんへーなにそれこわい〜\n");
  printf("-----------------\n");
  printf("0:続きから始める\n");
  printf("1:新しく始める\n");
  printf("-----------------\n");
  printf("項目を選択してください: ");
}

int print_menu(void)
{
  printf("\n------------------------------\n");
  printf("MENU\n");
  printf("0: ババ抜き, 1: 爆弾ゲーム\n");
  printf("------------------------------\n");
  printf("項目を選択してください: ");

  return get_input(MENU_LIST, MENU_LIST_LENGTH);
}

// check_listにinputが含まれているか確認する
// 含まれる -> return 1
// 含まれない -> return 0
int is_valid_input(int input, int* input_list, int length)
{
  int i;
  for(i = 0; i < length; i++)
  {
    if(input_list[i] == input)
    {
      return 1;
    }
  }

  return 0;
}

// 注意:適切な入力まで復帰しません
int get_input(int* input_list, int length)
{
  int user_select;

  while(1)
  {
    printf("項目を選択してください: \n");
    scanf("%d", &user_select);

    if(is_valid_input(user_select, input_list, length))
      return user_select;

    printf("入力は");
    print_array_literal(input_list, length);
    printf("の中から選択してください\n");
  }
}

int get_input_yes_no(void)
{
  printf("-----------------\n");
  printf("0:はい\n");
  printf("1:いいえ\n");
  printf("-----------------\n");

  return get_input(SELECT_LIST, SELECT_LIST_LENGTH);
}

void print_array_literal(int* input_list, int length)
{
  int i;

  for(i=0; i < length; i++)
  {
    printf("%d ",input_list[i]);
  }
}
