MERGESORT

void merge(int *A, int esq, int mid, int dir)
{
    int aux[MAX];
    int i=esq, j=mid+1, k=0;

    while(i<=mid && j<=dir)
        if(A[i] <= A[j])
            aux[k++] = A[i++];
        else
            aux[k++] = A[j++];

    while(i <= mid)
        aux[k++] = A[i++];
    while(j <= dir)
        aux[k++] = A[j++];

    for(i=esq, k=0; i<=dir; i++, k++)
        A[i] = aux[k];
}

void mergeSort(int *A, int esq, int dir)
{
    int mid = (esq + dir)/2;
    if(esq < dir){
        mergeSort(A, esq, mid);
        mergeSort(A, mid+1, dir);
        merge(A, esq, mid, dir);
    }
}


COMPLEXIDADE: O(n logn)

*Dividi o vetor em dois
*Ordena a primeira parte do vetor mergeSort(A, esq, mid)
*Ordena a segunda parte do vetor mergeSort(A, mid+1, dir)
*Escolhemos um vetor aux e percorremos os dois subvetores pegando o minimo de cada, a cada interação
até qu termine

