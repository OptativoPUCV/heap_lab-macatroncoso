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

for (awa = 0 ; awa < pq->capac ; awa++){
if ( pq->heapArray[awa].priority > mayor){
  mayor = pq->heapArray[awa].priority;
  mayordata = pq->heapArray[awa].data;
}
}
    return mayordata;
}



void heap_push(Heap* pq, void* data, int priority){

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
