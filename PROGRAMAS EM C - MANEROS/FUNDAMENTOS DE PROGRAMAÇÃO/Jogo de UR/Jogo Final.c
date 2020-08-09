#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//#include<time.h>

/* AJUSTAR: CONDI��O 6(CASAS DA ROSETA N�O PODEM SER EXPULSAS); A CONDI��O DA CASA DA ROSETA DEVE ESTAR NA FUN��O PROCESSAMENTO NO TEMPO DE EXECU��O N�O AP�S A EXECU��O */
/* VERIFICAR O QUE DEVE ACONTECER QUANDO UMA PE�A DO JOGADOR CAI SOBRE OUTRA PE�A DO MESMO JOGADOR */

void inicializando_tabuleiro(char t[][8]);
void inicializando_pecas(char s1[], char s2[]);
int sorteio(int dado[]);
void imprime_tabuleiro(char t[][8]);
void imprime_pecas(char s1[], char s2[]);
int verifica_pecas_caixa(char s1[], char s2[], int *existe_o, int *existe_x);
void processamento(int n, char t[][8], char jogador, char s1[7], char s2[7], int *m ,int *p);

/**************************** Fun��o Principal - Menu **************************************/
int main (int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    char t[3][8], s1[7], s2[7], primeiro, segundo;
    int i=0, m=6, p=6, dado[3], a, b, n, aux1=0, aux2=0, existe_o=0, existe_x=0;

    inicializando_tabuleiro(t);

    inicializando_pecas(s1, s2);

    printf("\n ***********************>>>>>>>>>>>>  JOGO DE UR  <<<<<<<<<<<<*********************** \n");
    /* REGRA 2 - Os jogadores lan�am os dados come�ando quem tiver a maior pontua��o. */
    do {
        printf("\n\nJogador O \n Pressione alguma tecla para sorteio dos dados ..:"); system("pause");
        a = sorteio(dado);
        printf("\n\nJogador X \n Pressione alguma tecla para sorteio dos dados  ..:"); system("pause");
        b  = sorteio(dado);

        if(a>b){
            printf("\n\n\n\nQuem joga primeiro � o jogador O\n\n"); primeiro = 'o'; segundo = 'x';
        }
        else if (a<b){
            printf("\n\n\n\nQuem joga primeiro � o jogador X\n\n"); primeiro = 'x'; segundo = 'o';
        }
        else
            printf("\n\n\n\n ..SORTEIO OBTEVE RESULTADOS IGUAIS, NECESS�RIO JOGAR NOVAMENTE.. \n\n");

    } while (a==b);

    //LIMPA A TELA
    system("pause"); system("CLS");

    //MOSTRAR O TABULEIRO E AS PE�AS ANTES DE INICIAR
    printf("\n       ..::::  TABULEIRO  ::::..      ");
    imprime_tabuleiro(t);
    printf("\n\n");
    imprime_pecas(s1, s2);
    printf("\n\n\n\n"); system("pause"); system("CLS");


    // LA�O DO PROCESSAMENTO DO JOGO
    do{
        i++;
        printf("\n\n\n\n %40d� JOGADA: \n\n",i);

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

        /* REGRA 6 - Pe�as que se encontre em casas com rosetas n�o podem ser expulsas. NESTE CASO N�O TEM COMO SER EXPULSA POIS O JOGADOR JOGA NOVAMENTE */

        //MOSTRAR SITUA��O DE TABULEIRO E PE�AS AP�S CADA JOGADA, PARA USU�RIO TER ID�IA DE COMO FOI A JOGADA ANTERIOR
        printf("\n\n");
        system("pause"); system("CLS");
        printf("      ..::::  TABULEIRO ANTERIOR ::::..     ");
        imprime_tabuleiro(t);
        imprime_pecas(s1, s2);


        //VERIFICAR SE CAIXA DE PE�AS EST� VAZIO
        verifica_pecas_caixa(s1, s2, &existe_o, &existe_x);

    } while ((m!=0 || p!=0) && (existe_o==1 || existe_x==1));

    /* REGRA 10 - Ganha quem conseguir retirar as sete pe�as do tabuleiro, o programa deve informar a vit�ria. */
    if (m==0)
        printf(".......::::  JOGADOR o � O VENCEDOR!! ::::.......");
    else
        printf(".......::::  JOGADOR x � O VENCEDOR!! ::::.......");

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
    printf("\n ..:: CAIXA DE PE�AS::.. \n");

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

/**************************** Forma de movimenta��o do tabuleiro **************************************/
void processamento(int n, char t[][8], char jogador, char s1[7], char s2[7], int *m ,int *p)
{
    int esc, lin, col, semafaro=0, achou_peca=-1;
    char aux;

    //VERIFICAR SE EXISTE A PE�A NO TABULEIRO
    achou_peca = verifica_pecas_tabuleiro(t, jogador);

    /* REGRA 3 - Caso n�o exista nenhuma pe�a no tabuleiro deve-se obrigatoriamente inserir a pe�a no tabuleiro. */
    if (achou_peca == -1){
        printf("\n[INSERIR]: inserindo pe�a no tabuleiro de acordo com sorteio realizado ..\n");
        esc = 2;
    }
    /* REGRA 3 - Enquanto houver pe�as para serem adicionadas no tabuleiro deve haver uma op��o para escolher entre entrar no tabuleiro ou movimentar uma pe�a j� existente. */
    else if (achou_peca == 1){
        printf("\n[ESCOLHA]: 1-move tabuleiro / 2-nova peca: ");
        scanf("%d", &esc);
        getchar();
        /* REGRA 9 - N�o � poss�vel passar a vez, sempre que jogar � necess�rio fazer algum movimento, exceto se n�o houver jogada poss�vel para sa�da. */
        while (esc<1 || esc>2){
            printf("\nVALOR INCORRETO!");
            printf("\n[ESCOLHA]: 1-move tabuleiro / 2-nova peca: ");
            scanf("%d", &esc);
            getchar();
        }
    }

    //ESCOLHA DO JOGADOR SOBRE QUAL PE�A MOVIMENTAR
    if(esc==1){
        printf("linha:"); scanf("%d", &lin);
        printf("coluna:"); scanf("%d", &col);
        /* REGRA 9 - N�o � poss�vel passar a vez, sempre que jogar � necess�rio fazer algum movimento, exceto se n�o houver jogada poss�vel para sa�da. */
        while (t[lin][col] != jogador){
            printf("\nN�O EXISTE PE�A NESSA POSI��O INFORMADA, (OU), VOC� N�O PODE MOVIMENTAR A PE�A DE OUTRO JOGADOR! \nJogue novamente: \n");
            printf("linha:"); scanf("%d", &lin);
            printf("coluna:"); scanf("%d", &col);
        }

        /* REGRA 4 - As pe�as entram por lados opostos do tabuleiro e se deslocam conforme a figura acima. Cada jogador s� pode movimentar a suas pe�as. */

        t[lin][col]=' ';

        /* REGRA 8 - Para sair to tabuleiro a pontua��o dos dados deve ser exata. Por exemplo, a pe�a do jogador A que se encontre na �ltima casa do tabuleiro deve obrigatoriamente tirar 1 para poder sair do jogo. */
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

        /* REGRA 7. Pe�as expulsas t�m de come�ar o jogo do in�cio, ou seja, devem estar fora do tabuleiro. */
        if (t[lin][col] == 'x'){
            ++(*p); s2[*p] = 'x';
        }
        if (t[lin][col] == 'o'){
            ++(*m); s1[*m] = 'o';
        }

        /* REGRA 5 - Uma pe�a isolada na fila central � expulsa do tabuleiro se sobre ela cair uma pe�a advers�ria. SERVE  TAMB�M PARA CASAS VAZIAS DO TABULEIRO */
        t[lin][col]=jogador;
    }

    //INSERIR NOVAS PE�AS
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
        printf("\nUMA PE�A %c RETIRADA!\n",aux);
}

