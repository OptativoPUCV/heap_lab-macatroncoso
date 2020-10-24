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

int last(Heap * pq){
int last = 0;
int awa;

for (awa = 0 ; awa < pq->capac ; awa++){
if ( pq->heapArray[awa].data != NULL){
  last = awa;
 }
}
return last;
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
int thelast = last(pq);
int aux;
pq->heapArray[0].priority = pq->heapArray[thelast-1].priority;
pq->heapArray[0].data = pq->heapArray[thelast - 1].data;
pq->heapArray[thelast - 1].data = NULL;
pq->heapArray[thelast-1].priority = 0;
pq->size--;
if (pq->size >=3){
  if (pq->heapArray[1].priority > pq->heapArray[2].priority){
     aux = pq->heapArray[0].priority;
     pq->heapArray[0].priority = pq->heapArray[1].priority;
    pq->heapArray[1].priority = aux;     
     
  }else{
  aux = pq->heapArray[0].priority;
   pq->heapArray[0].priority = pq->heapArray[2].priority;
    pq->heapArray[2].priority = aux;  
}
}


}


Heap* createHeap(){
Heap* hippie = (Heap*) malloc (sizeof(Heap));
hippie->heapArray = (heapElem*) malloc ( 3 * sizeof(heapElem));
hippie->size = 0;
hippie->capac = 3;
 return hippie;
}
