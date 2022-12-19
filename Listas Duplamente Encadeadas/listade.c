#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "listade.h"

void criaLista(ListaDE *lt){
     lt->inicio = NULL;
     lt->fim = NULL;
     lt->n = 0;
}

int incluiNoInicio(ListaDE *lt, Dado d){
    Nodo *pAux;
    pAux = (Nodo *) malloc (sizeof (Nodo));
    if (pAux == NULL)
       return(FALTOU_MEMORIA);
    else {
       pAux->info = d;
       pAux->prox = lt->inicio;
       pAux->ant = NULL;
       
       if (lt->n == 0)
          lt->fim = pAux;
       else
          lt->inicio->ant = pAux;  

       lt->inicio = pAux;
       lt->n++;
       return(SUCESSO);
    }
}

void exibe(ListaDE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nExibindo a Lista\n");
     printf("Inicio: %p \n", lt.inicio);
     printf("[End Ant] [cd] [End Nodo] [peso] [End Prox]\n");
     while (pAux != NULL) {
           printf("%p - %3d %p %.2f - %p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
     printf("Fim: %p - N= %d\n", lt.fim, lt.n);
}

int quantidadeDeNodos(ListaDE lt){
   return lt.n;
}

int estaVazia(ListaDE lt){
   if(lt.n==0){
      return 1;
   } else {
      return 0;
   }
}

int excluiDoInicio(ListaDE *lt, Dado *d){
   Nodo *pAux;
    if(lt->n==0){
        return LISTA_VAZIA;
    } else {
        *d = lt->inicio->info;
        pAux = lt->inicio;
        lt->inicio = lt->inicio->prox;
        (lt->n==1)?(lt->fim=NULL):(lt->inicio->ant = NULL);
        lt->n--;
        free(pAux);
        return SUCESSO;
    }
}

int incluiNoFim(ListaDE *lt, Dado d){
   Nodo *pAux;
    pAux = (Nodo *) malloc (sizeof (Nodo));
    if (pAux == NULL){
      return(FALTOU_MEMORIA);
    } else {
       pAux->info = d;
       pAux->ant = lt->fim;
       pAux->prox = NULL;
       
       if (lt->n == 0)
          lt->inicio = pAux;
       else
          lt->fim->prox = pAux;  

       lt->fim = pAux;
       lt->n++;
       return(SUCESSO);
    }
}

int excluiDoFim(ListaDE *lt, Dado *d){
   Nodo *pAux;
    if(lt->n==0){
        return LISTA_VAZIA;
    } else {
        *d = lt->fim->info;
        pAux = lt->fim;
        lt->fim = lt->fim->ant;
        (lt->n==1)?(lt->inicio=NULL):(lt->fim->prox = NULL);
        lt->n--;
        free(pAux);
        return SUCESSO;
    }
}

int incluiDepois(ListaDE *lt, Dado d, int cod){
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
        } 
        if(pAux->prox == NULL){
            incluiNoFim(lt, d);
            return SUCESSO;
        } else {
            pTemp->prox = pAux->prox;
            pTemp->ant = pAux;
            pAux->prox = pTemp;
            pTemp->info = d;
            pTemp->prox->ant = pTemp;
            //lt->n++;
            return SUCESSO;
    }
    }
}

int excluiNodo(ListaDE *lt, Dado *d, int cod){
   Nodo *pAux;

    if(lt->inicio==NULL){
        return LISTA_VAZIA;
    } else {
        pAux = lt->inicio;
        while(pAux->info.cod!=cod && pAux->prox!=NULL){
            pAux = pAux->prox;
        }
        if (pAux->info.cod!=cod){
            return CODIGO_INEXISTENTE;
        } else {
            if(pAux->prox == NULL){
                excluiDoFim(lt,d);
                return SUCESSO;
            }
            if (pAux->ant == NULL){
                excluiDoInicio(lt,d);
                return SUCESSO;
            }
            if(lt->n==1){
                *d = pAux->info;
                lt->inicio=NULL;
                lt->fim=NULL;
                lt->n--;
                free(pAux);
                return SUCESSO;
            } else {
                *d = pAux->info;
                pAux->ant->prox = pAux->prox;
                pAux->prox->ant = pAux->ant;
                lt->n--;
                free(pAux);
                return SUCESSO;
            }
        }
    }
}

int consultaPorCodigo(ListaDE lt, Dado *d, int cod){
    Nodo *pAux;
    
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

void lerArquivo(ListaDE *lt){
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

void gravaArquivo(ListaDE lt){
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
