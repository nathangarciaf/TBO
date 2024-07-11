#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

struct pq {
    Event **ev;
    int size, used;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    PQ *pq = calloc(1,sizeof(PQ));
    pq->size = max_N+1;
    pq->used = 0;
    pq->ev = calloc(max_N, sizeof(Event*));
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    for(int i = 0; i < pq->used; i++){
        destroy_event(pq->ev[i]);
    }
    free(pq->ev);
    free(pq);
}

void fix_up(PQ *pq, int k){
    Event **events = pq->ev;
    while(k/2 > 0){
        Event *ev = events[k];
        Event *parent = events[k/2];

        if((compare(ev, parent) >= 0)){
            break;
        }
            
        events[k] = parent;
        events[k/2] = ev;
        k /= 2;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if(pq->size == pq->used){
        printf("FILA ENCHEU");
        exit(1);
        pq->size *= 2;
        pq->ev = realloc(pq->ev, pq->size*sizeof(PQ*));
    }

    pq->used++;
    pq->ev[pq->used] = e;
    fix_up(pq, pq->used);
}

void fix_down(PQ *pq, int k){
    Event **events = pq->ev;

    while(k*2 <= pq->used){
        int j = 2*k;

        Event *e = events[k];
        Event *child1 = events[j];
        Event *def_child = child1;

        if( !( (j+1) > pq->used ) ){
            Event *child2 = events[j+1];
            if(compare(child1,child2) >= 0){
                def_child = child2;
                j++;
            }
            else{
                def_child = child1;
            }
        }

        if((compare(e, def_child) >= 0)){
            events[k] = def_child;
            events[j] = e;
            k = j;
            continue;
        }
        break;
    }
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    Event **events = pq->ev;

    Event *min = events[1];
    Event *last = events[pq->used];

    events[1] = last;
    fix_down(pq, 1);
    pq->used--;
    return min;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    if (pq->used == 0)
        return true;
    return false;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->used;
}
