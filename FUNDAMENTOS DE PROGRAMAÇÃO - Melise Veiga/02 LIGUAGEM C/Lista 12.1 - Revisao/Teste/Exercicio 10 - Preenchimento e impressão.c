#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct funcionario
{
    long mat, cpf, rg, titulo, conta, nascimento, dias_falta, dep, nascimento_dep[10];
    char transporte, refeicao, nome[51], endereco[51], civil[51], sexo, parentesco[10][51];
    float sb, hr_ext;
} tfuncionario;

void preencher_dados (tfuncionario list[], int n)
{
    int i, j;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",list[i].nome);
        printf ("Digite endereço: ");
        scanf (" %[^\n]",list[i].endereco);
        printf ("Digite estado civil: ");
        scanf (" %[^\n]",list[i].civil);
        printf ("Digite sexo(M / F): ");
        scanf (" %c",&list[i].sexo);
        printf ("Digite matricula: ");
        scanf ("%d",&list[i].mat);
        printf ("Digite CPF: ");
        scanf ("%d",&list[i].cpf);
        printf ("Digite RG(somente numeros): MG-");
        scanf ("%d",&list[i].rg);
        printf ("Digite titulo(somente numeros): MG-");
        scanf ("%d",&list[i].titulo);
        printf ("Digite conta: ");
        scanf ("%d",&list[i].conta);
        printf ("Digite salario base: ");
        scanf ("%f",&list[i].sb);
        printf ("Digite quantidade de hr extra: ");
        scanf ("%f",&list[i].hr_ext);
        printf ("Digite ano nascimento: ");
        scanf ("%d",&list[i].nascimento);
        printf ("Digite dias faltosos: ");
        scanf ("%d",&list[i].dias_falta);
        printf ("Digite transporte(S / N): ");
        scanf (" %c",&list[i].transporte);
        printf ("Digite refeicao (S / N): ");
        scanf (" %c",&list[i].refeicao);
        printf ("Quantidade de dependentes: ");
        scanf ("%d",&list[i].dep);
        if (list[i].dep>0){
            for (j=0; j<list[i].dep; j++){
                printf ("Informe o parentesco: ");
                scanf (" %[^\n]",list[i].parentesco[j]);
                printf ("Informe o ano de nascimento do parente: ");
                scanf ("%d",&list[i].nascimento_dep[j]);
            }
        }
        printf ("\n");
    }
    return ;
}

void imprime_dados (tfuncionario list[], int n)
{
    int i, j;
    for (i=0; i<n; i++){
        printf ("\nNome: %s     Endereço: %s    Estado Civil: %s    Sexo: %c",list[i].nome, list[i].endereco, list[i].civil, list[i].sexo);
        printf ("\nMatricula: %d     CPF: %d    RG: %d    Titulo: %d    Conta: %d",list[i].mat, list[i].cpf, list[i].rg, list[i].titulo, list[i].conta);
        printf ("\nSalario base: R$%.2f     Hora extra: %.2f",list[i].sb, list[i].hr_ext);
        printf ("\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refeição: %c  QTD Dependentes: %d\n",list[i].nascimento, list[i].dias_falta, list[i].transporte, list[i].refeicao, list[i].dep);
        if (list[i].dep>0){
            for (j=0; j<list[i].dep; j++){
                printf ("Parente: %s      Data de nascimento: %d\n",list[i].parentesco[j], list[i].nascimento_dep[j]);
            }
        }
        printf ("\n");
    }
    return ;
}

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

/*void imprime_dados (tfuncionario list[], int n, float extra[], float sal_fam[], float proventos[], float falta[], float porc_inss[], float refeicao[], float transporte[], float aux_saude[], float descontos[])*/
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

