#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  char nucleotideo;
  struct no* proximo;
}No;

typedef struct fila{
  No* inicio;
  No* fim;
}Fila;

typedef struct pilha{
  No* topo;
}Pilha;

void inicializaFila(Fila* fila){
  fila->inicio = NULL;
  fila->fim = NULL;
}

void inicializaPilha(Pilha* pilha){
  pilha->topo = NULL;
}

void inserirFila(Fila* fila, char caracter){
  No* novo = (No*)malloc(sizeof(No));

  if(novo){
    novo->nucleotideo = caracter;
    novo->proximo = NULL;
  }

  if(fila->fim == NULL){
    fila->inicio = novo;
    fila->fim = novo;
  }
  else{
    fila->fim->proximo = novo;
    fila->fim = novo;
  }
}

void inserirPilha(Pilha* pilha, char caracter) {
  No* novo = (No*)malloc(sizeof(No));

  if(novo){
    novo->nucleotideo = caracter;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
  }
}

void converterDNA(Fila* fila, Pilha* pilha){
  No* no = fila->inicio;

  while (no != NULL){
    switch (no->nucleotideo){
      case 'A':{
        inserirPilha(pilha, 'T');
        break;
      }
      case 'T':{
        inserirPilha(pilha, 'A');
        break;
      }
      case 'C':{
        inserirPilha(pilha, 'G');
        break;
      }  
      case 'G':{
        inserirPilha(pilha, 'C');
        break;
      } 
    }
    no = no->proximo;
  }  
}

void imprimirFila(Fila* fila){
  No* no = fila->inicio;

  if(no == NULL){
    printf("A Fila esta vazia!\n");
  } 
  else{
    printf("\nFila: ");
    while (no){
      printf("%c", no->nucleotideo);
      no = no->proximo;
    }
    printf("\n\n");
  } 
}

void imprimirPilha(Pilha* pilha){
  No* no = pilha->topo;

  if(no == NULL){
    printf("A Pilha esta vazia!\n");
  }
  else{
    printf("Pilha: ");
    while (no) {
      printf("%c", no->nucleotideo);
      no = no->proximo;
    }
    printf("\n\n");
  }
}

int main() {

  Fila fila;
  Pilha pilha;

  inicializaFila(&fila);
  inicializaPilha(&pilha);

  char nucleotideo;
  int i = 0;
  
  printf("Digite a sequencia de nucleotideos:\n");

  while(i <= 100 && (nucleotideo = getchar()) != '\n'){
    if(nucleotideo != 'A' && nucleotideo != 'C' && nucleotideo != 'T' && nucleotideo != 'G'){
      printf("Entrada invalida!\nA sequencia deve conter os caracteres (ACTG) em sequencia!\n");
      return 1;
    }
    else{
      inserirFila(&fila, nucleotideo); 
    } 
    i++;
  }

  converterDNA(&fila, &pilha);
  imprimirFila(&fila);
  imprimirPilha(&pilha);
  return 0;
}