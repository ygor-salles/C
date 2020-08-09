#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    arvore *a = criaarvore();;
    noarvore *no;
    insereelementoit(a,5);
    insereelementoit(a,3);
    insereelementoit(a,7);
    insereelementoit(a,2);
    insereelementoit(a,6);
    insereelementoit(a,10);
    insereelementoit(a,8);
    insereelementoit(a,9);
    

    no = retornaraiz(a);
    printf("\n\nA altura da árvore é: %d\n\n",altura(no));
    printf("\nO maior valor é: %d\n\n",maiorvalor(no));
    printf("\nO menor valor é: %d\n\n",menorvalor(no)); 
    
    return 0;
}