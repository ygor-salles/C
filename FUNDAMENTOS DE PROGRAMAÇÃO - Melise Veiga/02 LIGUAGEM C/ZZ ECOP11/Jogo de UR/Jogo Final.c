#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//#include<time.h>

/* AJUSTAR: CONDIÇÃO 6(CASAS DA ROSETA NÃO PODEM SER EXPULSAS); A CONDIÇÃO DA CASA DA ROSETA DEVE ESTAR NA FUNÇÃO PROCESSAMENTO NO TEMPO DE EXECUÇÃO NÃO APÓS A EXECUÇÃO */
/* VERIFICAR O QUE DEVE ACONTECER QUANDO UMA PEÇA DO JOGADOR CAI SOBRE OUTRA PEÇA DO MESMO JOGADOR */

void inicializando_tabuleiro(char t[][8]);
void inicializando_pecas(char s1[], char s2[]);
int sorteio(int dado[]);
void imprime_tabuleiro(char t[][8]);
void imprime_pecas(char s1[], char s2[]);
int verifica_pecas_caixa(char s1[], char s2[], int *existe_o, int *existe_x);
void processamento(int n, char t[][8], char jogador, char s1[7], char s2[7], int *m ,int *p);

/**************************** Função Principal - Menu **************************************/
int main (int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    char t[3][8], s1[7], s2[7], primeiro, segundo;
    int i=0, m=6, p=6, dado[3], a, b, n, aux1=0, aux2=0, existe_o=0, existe_x=0;

    inicializando_tabuleiro(t);

    inicializando_pecas(s1, s2);

    printf("\n ***********************>>>>>>>>>>>>  JOGO DE UR  <<<<<<<<<<<<*********************** \n");
    /* REGRA 2 - Os jogadores lançam os dados começando quem tiver a maior pontuação. */
    do {
        printf("\n\nJogador O \n Pressione alguma tecla para sorteio dos dados ..:"); system("pause");
        a = sorteio(dado);
        printf("\n\nJogador X \n Pressione alguma tecla para sorteio dos dados  ..:"); system("pause");
        b  = sorteio(dado);

        if(a>b){
            printf("\n\n\n\nQuem joga primeiro é o jogador O\n\n"); primeiro = 'o'; segundo = 'x';
        }
        else if (a<b){
            printf("\n\n\n\nQuem joga primeiro é o jogador X\n\n"); primeiro = 'x'; segundo = 'o';
        }
        else
            printf("\n\n\n\n ..SORTEIO OBTEVE RESULTADOS IGUAIS, NECESSÁRIO JOGAR NOVAMENTE.. \n\n");

    } while (a==b);

    //LIMPA A TELA
    system("pause"); system("CLS");

    //MOSTRAR O TABULEIRO E AS PEÇAS ANTES DE INICIAR
    printf("\n       ..::::  TABULEIRO  ::::..      ");
    imprime_tabuleiro(t);
    printf("\n\n");
    imprime_pecas(s1, s2);
    printf("\n\n\n\n"); system("pause"); system("CLS");


    // LAÇO DO PROCESSAMENTO DO JOGO
    do{
        i++;
        printf("\n\n\n\n %40dª JOGADA: \n\n",i);

        //PRIMEIRO JOGADOR
        printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO ");
        printf("\n Jogador O pressione [ENTER] para sortear dados ..:"); system("pause");
        n = sorteio(dado);
        processamento(n, t, primeiro, s1, s2 ,&m ,&p);

        /* REGRA 1 - Se um jogador atingir uma casa marcada com a roseta tem direito a jogar novamente */
        if (primeiro==t[0][0] || primeiro==t[0][6] || primeiro==t[1][3]){
            printf("\n ANTIGIU A ROSETA!.. Jogador O jogue novamente: "); system("pause");
            n = sorteio(dado);
            processamento(n, t, primeiro, s1, s2 ,&m ,&p);
        }

        //SEGUNDO JOGADOR
        printf("\n\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
        printf("\n Jogador X pressione [ENTER] para sortear dados ..:"); system("pause");
        n = sorteio(dado);
        processamento(n, t, segundo, s1, s2 ,&m ,&p);

        /* REGRA 1 - Se um jogador atingir uma casa marcada com a roseta tem direito a jogar novamente */
        if (segundo==t[2][0] || segundo==t[2][6] || segundo==t[1][3]){
            printf("\n ANTIGIU A ROSETA!.. Jogador X jogue novamente: "); system("pause");
            n = sorteio(dado);
            processamento(n, t, segundo, s1, s2 ,&m ,&p);
        }

        /* REGRA 6 - Peças que se encontre em casas com rosetas não podem ser expulsas. NESTE CASO NÃO TEM COMO SER EXPULSA POIS O JOGADOR JOGA NOVAMENTE */

        //MOSTRAR SITUAÇÃO DE TABULEIRO E PEÇAS APÓS CADA JOGADA, PARA USUÁRIO TER IDÉIA DE COMO FOI A JOGADA ANTERIOR
        printf("\n\n");
        system("pause"); system("CLS");
        printf("      ..::::  TABULEIRO ANTERIOR ::::..     ");
        imprime_tabuleiro(t);
        imprime_pecas(s1, s2);


        //VERIFICAR SE CAIXA DE PEÇAS ESTÁ VAZIO
        verifica_pecas_caixa(s1, s2, &existe_o, &existe_x);

    } while ((m!=0 || p!=0) && (existe_o==1 || existe_x==1));

    /* REGRA 10 - Ganha quem conseguir retirar as sete peças do tabuleiro, o programa deve informar a vitória. */
    if (m==0)
        printf(".......::::  JOGADOR o É O VENCEDOR!! ::::.......");
    else
        printf(".......::::  JOGADOR x É O VENCEDOR!! ::::.......");

    return 0;
}

void inicializando_tabuleiro(char t[][8])
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<8; j++)
            t[i][j] = ' ';
}

void inicializando_pecas(char s1[], char s2[])
{
    int i;
    for(i=0; i<7; i++) s1[i] = 'o';
    for(i=0; i<7; i++) s2[i] = 'x';
}

int sorteio(int dado[])
{
    int i, soma=0;
    //srand((unsigned) time(NULL));
    printf("[SORTEIO DE DADOS].: ");
    for(i=0; i<3; i++){
        dado[i] = rand() % 2;
        printf(" %d", dado[i]);
        soma = soma + dado[i];
    }
    printf(" = %d",soma);
    return soma;
}

void imprime_tabuleiro(char t[][8])
{
    int i, j;
    printf("\n    _0_ _1_ _2_ _3_  4   5  _6_ _7_ \n");
    for(i=0; i<3; i++){
        printf(" %d |",i);
        for(j=0; j<8; j++){
            if (i==0 && j==4)
                printf("_%c_ ",t[i][j]);
            else if (i==0 && j==5)
                printf("_%c_|",t[i][j]);
            else if (i==2 && j==4)
                printf(" %c  ",t[i][j]);
            else if (i==2 && j==5)
                printf(" %c |",t[i][j]);
            else
                printf("_%c_|",t[i][j]);
        }
        printf("\n");
    }
}

void imprime_pecas(char s1[], char s2[])
{
    int i;
    printf("\n ..:: CAIXA DE PEÇAS::.. \n");

    for (i=0; i<7; i++) printf("_%c_|",s1[i]);
    printf("\n");
    for (i=0; i<7; i++) printf("_%c_|",s2[i]);
}

int verifica_pecas_tabuleiro(char t[][8], char jogador)
{
    int i, j;
    for (i=0; i<3; i++)
        for (j=0; j<8; j++)
            if (t[i][j] == jogador)
                return 1;
    return -1;
}

int verifica_pecas_caixa(char s1[], char s2[], int *existe_o, int *existe_x)
{
    int i;
    for (i=0; i<7; i++)
        if (s1[i] == 'o'){
            *existe_o=1; break;
        }

    for (i=0; i<7; i++)
        if (s2[i] == 'x'){
            *existe_x=1; break;
        }
}

/**************************** Forma de movimentação do tabuleiro **************************************/
void processamento(int n, char t[][8], char jogador, char s1[7], char s2[7], int *m ,int *p)
{
    int esc, lin, col, semafaro=0, achou_peca=-1;
    char aux;

    //VERIFICAR SE EXISTE A PEÇA NO TABULEIRO
    achou_peca = verifica_pecas_tabuleiro(t, jogador);

    /* REGRA 3 - Caso não exista nenhuma peça no tabuleiro deve-se obrigatoriamente inserir a peça no tabuleiro. */
    if (achou_peca == -1){
        printf("\n[INSERIR]: inserindo peça no tabuleiro de acordo com sorteio realizado ..\n");
        esc = 2;
    }
    /* REGRA 3 - Enquanto houver peças para serem adicionadas no tabuleiro deve haver uma opção para escolher entre entrar no tabuleiro ou movimentar uma peça já existente. */
    else if (achou_peca == 1){
        printf("\n[ESCOLHA]: 1-move tabuleiro / 2-nova peca: ");
        scanf("%d", &esc);
        getchar();
        /* REGRA 9 - Não é possível passar a vez, sempre que jogar é necessário fazer algum movimento, exceto se não houver jogada possível para saída. */
        while (esc<1 || esc>2){
            printf("\nVALOR INCORRETO!");
            printf("\n[ESCOLHA]: 1-move tabuleiro / 2-nova peca: ");
            scanf("%d", &esc);
            getchar();
        }
    }

    //ESCOLHA DO JOGADOR SOBRE QUAL PEÇA MOVIMENTAR
    if(esc==1){
        printf("linha:"); scanf("%d", &lin);
        printf("coluna:"); scanf("%d", &col);
        /* REGRA 9 - Não é possível passar a vez, sempre que jogar é necessário fazer algum movimento, exceto se não houver jogada possível para saída. */
        while (t[lin][col] != jogador){
            printf("\nNÃO EXISTE PEÇA NESSA POSIÇÃO INFORMADA, (OU), VOCÊ NÃO PODE MOVIMENTAR A PEÇA DE OUTRO JOGADOR! \nJogue novamente: \n");
            printf("linha:"); scanf("%d", &lin);
            printf("coluna:"); scanf("%d", &col);
        }

        /* REGRA 4 - As peças entram por lados opostos do tabuleiro e se deslocam conforme a figura acima. Cada jogador só pode movimentar a suas peças. */

        t[lin][col]=' ';

        /* REGRA 8 - Para sair to tabuleiro a pontuação dos dados deve ser exata. Por exemplo, a peça do jogador A que se encontre na última casa do tabuleiro deve obrigatoriamente tirar 1 para poder sair do jogo. */
        //JOGADA X - INICIO E FIM DO TABULEIRO
        if (lin == 0){
            if (col==3) { lin=0; col=3-n; }

            else if (col==2 && n==3) { lin=1; col=0; }
            else if (col==2 && n<3) { lin=0; col=2-n; }

            else if (col==1 && n==3) { lin=1; col=1; }
            else if (col==1 && n==2) { lin=1; col=0; }
            else if (col==1 && n<=1) { lin=1; col=1-n; }

            else if (col==0 && n==0)  { lin=0; col=0; }
            else if (col==0 && n>0)  { lin=1; col=0+n-1; }

            else if (col==7 && n==3) { lin=1; col=7; }
            else if (col==7 && n==2) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
            else if (col==7 && n==1) { lin=0; col=6; }

            else if (col==6 && n==3) { lin=1; col=6; }
            else if (col==6 && n==2) { lin=1; col=7; }
            else if (col==6 && n==1) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
        }

        //JOGADA X - INICIO E FIM DO TABULEIRO
        else if (lin == 2){
            if (col==3) { lin=2; col=3-n; }

            else if (col==2 && n==3) { lin=1; col=0; }
            else if (col==2 && n<3) { lin=2; col=2-n; }

            else if (col==1 && n==3) { lin=1; col=1; }
            else if (col==1 && n==2) { lin=1; col=0; }
            else if (col==1 && n<=1) { lin=2; col=1-n; }

            else if (col==0 && n==0)  { lin=2; col=0; }
            else if (col==0 && n>0)  { lin=1; col=0+n-1; }

            else if (col==7 && n==3) { lin=1; col=7; }
            else if (col==7 && n==2) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
            else if (col==7 && n==1) { lin=2; col=6; }

            else if (col==6 && n==3) { lin=1; col=6; }
            else if (col==6 && n==2) { lin=1; col=7; }
            else if (col==6 && n==1) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
        }

        //JOGADA O - MEIO E FIM DO TABULEIRO
        else if (lin==1 && jogador=='o'){
            if (col<5)  { lin=1; col=col+n; }

            else if (col==5 && n==3) { lin=0; col=7; }
            else if (col==5 && n<3) { lin=1; col=5+n; }

            else if (col==6 && n==3) { lin=0; col=6; }
            else if (col==6 && n==2) { lin=0; col=7; }
            else if (col==6 && n<=1) { lin=1; col=6+n; }

            else if (col==7 && n==0) { lin=1; col=7; }
            else if (col==7 && n==1 || n==2) { lin=0; col=7-n+1; }
            else if (col==7 && n==3) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
        }

        //JOGADA X - MEIO E FIM DO TABULEIRO
        else if (lin==1 && jogador=='x'){
            if (col<5)  { lin=1; col=col+n; }

            else if (col==5 && n==3) { lin=2; col=7; }
            else if (col==5 && n<3) { lin=1; col=5+n; }

            else if (col==6 && n==3) { lin=2; col=6; }
            else if (col==6 && n==2) { lin=2; col=7; }
            else if (col==6 && n<=1) { lin=1; col=6+n; }

            else if (col==7 && n==0) { lin=2; col=7; }
            else if (col==7 && n==1 || n==2) { lin=2; col=7-n+1; }
            else if (col==7 && n==3) { aux=jogador; jogador=' '; semafaro=1; } /* REGRA 8 */
        }

        /* REGRA 7. Peças expulsas têm de começar o jogo do início, ou seja, devem estar fora do tabuleiro. */
        if (t[lin][col] == 'x'){
            ++(*p); s2[*p] = 'x';
        }
        if (t[lin][col] == 'o'){
            ++(*m); s1[*m] = 'o';
        }

        /* REGRA 5 - Uma peça isolada na fila central é expulsa do tabuleiro se sobre ela cair uma peça adversária. SERVE  TAMBÉM PARA CASAS VAZIAS DO TABULEIRO */
        t[lin][col]=jogador;
    }

    //INSERIR NOVAS PEÇAS
    if(esc == 2){
       if(jogador=='o'){
            s1[*m] = ' ';
            t[0][3-n]='o';
            --(*m);
       }
       if(jogador=='x'){
            s2[*p] = ' ';
            t[2][3-n]='x';
            --(*p);
       }
    }

    imprime_tabuleiro(t);
    if (semafaro == 1)
        printf("\nUMA PEÇA %c RETIRADA!\n",aux);
}

