#ifndef __BABANUKI_H
#define __BABANUKI_H

#define ACARD 53  //%4=マーク /4=数字
#define PLACARD 20    //プレイヤーが持てるカードの最大数
#define APL 3       //プレイヤーの最大人数

int babanuki_main(void);
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

#endif
