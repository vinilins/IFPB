#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
  int dado;
  struct no *prox;
}TListaenc;

void criarLista(TListaenc **lista){
  *lista = NULL;
}

int listaVazia(TListaenc *lista){
  if(lista==NULL) return 1;
  return 0;
}

int tamanhoLista(TListaenc*lista){
  int cont = 0;
  while(lista!=NULL){
    lista = lista->prox;
    cont+=1;
  }
  return cont;
}

int inserirElemento(TListaenc**lista,int elemento,int posicao){
  int tamanho = tamanhoLista(*lista);
  int vazia = listaVazia(*lista);
  TListaenc *novo=NULL, *aux=NULL;
  if(vazia==1 && posicao!=1){
    printf("A lista está vazia e a sua posição foi inválida. Insira na primeira posição!\n\n");
    return 0;
  }
  else if(vazia==1 && posicao==1){
    novo = (TListaenc*)malloc(sizeof(TListaenc));
    novo->dado = elemento;
    novo->prox = NULL;
    *lista = novo;
    return 1;
  }
  else if(vazia==0 && posicao==1){
    novo = (TListaenc*)malloc(sizeof(TListaenc));
    novo->dado = elemento;
    novo->prox = *lista;
    *lista = novo;
    return 1;
  }
  else if(vazia==0 && posicao>1){
    int cont=1;
    if(1<posicao<=tamanho+1){
      aux = *lista;
      while((cont<posicao-1) && (aux!=NULL)){
        aux = aux->prox;
        cont++;
      }
      if(aux==NULL){
        printf("Posição maior do que a possível que é: %d!\n",cont);
        return 0;
      }
      novo = (TListaenc*)malloc(sizeof(TListaenc));
      novo->dado = elemento;
      novo->prox = aux->prox;
      aux->prox = novo;
      return 1; 
    }
  return 0;
  }
  printf("Posição inválida\n");
  return 0;
}

void exibirLista(TListaenc*lista){
  int vazia = listaVazia(lista);
  if(vazia==1){printf("Lista Vazia!\n");}
  else{
    printf("[ ");
    while(lista!=NULL){
      printf("%d ",lista->dado);
      lista=lista->prox;
    }
    printf("]\n");
  }
}

int obterElementoDaPosicao(TListaenc*lista,int posicao){
  if(posicao<=0){
    printf("Posição inválida!\n");
    return 0;
  }
  TListaenc * aux = NULL;
  int cont=1;
  aux = lista;
  while((cont!=posicao) && (aux!=NULL)){
    aux=aux->prox;
    cont++;
  }
  if(aux==NULL){
    printf("Não existe elemento nessa posição!\n");
    return 0;
  }
  return aux->dado;
}

int obterPosicaoDoElemento(TListaenc* lista,int elemento){
  int cont = 1,cont_real = 0;
  TListaenc *aux=NULL;
  aux = lista;
  while(aux!=NULL){
    if(aux->dado==elemento){
      printf("Elemento %d na %dº posição!\n",elemento,cont);
      if(cont_real==0){
        cont_real = cont;
      }
    }
    aux = aux->prox;
    cont++;
  }
  if(cont_real==0){
    printf("Esse elemento não está na lista!\n");
  }
  return cont_real;
}

int removerElementoDaPosicao(TListaenc**lista,int posicao){
    int vazia = listaVazia(*lista);
    if(vazia==1){
      printf("A lista está vazia!\n");
      return 0;
    }
    else if(posicao<=0){
      printf("Posição inválida!\n");
      return 0;
    }
    int tam = tamanhoLista(*lista);
    if(posicao>tam){
      printf("Posição maior que a lista!\n");
      return 0;
    }
    if(posicao==1){
      TListaenc *aux=NULL;
      TListaenc *aux2=NULL;
      aux = *lista;
      aux2 = *lista;
      aux = aux->prox;
      *lista = aux;
      free(aux2);
      return 1;
    }
    int cont;
    TListaenc *aux=NULL,*aux2=NULL;
    cont=1;
    aux = *lista;
    while((cont<posicao-1) && (aux!=NULL)){
      aux = aux->prox;
      cont++;
    }
    aux2 = aux;
    aux = aux->prox;
    free(aux2->prox);
    aux2->prox = aux->prox;
    return 1;
}

int inserirNaPrimeira(TListaenc**lista,int elemento){
  TListaenc *novo=NULL;
  TListaenc *aux=NULL;
  novo = (TListaenc*)malloc(sizeof(TListaenc));
  aux = *lista;
  novo->dado = elemento;
  novo->prox = aux;
  *lista = novo;
  return 1;
}

int inserirNaUltima(TListaenc*lista,int elemento){
  int vazia = listaVazia(lista);
  if(vazia==1){
    printf("A lista está vazia. Insira elementos nela!\n");
    return 0;
  }
  TListaenc *novo=NULL;
  TListaenc *aux=NULL;
  novo = (TListaenc*)malloc(sizeof(TListaenc));
  novo->dado = elemento;
  aux = lista;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox=novo;
  novo->prox=NULL;
  return 1;

}

int modificarElementoNaPosicao(TListaenc**lista, int elemento, int posicao){
  TListaenc *aux=NULL;
  aux = *lista;
  int vazia = listaVazia(*lista);
  int tamanho = tamanhoLista(*lista);
  if(posicao>tamanho){
    printf("Posição escolhida maior que o tamanho da lista(%d)!\n",tamanho);
    return 0;
  }
  else if(vazia==1){
    printf("A lista está vazia!\n");
    return 0;
  }
  else if(posicao==1){
    aux->dado = elemento;
    return 1;
  }
  else if(posicao<=0){
    printf("Posição inválida!\n");
    return 0;
  }
  int cont=1;
  while(cont<posicao){
    aux = aux->prox;
    cont++;
  }
  aux->dado = elemento;
  return 1;
}

int removerPrimeiroElemento(TListaenc**lista){
  int vazia = listaVazia(*lista);
  if(vazia==1){
    printf("Lista Vazia!\n");
    return 0;
  }
  TListaenc *aux=NULL;
  TListaenc *aux2=NULL;
  aux = *lista;
  aux2 = *lista;
  aux = aux->prox;
  *lista = aux;
  free(aux2);
  return 1;
}

int removerUltimoElemento(TListaenc*lista){
  int vazia=listaVazia(lista);
  if(vazia==1){
    printf("A lista está vazia!\n");
    return 0;
  }
  TListaenc*aux=NULL;
  TListaenc*aux2=NULL;
  aux = lista;
  int tam = tamanhoLista(lista),cont=1;
  while(cont<tam-1){
    aux = aux->prox;
    cont++;
  }
  aux2 = aux->prox;
  aux->prox = NULL;
  free(aux2);
  return 1;
}

int removerElemento(TListaenc**lista,int elemento){
  TListaenc*aux=NULL;
  aux = *lista;
  if(aux->dado==elemento){
    TListaenc *aux=NULL;
    TListaenc *aux2=NULL;
    aux = *lista;
    aux2 = *lista;
    aux = aux->prox;
    *lista = aux;
    free(aux2);
    return 1;
    }
  int cont=1,cont2=0;
  TListaenc *aux2=NULL;
  TListaenc *aux3=NULL;
  int tam = tamanhoLista(*lista);
  while((aux!=NULL) && (cont<tam)){
    aux2 = aux;
    aux = aux->prox;
    if(aux->dado==elemento){
        aux3 = aux->prox;
        free(aux);
        aux2->prox = aux3;
        cont2=1;
        break;
    }
    cont++;
  }
  if(cont2==0){
    printf("O número não está na lista!\n");
    return 0;
  }
  return 1;
}
