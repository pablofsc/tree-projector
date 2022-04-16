/*
27/02/2020 - 31/03/2021
*/

// às vezes, a árvore fica muito larga e não cabe na tela - maximize a janela para mitigar o problema

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QTD_NUMEROS 8

struct no {
	struct no *ptr_esq;
	int dado;
	struct no *ptr_dir;
};

typedef struct no No;
typedef No *PtrNo;

void inserir_no(PtrNo *arvptr, int valor) {
	if(*arvptr == NULL) {
		*arvptr = (No*) malloc(sizeof(No));
		
		if(*arvptr != NULL) {
			(*arvptr)->dado = valor;
			(*arvptr)->ptr_esq = NULL;
			(*arvptr)->ptr_dir = NULL;
		}
		else {
			printf("%d não inserido, não há memória disponível.\n", valor);
		}
	}
	else {
		if(valor == (*arvptr)->dado) {
			valor++;
		}
		if(valor < (*arvptr)->dado) {
			inserir_no(&((*arvptr)->ptr_esq), valor);
		}
		else if(valor > (*arvptr)->dado) {
			inserir_no(&((*arvptr)->ptr_dir), valor);
		}
	}
}

void em_ordem(PtrNo arvptr) {
	if(arvptr != NULL) {
		em_ordem(arvptr->ptr_esq);
		printf("%5d", arvptr->dado);
		em_ordem(arvptr->ptr_dir);
	}
}

void pre_ordem(PtrNo arvptr) {
	if(arvptr != NULL) {
		printf("%5d", arvptr->dado);
		pre_ordem(arvptr->ptr_esq);
		pre_ordem(arvptr->ptr_dir);
	}
}

void pos_ordem(PtrNo arvptr) {
	if(arvptr != NULL) {
		pos_ordem(arvptr->ptr_esq);
		pos_ordem(arvptr->ptr_dir);
		printf("%5d", arvptr->dado);
	}
}

#include "projetor.h"

int main() {
	//setlocale(LC_ALL, "portuguese");
	
	int i, item;
	
	PtrNo PtrRaiz = NULL;
	
	srand(time(NULL));
	printf("Numeros que serao inseridos na arvore:\n");
	
	for(i = 1; i <= QTD_NUMEROS; i++) {
		item = rand() % 899 + 100;
		printf("%5d", item);
		inserir_no(&PtrRaiz, item);
	}
	
	printf("\n\nTravessia em pre ordem:\n");
	pre_ordem(PtrRaiz);
	
	printf("\n\nTravessia em ordem:\n");
	em_ordem(PtrRaiz);
	
	printf("\n\nTravessia em pos ordem:\n");
	pos_ordem(PtrRaiz);
	
	printf("\n\nAltura da arvore: %d\n", altura(PtrRaiz) + 1);
	projetar_arvore(PtrRaiz);
	
	printf("\n\nConcluido.\n");
	getchar();
	
	return 0;
}

