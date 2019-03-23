#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int lista[100];
  int posUltimo;
}TListaseq;

TListaseq* criarLista(){
  TListaseq *lista = NULL;
  lista = (TListaseq*)malloc(sizeof(TListaseq));
  lista->posUltimo = 0;
  return lista;
}

int listaVazia(TListaseq* lista){
  if(lista->posUltimo==0) return 1;
  return 0;
  }

int listaCheia(TListaseq* lista){
  if(lista->posUltimo==100) return 1;
  return 0;
}

int tamanhoLista(TListaseq* lista){
  return lista->posUltimo;
}

int exibirLista(TListaseq* lista){
  int vazia = listaVazia(lista);
  if(vazia==1) {printf("A lista está vazia.\n\n"); return 0;}
  int i; 
  printf("Lista: [ ");
  for(i=0;i<lista->posUltimo;i++){
    printf("%d ",lista->lista[i]);
  }
  printf("]\n");
  printf("Tamanho da lista: %d\n\n",lista->posUltimo);
  return 1;
}

int inserirElePosicao(TListaseq* lista, int elemento ,int posicao){
  int cheia = listaCheia(lista), vazia = listaVazia(lista);
  if(posicao<=0) {printf("Posição inválida.\n\n"); return 0;}
  if(cheia==1){
    printf("A lista está cheia. Operação inválida.\n\n"); 
    return 0;}
  if(posicao>lista->posUltimo+1) {printf("Posição inválida, pois a lista tem %d elementos.\n\n",lista->posUltimo); return 0;}
  int i,numero,numero2;
  numero = lista->lista[posicao-1];
  lista->lista[posicao-1] = elemento;
  for(i=posicao;i<lista->posUltimo+1;i++){
    numero2 = lista->lista[i];
    lista->lista[i] = numero;
    numero = numero2;
  }
  lista->posUltimo+=1;
  printf("Operação realizada.\n\n");
  return 1;
}

int removerNaPosicao(TListaseq*lista,int posicao){
  int vazia = listaVazia(lista);
  if(vazia==1) {printf("A lista está vazia. Posição inválida.\n"); return 0;}
  if(posicao>lista->posUltimo) {printf("Posição inválida, pois a lista tem %d elementos.\n\n",lista->posUltimo); return 0;}
  if(posicao<=0) {printf("Posição inválida.\n\n"); return 0;}
  int i;
  for(i=posicao-1;i<lista->posUltimo-1;i++){
    lista->lista[i] = lista->lista[i+1];
  }
  lista->posUltimo-=1;
  printf("Operação realizada.\n\n");
  return 1;
}

int exibirElemento(TListaseq *lista,int posicao){
  int vazia = listaVazia(lista);
  if(vazia==1) {printf("A lista está vazia. Posição inválida.\n"); return 0;}
  if(posicao>lista->posUltimo) {printf("Posição inválida, pois a lista tem %d elementos.\n\n",lista->posUltimo); return 0;}
  if(posicao<=0) {printf("Posição inválida.\n\n"); return 0;}
  printf("Elemento da posição %d: %d\n\n",posicao,lista->lista[posicao-1]);
  return 1;
}

int exibirPosicao(TListaseq*lista,int elemento){
  int vazia = listaVazia(lista);
  if(vazia==1) {printf("A lista está vazia.\n\n"); return 0;}
  int i,cont=0;
  for(i=0;i<lista->posUltimo;i++){
    if(lista->lista[i]==elemento){
      printf("O elemento %d está na posição: %d\n",elemento,i+1);
      cont+=1;
    }
  }
  if(cont==0) printf("O elemento %d não está na lista.\n",elemento);
  printf("\n");
  return 1;
}

int esvaziarLista(TListaseq*lista){
  int vazia = listaVazia(lista);
  if(vazia==1) {printf("A lista já está vazia.\n\n"); 
  printf("Deseja mesmo esvaziar a lista?\n1 - SIM\n2 - NÃO\n");}
  int num;
  scanf("%d",&num);
  if(num==2) {printf("Okay!\n\n"); return 0;}
  else if(num==1){
    lista->posUltimo = 0;
    printf("Lista esvaziada!\n\n");
    return 1;
  }
  return 0;
}

int inserirPrimeiraPos(TListaseq*lista,int elemento){
  int cheia = listaCheia(lista);
  if(cheia==1){
      printf("A lista está cheia. Operação inválida.\n\n"); 
      return 0;}
  int num,num2,i;
  num = lista->lista[0];
  lista->lista[0] = elemento;
  for(i=1;i<lista->posUltimo+1;i++){
    num2 = lista->lista[i];
    lista->lista[i] = num;
    num = num2;
  }
  lista->posUltimo+=1;
  return 1;
}

int inserirUltimaPos(TListaseq*lista,int elemento){
  int cheia = listaCheia(lista),vazia = listaVazia(lista);
  if(cheia==1){
      printf("A lista está cheia. Operação inválida.\n\n"); 
      return 0;}
  if(vazia==1){lista->lista[0] = elemento; lista->posUltimo+=1; return 1;}
  lista->lista[lista->posUltimo] = elemento;
  lista->posUltimo+=1;
  return 1;
}
