#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

/* 10. Os dados dos funcion�rios de uma empresa s�o armazenados em um arquivo funcionarios.dat. O arquivo cont�m registros com os campos: matr�cula, nome, endere�o, cpf, rg,
titulo de eleitor, estado civil, sexo, data nascimento, conta corrente, valor do sal�rio base (SB), num_horas_extras, num_de_dias_faltados, vale transporte(S/N), vale refei��o (S/N),
num dependentes - para cada dependente: grau de parentesco (filho, esposa), data nascimento.
a. Defina uma estrutura para representar os dados dos funcion�rios.
b. Elabore uma fun��o para ler os dados dos funcion�rios de um arquivo e preencher um vetor de funcion�rios com esses dados.
c. Elabore uma fun��o que receba o cpf de um funcion�rio e imprimir os seus dados.
Al�m dos dados originais, deve ser calculado e impresso o valor do sal�rio l�quido considerando os descontos e os proventos a partir do sal�rio base conforme as regras a seguir:
Proventos:
Valor do sal�rio fam�lia: R$ 120,00 por filho com menos de 14 anos.
Para cada hora extra o valor da hora � 50% mais que a hora normal.
Proventos = sal�rio base + sal�rio fam�lia + hora extra
Descontos:
Para cada dia faltado diminuir 8 horas de trabalho.
Tabela de desconto de INSS sobre todos os proventos: de 0 a 10 SB - 9%
de 10 a 25 SB - 15%
acima de 25 SB - 25%
Desconto do FGTS equivale a 8% do valor bruto de proventos.
Vale refei��o - 20% do SB.
Vale transporte - 6% do SB.
Tabela de desconto de auxilio sa�de - todos os funcion�rios possuem
titular - 1,5% do sal�rio bruto.
dependentes - esposa - 3% do sal�rio bruto
filhos at� 14 anos - 2% do sal�rio bruto
filhos acima de 14 anos - 3% do sal�rio bruto.
Desconto = (proventos * % do INSS) + vale refei��o + vale transporte + auxilio sa�de +
valor faltas
Sal�rio L�quido: proventos - descontos */

typedef struct funcionario
{
    int nascimento, dias_falta, dep, nascimento_dep[10];
    char mat[51], conta[51], cpf[51], rg[51], titulo[51], transporte, refeicao, nome[51], endereco[51], civil[51], sexo, parentesco[10][51];
    float sb, hr_ext;
} tfuncionario;

void preencher_dados (int n, tfuncionario lista[], int i, int j);
void imprime_dados (int n, tfuncionario lista[], int i, int j, float porc_inss[], float aux_saude[], float refeicao[], float transporte[], float falta[], float fgts[], float descontos[], float aux_saude_dep, float soma, float sal_fam[], float extra[], float proventos[]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, n;
    printf ("Digite a quantidade de funcion�rios: ");
    scanf ("%d",&n);
    tfuncionario lista[n];
    float porc_inss[n], aux_saude[n], refeicao[n], transporte[n], falta[n], fgts[n], descontos[n], aux_saude_dep, soma, sal_fam[n], extra[n], proventos[n];

    FILE *arq;
    arq = fopen("funcionario.txt","w+");
    if (arq == NULL){
        printf ("ARQUIVO N�O ENCONTRADO!");
        exit(1);
    }
    else{
        for (i=0; i<n; i++){
            preencher_dados (n, lista, i, j);
            fprintf (arq, "\nNome: %s     Endere�o: %s    Estado Civil: %s    Sexo: %c",lista[i].nome, lista[i].endereco, lista[i].civil, lista[i].sexo);
            fprintf (arq, "\nMatricula: %s     CPF: %s    RG: %s    Titulo: %s",lista[i].mat, lista[i].cpf, lista[i].rg, lista[i].titulo);
            fprintf (arq, "\nSalario base: R$%.2f     Hora extra: %.2f      Conta: %s",lista[i].sb, lista[i].hr_ext, lista[i].conta);
            fprintf (arq, "\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refei��o: %c  QTD Dependentes: %d\n",lista[i].nascimento, lista[i].dias_falta, lista[i].transporte, lista[i].refeicao, lista[i].dep);
            if (lista[i].dep>0){
                for (j=0; j<lista[i].dep; j++){
                    fprintf (arq, "Parente: %s      Data de nascimento: %d\n",lista[i].parentesco[j], lista[i].nascimento_dep[j]);
                }
            }

            imprime_dados(n, lista, i, j, porc_inss, aux_saude, refeicao, transporte, falta, fgts, descontos, aux_saude_dep, soma, sal_fam, extra, proventos);

            fprintf (arq, "\n Extra (%.2f)",extra[i]);
            fprintf (arq, "\n Sal�rio Fam�lia: (%.2f)",sal_fam[i]);
            fprintf (arq,  "\n PROVENTOS: %.2f\n",proventos[i]);
            fprintf (arq, "\n Falta: %.2f",falta[i]);
            fprintf (arq, "\n Valor inss: %.2f",proventos[i] * porc_inss[i]);
            fprintf (arq, "\n Refei��o: %.2f",refeicao[i]);
            fprintf (arq, "\n Transpote: %.2f",transporte[i]);
            fprintf (arq, "\n Auxilio saude: %.2f",aux_saude[i]);
            fprintf (arq,  "\n DESCONTO: %.2f\n",descontos[i]);
            fprintf (arq,  "\n SAL�RIO L�QUIDO: %.2f\n",proventos[i]-descontos[i]);
            fprintf (arq, "\n####################################################################################\n");
        }

        rewind(arq);

        for (i=0; i<n; i++){
            fscanf (arq, " %[^\n] %[^\n] %[^\n] %c %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %f %f %d %d %c %c %d",lista[i].nome, lista[i].endereco, lista[i].civil, &lista[i].sexo, &lista[i].mat, &lista[i].cpf, &lista[i].rg, &lista[i].titulo, &lista[i].conta, &lista[i].sb, &lista[i].hr_ext, &lista[i].nascimento, &lista[i].dias_falta, &lista[i].transporte, &lista[i].refeicao, &lista[i].dep);
            if (lista[i].dep>0){
                for (j=0; j<lista[i].dep; j++){
                    fscanf (arq, " %[^\n] %d",lista[i].parentesco[j], &lista[i].nascimento_dep[j]);
                }
            }
        }
    }

    printf ("\n\n");
    fclose(arq);
    system("pause");
    return 0;
}

void preencher_dados (int n, tfuncionario lista[], int i, int j)
{
        printf ("\nDigite nome: ");
        scanf (" %[^\n]",lista[i].nome);
        printf ("Digite endere�o: ");
        scanf (" %[^\n]",lista[i].endereco);
        printf ("Digite estado civil: ");
        scanf (" %[^\n]",lista[i].civil);
        printf ("Digite sexo(M / F): ");
        scanf (" %c",&lista[i].sexo);
        printf ("Digite matricula: ");
        scanf (" %[^\n]",&lista[i].mat);
        printf ("Digite CPF: ");
        scanf (" %[^\n]",&lista[i].cpf);
        printf ("Digite RG: ");
        scanf (" %[^\n]",&lista[i].rg);
        printf ("Digite titulo: ");
        scanf (" %[^\n]",&lista[i].titulo);
        printf ("Digite conta: ");
        scanf (" %[^\n]",&lista[i].conta);
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
    printf ("\n----------------------------------------------------------------------------");
    system("CLS");

    return ;
}

void imprime_dados (int n, tfuncionario lista[], int i, int j, float porc_inss[], float aux_saude[], float refeicao[], float transporte[], float falta[], float fgts[], float descontos[], float aux_saude_dep, float soma, float sal_fam[], float extra[], float proventos[])
{
        printf ("\nNome: %s     Endere�o: %s    Estado Civil: %s    Sexo: %c",lista[i].nome, lista[i].endereco, lista[i].civil, lista[i].sexo);
        printf ("\nMatricula: %s     CPF: %s    RG: %s    Titulo: %s",lista[i].mat, lista[i].cpf, lista[i].rg, lista[i].titulo);
        printf ("\nSalario base: R$%.2f     Hora extra: %.2f       Conta: %s",lista[i].sb, lista[i].hr_ext, lista[i].conta);
        printf ("\nNascimento: %d    Dias Faltosos: %d    Transporte: %c  Refei��o: %c  QTD Dependentes: %d\n",lista[i].nascimento, lista[i].dias_falta, lista[i].transporte, lista[i].refeicao, lista[i].dep);
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
        printf (" Extra (%.2f)  |  Sal�rio Fam�lia: (%.2f)",extra[i], sal_fam[i]);
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
        printf ("\n Refei��o: %.2f",refeicao[i]);

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

    //Salario l�quido
        printf (" \n(%s) - SAL�RIO L�QUIDO: %.2f\n",lista[i].nome, proventos[i]-descontos[i]);
        printf ("###########################################################################################\n");

    return ;
}
