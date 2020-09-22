#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

/* SISTEMA DE AN�LISE DE INVESTIMENTOS */

void menu();
void capitalizacao_simples();
void juros_simples();
void cap_composta();
void juros_compostos();
void uniforme_atual();
void uniforme_futuro();
void gradiente_atual();
void gradiente_futuro();
void gradiente_geometrico();
void vpl();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;

    do{
        menu();
        scanf("%d",&op);
        system("CLS");

        switch (op){
            case 1: capitalizacao_simples(); break;
            case 2: juros_simples(); break;
            case 3: cap_composta(); break;
            case 4: juros_compostos(); break;
            case 5: uniforme_atual(); break;
            case 6: uniforme_futuro(); break;
            case 7: gradiente_atual(); break;
            case 8: gradiente_futuro(); break;
            case 9: gradiente_geometrico(); break;
            case 10: vpl(); break;
            case 11: printf("\n\nFinalizando...\n"); break;
            default: printf("Op��o inv�lida!"); break;
        }

        printf("\n\n");
        system("pause");
        system("CLS");

  } while(op != 11);

  return 0;
}

void menu()
{
    int i;
    //TELA DE EXIBI��O AO INICIAR O SISTEMA
    printf("    #############################################################\n");
    for (i=0; i<7; i++){
        if (i==3)
            printf("    #            SISTEMA DE AN�LISE DE INVESTIMENTOS            #\n");
            printf("    #                                                           #\n");
    }
    printf("    #############################################################\n");

    printf("\n\n      ************ ....::: MENU DE OP��ES :::.... ************\n");
    printf("\n                ESCOLHA O N�MERO CONFORME OP��O DESEJADA\n");
    printf("\n                1 - Capitaliza��o Simples");
    printf("\n                2 - Juros Simples");
    printf("\n                3 - Capitaliza��o Composta");
    printf("\n                4 - Juros Compostos");
    printf("\n                5 - Fator de S�rie uniforme - data atual");
    printf("\n                6 - Fator de S�rie uniforme - data futura");
    printf("\n                7 - Fator de S�rie gradiente - data atual");
    printf("\n                8 - Fator de S�rie gradiente - data futura");
    printf("\n                9 - Fator de S�rie gradiente geom�trico - data atual");
    printf("\n                10 - VPL, VAUE(VAE), CAUE(CAE)");
    printf("\n                11 - Finalizar Programa");
    printf("\n                Opcao: ");
    return;
}

void capitalizacao_simples()
{
    int op;
    float s, p, i, n, resultado;
    printf("\n\n                ....:::  CAPITALIZA��O SIMPLES  :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Montante");
    printf("\n 2 - Capital");
    printf("\n 3 - Taxa");
    printf("\n 4 - Tempo");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p*( 1 + i * n);
        printf("\n\nMONTANTE = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = s/(1 + i * n);
        printf("\n\nCAPITAL = $%.2f\n\n",resultado);
    }
    else if (op == 3){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Tempo: "); scanf("%f",&n);
        resultado = (((s/p)-1)/n)*100;
        printf("\n\nTAXA = %.2f%%\n\n",resultado);
    }
    else if (op == 4){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        i = i/100;
        resultado = ((s/p)-1)/i;
        printf("\n\nTEMPO = %.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void juros_simples()
{
    int op;
    float j, p, i, n, resultado;
    printf("\n\n                    ....:::  JUROS SIMPLES  :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Rendimento de Juros");
    printf("\n 2 - Capital");
    printf("\n 3 - Taxa");
    printf("\n 4 - Tempo");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p * i * n;
        printf("\n\nRENDIMENTO DE JUROS = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = j/(n * i);
        printf("\n\nCAPITAL = $%.2f\n\n",resultado);
    }
    else if (op == 3){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Tempo: "); scanf("%f",&n);
        resultado = (j/(p * n))*100;
        printf("\n\nTAXA = %.2f%%\n\n",resultado);
    }
    else if (op == 4){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        i = i/100;
        resultado = j/(p * i);
        printf("\n\nTEMPO = %.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void cap_composta()
{
    int op;
    float s, p, i, n, resultado;
    printf("\n\n                ....:::  CAPITALIZA��O COMPOSTA  :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Montante");
    printf("\n 2 - Capital");
    printf("\n 3 - Taxa");
    printf("\n 4 - Tempo");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p*pow((1+i), n);
        printf("\n\nMONTANTE = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = s/pow((1+i), n);
        printf("\n\nCAPITAL = $%.2f\n\n",resultado);
    }
    else if (op == 3){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Tempo: "); scanf("%f",&n);
        resultado = (pow(s/p, 1/n) - 1) * 100;
        printf("\n\nTAXA = %.2f%%\n\n",resultado);
    }
    else if (op == 4){
        printf("\nInforme Montante: "); scanf("%f",&s);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        i = i/100;
        resultado = (log(s/p)) / (log(1+i));
        printf("\n\nTEMPO = %.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void juros_compostos()
{
    int op;
    float j, p, i, n, resultado;
    printf("\n\n                    ....:::  JUROS COMPOSTOS  :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Rendimento de Juros");
    printf("\n 2 - Capital");
    printf("\n 3 - Taxa");
    printf("\n 4 - Tempo");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p*(pow(1+i, n) - 1);
        printf("\n\nRENDIMENTO DE JUROS = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = j/(pow(1+i, n) - 1);
        printf("\n\nCAPITAL = $%.2f\n\n",resultado);
    }
    else if (op == 3){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Tempo: "); scanf("%f",&n);
        resultado = (pow((j/p)+1, 1/n) - 1) * 100;
        printf("\n\nTAXA = %.2f%%\n\n",resultado);
    }
    else if (op == 4){
        printf("\nInforme Juros: "); scanf("%f",&j);
        printf("Informe Capital: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        i = i/100;
        resultado = (log(j/p +1)) / (log(1+i));
        printf("\n\nTEMPO = %.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void uniforme_atual()
{
    int op;
    float r, p, i, n, a, soma=0, resultado;
    printf("\n\n            ....::: S�RIE UNIFORME - DATA ATUAL   :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Valor Atual (Capital Atual)");
    printf("\n 2 - Parcela");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Parcela: "); scanf("%f",&r);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        printf("Informe Acr�scimos (0 se n�o houve ou 0 para parar): \n");
        do{
            scanf("%f",&a);
            soma = soma + a;
        } while(a != 0);
        i = i/100;
        resultado = r * ( (pow(1+i, n)-1) / (pow(1+i, n) * i) );
        printf("\n\nVALOR ATUAL (CAPITAL ATUAL) = $%.2f\n\n",resultado);

        resultado = resultado + soma;
        printf("\n\nTOTAL (ATUAL + ACR�SCIMO) = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Valor Atual: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p / ( (pow(1+i, n)-1) / (pow(1+i, n) * i) );
        printf("\n\nPARCELA = $%.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void uniforme_futuro()
{
    int op;
    float r, f, i, n, a, soma=0, resultado;
    printf("\n\n            ....::: S�RIE UNIFORME - DATA FUTURA   :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Valor futuro (Montante)");
    printf("\n 2 - Parcela");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Parcela: "); scanf("%f",&r);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        printf("Informe Acr�scimos (0 se n�o houve ou 0 para parar): \n");
        do{
            scanf("%f",&a);
            soma = soma + a;
        } while(a != 0);
        i = i/100;
        resultado = r * ( (pow(1+i, n)-1) / i );
        printf("\n\nVALOR FUTURO (MONTANTE) = $%.2f\n\n",resultado);

        resultado = resultado + soma;
        printf("\n\nTOTAL (FUTURO + ACR�SCIMO) = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Valor Futuro: "); scanf("%f",&f);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = f / ( (pow(1+i, n)-1) / i );
        printf("\n\nPARCELA = $%.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void gradiente_atual()
{
    int op;
    float g, u, p, i, n, resultado, a, soma=0;
    printf("\n\n            ....::: S�RIE GRADIENTE - DATA ATUAL :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Valor Atual (Capital Atual)");
    printf("\n 2 - Parcela");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Parcela Gradiente: "); scanf("%f",&g);
        printf("Informe Parcela Uniforme: "); scanf("%f",&u);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        printf("Informe Acr�scimos (0 se n�o houve ou 0 para parar): \n");
        do{
            scanf("%f",&a);
            soma = soma + a;
        } while(a != 0);
        i = i/100;
        resultado = g * ( (pow(1+i, n)-i*n-1) / (pow(i, 2) * pow(1+i, n)) );
        printf("\n\nVALOR ATUAL GRADIENTE (CAPITAL ATUAL GRADIENTE) = $%.2f\n\n",resultado);

        resultado = resultado + soma + (u * ( (pow(1+i, n)-1) / (pow(1+i, n) * i) ) );
        printf("\n\nTOTAL (ATUAL GRADIENTE + UNIFORME + ACR�SCIMO) = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Valor Atual: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p / ( (pow(1+i, n)-i*n-1) / (pow(i, 2) * pow(1+i, n)) );
        printf("\n\nPARCELA GRADIENTE = $%.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void gradiente_futuro()
{
    int op;
    float g, u, f, i, n, resultado, a, soma=0;
    printf("\n\n            ....::: S�RIE GRADIENTE - DATA FUTURO :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Valor FUTURO (MONTANTE)");
    printf("\n 2 - Parcela");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Parcela Gradiente: "); scanf("%f",&g);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        printf("Informe Acr�scimos (0 se n�o houve ou 0 para parar): \n");
        do{
            scanf("%f",&a);
            soma = soma + a;
        } while(a != 0);
        i = i/100;
        resultado = g * ( (1/i) * ( ((pow(1+i, n)-1) / i) - n ) );
        printf("\n\nVALOR FUTURO GRADIENTE (CAPITAL FUTURO GRADIENTE) = $%.2f\n\n",resultado);

        resultado = resultado + soma + (u * ( (pow(1+i, n)-1) / (pow(1+i, n) * i) ));
        printf("\n\nVALOR PRESENTE TOTAL DA S�RIE GRADIENTE (PARCELAS UNIFORMES + PARCELAS GRADIENTES) �: $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Valor FUTURO: "); scanf("%f",&f);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = f / ( (1/i) * ( ((pow(1+i, n)-1) / i) - n ) );
        printf("\n\nPARCELA GRADIENTE = $%.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void gradiente_geometrico()
{
    int op;
    float g, p, i, n, resultado, a, s, soma=0;
    printf("\n\n            ....::: S�RIE GRADIENTE GEOM�TRICO - DATA ATUAL :::....\n");
    printf("INFORME QUAL VALOR QUER DESCOBRIR /OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS...\n");
    printf("\n 1 - Valor Atual (Capital Atual)");
    printf("\n 2 - Parcela");
    printf("\nOpcao: "); scanf("%d",&op);

    if (op == 1){
        printf("\nInforme Parcela: "); scanf("%f",&a);
        printf("Informe Taxa i(%%): "); scanf("%f",&i);
        printf("Informe Taxa g(%%): "); scanf("%f",&g);
        printf("Informe Tempo: "); scanf("%f",&n);
        printf("Informe Acr�scimos (0 se n�o houve ou 0 para parar): \n");
        do{
            scanf("%f",&s);
            soma = soma + s;
        } while(a != 0);
        i = i/100;
        resultado = a * ( (1- pow((1+g)/(1+i), n) ) / (i-g) );
        printf("\n\nVALOR ATUAL GEOM�TRICO (CAPITAL ATUAL GEOM�TRICO) = $%.2f\n\n",resultado);

        resultado = resultado + soma;
        printf("\n\nTOTAL (ATUAL GEOM�TRICO + ACR�SCIMO) = $%.2f\n\n",resultado);
    }
    else if (op == 2){
        printf("\nInforme Valor Atual: "); scanf("%f",&p);
        printf("Informe Taxa(%%): "); scanf("%f",&i);
        printf("Informe Tempo: "); scanf("%f",&n);
        i = i/100;
        resultado = p / ( (1- pow((1+g)/(1+i), n) ) / (i-g) );
        printf("\n\nPARCELA GEOM�TRICA = $%.2f\n\n",resultado);
    }
    else
        printf("\n\nOP��O INV�LIDA!..");

    return ;
}

void vpl()
{
    float r, i, n, a, investimento=0, resultado, rc, j;
    float vaue, caue;
    char op;
    printf("\n\n            ....::: VPL - VALOR PRESENTE L�QUIDO   :::....\n");
    printf("OBS: PER�ODO DA TAXA E TEMPO DEVEM SER IGUAIS e OS D�GITOS TUDO EM POSITIVO...\n");

    printf("\nInforme Custo Operacional: "); scanf("%f",&r);
    printf("Informe Taxa(%%): "); scanf("%f",&i);
    printf("Informe Tempo: "); scanf("%f",&n);
    printf("Informe investimentos (0 se n�o houve ou 0 para parar): \n");
    do{
        scanf("%f",&a);
        investimento = investimento + a;
    } while(a != 0);
    printf("Informe valor a recuperar (0 se n�o houve): "); scanf("%f",&rc);
    printf("Houve diferen�a no tempo de recupera��o? (s/n): "); scanf(" %c",&op);
    j = n;
    if (op == 's' || op == 'S'){
        printf("Informe o novo Tempo de recupera��o: "); scanf("%f",&j);
    }

    i = i/100;
    resultado = r * ( (pow(1+i, n)-1) / (pow(1+i, n) * i) );
    resultado = -investimento - resultado + ( (rc)/(pow(1+i, j)) );

    printf("\n\nTOTAL VPL = $%.2f\n\n",resultado);

    vaue = resultado / ( (pow(1+i, n)-1) / (pow(1+i, n) * i) );
    printf("\n\nTOTAL VAUE = $%.2f\n\n",vaue);

    caue = -resultado / ( (pow(1+i, n)-1) / (pow(1+i, n) * i) );
    printf("\n\nTOTAL CAUE = $%.2f\n\n",caue);

    return ;
}
