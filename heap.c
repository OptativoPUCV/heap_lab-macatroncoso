#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
int awa;
int mayor;
void* mayordata = 0;

if (pq->size == 0) return NULL;

for (awa = 0 ; awa < pq->capac ; awa++){
if ( pq->heapArray[awa].priority > mayor){
  mayor = pq->heapArray[awa].priority;
  mayordata = pq->heapArray[awa].data;
 }
}
if ((mayordata == NULL) || mayordata == 0){
    return NULL;}
else{
      return mayordata;
}
}



void heap_push(Heap* pq, void* data, int priority){
int current = pq->size;
if (pq->size + 1 > pq->capac){
  pq->capac = ((pq->capac) * 2 ) + 1;
  pq->heapArray = realloc(pq->heapArray, (pq->capac) * sizeof(heapElem));
}
while ((current >0) && (pq->heapArray[(current-1)/2]).priority < priority){
  pq->heapArray[current] = pq->heapArray[(current-1) / 2];
  current = (current - 1)/2;
  }
 pq->heapArray[current].priority = priority;
 pq->heapArray[current].data = data;
 pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
Heap* hippie = (Heap*) malloc (sizeof(Heap));
hippie->heapArray = (heapElem*) malloc (3 * sizeof(heapElem));
hippie->size = 0;
hippie->capac = 3;
 return hippie;
}
