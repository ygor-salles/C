#ifndef _LISTA_DE
#define _LISTA_DE

typedef struct elemento* Lista;

Lista* criar_lista();
void liberar_lista(Lista *li);

int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);

int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int dado);

int buscar_lista_posicao(Lista *li, int pos);
int buscar_lista_dado(Lista *li, int dado);


#endif