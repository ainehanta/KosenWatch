// status¹½Â¤ÂÎ
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

int delete_nl(char *str) {
  int i;
  for(i = 0; i < MAX_NAME_LENGTH || str[i] != '\0'; i++) {
    if(str[i] == '\n') {
      str[i] = '\0';
      return 1;
    }
  }
  return 0;
}

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
    delete_nl(ch);
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

  return 0;
}

int output_data(const char* filename) {
}
