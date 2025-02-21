#ifndef STR_H
#define STR_H

#include <stdbool.h>

typedef struct {
    char *c;
    int len;
} String;

String *create_string(char *cs);
String **create_str_array(int N);

int get_string_len(String *s);
int compare(String *s, String *t);
int compare_from(String *s, String *t, int d);
bool equals_substring(String *text, int start, String *query);

void print_string(String *s);
void print_str_array(String **a, int N);
void print_substring(String *text, int start, int end);

void free_string(String *s);
void free_string_array(String **a, int n);

#endif
