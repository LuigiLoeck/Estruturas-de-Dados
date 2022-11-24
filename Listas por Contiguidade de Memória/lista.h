#ifndef lista_h
#define lista_h

#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define POSICAO_INVALIDA 3
#define CODIGO_INEXISTENTE 4

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct
{
  int n;
  Dado v[MAX_NODOS];
} ListaCF;

void criaLista(ListaCF *lt);
int incluiNoFim(ListaCF *lt, Dado d);
void exibe(ListaCF lt);
int quantidadeDeNodos(ListaCF *lt);
int estaCheia(ListaCF *lt);
int estaVazia(ListaCF *lt);
int excluiDoFim(ListaCF *lt, Dado *d);
int incluiNoInicio(ListaCF *lt, Dado d);
int excluiDoInicio(ListaCF *lt, Dado *d);
int consultaPorCodigo(ListaCF *lt, Dado *d, int cod);
int incluiAntes(ListaCF *lt, Dado d, int cod);
int excluiNodo(ListaCF *lt, Dado *d, int cod);
void lerArquivo(ListaCF *lt);
void gravaArquivo(ListaCF lt);


#endif