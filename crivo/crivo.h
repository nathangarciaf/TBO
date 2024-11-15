#include <stdlib.h>
#include <stdio.h>

void vec_print(char *v, int start, int final);
void vec_free(char *v);
void item_mark_char(char *v, int i);
void item_mark_int(int *v, int i);
int next_item_find_char(char *v, int i, int size);
int next_item_find_int(int *v, int i, int size);