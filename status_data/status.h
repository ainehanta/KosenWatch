#ifndef INCLUDED_STATUS
#define INCLUDED_STATUS
#define MAX_NAME_LENGTH

struct status {
  int health;
  int intelli;
  int turn;
  char name[MAX_NAME_LENGTH];
};

#endif
