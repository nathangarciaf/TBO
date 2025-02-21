#include <stdio.h>
#include <stdlib.h>
#include "str.h"

static int mystrlen(char *a)
{
    int i;
    for (i = 0; a[i] != '\0'; i++);
    return i;
}

String *create_string(char *a)
{
    String *s = malloc(sizeof *s);
    s->len = mystrlen(a);
    s->c = malloc((s->len + 1) * sizeof(char));
    for (int i = 0; i < s->len + 1; i++)
    {
        s->c[i] = a[i];
    }
    return s;
}

void free_string(String *s)
{
    free(s->c);
    free(s);
}

void print_string(String *s)
{
    for (int i = 0; i < s->len; i++)
    {
        printf("%c", s->c[i]);
    }
}

int get_string_len(String *s){
    return s->len;
}

int compare(String *s, String *t){
    return compare_from(s, t, 0);
}

int compare_from(String *s, String *t, int d)
{
    int min = s->len < t->len ? s->len : t->len;
    for (int i = d; i < min; i++)
    {
        if (s->c[i] < t->c[i])
        {
            return -1;
        }
        if (s->c[i] > t->c[i])
        {
            return 1;
        }
    }
    return s->len - t->len;
}

String **create_str_array(int N)
{
    String **a = malloc(N * sizeof(String *));
    return a;
}

void free_string_array(String **a, int n){
    for (int i = 0; i < n; i++)
        free_string(a[i]);
    free(a);
}

void print_str_array(String **a, int n){
    for (int i = 0; i < n; i++){
        print_string(a[i]);
        printf("\n");
    }
}

bool equals_substring(String *text, int start, String *query){
    for (int i = 0; i < query->len; i++){
        if (query->c[i] != text->c[start + i])
        {
            return false;
        }
    }
    return true;
}

void print_substring(String *s, int start, int end){
    for (int i = start; i < end; i++){
        printf("%c", s->c[i]);
    }
}
