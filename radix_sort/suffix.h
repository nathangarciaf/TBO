#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"

#define R 256

typedef struct
{
    String *s;
    int index;
} Suffix;

Suffix *create_suffix_array(String *s, int *size_array);
void print_suffix_array(Suffix *suffix_array, int size_array);
int compare_from_suffix(Suffix s, Suffix t);
void sort_suffix_array(Suffix *suffix_array, int size_array);
int compare_suffixes(const void *s1, const void *s2);
int compare_substrings_at(Suffix s1, String *s2);
void free_suffixes(Suffix *suffixes);

#endif