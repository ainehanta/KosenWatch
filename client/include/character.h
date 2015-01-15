#ifndef __CHARACTER_H
#define __CHARACTER_H

#define SINKA_FIRST 0
#define SINKA_FINAL 1

void setting(status *player);
void print_character(status *player);
int judge(status *player);

// PRIVATE
void _first_judge(status *player);
void _final_judge(status *player);

#endif
