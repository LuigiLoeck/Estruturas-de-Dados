#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "lista.h"

int main() {
	ListaCF lista;
	Dado dado;
	int cod,aux;

	criaLista(&lista);
	do {
        
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n");	
		printf("11-Ler dados de arquivo texto\n");	
		printf("12-Gravar dados em arquivo texto\n\n");	
		printf("Informe a operacao: ");
		scanf("%d",&cod);
        system("cls");
		
		switch (cod)
			{
			case 1 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("\nInforme o peso: ");
					 scanf("%f",&dado.peso);
                     system("cls");
					 if (incluiNoFim(&lista,dado)==LISTA_CHEIA){
					 	printf("ERRO: Lista Cheia!\n");
                     } else {
					    printf("Dados Incluidos com SUCESSO!\n");		
                     }
					 break;


			case 2 : exibe(lista);
					break;


			case 3 : printf("A lista possui %d nodos\n\n",quantidadeDeNodos(&lista));
                    break;


			case 4 : if(estaCheia(&lista)==1){
                printf("A lista esta cheia\n\n");
            } else if(estaVazia(&lista)==1){
                printf("A lista esta vazia\n\n");
            } else {
                printf("A lista possui 1 ou mais nodos\n\n");
            }
                    break;


			case 5 :if (excluiDoFim(&lista,&dado)==LISTA_VAZIA){
					 	printf("ERRO: Lista Vazia!\n");
                    }else{
					    printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n",dado.cod,dado.peso);
                    }
                    break;


			case 6 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("\nInforme o peso: ");
					 scanf("%f",&dado.peso);
                     system("cls");
					 if (incluiNoInicio(&lista,dado)==LISTA_CHEIA){
					 	printf("ERRO: Lista Cheia!\n");
                     } else {
					    printf("Dados Incluidos com SUCESSO!\n");		
                     }
                    break;


			case 7 : if (excluiDoInicio(&lista,&dado)==LISTA_VAZIA){
					 	printf("ERRO: Lista Vazia!\n");
                    }else{
                        printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n",dado.cod,dado.peso);
                    }
                    break;


			case 8 : printf("Informe o codigo: ");
					 scanf("%d",&aux);
                     system("cls");
					 if (consultaPorCodigo(&lista,&dado,aux)==CODIGO_INEXISTENTE){
					 	printf("ERRO: Codigo Inexistente!\n");
                     } else {
                        printf("Dados Encontrados com SUCESSO!\n");
                        printf("Dados Encontrados: %d  %.2f\n",dado.cod,dado.peso);
                     }
                    break;


			case 9 : printf("Informe o codigo para procura: ");
					 scanf("%d",&aux);
                     printf("Informe o codigo a ser incluido: ");
					 scanf("%d",&dado.cod);
					 printf("\nInforme o peso a ser incluido: ");
					 scanf("%f",&dado.peso);
                     system("cls");
					 switch (incluiAntes(&lista,dado,aux))
					 {
					 case SUCESSO:
						printf("Dados Incluidos com SUCESSO!\n");
						break;
					 case LISTA_CHEIA:
						printf("ERRO: Lista Cheia!\n");
						break;
					 case CODIGO_INEXISTENTE:
						printf("ERRO: Codigo Inexistente!\n");
						break;
					 default:
						break;
					 }
                    break;


			case 10 : printf("Informe o codigo para exclusao: ");
					 scanf("%d",&aux);
                     system("cls");
					 switch (excluiNodo(&lista,&dado,aux))
					 {
					 case SUCESSO:
						printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n",dado.cod,dado.peso);
						break;
					 case LISTA_VAZIA:
						printf("ERRO: Lista Vazia!\n");
						break;
					 case CODIGO_INEXISTENTE:
						printf("ERRO: Codigo Inexistente!\n");
						break;
					 default:
						break;
					 }
                    break;

			case 11 : system("cls");
					lerArquivo(&lista);
					break;

			case 12 : system("cls");
					gravaArquivo(lista);
					break;
			}
		    if (cod != 2){
			    exibe(lista);
            }

	} while (cod !=0);

	return 0;
}