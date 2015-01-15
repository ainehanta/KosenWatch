#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ACARD 53  //%4=�ޡ��� /4=����
#define PLACARD 20    //�ץ쥤�䡼�����Ƥ륫���ɤκ����
#define APL 3       //�ץ쥤�䡼�κ���Ϳ�

void disp(int playre[][PLACARD]);       //���٤ƤΥ�����ɽ���ʥǥХå��ѡ�
void disp_pl(int playre[][PLACARD],int p,int pmax[]);    //����Υץ쥤�䡼�Υ����ɤΤ�ɽ��������ʳ���*��ɽ��
void del_card(int playre[][PLACARD],int card[],int pmax[]);    //�ڥ��ˤʤä������ɤξõ�
void reset_card(int playre[][PLACARD],int i,int pmax[]);    //����������
void game(int playre[][PLACARD],int card[],int pmax[],char rank[]);    //��������ʬ
void resurt(char rank[]);    //���ȯɽ
void debug_disp(int playre[][PLACARD]);     //�ǥХå��ѡ���Ȥ򤹤٤�ɽ��
char flagck(int playre[][PLACARD],int i);    //�夬��ե饰�����å�

int main(void){
  int card[ACARD];    //�����ɤ��ۤ�Ȥ��Τ��������
  int playre[APL][PLACARD];    //�ץ쥤�䡼�����줾����ĥ����ɳ�Ǽ -1�Ჿ��ʤ�
  int pmax[APL];   //���Υץ쥤�䡼�����ĥ����ɤ����
  char rank[APL];   //��̳�Ǽ
  int i,j,k,l,p,h;  
  srand((unsigned)time(NULL));
  for(i=0;i<ACARD;i++){     //��������
    card[i]=0;
  }
  for(i=0;i<PLACARD;i++){
    for(h=0;h<APL;h++){
      playre[h][i]=-1;
      rank[h]=-1;
    }
  }
  h=0;
  l=0;
  p=1;
  for(i=0;i<ACARD;i++){      //�������ۤ�
    j=rand()%(ACARD-l);
    for(k=0;j!=-1;k++){
      if(card[k]==0){
	j--;
      }
    }
    card[k-1]=p;
    playre[p-1][h]=k-1;
    p++;
    if(p>APL){
      p=1;
      h++;
    }
    l++;
  }
  pmax[0]=pmax[1]=19;
  pmax[2]=18;
  //disp(playre);
  del_card(playre,card,pmax);
  game(playre,card,pmax,rank);
  resurt(rank);
}

void disp(int playre[][PLACARD])
{
  int i,j,h;
  for(i=0;i<APL;i++){
    printf("\n�ץ쥤�䡼%d\n",i+1);
    for(j=0;j<PLACARD;j++){
      printf("|");
      h=playre[i][j]%4;
      if(playre[i][j]==52){
	printf(" J");
      }else{
	switch(h){
	case 0:
	  printf(" #");
	  break;
	case 1:
	  printf(" $");
	  break;
	case 2:
	  printf(" %%");
	  break;
	case 3:
	  printf(" &");
	  break;
	}
      }if(playre[i][j+1]==-1){
	break;
      }
    }puts("|");
    for(j=0;j<PLACARD;j++){
      printf("|");
      h=playre[i][j]/4;
      if(h==13){
	printf(" K");
      }else{
	printf("%2d",h+1);
      }
      if(playre[i][j+1]==-1){
	break;
      }
    }
    puts("|");
  }
}

void disp_pl(int playre[][PLACARD],int p,int pmax[])
{
   int i,j,h;
  for(i=0;i<APL;i++){
    printf("\n�ץ쥤�䡼%d\n",i+1);
    if(pmax[i]==0){     //�����ɤ�����ʤ�Х����ɤ�ɽ�����ʤ�
      printf("�夬��\n");
    }else{
      for(j=0;j<PLACARD;j++){
	printf("|");
	h=playre[i][j]%4;
	if(p==i){
	  if(playre[i][j]==52){
	    printf(" J");        //���硼����
	  }else{
	    switch(h){
	    case 0:
	      printf(" #");
	      break;
	    case 1:
	      printf(" $");
	      break;
	    case 2:
	      printf(" %%");
	      break;
	    case 3:
	      printf(" &");
	      break;
	    }
	  }
	}else{
	  printf(" *");
	}if(playre[i][j+1]==-1){
	  break;
	}
      }
      puts("|");
      for(j=0;j<PLACARD;j++){
	printf("|");
	h=playre[i][j]/4;
	if(i==p){
	  if(h==13){
	    printf(" K");      //���硼����
	  }else{
	    printf("%2d",h+1);
	  }
	  if(playre[i][j+1]==-1){
	    break;
	  }
	}else{
	  printf(" *");
	  if(playre[i][j+1]==-1){
	    break;
	  }
	}
	
      }
      puts("|");
    }
  }
}


void del_card(int playre[][PLACARD],int card[],int pmax[])
{
  int i,j,k,l;
  for(i=0;i<APL;i++){
    for(j=0;j<=pmax[i];j++){
      if(playre[i][j]>=0){
	for(k=j+1;k<=pmax[i];k++){
	  if(playre[i][j]/4==playre[i][k]/4&&playre[i][k]>=0){    //�����ɤ˥ڥ������ä���ä�
	    playre[i][j]=playre[i][k]=-2;
	    card[playre[i][j]]=card[playre[i][k]]=4;
	    break;
	  }if(playre[i][k]==-1){
	    break;
	  }
	}
      }
    }
    reset_card(playre,i,pmax);
  }
}

void reset_card(int playre[][PLACARD],int i,int pmax[])
{
  int j,l,k;
  l=0;
  k=0;
  for(j=0;j<=PLACARD;j++){
    if(playre[i][j]>=0){
      if(l!=0){
	playre[i][j-l]=playre[i][j];      //�����ɤ�ü�˵ͤ��
	playre[i][j-l+1]=-1;
      }
    }else if(playre[i][j]==-2){
      l++;
    }else if(playre[i][j]==-1){
      break;
    }
  }
  for(j=0;playre[i][j]>-1;j++){
    pmax[i]=j+1;
    k=1;
  }if(k==0){
    pmax[i]=0;
  }
  
  for(i=0;i<APL;i++){        //�Ǹ����˥����ɤ��ʤ����Ȥ�Ĥ���
    for(j=pmax[i];j<PLACARD;j++){
      playre[i][j]=-1;
    }
  }
}


void game(int playre[][PLACARD],int card[],int pmax[],char rank[])
{
  int i,j,k,l,m;
  char n;
  i=0;
  while(rank[2]==-1){
    if(i!=rank[0]){        //�夬�ä��ۤ��֤ϥ��롼
      disp_pl(playre,i,pmax);
      j=i+1;
      j%=3;
      if(j==rank[0]){
	j=i-1;
	if(j<0){
	  j=2;
	}
      }
      printf("�ץ쥤�䡼%d���֤Ǥ���\n�ץ쥤�䡼%d�κ����鲿���ܤΥ����ɤ���ޤ���?",(i+1),(j+1));
      scanf("%d",&n);
      j=i+1;
      j%=3;
      if(j==rank[0]){
	j=i-1;
	if(j<0){
	  j=2;
	}
      }
      while(n>pmax[j]||n<1){
	printf("���������ϤǤ�\n�����ܤΥ����ɤ���ޤ���?");
	
	scanf("%d",&n);
      }
      
      playre[i][pmax[i]]=playre[j][n-1];
      pmax[i]++;
      playre[j][n-1]=-2;
      //debug_disp(playre);
      del_card(playre,card,pmax);
      //debug_disp(playre);
      if(rank[0]==-1){
	/*	if(flagck(playre,i)==1&&flagck(playre,j)==1){
	  rank[0]=i;
	  rank[1]=j;
	  }*/
	if(flagck(playre,i)==1){
	  rank[0]=i;
	}else if(flagck(playre,j)==1){
	  rank[0]=j;
	}
      }else if(rank[0]!=-1){
	if(playre[i][0]==52&&playre[j][0]<0){
	  rank[1]=j;
	  rank[2]=i;
	}if(playre[j][0]==52&&playre[i][0]<0){
	  rank[1]=i;
	  rank[2]=j;
	}
      }
    }
    i++;
    if(i==3){
      i=0;
    }
  }
}

void resurt(char rank[])
{
  printf("��� �ץ쥤�䡼%d\n��� �ץ쥤�䡼%d\n���� �ץ쥤�䡼%d\n",rank[0]+1,rank[1]+1,rank[2]+1);
}


void debug_disp(int playre[][PLACARD])
{
  int i,j;
  printf("\n");
  for(i=0;i<APL;i++){
    for(j=0;j<PLACARD;j++){
      printf(" %d ",playre[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

char flagck(int playre[][PLACARD],int i)
{
  if(playre[i][0]<0){
    return 1;
  }else{
    return -1;
  }
}
