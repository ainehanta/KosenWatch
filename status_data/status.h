// status¹½Â¤ÂÎ
#ifndef INCLUDED_STATUS
#define INCLUDED_STATUS
#define MAX_NAME_LENGTH

typedef struct status {
  int health;
  int intelli;
  int turn;
  char name[MAX_NAME_LENGTH];
} status;

int input_data(const char* filename);
int output_data(const char* filename);

#endif
