#ifndef UTILS_H
#define UTILS_H

#include "str.h"
#include "suffix.h"

char *remove_spaces_and_enter(char *str);
int query_binary_search(Suffix *suffixes, String *text, String *query);
void sort_suffix_array_msd_cutoff(Suffix *suffix_array, int size_array);
void sort_suffix_array_msd(Suffix *suffix_array, int size_array);
void radix_sort_msd(Suffix *suffix_array, int lo, int hi, int d);
void radix_sort_msd_cutoff(Suffix *suffix_array, int lo, int hi, int d);
void insertion_sort(Suffix *suffix_array, int lo, int hi, int d);
void print_searchs(Suffix *suffixes, String *text, String *query);

#endif