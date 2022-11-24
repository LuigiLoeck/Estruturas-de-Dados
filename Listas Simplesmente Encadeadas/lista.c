#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "lista.h"

void criaLista(ListaSE *lt){
    lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
    Nodo *pAux;

    pAux = (Nodo *) malloc (sizeof(Nodo));

    if(pAux==NULL){
        return FALTOU_MEMORIA;
    } else {
        pAux->info = d;
        pAux->prox = lt->inicio;
        lt->inicio = pAux;
        return SUCESSO;
    }
}


void exibe(ListaSE lt){
    Nodo *pAux;
    pAux = lt.inicio;

    printf("Lista: \n");
    printf("[EndNodo] [cd] [peso] [EndProx]\n");
    while(pAux != NULL){
        printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
        pAux = pAux->prox;
    }
}


int quantidadeDeNodos(ListaSE lt){
    int c=0;
    Nodo *pAux;

    pAux = lt.inicio;
    while(pAux != NULL){
        c++;
        pAux = pAux->prox;
    }
    return c;
}


int estaVazia(ListaSE lt){
    if(lt.inicio==NULL){
        return LISTA_VAZIA;
    } else {
        return 0;
    }
}


int excluiDoInicio(ListaSE *lt, Dado *d){
    Nodo *pAux;
    if(lt->inicio==NULL){
        return LISTA_VAZIA;
    } else {
        *d = lt->inicio->info;
        pAux = lt->inicio;
        lt->inicio = lt->inicio->prox;
        free(pAux);
        return SUCESSO;
    }
}


int incluiNoFim(ListaSE *lt, Dado d){
    Nodo *pAux, *pTemp;
    
    pAux = lt->inicio;
    if(lt->inicio!=NULL){
        while(pAux->prox!=NULL){
            pAux = pAux->prox;
        }
    }
    pTemp = (Nodo *) malloc (sizeof(Nodo));
    if(pTemp==NULL){
        return FALTOU_MEMORIA;
    } else {
        pTemp->info = d;
        (lt->inicio!=NULL)?(pAux->prox = pTemp):(lt->inicio = pTemp);
        pTemp->prox = NULL;
        return SUCESSO; 
    }
}

int excluiDoFim(ListaSE *lt, Dado *d){
    Nodo *pAux, *pTemp;

    if(lt->inicio==NULL){
        return LISTA_VAZIA;
    } else {
        pAux = lt->inicio;
        if(pAux->prox!=NULL){
            while(pAux->prox->prox!=NULL){
            pAux = pAux->prox;
            }
            *d = pAux->prox->info;
            pTemp = pAux->prox;
            pAux->prox = NULL;
            free(pTemp);
        } else {
            *d = pAux->info;
            free(pAux);
            lt->inicio = NULL;
        }
        return SUCESSO;
    }
}


int incluiDepois(ListaSE *lt, Dado d, int cod){
    Nodo *pAux, *pTemp;

    pAux = lt->inicio;
    while(pAux->info.cod!=cod && pAux->prox!=NULL){
        pAux = pAux->prox;
    }
    if (pAux->info.cod!=cod){
        return CODIGO_INEXISTENTE;
    } else {
        pTemp = (Nodo *) malloc (sizeof(Nodo));
        if(pTemp==NULL){
            return FALTOU_MEMORIA;
        } else {
            pTemp->prox = pAux->prox;
            pAux->prox = pTemp;
            pTemp->info = d;
            return SUCESSO;
    }
    }
       
}


int excluiNodo(ListaSE *lt, Dado *d, int cod){
    Nodo *pAux, *pTemp;

    if(lt->inicio==NULL){
        return LISTA_VAZIA;
    } else {
        pAux = lt->inicio;
        while(pAux->prox->info.cod!=cod && pAux->prox->prox!=NULL){
            pAux = pAux->prox;
        }
        if (pAux->prox->info.cod!=cod){
            return CODIGO_INEXISTENTE;
        } else {
           *d = pAux->prox->info;
            pTemp = pAux->prox;
            pAux->prox = pTemp->prox;
            free(pTemp);
            return SUCESSO;
        }
    }
}


int consultaPorCodigo(ListaSE lt, Dado *d, int cod){
    Nodo *pAux, *pTemp;
    
    pAux = lt.inicio;
    while(pAux->info.cod!=cod && pAux->prox!=NULL){
        pAux = pAux->prox;
    }
    if (pAux->info.cod!=cod){
        return CODIGO_INEXISTENTE;
    } else {
        *d = pAux->info;
        return SUCESSO;
    }
}


void lerArquivo(ListaSE *lt){
    FILE *stream;
	char nomeArq[10];
	Dado d;

	strcpy(nomeArq,"dados.txt");

	if((stream=fopen(nomeArq,"r"))==NULL){
		printf("Nao foi possivel abrir %s\n", nomeArq);
	} else {
		criaLista(lt);
	while (fscanf(stream,"%d %f\n",&d.cod,&d.peso)!=EOF){
		incluiNoFim(lt,d);
	}
	fclose(stream);
	printf("Importacao Realizada com Sucesso!\n");
	}
}


void gravaArquivo(ListaSE lt){
    FILE *stream;
    Nodo *pAux;
    pAux = lt.inicio;
	char nomeArq[10];

	strcpy(nomeArq,"dados.txt");

	if((stream=fopen(nomeArq,"w"))==NULL){
		printf("Nao foi possivel abrir %s\n", nomeArq);
	} else {
		while(pAux!=NULL){
		fprintf(stream,"%d %.2f\n",pAux->info.cod,pAux->info.peso);
        pAux = pAux->prox;
		}
	fclose(stream);
	printf("Gravacao Realizada com Sucesso!\n");
	}
}

