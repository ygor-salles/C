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


Complexixidade O(n�) em todos os casos

Pega a posi��o que est�, (come�ando do zero) e compara com todos as posi��es da sua frente, 
o menor � selecionado e troca a posi��o dos valores entre o comparado e o selecionado