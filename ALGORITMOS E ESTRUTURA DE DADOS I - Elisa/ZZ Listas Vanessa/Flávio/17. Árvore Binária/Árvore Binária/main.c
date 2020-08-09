#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    arvore *a;
    noarvore *no; 
    a = criaarvore();
    insereelementoit(a,10);
    insereelementoit(a,5);
    insereelementoit(a,15);
    insereelementoit(a,20);  
    insereelementoit(a,35);
    insereelementoit(a,25);
    insereelementoit(a,40);
    insereelementoit(a,38);
    
    no = retornaraiz(a);
    predecessor(no,35);
    percorreemordem(no);
    
    return 0;
}