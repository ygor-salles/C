#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*6. Faça uma função para criptografar uma frase digitada pelo usuário.
A criptografia deverá substituir todas as vogais por *. Utilize a função no programa principal.
A frase poderá ter, no máximo, 50 caracteres */

void criptografia (char vogal[]);

int main ()
{
    char vogal[50];
    setlocale(LC_ALL, "Portuguese");
    printf ("Digite uma frase: ");
    scanf (" %[^\n]",vogal);

    criptografia (vogal);
    printf ("\n %s \n",vogal);
    return 0;
}

void criptografia (char vogal[])
{
    int i;
    for (i=0; i<=50; i++){
        if (vogal[i]=='a' || vogal[i]=='e' || vogal[i]=='i' || vogal[i]=='o' || vogal[i]=='u' || vogal[i]=='A' || vogal[i]=='E' || vogal[i]=='I' || vogal[i]=='O' || vogal[i]=='U'){
            vogal[i] = '*';
            i++;
        }
    }
    return ;
}
