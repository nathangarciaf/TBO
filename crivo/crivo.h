#include <stdlib.h>
#include <stdio.h>

void vec_print(char *v, int start, int final);
void vec_free(char *v);
void item_mark(char *v, int i);
int next_item_find(char *v, int i, int size);