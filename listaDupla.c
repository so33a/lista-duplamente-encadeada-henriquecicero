#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

link novoNo (int item, link prev, link next) {
  link aux = malloc(sizeof(struct node));
  if (aux == NULL) {
    printf ("Erro ao alocar um novo no\n");
    exit(-1);
  }
  aux->item = item;
  aux->prev = prev;
  aux->next = next;
  return aux;
}

ListaDupla inicializa() {
  ListaDupla aux;
  aux = malloc(sizeof *aux);
  aux->head = NULL;
  aux->z = novoNo(0, NULL, NULL);
  return aux;
}

void insereDepois (ListaDupla l, link x, link t) {
  if (x == NULL) {
    l->head = t;
    t->next = l->z;
    t->prev = l->z;
    l->z->prev = t;
    l->z->next = t; 
  } else {
    t->next = x->next;
    t->prev = x;
    x->next = t;
    t->next->prev = t;
  }
}

link removeNo (link x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  return x;
}

void imprimeReverso(ListaDupla l) {
  link t = l->z->prev;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->prev;
  }
  printf("\n");
}

void imprime(ListaDupla l) {
  link t = l->head;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->next;
  }
  printf("\n");
}

link buscar(ListaDupla l, int item) {
  link t = l->head;
  while ( t != l->z ) {
    if(t->item == item)
      return t;
    t = t->next;
  }
  return NULL;
}

/* 
void insereAntes (ListaDupla l, link x, link t);
*/

void destroiLista(ListaDupla l) {
  link t = l->head;
  while (t != l->z) {
    l->head = t->next;
    l->z->next = t->next;
    l->head->prev = l->z;
    free(t); 
    t = l->head;
  } 
  free(t);
  free(l);
}

link buscarMenor (ListaDupla l) {
  link t = l->head;
  link menor;

  if (t == l->z)
    return NULL;
  else
    menor = t;

  while (t != l->z) {
    if(t->item < menor->item) {
      menor = t;
    }
    t = t->next;
  }
  return menor;  
}

ListaDupla ordenar (ListaDupla l) {
  ListaDupla lst = inicializa();
  link t = l->head;
  link menor;

  if (t == l->z)
    return NULL;
  else {
    while (t != l->z) {
      menor = buscarMenor (l);
      insereDepois(lst, lst->z->prev, novoNo (menor->item, menor->prev, menor->next));
      removeNo (menor);
      t = t->next;
    }
    insereDepois(lst, lst->z->prev, novoNo (l->head->item, l->head->prev, l->head->next));
    destroiLista (l);
    return lst;
  }
}
