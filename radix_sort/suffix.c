#include <stdio.h>
#include <stdlib.h>
#include "suffix.h"
#include "str.h"
#include <string.h>
#include <stdbool.h>

Suffix *create_suffix_array(String *s, int *size_array){
    int str_len = get_string_len(s);
    Suffix *suffix_array = (Suffix *)calloc(str_len + 1, sizeof(Suffix));

    for (int i = 0; i < str_len + 1; i++){
        suffix_array[i].s = s;
        suffix_array[i].index = i;
    }

    *size_array = str_len;

    return suffix_array;
}

void print_suffix_array(Suffix *suffix_array, int size_array){
    for (int i = 0; i < size_array; i++){
        print_substring(suffix_array[i].s, suffix_array[i].index, size_array);
        printf("\n");
    }
}

int compare_from_suffix(Suffix s, Suffix t){
    for (int i = s.index, j = t.index; i < s.s->len && j < s.s->len; i++, j++){
        if (s.s->c[i] < t.s->c[j])
            return -1;
        if (s.s->c[i] > t.s->c[j])
            return 1;
    }
    return 0;
}

int compare_substrings_at(Suffix s1, String *s2){
    for (int i = s1.index, j = 0; i < s1.index + s2->len && j < s2->len; i++, j++){
        if (s1.s->c[i] > s2->c[j])
            return -1;

        if (s1.s->c[i] < s2->c[j])
            return 1;
    }

    return 0;
}

void sort_suffix_array(Suffix *suffix_array, int size_array){
    qsort(suffix_array, size_array, sizeof(Suffix), compare_suffixes);
}

int compare_suffixes(const void *s1, const void *s2){
    Suffix suffix1 = *(Suffix *)s1;
    Suffix suffix2 = *(Suffix *)s2;

    return compare_from_suffix(suffix1, suffix2);
}

void free_suffixes(Suffix *suffixes){
    free(suffixes);
}