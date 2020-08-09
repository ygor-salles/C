#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include "tad.h"

//REGISTRO PARA OS VETORES DATA ATUAL E DATA ANTIGA
struct Registro
{
    char nome[50], tipo[30], data[15], nome_vendas[50];
    int cod, cont_espaco;
    float valor;
    float ac, anc, pc, pnc, pl, dre;
};
typedef struct Registro Registro;

//REGISTRO PARA USU�RIO INFORMAR O C�IGO DAS TRANSA��ES PARA C�LCULO DOS �NDICES
struct Indices
{
    int vendas, imob, atrl, disp, clientes, aplFin;
};
typedef struct Indices Indices;

//REGISTRO AUXILIAR CASO USU�RIO ESCOLHA A OP��O DE EMITIR RELAT�RIO APENAS DE ITENS MAIS RELEVANTES
struct Input
{
    float ac[2], anc[2], pc[2], pnc[2], pl[2], dre[2];
};
typedef struct Input Input;

//CABE�ALHO DAS FUN��ES
int insercao_dados(Lista *li);
void limpa_tela();
void classe(char string[]);

void copiar_dados(int qtd, Lista *li, char data[], Registro reg[]);
void menu_relatorios (int qtd, Registro atual[], Registro antigo[], Lista *li);
void encerramento_exercicio (int qtd, Registro atual[], Registro antigo[], Registro *soma_atual, Registro *soma_antigo, int cod_vendas, Input a, int op);
void relatorio_av_ah(int qtd, Registro atual[], Registro antigo[], Registro soma_atual, Registro soma_antigo, int cod_vendas, int indicador);
void relatorio_indices(int qtd, Registro atual[], Registro antigo[], Registro soma_atual, Registro soma_antigo, Indices codigo);

/****************************************************************************************************************************/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista *li;
    char data_atual[15], data_antiga[15];
    int qtd;

    //CRIAR LISTA
    li = criar_lista();
    if(li != NULL)
        printf(" \n\n");
    else
        printf("\nERROR, LISTA N�O CRIADA, REINICIE O PROGRAMA\n!");

    //INSERIR DADOS
    qtd = insercao_dados(li);

    //DECLARA��O DE VETORES
    Registro *atual = (Registro*) malloc((qtd+1) * sizeof(Registro));
    Registro *antigo = (Registro*) malloc((qtd+1) * sizeof(Registro));

    //COPIAR DADOS DA LISTA PARA OS VETORES E INSERIR VALORES DE CADA TRANSA��O
    printf("\nInforme a [DATA] atual: "); scanf(" %[^\n]",data_atual);
    printf("\nInforme a [DATA] antiga: "); scanf(" %[^\n]",data_antiga);
    printf("\n\n ...::: PREENCHA VALORES DA DATA ATUAL [%s] :::... \n",data_atual);
    copiar_dados(qtd, li, data_atual, atual);
    printf("\n\n ...::: PREENCHA VALORES DA DATA ANTIGA [%s] :::... \n",data_antiga);
    copiar_dados(qtd, li, data_antiga, antigo);

    //FUN��O PARA LIMPAR A TELA
    limpa_tela();

    //MENU PARA ESCOLHA DE QUAL AN�LISE SER� FEITA SOBRE OS DADOS   //SER�O GERADOS OS REAT�RIOS CONFORME ESCOHA DO USU�RIO
    menu_relatorios (qtd, atual, antigo, li);

    return 0;
}

/****************************************************************************************************************************/
int insercao_dados(Lista *li)
{
    int opcao, codigo, cod=0, i;
    char string[30];
    Transacao dados;

    do{
         //TELA DE EXIBI��O AO INICIAR O SISTEMA
        printf("    #############################################################\n");
        for (i=0; i<8; i++){
            if (i==2)
                printf("    #                  SISTEMA DE CONTABILIDADE                 #\n");
            if (i==4)
                printf("    # INDICES DE BALAN�O, AN�LISE VERTICAL E AN�LISE HORIZONTAL #\n");
                printf("    #                                                           #\n");
        }
        printf("    #############################################################\n");

        //MENU PARA USU�RIO CADASTRAR VISUALIZAR E REMOVER TRANSA��ES
        printf("\n\n      ************ ....::: MENU DE OP��ES :::.... ************\n");
        printf("\n                     1 - Inserir transa��o");
        printf("\n                     2 - Imprime transa��es");
        printf("\n                     3 - Remove transa��o");
        printf("\n                     4 - Quantidade de transa��es");
        printf("\n                     5 - Limpar transa��es");
        printf("\n                     6 - Concluir transa��es");
        printf("\n\n                   Op��o: ");
        scanf("%d",&opcao);
        printf("\n\n"); system("CLS");

        switch(opcao){
            case 1:
                cod++;
                //imprimir_lista(li);
                printf("\n  Digite o nome da transa��o: "); scanf(" %[^\n]",dados.nome);
                printf("\n\n  Informe a classe: "); classe(string); strcpy(dados.tipo, string);
                dados.cod = cod; printf("\n  C�digo: %d\n",dados.cod);

                if(inserir_lista_fim(li, dados) == 1) printf("\n\nInser��o realizada com sucesso!");
                break;

            case 2:
                if(imprimir_lista(li) == 1) printf("\n\nImpress�o realizada com sucesso!\n");
                break;

            case 3:
                imprimir_lista(li);
                printf("\n\nDigite o c�digo da transa��o a ser removida: "); scanf("%d",&codigo);
                if(remover_elemento_dado(li, codigo) == 1)
                    printf("\nRemo��o realizada com sucesso!");
                cod--;
                break;

            case 4: printf("\nA quantidade de transa��es �: %d",tamanho_lista(li)); break;

            case 5: if(esvaziar_lista(li) == 1) printf("\nLista de transa��es Esvaziada!"); break;

            case 6: printf("\nCARREGANDO TRANSA��ES..."); break;

            default:
                printf("\n[ERROR]: OP��O INV�LIDA!");
                break;
        }
        limpa_tela();

    }while(opcao != 6);

    return cod;
}

/****************************************************************************************************************************/
void limpa_tela()
{
    printf("\n\n"); system("pause"); system("CLS");
}

/****************************************************************************************************************************/
void classe(char string[])
{
    int tipo;

    //MENU DE ESCOLHA A QUE CLASSE PERTENCE A TRANSA��O, PARA ORGANIZAR NO BALAN�O
    printf("\n  1  -  ATIVO CIRCULANTE");
    printf("\n  2  -  ATIVO N�O CIRCULANTE");
    printf("\n  3  -  PASSIVO CIRCULANTE");
    printf("\n  4  -  PASSIVO N�O CIRCULANTE");
    printf("\n  5  -  PATRIM�NIO L�QUIDO");
    printf("\n  6  -  DEMONSTRATIVO DE RESULTADO DO EXERC�CIO (DRE)");
    printf("\n\n  Tipo..: "); scanf("%d",&tipo);

    if (tipo == 1) strcpy(string, "ATIVO CIRCULANTE");
    else if (tipo == 2) strcpy(string, "ATIVO NAO CIRCULANTE");
    else if (tipo == 3) strcpy(string, "PASSIVO CIRCULANTE");
    else if (tipo == 4) strcpy(string, "PASSIVO NAO CIRCULANTE");
    else if (tipo == 5) strcpy(string, "PATRIMONIO LIQUIDO");
    else if (tipo == 6) strcpy(string, "DRE");
    else{
        printf("\n\nValor incorreto! Digite novamente..\n\n");
        return classe(string);
    }
}

/****************************************************************************************************************************/
void copiar_dados(int qtd, Lista *li, char data[], Registro reg[])
{
    int i=0;
    Elemento *no = li->inicio;

    //REALIZAR A C�PIA DOS DADOS DA LISTA PARA OS VETORES
    do{
        reg[i].cod = no->dados.cod;
        strcpy(reg[i].data, data);
        strcpy(reg[i].nome, no->dados.nome);
        strcpy(reg[i].tipo, no->dados.tipo);

        int cont; char aux[31] = "                               ";
        cont = 30 - strlen(reg[i].nome);
        strncat(reg[i].nome, aux, cont);

        printf("\n %s ",reg[i].nome);
        printf("\n Informe valor: "); scanf("%f",&reg[i].valor);

        i++;
        no = no->prox;
    } while(no!=NULL);
}

/****************************************************************************************************************************/
void menu_relatorios (int qtd, Registro atual[], Registro antigo[], Lista *li)
{
    Registro soma_atual, soma_antigo;
    Input a;
    char op;
    int op1, i;
    imprimir_lista(li);

    //NECESS�RIO USU�RIO INFORMAR O C�DIGO DE VENDAS PARA EXIBIR O BALAN�O PATRIMONIAL
    Indices codigo;
    printf("\nINFORME C�DIGO DE VENDAS: "); scanf("%d",&codigo.vendas);
    limpa_tela();

    //OP��O DE ESCOLHA PARA USU�RIO, SE SER� UM RELATPORIO GERAL OU DE ITENS MAIS RELEVANTES
    printf("\nOS DADOS INFORMADOS � PARA UM RELAT�RIO GERAL OU ITENS MAIS RELEVANTES DO BALAN�O? [ESCOLHA]... \n1 - Geral \n2 - Itens mais relevantes");
    printf("\nOp��o ..:"); scanf("%d",&op1);
    if (op1==2){
        for (i=0; i<2; i++){
            if (i==0) printf("\n INFORME TOTAIS DA DATA [%s]",atual[0].data);
            printf("\nInforme total do Ativo Circulante: "); scanf("%f",&a.ac[i]);
            printf("Informe total do Ativo N�o Circulante: "); scanf("%f",&a.anc[i]);
            printf("Informe total do Passivo Circulante: "); scanf("%f",&a.pc[i]);
            printf("Informe total do Passivo N�o Circulante: "); scanf("%f",&a.pnc[i]);
            printf("Informe total do Patrim�nio L�quido: "); scanf("%f",&a.pl[i]);
            printf("Informe total do DRE: "); scanf("%f",&a.dre[i]);
            if (i==0) printf("\n\n INFORME TOTAIS DA DATA [%s]",antigo[0].data);
        }
    }
    limpa_tela();
    encerramento_exercicio (qtd, atual, antigo, &soma_atual, &soma_antigo, codigo.vendas, a, op1);
    limpa_tela();

    //PERGUNTAR AO USU�RIO SE SER� CALCULADO OS INDICES, POIS O CALCULO DOS INDICES NECESSITA DE MAIS INFORMA��ES
    printf("\n ... SER� REALIZADO O C�LCULO DOS �NDICES? (S/N): .."); scanf(" %c",&op);
    if (op == 'S' || op=='s'){
        imprimir_lista(li);
        printf("\n\nINFORME OS C�DIGOS PARA C�LCULO DOS �NDICES, CASO N�O ENCONTRE NA LISTA DIGITE C�DIGO 0 ...\n\n");
        printf("\nINFORME C�DIGO DE IMOBILIZADO: "); scanf("%d",&codigo.imob);
        printf("\nINFORME C�DIGO DE DISPON�VEL (CAIXA): "); scanf("%d",&codigo.disp);
        printf("\nINFORME C�DIGO DE ATIVO REALIZ�VEL LONGO PRAZO: "); scanf("%d",&codigo.atrl);
        printf("\nINFORME C�DIGO DE CLIENTES (CONTAS A RECEBER): "); scanf("%d",&codigo.clientes);
        printf("\nINFORME C�DIGO DE APLICA��ES FINANCEIRAS: "); scanf("%d",&codigo.aplFin);
        limpa_tela();
    }

     //MENU DE OP��ES PARA GERAR O RELAT�RIO DESEJADO
     int opcao;
     do{
        printf("\n\n  Escolha uma op��o para gerar o Relat�rio conforme desejado:.. \n");
        printf("\n  0  -  ENCERRAMENTO DO EXERC�CIO");
        printf("\n  1  -  AN�LISE VERTICAL");
        printf("\n  2  -  AN�LISE HORIZONTAL");
        printf("\n  3  -  �NDICES");
        printf("\n  4  -  FINALIZAR PROGRAMA");
        printf("\n\n  Op��o: ");
        scanf("%d",&opcao);
        printf("\n\n"); system("CLS");

        switch(opcao){
            case 0: encerramento_exercicio (qtd, atual, antigo, &soma_atual, &soma_antigo, codigo.vendas, a, op1); break;
            case 1: relatorio_av_ah(qtd, atual, antigo, soma_atual, soma_antigo, codigo.vendas, 1); break;
            case 2: relatorio_av_ah(qtd, atual, antigo, soma_atual, soma_antigo, codigo.vendas, 2); break;
            case 3:
                if (op=='S' || op=='s') relatorio_indices(qtd, atual, antigo, soma_atual, soma_antigo, codigo);
                else  printf("\nINDISPON�VEL NO MOMENTO!\n");
                break;
            case 4: printf("\nLiberando mem�ria..\n"); printf("\nFINALIZANDO PROGRAMA..."); free(atual); free(antigo); free(li); break;
            default: printf("\n[ERROR]: OP��O INV�LIDA!"); break;
        }

        limpa_tela();

    }while(opcao != 4);
}

/****************************************************************************************************************************/
void encerramento_exercicio (int qtd, Registro atual[], Registro antigo[], Registro *soma_atual, Registro *soma_antigo, int cod_vendas, Input a, int op)
{
    int i;

    //INICIALIZANDO AS VARI�VEIS PARA CALCULO DO ENCERRAMENTO DO EXERC�CIO
    soma_atual->ac=0; soma_atual->anc=0; soma_atual->pc=0; soma_atual->pnc=0; soma_atual->pl=0;
    soma_antigo->ac=0; soma_antigo->anc=0; soma_antigo->pc=0; soma_antigo->pnc=0; soma_antigo->pl=0;
    for (i=0; i<qtd; i++)
        if (cod_vendas == atual[i].cod){
            soma_atual->dre = atual[i].valor;
            soma_antigo->dre = antigo[i].valor;
            break;
        }


    printf("\n    ENCERRAMENTO EXERC�CIO          %s      %s  \n",atual[0].data, antigo[0].data);
    printf("\n___________________________________________________________________");

    printf("\n    ATIVO CIRCULANTE                         \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"ATIVO CIRCULANTE")==0){
            soma_atual->ac = soma_atual->ac + atual[i].valor;
            soma_antigo->ac = soma_antigo->ac + antigo[i].valor;
            printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->ac = a.ac[0]; soma_antigo->ac = a.ac[1]; }
    printf("\n\n    TOTAL ATIVO CIRCULANTE         %.2f   %.2f \n ",soma_atual->ac, soma_antigo->ac);
    printf("\n___________________________________________________________________");


    printf ("\n    ATIVO N�O CIRCULANTE                      \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"ATIVO NAO CIRCULANTE")==0){
            soma_atual->anc = soma_atual->anc + atual[i].valor;
            soma_antigo->anc = soma_antigo->anc + antigo[i].valor;
            printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->anc = a.anc[0]; soma_antigo->anc = a.anc[1]; }
    printf("\n\n    TOTAL ATIVO N�O CIRCULANTE     %.2f   %.2f \n ",soma_atual->anc, soma_antigo->anc);
    printf("\n___________________________________________________________________");


    printf("\n    PASSIVO CIRCULANTE                        \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PASSIVO CIRCULANTE")==0){
            soma_atual->pc = soma_atual->pc + atual[i].valor;
            soma_antigo->pc = soma_antigo->pc + antigo[i].valor;
            printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->pc = a.pc[0]; soma_antigo->pc = a.pc[1]; }
    printf("\n\n    TOTAL PASSIVO CIRCULANTE       %.2f   %.2f \n ",soma_atual->pc, soma_antigo->pc);
    printf("\n___________________________________________________________________");


    printf("\n    PASSIVO N�O CIRCULANTE                    \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PASSIVO NAO CIRCULANTE")==0){
            soma_atual->pnc = soma_atual->pnc + atual[i].valor;
            soma_antigo->pnc = soma_antigo->pnc + antigo[i].valor;
            printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->pnc = a.pnc[0]; soma_antigo->pnc = a.pnc[1]; }
    printf("\n\n    TOTAL PASSIVO N�O CIRCULANTE   %.2f   %.2f \n ",soma_atual->pnc, soma_antigo->pnc);
    printf("\n___________________________________________________________________");


    printf("\n    PATRIM�NIO L�QUIDO                        \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PATRIMONIO LIQUIDO")==0){
            soma_atual->pl = soma_atual->pl + atual[i].valor;
            soma_antigo->pl = soma_antigo->pl + antigo[i].valor;
            printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->pl = a.pl[0]; soma_antigo->pl = a.pl[1]; }
    printf("\n\n    TOTAL PATRIM�NIO L�QUIDO       %.2f   %.2f \n\n\n",soma_atual->pl, soma_antigo->pl);
    printf("\n___________________________________________________________________");


    printf("\n\n___________________________________________________________________");
    printf("\n    DRE                                       \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"DRE")==0){
            if (cod_vendas != atual[i].cod){
                soma_atual->dre = soma_atual->dre - atual[i].valor;
                soma_antigo->dre = soma_antigo->dre - antigo[i].valor;
                printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
            }
            else
                printf ("\n    %s %.2f   %.2f  ", atual[i].nome, atual[i].valor, antigo[i].valor);
        }
    if (op==2) { soma_atual->dre = a.dre[0]; soma_antigo->dre = a.dre[1]; }
    printf("\n\n    LUCRO L�QUIDO                  %.2f   %.2f \n\n\n",soma_atual->dre, soma_antigo->dre);

}

/****************************************************************************************************************************/
void relatorio_av_ah(int qtd, Registro atual[], Registro antigo[], Registro soma_atual, Registro soma_antigo, int cod_vendas, int indicador)
{
    int i;
    float *vendas = (float*) malloc(2 * sizeof(float));
    for (i=0; i<qtd; i++)
        if (cod_vendas == atual[i].cod){
            vendas[0] = atual[i].valor;
            vendas[1] = antigo[i].valor;
        }

    if(indicador==1) printf("\n    AN�LISE VERTICAL               %s      %s  \n",atual[0].data, antigo[0].data);
    else printf("\n    AN�LISE HORIZONTAL            \n");

    printf("\n___________________________________________________________________");
    printf("\n    ATIVO CIRCULANTE                         \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"ATIVO CIRCULANTE")==0){
            if (indicador == 1)
                printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/(soma_atual.ac+soma_atual.anc))*100, (antigo[i].valor/(soma_antigo.ac+soma_antigo.anc))*100 );
            else
                printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }
    printf("\n___________________________________________________________________");



    printf ("\n    ATIVO N�O CIRCULANTE                      \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"ATIVO NAO CIRCULANTE")==0){
            if (indicador == 1)
                printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/(soma_atual.ac+soma_atual.anc))*100, (antigo[i].valor/(soma_antigo.ac+soma_antigo.anc))*100 );
            else
                printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }
    printf("\n___________________________________________________________________");



    printf("\n    PASSIVO CIRCULANTE                        \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PASSIVO CIRCULANTE")==0){
            if (indicador == 1)
                printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/(soma_atual.pc+soma_atual.pnc+soma_atual.pl))*100, (antigo[i].valor/(soma_antigo.pc+soma_antigo.pnc+soma_antigo.pl))*100 );
            else
                printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }
    printf("\n___________________________________________________________________");



    printf("\n    PASSIVO N�O CIRCULANTE                    \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PASSIVO NAO CIRCULANTE")==0){
            if (indicador == 1)
                printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/(soma_atual.pc+soma_atual.pnc+soma_atual.pl))*100, (antigo[i].valor/(soma_antigo.pc+soma_antigo.pnc+soma_antigo.pl))*100 );
            else
                printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }
    printf("\n___________________________________________________________________");



    printf("\n    PATRIM�NIO L�QUIDO                        \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"PATRIMONIO LIQUIDO")==0){
            if (indicador == 1)
                printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/(soma_atual.pc+soma_atual.pnc+soma_atual.pl))*100, (antigo[i].valor/(soma_antigo.pc+soma_antigo.pnc+soma_antigo.pl))*100 );
            else
                printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }


    printf("\n\n\n\n___________________________________________________________________");
    printf("\n    DRE                                       \n");
    for (i=0; i<qtd; i++)
        if (strcmp(antigo[i].tipo,"DRE")==0){
            if (indicador == 1){
                if (cod_vendas == antigo[i].cod)
                    printf ("\n    %s %.2f%%   %.2f%%  \n", atual[i].nome, (vendas[0]/vendas[0])*100, (vendas[1]/vendas[1])*100 );
                else
                    printf ("\n    %s %.2f%%   %.2f%%  ", atual[i].nome, (atual[i].valor/vendas[0])*100, (antigo[i].valor/vendas[1])*100 );
            }
            else
                if (cod_vendas == antigo[i].cod)
                    printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
                else
                    printf ("\n    %s %.2f%%",atual[i].nome, ((atual[i].valor/antigo[i].valor)-1)*100);
        }
    printf("\n___________________________________________________________________");

    free(vendas);
}

/****************************************************************************************************************************/
void relatorio_indices(int qtd, Registro atual[], Registro antigo[], Registro soma_atual, Registro soma_antigo, Indices codigo)
{
    int i;
    float imob_atual=0, atrl_atual=0, disp_atual=0, client_atual=0, vendas_atual=0, aplFin_atual=0;
    float imob_antigo=0, atrl_antigo=0, disp_antigo=0, client_antigo=0, vendas_antigo=0, aplFin_antigo=0;


    //COPIAR OS VALORES PARA AS NOVAS VARI�VEIS AUXILIARES PARA CALCULAR OS �NDICES
    for (i=0; i<qtd; i++){
        if (codigo.imob == atual[i].cod){
            imob_atual = atual[i].valor;
            imob_antigo = antigo[i].valor;
        }
        if (codigo.atrl== atual[i].cod){
            atrl_atual = atual[i].valor;
            atrl_antigo = antigo[i].valor;
        }
        if (codigo.disp == atual[i].cod){
            disp_atual =  atual[i].valor;
            disp_antigo = antigo[i].valor;
        }
        if (codigo.aplFin == atual[i].cod){
            aplFin_atual =  atual[i].valor;
            aplFin_antigo = antigo[i].valor;
        }
        if (codigo.clientes == atual[i].cod){
            client_atual = atual[i].valor;
            client_antigo = antigo[i].valor;
        }
        if (codigo.vendas == atual[i].cod){
            vendas_atual = atual[i].valor;
            vendas_antigo = antigo[i].valor;
        }
    }

    printf("\n\n *********************:::::::: �NDICES ::::::::*********************");
    printf("\n\n               DATAS                      [%s]  [%s]", atual[0].data, antigo[0].data);

    printf("\n\n\n �NDICES DE ESTRUTURA DE CAPITAL \n");
    printf("\nParticipa��o de Capital de Terceiros      %.2f%%  %.2f%%", ((soma_atual.pc + soma_atual.pnc)/soma_atual.pl)*100, ((soma_antigo.pc + soma_antigo.pnc)/soma_antigo.pl)*100 );
    printf("\nEndividamento                             %.2f%%  %.2f%%", (soma_atual.pc/(soma_atual.pc + soma_atual.pnc))*100, (soma_antigo.pc/(soma_antigo.pc + soma_antigo.pnc))*100 );
    printf("\nImobiliza��o do Patrim�nio L�quido        %.2f%%  %.2f%%", (imob_atual/soma_atual.pl)*100, (imob_antigo/soma_antigo.pl)*100 );

    printf("\n\n\n �NDICES DE LIQUIDEZ \n");
    printf("\nLiquidez Geral                            %.2f    %.2f  ", (soma_atual.ac + atrl_atual)/(soma_atual.pc + soma_atual.pnc), (soma_antigo.ac + atrl_antigo)/(soma_antigo.pc + soma_antigo.pnc) );
    printf("\nLiquidez Corrente                         %.2f    %.2f  ", soma_atual.ac/soma_atual.pc, soma_antigo.ac/soma_antigo.pc );
    printf("\nLiquidez Seca                             %.2f    %.2f  ", (disp_atual+aplFin_atual+client_atual)/soma_atual.pc, (disp_antigo+aplFin_antigo+client_antigo)/soma_antigo.pc );

    printf("\n\n\n �NDICES DE RENTABILIDADE \n");
    printf("\nGiro do Ativo                             %.2f%%  %.2f%%", (vendas_atual/(soma_atual.ac+soma_atual.anc))*100, (vendas_antigo/(soma_antigo.ac+soma_antigo.anc))*100 );
    printf("\nMargem L�quida                            %.2f%%  %.2f%%", (soma_atual.dre/vendas_atual)*100, (soma_antigo.dre/vendas_antigo)*100 );
    printf("\nRentabilidade do Ativo                    %.2f%%  %.2f%%", (soma_atual.dre/(soma_atual.ac+soma_atual.anc))*100, (soma_antigo.dre/(soma_antigo.ac+soma_antigo.anc))*100 );
    printf("\nRentabilidade do Patrim�nio L�quido       %.2f%%  %.2f%%", (soma_atual.dre/((soma_atual.pl+soma_antigo.pl)/2))*100, (soma_antigo.dre/((soma_antigo.pl+soma_atual.pl)/2))*100);

    printf("\n\n\n\n");
}
