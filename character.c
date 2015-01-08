#include <stdio.h>
#include <stdlib.h>

int num;

struct parameter{
  int inteli;
  int health;
  int turn;
  char name[];
};

void setting(struct parameter player[]);
void first_judge(struct parameter player[]);
void final_judge(struct parameter player[]);
void print_menu(struct parameter player[],int *action);

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
  player[0].inteli = 65;
  player[0].health = 60;
  player[0].turn = 0;

  num = 0;

  printf("What is your name?\n");
  scanf("%s",player[0].name);

}

void first_judge(struct parameter player[])
{

  if(player[0].turn==6){

    if(player[0].inteli<player[0].health){
      num = 1;
      player[1].inteli = player[0].inteli;
      player[1].health = player[0].health;
      
      printf("�ʲ����ޤ�����\n");
     

    } else if(player[0].inteli>player[0].health){
      num = 2;
      player[2].inteli = player[0].inteli;
      player[2].health = player[0].health;

      printf("�ʲ����ޤ�����\n");
   
    }
  }
}

void final_judge(struct parameter player[])
{
  if(player[0].turn>11){

    if(player[1].inteli<60 && player[1].health<60){
      printf("NHK(�ˡ��ȡ��ҥå�����������)END\n");
 
      printf(" ���ޡ�\n");
      printf("��/��   �ޡ�\n");
      printf(" | 3 (����]\n");
      printf("������  (����]\n");
      printf("-------------\n");
    }else if(player[2].inteli<60 && player[2].health<60){
      printf("NHK(�ˡ��ȡ��ҥå�����������)END\n");
      printf(" ���ޡ�\n");
      printf("��/��   �ޡ�\n");
      printf(" | 3 (����]\n");
      printf("������  (����]\n");
      printf("-------------\n");
    }else if(player[1].inteli<60 && player[1].health>60){
      printf("�����ġ��ɤ���Ĥ��ä�������ɤ�END\n");

    }else if(player[2].inteli>=60 && player[0].health<60){
      printf("����������Ʊ���Ͷ����˺��Ƥ�END\n");
      printf("      ��,,��\n");
      printf("    �� �ߦ؎� ) ���Ǥꤷ�ޤ�\n");
      printf("   ��   ��\n");
      printf("((�� �� ��  ����))\n");
      printf("    �ʡ��ޡ�\n");
      printf("     �� ��  }\n");
      printf("�Ţ᦮ �ɥ� ��J\n");
    }else if(player[2].inteli>=60 && player[2].health>=60 && player[2].inteli<80 && player[2].health<80){
      printf("��ؿʳؤ���ǤȤ�END\n");
      printf("          ��__��\n");
      printf("        �ʡ����؎���\n");
      printf("       .��^ y����\n");
      printf("      ��,,��==l ��\n");
      printf("          / l |\n");
      printf("������������������������\n");
    }else if(player[1].inteli>=60 && player[1].health>=60 && player[1].inteli<80 && player[1].health<80){
      printf("������ޤäƤ���ǤȤ�END\n");
      printf("������������__�ʢʢʢʢʢ�\n");
      printf("�������� (���؎�` )������������\n");
      printf("�����������ȡ�_,�Ύޡ�.����.����.����.��\n");
      printf("�������� �� (�� ���� ��������������\n");
      printf("������ �� �� ����'����__��__��__��_��__��_��__�� \n");
    }else if(player[1].inteli>=80 && player[1].health>=80){
      printf("������ϹӤ��αǯ���������Ǥ�Ω�ɤʥ٥���㡼��Ȥμ�ĹEND\n");
      printf("����������������*'``��* ��\n");
      printf("����������������|�������� `*��\n");
      printf("�������� ����,������������ ��* ������\n");
      printf("������������+��(�����؎�`)��*��+��\n");
      printf("������������`*�� ������ �� *��*\n");
      printf("��������������`��+��*��' �ߢ� +��\n");
      printf("�������������������� ��~ ��*��\n");
      printf("�� ������������`��+��*�� ��\n");
    }else if(player[2].inteli>=80 && player[2].health>=80){
      printf("������ϹӤ��αǯ���������Ǥ�Ω�ɤʥ٥���㡼��Ȥμ�ĹEND\n");
      printf("����������������*'``��* ��\n");
      printf("����������������|�������� `*��\n");
      printf("�������� ����,������������ ��* ������\n");
      printf("������������+��(�����؎�`)��*��+��\n");
      printf("������������`*�� ������ �� *��*\n");
      printf("��������������`��+��*��' �ߢ� +��\n");
      printf("�������������������� ��~ ��*��\n");
      printf("�� ������������`��+��*�� ��\n");
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
  printf("%d��\n",month);
  printf("\n");
  printf("your name: %s\n",player[0].name);
  printf("your parameter: inteli %d  health %d\n",player[num].inteli,player[num].health);

  if(num==0){
    printf("your title: [αǯ��]\n"); 
    printf("status:\n");
    printf("        �ʢ�\n");
    printf("     ��(���؎�)/ ���ގ���\n");
    printf("   ��(.�� ��\n");
    printf(")����,,��\n");

  }else if(num==1){
    printf("your title: [���ȥ�󥰹�����]\n");
    printf("status:\n");
    printf(" �ʡ���\n");
    printf("( ���؎�)=�Ģ��\n");
    printf("(�� ���=��\n");
    printf("/ ) �ʎގʎގʎގʎ�\n");
    printf("( /����\n");
    
  }else if(num==2){
    printf("your title: [����ƥ������]\n");
    printf("status:\n");
    printf(" ���� �ʡ���\n");
    printf("���ޡ� ���ء���\n");
    printf("  ����_�â�/�ޣ�\n");
    printf("       �� ��\n");
  }

  printf("\n------------------------------\n");
  printf("MENU\n");
  printf("0: �Х�ȴ��, 1: ���ƥ�����\n"); 
  printf("------------------------------\n");
  printf("Input number: ");
  scanf("%d", action);
}

