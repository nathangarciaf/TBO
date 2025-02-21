#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "suffix.h"
#include "utils.h"

char *remove_spaces_and_enter(char *str) {
    size_t len = strlen(str);
    char *novo_str = (char *)malloc(len + 1);
    if (!novo_str){
        perror("Erro ao alocar memória");
        return NULL;
    }

    char *src = str, *dest = novo_str;
    int espaco_anterior = 0;

    while (*src){
        if (*src == '\n' || *src == '\r'){
            if (!espaco_anterior){
                *dest++ = ' ';
                espaco_anterior = 1;
            }
        }
        else if (*src == ' '){
            if (!espaco_anterior){
                *dest++ = ' ';
                espaco_anterior = 1;
            }
        }
        else{
            *dest++ = *src;
            espaco_anterior = 0;
        }
        src++;
    }

    *dest = '\0';
    return novo_str;
}

int query_binary_search(Suffix *suffixes, String *text, String *query){
    int begin = 0;
    int end = text->len;

    while (begin <= end){
        int mid = (begin + end) / 2;

        int comp = compare_substrings_at(suffixes[mid], query);
        if (!comp)
            return mid;
        if (comp > 0)
            begin = mid + 1;
        else
            end = mid - 1;
        
    }
    return -1;
}

void print_searchs(Suffix *suffixes, String *text, String *query){
    int index = query_binary_search(suffixes, text, query);
    if (index != -1) {
        while (1) {
            int comp = compare_substrings_at(suffixes[index], query);

            if (comp == 0 && index - 1 > 0)
                index--;
            else
                break;
        }

        while (1) {
            int comp = compare_substrings_at(suffixes[index], query);

            if (comp == 0){
                print_substring(suffixes[index].s, suffixes[index].index, text->len);
                printf("\n");
            }

            if (index + 1 < text->len)
                index++;
            else
                break;
        }
    }
    else 
        printf("A BUSCA NÃO RETORNOU RESULTADOS!\n");
}

void sort_suffix_array_msd_cutoff(Suffix *suffix_array, int size_array){
    radix_sort_msd_cutoff(suffix_array, 0, size_array - 1, 0);
}

void sort_suffix_array_msd(Suffix *suffix_array, int size_array){
    radix_sort_msd(suffix_array, 0, size_array - 1, 0);
}

void radix_sort_msd_cutoff(Suffix *suffix_array, int lo, int hi, int d){
    if (hi <= lo)
        return;

    if (hi - lo < 10){
        insertion_sort(suffix_array, lo, hi, d);
        return;
    }

    int count[R + 2] = {0};
    Suffix *aux = (Suffix *)malloc((hi - lo + 1) * sizeof(Suffix));

    for (int i = lo; i <= hi; i++){
        int c = (suffix_array[i].index + d < suffix_array[i].s->len) ? suffix_array[i].s->c[suffix_array[i].index + d] + 1 : 0;
        count[c + 1]++;
    }

    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];
    
    for (int i = lo; i <= hi; i++){
        int c = (suffix_array[i].index + d < suffix_array[i].s->len) ? suffix_array[i].s->c[suffix_array[i].index + d] + 1 : 0;
        aux[count[c]++] = suffix_array[i];
    }

    for (int i = lo; i <= hi; i++)
        suffix_array[i] = aux[i - lo];

    free(aux);

    for (int r = 0; r < R; r++)
        radix_sort_msd(suffix_array, lo + count[r], lo + count[r + 1] - 1, d + 1);
}

void radix_sort_msd(Suffix *suffix_array, int lo, int hi, int d){
    if (hi <= lo)
        return;

    int count[R + 2] = {0};
    Suffix *aux = (Suffix *)malloc((hi - lo + 1) * sizeof(Suffix));

    for (int i = lo; i <= hi; i++){
        int c = (suffix_array[i].index + d < suffix_array[i].s->len) ? suffix_array[i].s->c[suffix_array[i].index + d] + 1 : 0;
        count[c + 1]++;
    }

    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];
    
    for (int i = lo; i <= hi; i++){
        int c = (suffix_array[i].index + d < suffix_array[i].s->len) ? suffix_array[i].s->c[suffix_array[i].index + d] + 1 : 0;
        aux[count[c]++] = suffix_array[i];
    }

    for (int i = lo; i <= hi; i++)
        suffix_array[i] = aux[i - lo];

    free(aux);

    for (int r = 0; r < R; r++)
        radix_sort_msd(suffix_array, lo + count[r], lo + count[r + 1] - 1, d + 1);
}

void insertion_sort(Suffix *suffix_array, int lo, int hi, int d){
    for (int i = lo + 1; i <= hi; i++){
        Suffix temp = suffix_array[i];
        int j = i - 1;
        while (j >= lo && compare_from_suffix(suffix_array[j], temp) > 0) {
            suffix_array[j + 1] = suffix_array[j];
            j--;
        }
        suffix_array[j + 1] = temp;
    }
}