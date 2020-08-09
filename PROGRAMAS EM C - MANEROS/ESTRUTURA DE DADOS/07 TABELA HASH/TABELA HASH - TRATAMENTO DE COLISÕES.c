#include<stdio.h>
#include<stdlib.h>

/*
    Ygor Salles Aniceto Carvalho - 2017014382
    Bruno Felipe de Moraes - 2017009453
    Thiago Geovane dos Santos - 2016014154
*/

struct Registro
{
    int chave;
    char string[30];
};
typedef struct Registro Registro;

struct Tabela
{
    int qtd, TABLE_SIZE;
    //PONTEIRO P/ PONTEIRO,
    //PERMITE CRIAR UM VETOR ONDE CADA POSIÇÃO DO VETOR EU POSSA GUARDAR UM ENDEREÇO DE UM ELENTO ARMAZENADO NA TABELA
    Registro **itens;
};
typedef struct Tabela Tabela;

Tabela* cria_tabela(int TABLE_SIZE);
void esvazia_tabela (Tabela *hash);
int insere_hash (Tabela *hash, Registro reg);
int chave_divisao (int chave, int TABLE_SIZE);
int sondagem_linear(int pos, int i, int TABLE_SIZE);
int consulta_hash (Tabela *hash, int chave, Registro *reg);
int remover (Tabela *hash, int chave);

int main (int argv, char *argc[])
{
    Registro reg;
    Tabela *hash = cria_tabela(101);
    int chave, op, x;

    do {
        printf("\n MENU DE OPCOES: ");
        printf("\n1 - Inserir");
        printf("\n2 - Consultar");
        printf("\n3 - Remover");
        printf("\n4 - Sair");
        printf("\nOpcao ..: "); scanf("%d",&op);

        switch (op){
            case 1:
                printf("\nCHAVE: "); scanf("%d",&reg.chave);
                printf("STRING: "); scanf(" %s",reg.string);
                x=insere_hash(hash, reg);
                if (x==1) printf("Inserido com sucesso!");
                break;

            case 2:
                printf("\nCHAVE: "); scanf("%d",&chave);
                x = consulta_hash(hash, chave, &reg);
                if (x==1)
                    printf("\n %d %s",reg.chave, reg.string);
                break;

            case 3:
                printf("\nCHAVE: "); scanf("%d",&chave);
                x = remover (hash, chave);
                if (x==1) printf("\nRemovido com sucesso!...");
                break;

            case 4:
                esvazia_tabela(hash);
                printf("\nTABELA ESVAZIADA...");
                printf("\n\nFinalizando Programa...");
                break;

            default:
                printf("\nOPCAO INVALIDA!");
                break;
        }
        printf ("\n\n");

    } while (op != 4);

    return 0;
}

Tabela* cria_tabela(int TABLE_SIZE)
{
    //CRIAR STRUCT ASSOCIADO AO PONTEIRO TABELA
    Tabela *hash = (Tabela*) malloc(sizeof(Tabela));
    if (hash == NULL) return 0;

    else{
        int i;
        hash->TABLE_SIZE = TABLE_SIZE; //ASSOCIAR TAMANHO DA TABELA COM O VALOR PASSADO
        hash->itens = (Registro**) //INICIALIZA O PONTEIRO ITENS
            malloc(TABLE_SIZE * sizeof(Registro*)); //CRIAR VETOR DE TAMANHO "REGISTRO"

        //SE OCORREU ERRO NA ALOCAÇÃO, LIBERAR PRIMEIO PONTEIRO E RETORNAR NULL
        if (hash->itens == NULL){
            free(hash);
            return NULL;
        }

        //SE ALOCAÇÃO OK, INICILIZA TODA A POSIÇÃO DO ARRAY COM NULL
        hash->qtd = 0;
        for(i=0; i<hash->TABLE_SIZE; i++)
            hash->itens[i] = NULL;
    }
    return hash;
}

void esvazia_tabela (Tabela *hash)
{
    if (hash != NULL) {
        int i;
        //LIBERAR CADA ITEM DA TABELA
        for (i=0; i< hash->TABLE_SIZE; i++){
            if (hash->itens[i] != NULL)
                free(hash->itens[i]);
        }

        //LIBERAR O VETOR DA TABELA E, A ESTRUTURA DEFINIDA
        free(hash->itens);
        free(hash);
    }
}

int insere_hash (Tabela *hash, Registro reg)
{
    if (hash == NULL || hash->qtd == hash->TABLE_SIZE) return 0;

    int chave = reg.chave;
    //CALCULAR A CHAVE DA DIVISÃO
    int i, newpos;
    int pos = chave_divisao(chave, hash->TABLE_SIZE);

    for (i=0; i<hash->TABLE_SIZE; i++){
        newpos = sondagem_linear(pos, i, hash->TABLE_SIZE);
        if (hash->itens[newpos] == NULL){
            Registro *no;
            no = (Registro*)
                malloc(sizeof(Registro));
            if (no==NULL) return 0;
            *no = reg;
            hash->itens[newpos] = no;
            hash->qtd++;
            return 1;
        }
    }
    return 0;
}

int sondagem_linear(int pos, int i, int TABLE_SIZE)
{
    return ((pos+1) & 0x7FFFFFFF) % TABLE_SIZE;
}

// MÉTODO RESTO DA DIVISÃO
int chave_divisao (int chave, int TABLE_SIZE)
{
    //E BIT-A-BIT, ELIMINA O BIT DE SINAL DO VALOR CHAVE, EVITAR OVERFLOW E NUMEROS NEGATIVOS
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int consulta_hash (Tabela *hash, int chave, Registro *reg)
{
    if (hash == NULL) return 0;

    //CALCULAR A CHAVE DA DIVISÃO
    int i, newpos;
    int pos = chave_divisao(chave, hash->TABLE_SIZE);
    for (i=0; i<hash->TABLE_SIZE; i++){
        newpos = sondagem_linear(pos, i, hash->TABLE_SIZE);
        if (hash->itens[newpos] == NULL) return 0;
        if (hash->itens[newpos]->chave == chave){
            *reg = *(hash->itens[newpos]); return 1;
        }
    }
    return 0;
}

int remover (Tabela *hash, int chave)
{
    int i, aux;
    if (hash == NULL) return 0;

    //PROUCURA A POSIÇÃO INFORMADA E SE FOR DIFERENTE DE NULL, LIBERA A POSIÇÃO
    int pos = chave_divisao(chave, hash->TABLE_SIZE);
    if (hash->itens[pos] != NULL)
        free(hash->itens[pos]);
    else //SE NÃO NÃO HÁ ELEMENTOS
        return 0;

    //PREENCHER A MEMORIA DESALOCADA, ORGANIZANDO A LISTA
    if (pos<hash->TABLE_SIZE-1){
        aux = pos;
        for (i=pos; i<hash->TABLE_SIZE; i++){
            hash->itens[aux] = hash->itens[aux+1];
            aux++;
        }
    }
    //DIMINUIR A QUANTIDADE DE ELEMENTOS DA TABELA
    hash->qtd--;

    return 1;
}
