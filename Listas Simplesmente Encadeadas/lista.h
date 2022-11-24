#ifndef lista_h
#define lista_h

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
    Dado info;
    Nodo *prox;
};

typedef struct {
    Nodo *inicio;
} ListaSE;


void criaLista(ListaSE *lt);
int incluiNoInicio(ListaSE *lt, Dado d);
void exibe(ListaSE lt);
int quantidadeDeNodos(ListaSE lt);
int estaVazia(ListaSE lt);
int excluiDoInicio(ListaSE *lt, Dado *d);
int incluiNoFim(ListaSE *lt, Dado d);
int excluiDoFim(ListaSE *lt, Dado *d);
int incluiDepois(ListaSE *lt, Dado d, int cod);
int excluiNodo(ListaSE *lt, Dado *d, int cod);
int consultaPorCodigo(ListaSE lt, Dado *d, int cod);
void lerArquivo(ListaSE *lt);
void gravaArquivo(ListaSE lt);

#endif