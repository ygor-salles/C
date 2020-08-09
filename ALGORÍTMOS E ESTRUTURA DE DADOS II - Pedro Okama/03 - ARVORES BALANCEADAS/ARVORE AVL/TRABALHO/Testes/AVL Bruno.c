#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct no * pno;

typedef struct no{
  int chave;
  char nome[20];
  pno esq;
  pno dir;
  int alt;
}no;

/****************************************************************************/
pno criar_no(int c, char nome[])
{
  pno aux = (pno) malloc(sizeof(pno));
  aux->chave = c;
  strcpy(aux->nome,nome);
  aux->esq = NULL;
  aux->dir = NULL;
  aux->alt = 0;
  return aux;
}

/****************************************************************************/
int altura(pno n)
{
  if(n == NULL) return -1;
  else return n->alt;
}

/****************************************************************************/
int max(int a, int b)
{
  if(a>b)return a;
  return b;
}

/****************************************************************************/
pno rotaciona_direita(pno n)
{
  pno aux;
  aux = n->esq;
  n->esq = aux->dir;
  aux->dir = n;

  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

  return(aux);
}

/****************************************************************************/
pno rotaciona_esquerda(pno n)
{
  pno aux;
  aux = n->dir;
  n->dir = aux->esq;
  aux->esq = n;

  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

  return(aux);
}

/****************************************************************************/
pno rotaciona_esquerda_direita(pno n)
{
  n->esq = rotaciona_esquerda(n->esq);
  pno aux = rotaciona_direita(n);
  return aux;
}

/****************************************************************************/
pno rotaciona_direita_esquerda(pno n)
{
  n->dir = rotaciona_direita(n->dir);
  pno aux = rotaciona_esquerda(n);
  return aux;
}

/****************************************************************************/
void print_arvore(pno arv)
{
  if(arv == NULL) return;
  printf("(%d %s ", arv->chave, arv->nome);
  print_arvore(arv->esq);
  printf(" ");
  print_arvore(arv->dir);
  printf(")");
  return;
}

/****************************************************************************/
int consulta(pno arv, int c)
{
  int achou = -1;
  if (arv->chave == c)
    return arv->chave;
  if(arv->chave > c){
    if(arv->esq == NULL)
      return -1;
    achou = consulta(arv->esq, c);
  }
  if(arv->chave < c){
    if(arv->dir == NULL)
      return -1;
    achou = consulta(arv->dir, c);
  }

  return achou;
}

/****************************************************************************/
int fator_balanceamento(pno n)
{
  if(n == NULL) return 0;
  return(altura(n->dir) - altura(n->esq));
}

/****************************************************************************/
pno minValueNode(pno node)
{
    pno current = node;

    /* loop para encontrar folha mais a direita */
    while (current->dir != NULL)
        current = current->dir;

    return current;
}

pno remover(pno arv, int chave){
    if (arv == NULL)
        return arv;

    if ( chave < arv->chave )
        arv->esq = remover(arv->esq, chave);

    else if( chave > arv->chave )
        arv->dir = remover(arv->dir, chave);

    else
    {
        // n� com uma folha ou sem folhas
        if( (arv->esq == NULL) || (arv->dir == NULL) )
        {
            pno temp = arv->esq ? arv->esq : arv->dir;

            // N� folha
            if (temp == NULL)
            {
                temp = arv;
                arv = NULL;
            }
            else // uma folha
             *arv = *temp; // Copy the contents of
                            // the non-empty child
            // free(temp);
        }
        else
        {
            pno temp = minValueNode(arv->dir);

            // Copy the inorder successor's data to this node
            arv->chave = temp->chave;

            // Delete the inorder successor
            arv->dir = remover(arv->dir, temp->chave);
        }
    }

    // If the tree had only one node then return
    if (arv == NULL)
      return arv;

    // STEP 2: UPDATE altura OF THE CURRENT NODE
    arv->alt = 1 + max(altura(arv->esq),
                           altura(arv->dir));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = fator_balanceamento(arv);

    // If this node becomes unbalanced, then there are 4 cases

    // esq esq Case
    if (balance > 1 && fator_balanceamento(arv->esq) >= 0)
        return rotaciona_direita(arv);

    // esq dir Case
    if (balance > 1 && fator_balanceamento(arv->esq) < 0)
    {
        arv->esq =  rotaciona_esquerda(arv->esq);
        return rotaciona_direita(arv);
    }

    // dir dir Case
    if (balance < -1 && fator_balanceamento(arv->dir) <= 0)
        return rotaciona_esquerda(arv);

    // dir esq Case
    if (balance < -1 && fator_balanceamento(arv->dir) > 0)
    {
        arv->dir = rotaciona_direita(arv->dir);
        return rotaciona_esquerda(arv);
    }

    return arv;
}

/****************************************************************************/
pno insere(pno arvore, int c, char nome[])
{
  if(arvore == NULL) return(criar_no(c, nome));
  if(arvore->chave == c){
    printf("Chave existente\n");
    return arvore;
  }
  if(arvore->chave > c){
    //insere na esquerda
    arvore->esq = insere(arvore->esq, c, nome);
    //como eu inseri na esquerda o unico problema que eu posso ter ? se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == -2){
      if(c < arvore->esq->chave) arvore = rotaciona_direita(arvore);
      else arvore = rotaciona_esquerda_direita(arvore);
    }
  }
  if(arvore->chave < c){
    //insere na direita
    arvore->dir = insere(arvore->dir, c, nome);
    //como eu inseri na esquerda o unico problema que eu posso ter ? se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == 2){
      if(c > arvore->dir->chave) arvore = rotaciona_esquerda(arvore);
      else arvore = rotaciona_direita_esquerda(arvore);
    }
  }
  arvore->alt   = max(altura(arvore->esq), altura(arvore->dir)) + 1;
  return(arvore);
}

/****************************************************************************/
int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");
  pno arvore = NULL;

  int chave;
  char nome[20], op;

  do{
    printf("\n\n***MENU DE OP��ES***");
    printf("\nESCOLHA O CARACTER CONFORME OP��O DESEJADA");
    printf("\n[i] - Inserir registro");
    printf("\n[c] - Consultar");
    printf("\n[p] - Imprimir");
    printf("\n[r] - Remover");
    printf("\n[v] - Verificar se arvore est� balanceada");
    printf("\n[x] - Encerrar");
    printf("\nOp��o: "); scanf(" %c",&op);
    printf("\n\n");

    switch (op){
        case 'i':
            printf("Informe CHAVE: "); scanf("%d",&chave);
            printf("Informe NOME: "); scanf(" %[^\n]",nome);
            arvore = insere(arvore, chave, nome);
            break;

        //implementar
        case 'c':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            if(consulta(arvore, chave) != -1)
              printf("Chave existente\n\n");
            else
              printf("Chave n�o encontrada\n\n");
            break;

        case 'p':
            print_arvore(arvore);
            break;

        //implementar
        case 'r':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            arvore = remover(arvore, chave);
            // printf("INDISPON�VEL NO MOMENTO!");
            break;

        case 'v':
            if(fator_balanceamento(arvore) >= -1 && fator_balanceamento(arvore) <= 1)
                printf(" SIM ");
            else
                printf(" N�O ");
            break;

        case 'x':
            //liberar_arvore(arvore); implementar
            printf("Finalizando...");
            break;

        default:
            printf("Op��o inv�lida!");
            break;
    }

    printf("\n\n");
    // system("pause");
    // system("clear");

  } while(op != 'x');

  return 0;
}
