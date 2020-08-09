#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    char palavra[10];
    int i;

    printf ("Digite uma palavra: ");
    scanf (" %[^\abc]",palavra);    			//-->Leria toda cadeia de caracter até achar abc
    printf ("\nA palavra digitada eh %s\n",palavra);

    return 0;
}
