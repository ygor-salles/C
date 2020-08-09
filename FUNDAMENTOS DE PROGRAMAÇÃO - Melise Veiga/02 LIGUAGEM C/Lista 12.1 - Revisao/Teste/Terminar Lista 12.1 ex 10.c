#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

typedef struct funcionario
{
    long mat, cpf, rg, titulo, conta, nascimento, dias_falta, dep, nascimento_dep[10];
    char transporte, refeicao, nome[51], endereco[51], civil[51], sexo, parentesco[10][51];
    float sb, hr_ext;
} tfuncionario;

void preencher_dados (tfuncionario lista[], int n);
void imprime_dados (tfuncionario lista[], int n);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, n;
    printf ("Digite a quantidade de funcionários: ");
    scanf ("%d",&n);
    tfuncionario lista[n];

    preencher_dados (lista, n);
    imprime_dados(lista, n);
    return 0;
}

void preencher_dados (tfuncionario lista[], int n)
{
    int i, j;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",lista[i].nome);
        printf ("Digite endereço: ");
        scanf (" %[^\n]",lista[i].endereco);
        printf ("Digite estado civil: ");
        scanf (" %[^\n]",lista[i].civil);
        printf ("Digite sexo(M / F): ");
        scanf (" %c",&lista[i].sexo);
        printf ("Digite matricula: ");
        scanf ("%d",&lista[i].mat);
        printf ("Digite CPF: ");
        scanf ("%d",&lista[i].cpf);
        printf ("Digite RG(somente numeros): MG-");
        scanf ("%d",&lista[i].rg);
        printf ("Digite titulo(somente numeros): MG-");
        scanf ("%d",&lista[i].titulo);
        printf ("Digite conta: ");
        scanf ("%d",&lista[i].conta);
        printf ("Digite salario base: ");
        scanf ("%f",&lista[i].sb);
        printf ("Digite quantidade de hr extra: ");
        scanf ("%f",&lista[i].hr_ext);
        printf ("Digite ano nascimento: ");
        scanf ("%d",&lista[i].nascimento);
        printf ("Digite dias faltosos: ");
        scanf ("%d",&lista[i].dias_falta);
        printf ("Digite transporte(S / N): ");
        scanf (" %c",&lista[i].transporte);
        printf ("Digite refeicao (S / N): ");
        scanf (" %c",&lista[i].refeicao);
        printf ("Quantidade de dependentes: ");
        scanf ("%d",&lista[i].dep);
        if (lista[i].dep>0){
            for (j=0; j<lista[i].dep; j++){
                printf ("Informe o parentesco: ");
                scanf (" %[^\n]",lista[i].parentesco[j]);
                printf ("Informe o ano de nascimento do parente: ");
                scanf ("%d",&lista[i].nascimento_dep[j]);
            }
        }
        printf ("\n");
    }
    printf ("#####################################################################################");
    printf ("\n");
    return ;
}

void imprime_dados (tfuncionario lista[], int n)
{
    int i, j;

    float porc_inss[n], aux_saude[n], refeicao[n], transporte[n], falta[n], fgts[n], descontos[n], aux_saude_dep, soma, sal_fam[n], extra[n], proventos[n];
    for (i=0; i<n; i++){
        printf ("\nNome: %s     Endereço: %s    Estado Civil: %s    Sexo: %c",lista[i].nome, lista[i].endereco, lista[i].civil, lista[i].sexo);
        printf ("\nMatricula: %d     CPF: %d    RG: %d    Titulo: %d    Conta: %d",lista[i].mat, lista[i].cpf, lista[i].rg, lista[i].titulo, lista[i].conta);
        printf ("\nSalario base: R$%.2f     Hora extra: %.2f",lista[i].sb, lista[i].hr_ext);
        printf ("\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refeição: %c  QTD Dependentes: %d\n",lista[i].nascimento, lista[i].dias_falta, lista[i].transporte, lista[i].refeicao, lista[i].dep);
        if (lista[i].dep>0){
            for (j=0; j<lista[i].dep; j++){
                printf ("Parente: %s      Data de nascimento: %d\n",lista[i].parentesco[j], lista[i].nascimento_dep[j]);
            }
        }
        printf ("\n");


    //Proventos
        extra[i] = 0;
        if (lista[i].hr_ext>0)
            extra[i] = lista[i].hr_ext*((lista[i].sb/220)+((lista[i].sb/220)*0.5));

        sal_fam[i] = 0;
        if (lista[i].dep>0){
            for (j=0; j<lista[i].dep; j++){
                if (lista[i].nascimento_dep[j] > 2004){
                    sal_fam[i] = sal_fam[i] + 120;
                }
            }
        }
        printf ("\n Extra (%.2f)  |  Salário Família: (%.2f)",extra[i], sal_fam[i]);
        proventos[i] = lista[i].sb + sal_fam[i] + extra[i];
        printf ("\n PROVENTOS: %.2f\n", proventos[i]);

    //Descontos
        falta[i] = 0;
        if (lista[i].dias_falta>0)
            falta[i] = (lista[i].dias_falta*8)*(lista[i].sb/220);
        printf ("\n Falta: %.2f",falta[i]);

        if (lista[i].sb<=10000)
            porc_inss[i] = 0.09;
        else if (lista[i].sb>10000 && lista[i].sb<=25000)
            porc_inss[i] = 0.15;
        else if (lista[i].sb>25000)
            porc_inss[i] = 0.25;
        printf ("\n Valor inss: %.2f",proventos[i]*porc_inss[i]);

        fgts[i] = (proventos[i]*0.08);

        refeicao[i] = 0;
        if (lista[i].refeicao == 's' || lista[i].refeicao == 'S')
            refeicao[i] = lista[i].sb*0.20;
        printf ("\n Refeição: %.2f",refeicao[i]);

        transporte[i] = 0;
        if (lista[i].transporte == 's' || lista[i].transporte == 'S')
             transporte[i] = lista[i].sb*0.06;
        printf ("\n Transpote: %.2f",transporte[i]);

        soma = 0;
        aux_saude[i] = lista[i].sb*0.015;
        if (lista[i].dep > 0)
        {
            for (j=0; j<lista[i].dep; j++){
                if (lista[i].nascimento_dep[j] > 2004)
                    aux_saude_dep = lista[i].sb*0.02;
                else
                    aux_saude_dep = lista[i].sb*0.03;
                soma = soma + aux_saude_dep;
              }
        }
        aux_saude[i] = aux_saude[i] + soma;
        printf ("\n auxilio saude: %.2f",aux_saude[i]);

        descontos[i] = (proventos[i]*porc_inss[i]) + refeicao[i] + transporte[i] + aux_saude[i] + falta[i];
        printf ("\n DESCONTO: %.2f\n",descontos[i]);

    //Salario líquido
        printf (" \n(%s) - SALÁRIO LÍQUIDO: %.2f\n",lista[i].nome, proventos[i]-descontos[i]);
        printf ("-------------------------------------------------------------------------------------------\n");
    }

    return ;
}

















/*void imprime_dados (tfuncionario lista[], int n, float extra[], float sal_fam[], float proventos[], float falta[], float porc_inss[], float refeicao[], float transporte[], float aux_saude[], float descontos[])*/
/*float mein_extra[n], mein_sal_fam[n], mein_proventos[n], mein_falta[n], mein_porc_inss[n], mein_refeicao[n], mein_transporte[n], mein_aux_saude[n], mein_descontos[n];
    imprime_dados(lista, n, mein_extra, mein_sal_fam, mein_proventos, mein_falta, mein_porc_inss, mein_refeicao, mein_transporte, mein_aux_saude, mein_descontos);

    //Impressao no arquivo
    for (i=0; i<n; i++){
        fprintf (arq, "\n (%s) - Extra (%.2f)",lista[i].nome, mein_extra[i]);
        fprintf (arq, "\n (%s) - Salário Família: (%.2f)",lista[i].nome, mein_sal_fam[i]);
        fprintf (arq,  "\n (%s) - PROVENTOS: %.2f\n",lista[i].nome, mein_proventos[i]);
        fprintf (arq, "\n (%s) - Falta: %.2f",lista[i].nome, mein_falta[i]);
        fprintf (arq, "\n (%s) - Valor inss: %.2f",lista[i].nome, mein_proventos[i]*mein_porc_inss[i]);
        fprintf (arq, "\n (%s) - Refeição: %.2f",lista[i].nome, mein_refeicao[i]);
        fprintf (arq, "\n (%s) - Transpote: %.2f",lista[i].nome, mein_transporte[i]);
        fprintf (arq, "\n (%s) - auxilio saude: %.2f",lista[i].nome, mein_aux_saude[i]);
        fprintf (arq,  "\n (%s) - DESCONTO: %.2f\n",lista[i].nome, mein_descontos[i]);
        fprintf (arq,  "\n (%s) - SALÁRIO LÍQUIDO: %.2f\n",lista[i].nome, mein_proventos[i]-mein_descontos[i]);
    }*/
