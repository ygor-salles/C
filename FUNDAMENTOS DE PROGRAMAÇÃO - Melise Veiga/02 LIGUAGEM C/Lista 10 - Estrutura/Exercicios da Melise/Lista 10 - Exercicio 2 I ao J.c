typedef struct livro
{
    int cod, ano;
    char tit[101], status;
}tlivro;

void alteraStatus (tlivro lista[], int n)
{
    int i;
    for (i=0; i<n; i++)
        if (lista[i].ano>1950)
            lista[i].status = 'A';
        else
            lista[i].status = 'N';
}

int main ()
{
    tlivro lista[50];
    int i, n;
    
    printf ("Digite n: ");
    scanf ("%d",&n);
    if (n>0 && n<=50){
        for (i=0; i<n; i++){
            printf ("Digite os valores: ");
            scanf (" %[^\n] %d %d", lista[i].tit, &lista[i].cod, &lista[i].ano);
        }
        alteraStatus (lista, n);
    }
    return 0;
}