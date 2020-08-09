// TAD para Lista Din�mica Encadeada Circular

#ifndef _FILA_H
#define _FILA_H

struct elemento{
	int num;
	struct elemento *prox;
};

struct fila{
    struct elemento *inicio; /*aponta para o elemento do in�cio da fila*/
    struct elemento *fim; /*aponta para o elemento do fim da fila*/
    int tamanho;
};

struct senha{
	char tipo;
    char perfil;
    int senha;
	struct senha *prox;
};

struct atendimento{
    struct senha *inicio; /*aponta para o elemento do in�cio da fila*/
    struct senha *fim; /*aponta para o elemento do fim da fila*/
    int tamanho;
};

// defini��o de tipos abstratos
typedef struct elemento Elemento;
typedef struct fila Fila;
typedef struct senha Senha;
typedef struct atendimento Atendimento;

Fila *criar_fila();
Atendimento *criar_atendimento();

int liberar_fila(Fila *li);
int liberar_atendimento(Atendimento *fi);
void imprimir_senha_por_mesa(Atendimento *fi, int mesa);

// fun��es para obter informa��es da lista
int tamanho_fila(Fila *li);
// fun��es para inser��o de elementos da lista
int enfileirar(Fila *fi, int n);
int enfileirarAtendimento(Atendimento *fi, int n, char type, char profile);

// fun��es para remo��o de elementos da lista
int desenfileirar(Fila *fi);

// fun��es para buscar elementos na lista
int buscar_posicao(Fila *fi, int pos);
int buscar_dado(Fila *fi, int codigo);
int buscarAtendimento(Atendimento *xp, Atendimento *mesa);

int imprimir(Fila *fi);
int imprimirAtendimento(Atendimento *xp);

#endif
