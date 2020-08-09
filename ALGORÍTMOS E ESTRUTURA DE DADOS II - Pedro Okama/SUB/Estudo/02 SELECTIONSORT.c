SELECTIONSORT

void selectionSort (TipoItem *A, int n)
{
    int i, j, min;
    TipoItem aux;
    for (i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++)
            if (A[j].Chave < A[min].Chave)
                min = j;

        aux = A[min];
        A[min] = A[i];
        A[i] = aux;
    }
}


Complexixidade O(n²) em todos os casos

Pega a posição que está, (começando do zero) e compara com todos as posições da sua frente, 
o menor é selecionado e troca a posição dos valores entre o comparado e o selecionado