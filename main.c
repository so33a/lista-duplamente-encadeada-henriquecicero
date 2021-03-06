#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

int main () {
  ListaDupla l = inicializa();
  ListaDupla lst;
  link aux, aux2, menor;
  insereDepois(l, l->head, aux= novoNo(51, NULL, NULL));
  aux2 = novoNo(80, NULL, NULL);
  insereDepois(l,aux,aux2);
  aux = novoNo(23, NULL, NULL); 
  insereDepois(l, aux2, aux);
  imprime(l);
  menor = buscarMenor (l);
  printf ("\nmenor %d \n", menor->item);
  l = insertionSort (l);
  imprime(l);
  imprimeReverso(l);
  printf ("\nremovendo %d \n", aux2->item);
  if((aux2 = buscar(l, aux2->item) ) != NULL) 
    removeNo(aux2);
  imprime(l);
  destroiLista(l);

  return 0;
}
