// status¹½Â¤ÂÎ
#ifndef INCLUDED_STATUS
#define INCLUDED_STATUS
#define MAX_NAME_LENGTH 10

typedef struct status {
  int health;
  int intelli;
  int turn;
  char name[MAX_NAME_LENGTH];
} status;

int delete_nl(char *str);
int input_data(const char* filename, status* data);
int output_data(const char* filename);

#endif
