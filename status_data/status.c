// status¹½Â¤ÂÎ
#include "status.h"
#include <stdio.h>

int input_data(const char* filename) {
  FILE *fp;

  fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("[Error] : can't open file %s\n", filename);
    return 1;
  }
  return 0;
}

int output_data(const char* filename) {
}
