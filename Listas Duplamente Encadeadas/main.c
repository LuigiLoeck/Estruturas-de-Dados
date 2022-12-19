#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "listade.h"

int main()
{
    int op,cd,peso;
    ListaDE lt;
    Dado d;

    criaLista(&lt);

    do {
        printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
        printf("1. Inclui no Inicio            6. Inclui no Fim            11. Ler Arquivo\n");    
        printf("2. Exibe Lista                 7. Exclui do Fim            12. Gravar Arquivo\n");    
        printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
        printf("4. Exibe Situacao da Lista     9. Inclui Depois           \n");
        printf("Operacao: ");    
        scanf("%d", &op);
        system("cls");
        switch(op){
            case 1:
                printf("Operacao: Inclui no Inicio\n");
                printf("[cd][peso]\n");
                scanf (" %d %f", &d.cod,&d.peso);
                system("cls");
                if (incluiNoInicio(&lt, d)==SUCESSO){
                   printf("Operacao Realizada com Sucesso!\n\n");
                }else{
                   printf("Operacao NAO realizada: Faltou Memoria!\n\n");
                }
                break;

            case 2: 
                printf("Operacao: Exibe Lista\n\n");
                exibe(lt);
                break;

            case 3:
                printf("Operacao: Quantidade de Nodos\n");
                printf("Quantidade de Nodos = %d\n\n", quantidadeDeNodos(lt));
                break;
            
            case 4:
                printf("Operacao: Exibe Situacao da Lista\n");
                if(estaVazia(lt)==1){
                    printf("A lista esta vazia\n\n");
                } else {
                    printf("A lista possui 1 ou mais nodos\n\n");
                }
                break;

            case 5:
                printf("Operacao: Exclui do Inicio\n");
                if (excluiDoInicio(&lt,&d)==LISTA_VAZIA){
					 	printf("ERRO: Lista Vazia!\n\n");
                    }else{
                        printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n\n",d.cod,d.peso);
                    }
                break;

            case 6:
                printf("Operacao: Inclui no Fim\n");
                printf("[cd][peso]\n");
                scanf (" %d %f", &d.cod,&d.peso);
                system("cls");
                if (incluiNoFim(&lt,d)==FALTOU_MEMORIA){
					 	printf("Operacao NAO realizada: Faltou Memoria!\n\n");
                    } else {
					    printf("Dados Incluidos com SUCESSO!\n\n");		
                    }
                break;

            case 7:
                printf("Operacao: Exclui do Fim\n");
                if (excluiDoFim(&lt,&d)==LISTA_VAZIA){
					 	printf("ERRO: Lista Vazia!\n\n");
                    }else{
                        printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n\n",d.cod,d.peso);
                    }
                break;

            case 8:
                printf("Operacao: Consulta por Codigo\n");
                printf("Informe o codigo: ");
				scanf("%d",&cd);
                system("cls");
				if (consultaPorCodigo(lt,&d,cd)==CODIGO_INEXISTENTE){
					printf("ERRO: Codigo Inexistente!\n\n");
                    } else {
                        printf("Dados Encontrados com SUCESSO!\n\n");
                        printf("Dados Encontrados: %d  %.2f\n\n",d.cod,d.peso);
                     }
                break;

            case 9:
                printf("Operacao: Inclui Depois\n");
                printf("Informe o codigo para procura: ");
				scanf("%d",&cd);
                printf("[cd][peso]\n");
                scanf (" %d %f", &d.cod,&d.peso);
                system("cls");
				switch (incluiDepois(&lt,d,cd))
				{
				    case SUCESSO:
						printf("Dados Incluidos com SUCESSO!\n\n");
						break;
					case FALTOU_MEMORIA:
						printf("Operacao NAO realizada: Faltou Memoria!\n\n");
						break;
					case CODIGO_INEXISTENTE:
						printf("ERRO: Codigo Inexistente!\n\n");
						break;
					default:
						break;
					 }
                break;

            case 10:
                printf("Operacao: Exclui Nodo\n");
                printf("Informe o codigo para exclusao: ");
				scanf("%d",&cd);
                system("cls");
				switch (excluiNodo(&lt,&d,cd))
				{
					case SUCESSO:
						printf("Dados Excluidos com SUCESSO!\n");
                        printf("Dados Excluidos: %d  %.2f\n\n",d.cod,d.peso);
						break;
					case LISTA_VAZIA:
						printf("ERRO: Lista Vazia!\n\n");
						break;
					case CODIGO_INEXISTENTE:
						printf("ERRO: Codigo Inexistente!\n\n");
						break;
					default:
						break;
					}
                break;

            case 11 : 
                printf("Operacao: Ler Arquivo\n");
				lerArquivo(&lt);
				break;

			case 12 : 
                printf("Operacao: Gravar Arquivo\n");
				gravaArquivo(lt);
				break;

            default:
                break;
      }
      if(op!=2){
      exibe(lt);            
      }
    } while (op!=0); 

  return(0);
}
