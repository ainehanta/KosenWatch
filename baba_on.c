#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ACARD 53  //%4=マーク /4=数字
#define PLACARD 20    //プレイヤーが持てるカードの最大数
#define APL 3       //プレイヤーの最大人数

void init(int playre[][PLACARD],int pmax[],int card[],char rank[]);    //初期化  サーバー側
void disp(int playre[][PLACARD]);       //すべてのカード表示（デバッグ用）
void disp_pl(int playre[][PLACARD],int p,int pmax[]);    //特定のプレイヤーのカードのみ表示．それ以外は*で表示  クライアント側
void del_card(int playre[][PLACARD],int card[],int pmax[]);    //ペアになったカードの消去  サーバー側
void workcard(int playre[][PLACARD],int card[],int pmax[],char rank[],int *i,int *j,char *n);    //カード全般処理   サーバー側
void reset_card(int playre[][PLACARD],int i,int pmax[]);    //カード整理  サーバー側
void game(int playre[][PLACARD],int card[],int pmax[],char rank[]);    //ゲーム部分  サーバー側？
void resurt(char rank[]);    //順位発表  クライアント側
void getscan(char *n,int pmax[],int j);     //入力  仮
void debug_disp(int playre[][PLACARD],char rank[]);     //デバッグ用．中身をすべて表示
char flagck(int playre[][PLACARD],int i);    //上がりフラグチェック  サーバー側

int main(void){
  int card[ACARD];    //カードを配るときのための配列  サーバー側
  int playre[APL][PLACARD];    //プレイヤーがそれぞれ持つカード格納 -1＝何もなし  サーバー側
  int pmax[APL];   //そのプレイヤーが持つカードの枚数  サーバー側
  char rank[APL];   //順位格納  サーバー側 
  srand((unsigned)time(NULL));
  init(playre,pmax,card,rank);
  game(playre,card,pmax,rank);
  resurt(rank);
}

void disp(int playre[][PLACARD])      //デバッグ用
{
  int i,j,h;
  for(i=0;i<APL;i++){
    printf("\nプレイヤー%d\n",i+1);
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

void disp_pl(int playre[][PLACARD],int p,int pmax[])   //クライアント int pで指定したプレイヤーのカードのみ表示．それ以外は伏せて表示
{
   int i,j,h;
  for(i=0;i<APL;i++){
    printf("\nプレイヤー%d\n",i+1);
    if(pmax[i]==0){     //カードが０枚ならばカードを表示しない
      printf("上がり\n");
    }else{
      for(j=0;j<PLACARD;j++){
	printf("|");
	h=playre[i][j]%4;
	if(p==i){
	  if(playre[i][j]==52){
	    printf(" J");        //ジョーカー
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
	    printf(" K");      //ジョーカー
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


void del_card(int playre[][PLACARD],int card[],int pmax[])    //カード消去．
{
  int i,j,k,l;
  for(i=0;i<APL;i++){
    for(j=0;j<=pmax[i];j++){
      if(playre[i][j]>=0){
	for(k=j+1;k<=pmax[i];k++){
	  if(playre[i][j]/4==playre[i][k]/4&&playre[i][k]>=0){    //カードにペアがあったら消す
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

void reset_card(int playre[][PLACARD],int i,int pmax[]) //カードの整理．
{
  int j,l,k;
  l=0;
  k=0;
  for(j=0;j<=PLACARD;j++){
    if(playre[i][j]>=0){
      if(l!=0){
	playre[i][j-l]=playre[i][j];      //カードを左端に詰める
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
  
  for(i=0;i<APL;i++){        //最後尾にカードがないことをつける
    for(j=pmax[i];j<PLACARD;j++){
      playre[i][j]=-1;
    }
  }
}


void game(int playre[][PLACARD],int card[],int pmax[],char rank[])   //ゲームの基礎部分
{
  int i,j,k,l,m;
  char n;
  i=0;
  while(rank[1]==-1){
    if(i!=rank[0]){        //上がった奴の番はスルー
      disp_pl(playre,i,pmax);
      j=i+1;
      j%=3;
      if(j==rank[0]){
	j=i-1;
	if(j<0){
	  j=2;
	}
      }
      printf("プレイヤー%dの番です。\nプレイヤー%dの左から何番目のカードを取りますか?",(i+1),(j+1));
      getscan(&n,pmax,j);
      j=i+1;
      j%=3;
      if(j==rank[0]){
	j=i-1;
	if(j<0){
	  j=2;
	}
      }
      
      workcard(playre,card,pmax,rank,&i,&j,&n);    //カード情報の移動
      
    }
    i++;
    if(i==3){
      i=0;
    }
  }
}


void workcard(int playre[][PLACARD],int card[],int pmax[],char rank[],int *i,int *j,char *n)    //カード整理及び順位チェックなど
{
  playre[*i][pmax[*i]]=playre[*j][(*n)-1];    
  pmax[*i]++;
  playre[*j][(*n)-1]=-2;
  //debug_disp(playre);
  del_card(playre,card,pmax);
  //debug_disp(playre);
  if(rank[0]==-1){

    /*	if(flagck(playre,*i)==1&&flagck(playre,*j)==1){    //無くてもよいはず
	rank[0]=*i;
	rank[1]=*j;
	}*/

    if(flagck(playre,*i)==1){
      rank[0]=*i;
    }if(flagck(playre,*j)==1){
      if(rank[0]==-1){
	rank[0]=*j;
      }else{
	rank[1]=*j;
	switch(*i){
	case 0:
	  if(*j==1){
	    rank[2]=2;
	  }else if(*j==2){
	    rank[2]=1;
	  }
	  break;
	case 1:
	  if(*j==0){
	    rank[2]=2;
	  }else if(*j==2){
	    rank[2]=0;
	  }
	  break;
	case 2:
	  if(*j==0){
	    rank[2]==1;
	  }else if(*j==1){
	    rank[2]=0;
	  }
	  break;
	defalt:
	  break;
	}
      }
    }
  }else{
    printf("\ntest\n");
    if(playre[*i][0]==52&&playre[*j][0]<0){
      rank[1]=*j;
      rank[2]=*i;
    }if(playre[*j][0]==52&&playre[*i][0]<0){
      rank[1]=*i;
      rank[2]=*j;
    }
  }
}

  

void resurt(char rank[])
{
  printf("一位 プレイヤー%d\n二位 プレイヤー%d\n三位 プレイヤー%d\n",rank[0]+1,rank[1]+1,rank[2]+1);
}


void debug_disp(int playre[][PLACARD],char rank[])
{
  int i,j;
  printf("\n");
  printf("rank %d %d %d\n",rank[0],rank[1],rank[2]);
  for(i=0;i<APL;i++){
    for(j=0;j<PLACARD;j++){
      printf(" %d ",playre[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void getscan(char *n,int pmax[],int j)       //入力
{
  scanf("%d",n);
  while(*n>pmax[j]||*n<1){
    printf("不正な入力です\n何番目のカードを取りますか?");
    scanf("%d",n);
  }
}

char flagck(int playre[][PLACARD],int i)   //勝利判定
{
  if(playre[i][0]<0){
    return 1;
  }else{
    return -1;
  }
}

void init(int playre[][PLACARD],int pmax[],int card[],char rank[])   //初期化
{
  int i,h,l,p,j,k;
  for(i=0;i<ACARD;i++){     //配列初期化
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
  for(i=0;i<ACARD;i++){      //カード配り
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
}
