#include "status.h"
#include <stdio.h>

int main(void) {
  status data;
  input_data("char.dat", &data);
  printf("%s\n", data.name);
  printf("%d\n", data.health);
  printf("%d\n", data.intelli);
  printf("%d\n", data.turn);
  output_data("afun.dat", data);
  return 0;
}
