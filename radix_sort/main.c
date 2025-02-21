#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "str.h"
#include "suffix.h"

int main(int argc, char *argv[]){
    FILE *f = fopen(argv[1], "r");
    if (!f){
        printf("Arquivo inexistente!\n");
        exit(1);
    }
    int n = 0;
    fscanf(f, "%d\n", &n);

    char *file_string = (char*)calloc((n + 2), sizeof(char));
    fread(file_string, 1, n + 2, f);
    fclose(f);

    char *formatted_string = remove_spaces_and_enter(file_string);
    free(file_string);

    String *s = create_string(formatted_string);
    free(formatted_string);

    int size_array_suffixes = 0;
    Suffix *suffixes = create_suffix_array(s, &size_array_suffixes);

    clock_t begin = clock();
    //sort_suffix_array_msd_cutoff(suffixes, size_array_suffixes);
    //sort_suffix_array(suffixes,size_array_suffixes);
    sort_suffix_array_msd(suffixes, size_array_suffixes);
    clock_t end = clock();

    printf("SORT: %f\n", ((float)end - (float)begin) / CLOCKS_PER_SEC);

    while (1)
    {
        char query[100];

        if (scanf("%[^\n]%*c", query) == 0){
            break;
        }

        String *q = create_string(query);

        print_searchs(suffixes, s, q);

        free_string(q);
    }
    free_suffixes(suffixes);
    free_string(s);

    return 0;
}