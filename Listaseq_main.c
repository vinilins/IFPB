#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <listaseq.h>
int main(){
  TListaseq *listaseq = NULL;
  listaseq = criarLista();
  int num,elemento,posicao;
  while(1){
  printf("Editor de Listas\n----------------------------------\n1 - Exibir Lista\n2 - Inserir Elemento na Posição\n3 - Inserir na Primeira Posição\n4 - Inserir na Última Posição\n5 - Exibir Elemento da Posição\n6 - Exibir Posição do Elemento\n7 - Esvaziar Lista\n8 - Remover da Posição\n9 - Sair\n\nDigite sua Opção: ");
  scanf("%d",&num);
  printf("\n\n");
  if(num==1) exibirLista(listaseq);
  else if(num==2) {
    printf("Digite o Elemento: ");
    scanf("%d",&elemento);
    printf("Digite a Posição: ");
    scanf("%d",&posicao);
    inserirElePosicao(listaseq,elemento,posicao);
    }
  else if(num==4){
    printf("Digite o Elemento: ");
    scanf("%d",&elemento);
    printf("\n");
    inserirUltimaPos(listaseq,elemento);
  }
  else if(num==3){
    printf("Digite o Elemento: ");
    scanf("%d",&elemento);
    printf("\n");
    inserirPrimeiraPos(listaseq,elemento);
  }
  else if(num==8) {
    int vazia = listaVazia(listaseq);
    if(vazia==1) {printf("Não há como remover pois a lista está vazia.\n\n"); continue;}
    printf("Digite a Posição: ");
    scanf("%d",&posicao);
    removerNaPosicao(listaseq,posicao);
  }
  else if(num==5) {
    int vazia = listaVazia(listaseq);
    if(vazia==1) {printf("Não há como exibir pois a lista está vazia.\n\n"); continue;}
    printf("Digite a Posição: ");
    scanf("%d",&posicao);
    exibirElemento(listaseq,posicao);
  }
  else if(num==6) {
    int vazia = listaVazia(listaseq);
    if(vazia==1) {printf("Não há como exibir pois a lista está vazia.\n\n"); continue;}
    printf("Digite o Elemento: ");
    scanf("%d",&elemento);
    exibirPosicao(listaseq,elemento);
  }
  else if(num==7) {
    int vazia = listaVazia(listaseq);
    if(vazia==1) {printf("Não há como esvaziar pois a lista está vazia.\n\n"); continue;}
    esvaziarLista(listaseq);
  }
  else if(num==9){
    printf("Okay, até mais!\n");
    break;
  }
  }
  return 0;
}
