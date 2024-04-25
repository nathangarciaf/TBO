#ifndef QS_H
#define QS_H

#include "item.h"

void shuffle(Item *a, int N);
int partition(Item *a, int lo, int hi);
void quick_sort(Item *a, int lo, int hi);
void sort(Item *a, int lo, int hi);

#endif