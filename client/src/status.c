// status構造体
#include "status.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int input_data(const char* filename, status* data) {
  FILE *fp;
  char ch[MAX_NAME_LENGTH];

  fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("[Error] : can't open file %s\n", filename);
    return 1;
  }

  // name
  if(fgets(ch, MAX_NAME_LENGTH, fp) == NULL) {
    printf("[Error] : file reading error.\n");
    return 1;
  } else {
    _delete_nl(ch);
    strcpy(data->name, ch);
  }

  // health
  if(fgets(ch, MAX_NAME_LENGTH, fp) == NULL) {
    printf("[Error] : file reading error.\n");
    return 1;
  } else {
    data->health = atoi(ch);
  }

  // intelli
  if(fgets(ch, MAX_NAME_LENGTH, fp) == NULL) {
    printf("[Error] : file reading error.\n");
    return 1;
  } else {
    data->intelli = atoi(ch);
  }

  // turn
  if(fgets(ch, MAX_NAME_LENGTH, fp) == NULL) {
    printf("[Error] : file reading error.\n");
    return 1;
  } else {
    data->turn = atoi(ch);
  }

  // sinka
  if(fgets(ch, MAX_NAME_LENGTH, fp) == NULL) {
    printf("[Error] : file reading error.\n");
    return 1;
  } else {
    data->sinka = atoi(ch);
  }

  return 0;
}

int output_data(const char* filename, status* data) {
  FILE *fp;
  char str[10];

  fp = fopen(filename, "w");

  fputs(data->name, fp);
  fputc('\n', fp);
  _itoa(data->health, str);
  fputs(str, fp);
  fputc('\n', fp);
  _itoa(data->intelli, str);
  fputs(str, fp);
  fputc('\n', fp);
  _itoa(data->turn, str);
  fputs(str, fp);
  fputc('\n', fp);
  _itoa(data->sinka, str);
  fputs(str, fp);
  fputc('\n', fp);

  return 0;
}

// PRIVATE
int _delete_nl(char *str) {
  int i;
  for(i = 0; i < MAX_NAME_LENGTH || str[i] != '\0'; i++) {
    if(str[i] == '\n') {
      str[i] = '\0';
      return 1;
    }
  }
  return 0;
}

// PRIVATE
void _itoa (int n,char *s) {
  if(n) {
    int i = 0;
    int l = n;
    while( l /= 10) i++;
    _itoa(n/10, s);
    s[i] = n % 10 + '0';
    s[i+1] = '\0';
  }
}
