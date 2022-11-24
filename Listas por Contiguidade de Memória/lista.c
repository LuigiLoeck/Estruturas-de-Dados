#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "lista.h"

void criaLista(ListaCF *lt){
    lt-> n = 0;
}


int incluiNoFim(ListaCF *lt, Dado d){
    if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;
	else {
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}
}


void exibe(ListaCF lt){
	int i;
	
	printf("-------------\n");
	printf("Lista:\n");
	for (i=0; i<lt.n; i++) 
		printf("   %d %.2f\n", lt.v[i].cod,lt.v[i].peso);
	printf("-------------\n\n");
}


int quantidadeDeNodos(ListaCF *lt){
	return lt->n;
}


int estaCheia(ListaCF *lt){
if (lt->n==MAX_NODOS){
	return 1;
} else {
	return 0;
}
}


int estaVazia(ListaCF *lt){
if (lt->n==0){
	return 1;
} else {
	return 0;
}
}


int excluiDoFim(ListaCF *lt, Dado *d){
	if (lt->n==0){
		return LISTA_VAZIA;
	} else {
		lt->n--;
		*d = lt->v[lt->n];
		return SUCESSO;
	}
	
}


int incluiNoInicio(ListaCF *lt, Dado d){
	int i;
	
	if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;
	else {
		for (i=lt->n; i>0; i--){
			lt->v[i] = lt->v[i-1];
		}
		lt->v[0] = d;
		lt->n++;
		return SUCESSO;
	}

}


int excluiDoInicio(ListaCF *lt, Dado *d){
	int i;

	if (lt->n==0){
		return LISTA_VAZIA;
	} else {
		*d = lt->v[0];
		for (i=1; i<lt->n; i++){
			lt->v[i-1] = lt->v[i];
		}
		lt->n--;
		return SUCESSO;
	}

}


int consultaPorCodigo(ListaCF *lt, Dado *d, int cod){
	int i;

	for (i=1; i<lt->n; i++){
		if (lt->v[i-1].cod==cod){
			*d=lt->v[i-1];
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}


int incluiAntes(ListaCF *lt, Dado d, int cod){
	int i,j;

	if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;
	else {
		for (i=1; i<=lt->n; i++){
		if (lt->v[i-1].cod==cod){
			for (j=lt->n; j>=i-1; j--){
			lt->v[j] = lt->v[j-1];
			}
			lt->v[i-1]=d;
			lt->n++;
			return SUCESSO;
			}
		}
	return CODIGO_INEXISTENTE;
	}

}


int excluiNodo(ListaCF *lt, Dado *d, int cod){
	int i,j;

	if (lt->n==0){
		return LISTA_VAZIA;
	} else {
		for (i=1; i<=lt->n; i++){
		if (lt->v[i-1].cod==cod){
			*d=lt->v[i-1];
			for (j=i; j<lt->n; j++){
			lt->v[j-1] = lt->v[j];
			}
			lt->n--;
			return SUCESSO;
			}
		}
		return CODIGO_INEXISTENTE;
	}

}

void lerArquivo(ListaCF *lt){
	FILE *stream;
	char nomeArq[10];
	Dado dado;

	strcpy(nomeArq,"dados.txt");

	if((stream=fopen(nomeArq,"r"))==NULL){
		printf("Nao foi possivel abrir %s\n", nomeArq);
	} else {
		criaLista(lt);
	while (fscanf(stream,"%d %f\n",&dado.cod,&dado.peso)!=EOF){
		incluiNoFim(lt,dado);
	}
	fclose(stream);
	printf("Importacao Realizada com Sucesso!\n");
	}
}

void gravaArquivo(ListaCF lt){
	FILE *stream;
	char nomeArq[10];
	int i;

	strcpy(nomeArq,"dados.txt");

	if((stream=fopen(nomeArq,"w"))==NULL){
		printf("Nao foi possivel abrir %s\n", nomeArq);
	} else {
		for(i=0;i<lt.n;i++){
		fprintf(stream,"%d %.2f\n",lt.v[i].cod,lt.v[i].peso);
		}
	fclose(stream);
	printf("Gravacao Realizada com Sucesso!\n");
	}
}