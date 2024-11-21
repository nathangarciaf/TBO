#include "dijkstra.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    CS *cs = char_stack_init();
    DS *ds = double_stack_init();

    char c = '\0';
    while(c != '\n'){
        scanf("%c", &c);

        if(c == '+' || c == '-' || c == '/' || c == '*'){
            char_stack_push(cs,c);
        }
        else if(c == ')'){
            char operador = char_stack_pop(cs);
            double op1 = double_stack_pop(ds);
            double op2 = double_stack_pop(ds);

            //printf("1: %f\n2: %f\nOP: %c\n", op1, op2, operador);
            
            double result = 0;
            if(operador == '+'){
                result = op2 + op1;
            }
            else if(operador == '-'){
                result = op2 - op1;
            }
            else if(operador == '/'){
                result = op2 / op1;
            }
            else if(operador == '*'){
                result = op2 * op1;
            }

            double_stack_push(ds,result);
        }
        //NUMEROS
        else if(c >= '0' && c <= '9'){
            double_stack_push(ds,((double)c - 48.00));
        }
    }

    printf("%f\n", double_stack_pop(ds));
    double_stack_free(ds);
    char_stack_free(cs);
    return 0;
}