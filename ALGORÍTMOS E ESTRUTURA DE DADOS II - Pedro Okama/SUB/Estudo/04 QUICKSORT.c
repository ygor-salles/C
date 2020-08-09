QUICKSORT

void particao(int esq, int dir, int *i, int *j, TipoItem *A)
{
    TipoItem x, w;
    *i = esq;
    *j = dir;
    x = A[(*i + *j)/2]; //obtem o pivô
    do{
        while(x.Chave > A[*i].Chave) (*i)++;
        while(x.Chave < A[*j].Chave) (*j)--;
        if(*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
        }
    } while(*i < *j);
}

void ordena (int esq, int dir, TipoItem *A)
{
    int i, j;
    particao(esq, dir, &i, &j, A);
    if(esq < j) ordena(esq, j, A);
    if(i < dir) ordena(i, dir, A);
}

void quickSort(TipoItem *A, int n)
{
    ordena(1, n, A);
}



Complexidade:
Melhor Caso: O(nlogn), O(nlogn), O(n²)


QUICKSORT: 
*DIvidir e conquistar;
*Um elemento é escolhido como pivo;
* Particionar os dados: partindo do pivo, valores menores do que o pivo 
são colocados antes dele e valores maiores que ele depois dele;
*Recursivamente ordena as duas partições.

*percorre o vetor a partir da esquerda A[i]>= que o pivo, 
depois percore o vetor a partir da direita até que A[j]<= que o pivo, Troca A[i] com A[j].
*Vai Fazendo isso até q i e j se cruzem 
