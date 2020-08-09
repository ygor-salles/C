ARVORE RUBRO-NEGRA

COMPLEXIDADE O(LOG N)

*todo no da minha arvore � vermalho ou preto

*toda raiz e nulls s�o pretos

*se um n� � vermelho ent�o seus filhos s�o pretos

*rebalancemenato local, afeta a insere��o e remo��o

*uso de rota��es e ajustes de cores

*log n

*compara��o com avl

*na pratica alv mais rapida para busca, porem mais lenta na iser��o e remo��o. AVL 
� mais balanceada q rubro negraacelera na busca, pois para inserir e remover na avl eu gasto mais rota��es q na rubro negra 



typedef enum Cor{VERMELHO, PRETO};

typedef struct No *pno;

typedef struct NO{
    int chave;
    Cor cor;
    pno *esq, pno *dir;
}No;

int ehVermelho(pno x)
{
    if (x==NULL) return 0;
    return x->cor;
}

int ehPreto(pno x)
{
    if(x==NULL) return 1;
    return x->cor;
}

pno rotaciona_esquerda(pno raiz)
{
    pno aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return aux;
}

pno rotaciona_direita(pno raiz)
{
    pno aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return aux;
}

void sobe_vermelho(pno raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

pno inserir_recursivo(pno raiz, int chave)
{
    pno novo;
    if (raiz == NULL){
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->cor = VERMELHO;
        return novo;
    }
    
    if (chave < raiz->chave)
        raiz->esq - inserir_recursivo(raiz->esq, chave);
    else
        raiz->dir = inserir_recursivo(raiz->dir, chave);
    
    //CORRRIGI ARVORE
    if(ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);
    
    return raiz;
}

pno inserir(pno raiz, int chave)
{
    raiz = inserir_recursivo(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}