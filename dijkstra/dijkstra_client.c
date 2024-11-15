#include "dijkstra.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    Stack *pilha_operandos = init_stack();
    Stack *pilha_operadores = init_stack();

    char *operacao = (char*)calloc(1, sizeof(char)*10);
    char c;
    while(c != '\n'){
        scanf("%s", operacao);
        scanf("%c", &c);

        if(!strcmp(operacao, "+") ){
            
        }
        else if(!strcmp(operacao, "-")){

        }
        else if(!strcmp(operacao, "/")){

        }
        else if(!strcmp(operacao, "*")){

        }
        else if(!strcmp(operacao, ")")){

        }
        //NUMEROS
        else{
            
        }

    }

    return 0;
}