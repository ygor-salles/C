#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Questão A
typedef struct funcionario
{
    long int mat, cpf, rg, titulo, conta, nascimento, dias_falta, dep, nascimento_dep;
    char transporte, refeicao, nome[51], endereco[51], civil[51], sexo, parentesco[51];
    float sb, hr_ext;
} tfuncionario;

//Questão B
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
        printf ("Digite RG: ");
        scanf ("%d",&list[i].rg);
        printf ("Digite titulo: ");
        scanf ("%d",&list[i].titulo);
        printf ("Digite conta: ");
        scanf ("%d",&list[i].conta);
        printf ("Digite salario base: ");
        scanf ("%f",&list[i].sb);
        printf ("Digite quantidade de hr extra: ");
        scanf ("%f",&list[i].hr_ext);
        printf ("Digite nascimento: ");
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
                scanf (" %s",list[j].parentesco);
                printf ("Informe o ano de nascimento do parente: ");
                scanf ("%d",&list[j].nascimento_dep);
            }
        }
        printf ("\n");
    }
    return ;
}

//Questão C
void imprime_dados (tfuncionario list[], int n)
{
    int i, j;

    for (i=0; i<n; i++){
        printf ("\nNome: %s     Endereço: %s    Estado Civil: %s    Sexo: %c",list[i].nome, list[i].endereco, list[i].civil, list[i].sexo);
        printf ("\nMatricula: %d     CPF: %d    RG: %d    Titulo: %d    Conta: %d",list[i].mat, list[i].cpf, list[i].rg, list[i].titulo, list[i].conta);
        printf ("\nSalario base: R$%.2f     Hora extra: %.2f",list[i].sb, list[i].hr_ext);
        printf ("\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refeição: %c  QTD Dependentes: %d",list[i].nascimento, list[i].dias_falta, list[i].transporte, list[i].refeicao, list[i].dep);
        if (list[i].dep>0){
            for (j=0; j<list[i].dep; j++){
                printf ("\nParente: %s      Data de nascimento: %d\n",list[j].parentesco, list[j].nascimento_dep);
            }
        }
        printf ("\n");
    }

    //Proventos
    float sal_fam[n], extra[n], proventos[n];
    for (i=0; i<n; i++){
        sal_fam[i]=0;
        if (list[i].hr_ext>0){
            extra[i] = list[i].hr_ext*((list[i].sb/220)+((list[i].sb/220)*0.5));
        }
        if (list[i].dep>0){
            for (j=0; j<list[i].dep; j++){
                if (list[j].nascimento_dep > 2004){
                    sal_fam[i] = sal_fam[i] + 120;
                }
            }
        }
        printf ("\n (%s) - Extra (%.2f)",extra[i]);
        printf ("\n (%s) - Salário Família: (%.2f)",sal_fam[i]);
        proventos[i] = list[i].sb + sal_fam[i] + extra[i];
        printf (" \n (%s) - PROVENTOS: %.2f\n",list[i].nome, proventos[i]);
    }
    printf ("\n");

    //Descontos
    float porc_inss[n], aux_saude[n], refeicao[n], transporte[n], falta[n], fgts[n], descontos[n], aux_saude_dep, soma=0;
    for (i=0; i<n; i++){
        if (list[i].dias_falta>0)
            falta[i] = (list[i].dias_falta*8)*(list[i].sb/220);
            printf ("\n (%s) - Falta: %.2f",list[i].nome, falta[i]);

        if (list[i].sb<=10000)
            porc_inss[i] = 0.09;
        else if (list[i].sb>10000 && list[i].sb<=25000)
            porc_inss[i] = 0.15;
        else if (list[i].sb>25000)
            porc_inss[i] = 0.25;
        printf ("\n (%s) - Valor inss: %.2f",list[i].nome, proventos[i]*porc_inss[i]);

        fgts[i] = (proventos[i]*0.08);

        if (list[i].refeicao == 's' || list[i].refeicao == 'S')
            refeicao[i] = list[i].sb*0.20;
            printf ("\n (%s) - Refeição: %.2f",list[i].nome, refeicao[i]);

        if (list[i].transporte == 's' || list[i].transporte == 'S')
             transporte[i] = list[i].sb*0.06;
             printf ("\n (%s) - Transpote: %.2f",list[i].nome, transporte[i]);

        aux_saude[i] = list[i].sb*0.015;
        if (list[i].dep > 0)
        {
              for (j=0; j<list[i].dep; j++){
                if (list[j].nascimento_dep > 2004)
                    aux_saude_dep = list[i].sb*0.02;
                else
                    aux_saude_dep = list[i].sb*0.03;
                soma = soma + aux_saude_dep;
              }
        }
        aux_saude[i] = aux_saude[i] + soma;
        printf ("\n (%s) - auxilio saude: %.2f",list[i].nome, aux_saude[i]);

        descontos[i] = (proventos[i]*porc_inss[i]) + refeicao[i] + transporte[i] + aux_saude[i] + falta[i];
        printf (" \n (%s) - DESCONTO: %.2f\n",list[i].nome, descontos[i]);
    }

    //Salario líquido
    for (i=0; i<n; i++)
        printf (" \n (%s) - SALÁRIO LÍQUIDO: %.2f\n",list[i].nome, proventos[i]-descontos[i]);

    return ;
}

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    int n, i, j;
    FILE *arq;
    arq = fopen("funcionarios.txt","w+");

    if (arq == NULL){
        printf ("\nArquivo não encontrado!\n");
        exit(1);
        return 0;
    }

    printf ("Digite a quantidade de funcionários: ");
    scanf ("%d",&n);
    tfuncionario lista[n];

    preencher_dados (lista, n);

    for (i=0; i<n; i++){
        fprintf (arq, "\nNome: %s     Endereço: %s    Estado Civil: %s    Sexo: %c",lista[i].nome, lista[i].endereco, lista[i].civil, lista[i].sexo);
        fprintf (arq, "\nMatricula: %d     CPF: %d    RG: %d    Titulo: %d    Conta: %d",lista[i].mat, lista[i].cpf, lista[i].rg, lista[i].titulo, lista[i].conta);
        fprintf (arq, "\nSalario base: R$%.2f     Hora extra: %.2f",lista[i].sb, lista[i].hr_ext);
        fprintf (arq, "\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refeição: %c  QTD Dependentes: %d\n",lista[i].nascimento, lista[i].dias_falta, lista[i].transporte, lista[i].refeicao, lista[i].dep);
        if (lista[i].dep>0){
            for (j=0; j<lista[i].dep; j++){
                fprintf (arq, "\nParente: %s      Data de nascimento: %d\n",lista[j].parentesco, lista[j].nascimento_dep);
            }
        }
        fprintf (arq, "\n\n");
    }
    rewind(arq);

    for (i=0; i<n; i++){
        fscanf (arq, " %s %s %s %c %d %d %d %d %d %f %f %d %d %c %c %d",lista[i].nome, lista[i].endereco, lista[i].civil, &lista[i].sexo, &lista[i].mat, &lista[i].cpf, &lista[i].rg, &lista[i].titulo, &lista[i].conta, &lista[i].sb, &lista[i].hr_ext, &lista[i].nascimento, &lista[i].dias_falta, &lista[i].transporte, &lista[i].refeicao, &lista[i].dep);
        if (lista[i].dep>0){
            for (j=0; j<lista[i].dep; j++){
                fscanf (arq, " %s %d",lista[j].parentesco, &lista[j].nascimento_dep);
            }
        }
    }

    imprime_dados(lista, n);

    /*//Impressao no arquivo
    for (i=0; i<n; i++){
        fprintf (arq, "\n (%s) - Extra (%.2f)",extra[i]);
        fprintf (arq, "\n (%s) - Salário Família: (%.2f)",sal_fam[i]);
        fprintf (arq,  "\n (%s) - PROVENTOS: %.2f\n",list[i].nome, proventos[i]);
        fprintf (arq, "\n (%s) - Falta: %.2f",list[i].nome, falta[i]);
        fprintf (arq, "\n (%s) - Valor inss: %.2f",list[i].nome, proventos[i]*porc_inss[i]);
        fprintf (arq, "\n (%s) - Refeição: %.2f",list[i].nome, refeicao[i]);
        fprintf (arq, "\n (%s) - Transpote: %.2f",list[i].nome, transporte[i]);
        fprintf (arq, "\n (%s) - auxilio saude: %.2f",list[i].nome, aux_saude[i]);
        fprintf (arq,  "\n (%s) - DESCONTO: %.2f\n",list[i].nome, descontos[i]);
        fprintf (arq,  "\n (%s) - SALÁRIO LÍQUIDO: %.2f\n",list[i].nome, proventos[i]-descontos[i]);
    }*/

    printf ("\n\n");
    fclose(arq);
    system ("pause");
}
