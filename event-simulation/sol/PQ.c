#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

struct pq {
    Event* *events; // Min-heap array.
    int size;       // Tamanho atual.
    int N;          // Número máximo de elementos.
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    PQ *pq = malloc(sizeof *pq);

    pq->N = max_N + 1;
    pq->events = malloc(pq->N * sizeof(Event*));
    for (int i = 0; i < pq->N; i++) {
        pq->events[i] = NULL;
    }
    pq->size = 0;

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    for (int i = 1; i <= pq->size; i++) {
        destroy_event(pq->events[i]);
    }
    free(pq->events);
    free(pq);
}

#define greater(A, B)   (compare(A, B) > 0)
#define exch(A, B)      { Event *t = A; A = B; B = t; }

static void fix_up(PQ *pq, int k) {
    Event* *a = pq->events;
    while (k > 1 && greater(a[k/2], a[k])) {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

void fix_down(PQ *pq, int k){
    Event* *a = pq->events;
    while (2*k <= pq->size) {
        int j = 2*k;
        if (j < pq->size && greater(a[j], a[j+1])){
          j++;
        }
        if (!greater(a[k], a[j])) {
            break;
        }
        exch(a[k], a[j]);
        k = j;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    if (pq->size == pq->N) {
        fprintf(stderr, "ERROR: Queue is full (%d)!\n", pq->size);
        exit(EXIT_FAILURE);
    }
    pq->size++;
    pq->events[pq->size] = e;
    fix_up(pq, pq->size);
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    Event *e = pq->events[1];
    pq->events[1] = pq->events[pq->size];
    pq->events[pq->size] = NULL;
    pq->size--;
    fix_down(pq, 1);
    return e;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    return pq->size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->size;
}
