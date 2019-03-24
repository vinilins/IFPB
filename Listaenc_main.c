#include <stdio.h>
#include <listaenc.h>

int main(void) {
  TListaenc * lista;
  criarLista(&lista);
  int vazia = listaVazia(lista);
  int tamanho = tamanhoLista(lista);
  inserirElemento(&lista,55,1);
  inserirElemento(&lista,12,2);
  inserirElemento(&lista,558,3);
  inserirElemento(&lista,8,3);
  exibirLista(lista);
  int elemento = obterPosicaoDoElemento(lista,558);
  printf("elemento 558: %d\n",elemento);
  int tam = tamanhoLista(lista);
  printf("TAMANHO DA LISTA: %d\n",tam);
  removerElementoDaPosicao(&lista,1);
  exibirLista(lista);
  inserirNaPrimeira(&lista,1234);
  inserirNaPrimeira(&lista,34);
  exibirLista(lista);
  inserirNaUltima(lista,219);
  inserirNaUltima(lista,219123);
  exibirLista(lista);
  modificarElementoNaPosicao(&lista,777,1);
  exibirLista(lista);
  removerPrimeiroElemento(&lista);
  exibirLista(lista);
  removerUltimoElemento(lista);
  exibirLista(lista);
  removerUltimoElemento(lista);
  exibirLista(lista);
  removerElemento(&lista,1234);
  exibirLista(lista);
}
